#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int initial_ticket = 100;  // Starting ticket number
    
    // Create/open file for writing
    fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    // Write initial ticket number
    if (write(fd, &initial_ticket, sizeof(int)) == -1) {
        perror("write");
        close(fd);
        return 1;
    }
    
    printf("Ticket file initialized with ticket number: %d\n", initial_ticket);
    
    close(fd);
    return 0;
}

// ticket_reserve.c

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int fd;
    int ticket_number;
    struct flock lock;
    
    printf("Attempting to reserve a ticket...\n");
    
    // Open file for read and write
    fd = open("ticket.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        printf("Make sure to run ticket_init first!\n");
        return 1;
    }
    
    // Set up write lock structure
    lock.l_type = F_WRLCK;     // Write lock
    lock.l_whence = SEEK_SET;  // From beginning of file
    lock.l_start = 0;          // Start from byte 0
    lock.l_len = 0;            // Lock entire file
    
    printf("Acquiring write lock...\n");
    
    // Acquire write lock (blocking)
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - lock failed");
        close(fd);
        return 1;
    }
    
    printf("Write lock acquired successfully!\n");
    printf("Processing ticket reservation...\n");
    
    // Simulate some processing time
    sleep(2);
    
    // Read current ticket number
    lseek(fd, 0, SEEK_SET);  // Go to beginning of file
    if (read(fd, &ticket_number, sizeof(int)) == -1) {
        perror("read");
        close(fd);
        return 1;
    }
    
    printf("Current ticket number: %d\n", ticket_number);
    
    // Increment ticket number
    ticket_number++;
    
    // Write updated ticket number back to file
    lseek(fd, 0, SEEK_SET);  // Go to beginning of file
    if (write(fd, &ticket_number, sizeof(int)) == -1) {
        perror("write");
        close(fd);
        return 1;
    }
    
    printf("NEW TICKET RESERVED: %d\n", ticket_number);
    
    // Release lock
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    
    printf("Lock released. Ticket reservation complete!\n");
    
    close(fd);
    return 0;
}