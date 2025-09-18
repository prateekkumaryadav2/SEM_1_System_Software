/*
==========================================================================
Name : 17_part_2.c
Author : Prateek Kumar Yadav
Description : Write a program to simulate online ticket reservation.  Implement write lock  Write a program to open a file, store a ticket number and exit.  Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char buffer[25];
    int ticket_number;
    struct flock lock;
    
    int fd = open("ticket.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    // Setting up a write lock 
    // we are applying a whole file lock as we are just storing the ticket count number, so that will do our job
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    
    // setting lock
    fcntl(fd, F_SETLKW, &lock);
    
    printf("Acquiring ticket for you\n");

    // Reading curr ticket number as text
    // 0 indicating move 0 bytes from the current reference point
    lseek(fd, 0, SEEK_SET);
    
    // -1 for space of null terminator '\0'
    int bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytes_read] = '\0';
    
    // we can avoid convertion by storing binary(raw) notations inside the file, but this string way is more human readable

    // Converting ticket number from string to integer for incrementing purpose
    ticket_number = atoi(buffer);
    printf("Current ticket number is %d\n", ticket_number);
    
    // Increment and write back as text
    ticket_number++;
    sprintf(buffer, "%d\n", ticket_number);
    
    lseek(fd, 0, SEEK_SET);
    // Clear file and now re-write the new value
    ftruncate(fd, 0);  
    write(fd, buffer, strlen(buffer));
    
    printf("New Ticket issued with number = %d\n", ticket_number);
    
    // Release lock
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    
    close(fd);
    return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 17 % cc 17_part_2.c -o part_2
          prateek@Prateek-Kumar 17 % ./part_2                
          Acquiring ticket for you
          Current ticket number is 501
          New Ticket issued with number = 502
          prateek@Prateek-Kumar 17 % ./part_2
          Acquiring ticket for you
          Current ticket number is 502
          New Ticket issued with number = 503
          prateek@Prateek-Kumar 17 % ./part_2
          Acquiring ticket for you
          Current ticket number is 503
          New Ticket issued with number = 504
          prateek@Prateek-Kumar 17 % cat ticket.txt
          504
======================================================================
*/