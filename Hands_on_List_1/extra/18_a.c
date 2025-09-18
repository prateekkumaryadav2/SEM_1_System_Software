#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define RECORD_SIZE 10  // Each record is 10 characters (including newline)
#define NUM_RECORDS 3

void initialize_file() {
    int fd = open("rough.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    // Writting exactly 3 records: abc, mno, xyz
    write(fd, "abc      \n", RECORD_SIZE);  // Padded to 10 chars
    write(fd, "mno      \n", RECORD_SIZE);
    write(fd, "xyz      \n", RECORD_SIZE);
    
    close(fd);
    printf("File initialized with assigned records\n");
}

int lock_record(int fd, int record_num) {
    struct flock lock;
    
    lock.l_type = F_WRLCK;        // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    
    printf("Attempting to lock record %d...\n", record_num + 1);
    
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        printf("Failed to lock record %d - already locked by another process\n", record_num + 1);
        return -1;
    }
    
    printf("Record %d locked successfully\n", record_num + 1);
    return 0;
}

void unlock_record(int fd, int record_num) {
    struct flock lock;
    
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    
    fcntl(fd, F_SETLK, &lock);
    printf("Record %d unlocked\n", record_num + 1);
}

void modify_record(int record_num, char *new_data) {
    int fd;
    char record[RECORD_SIZE + 1];
    char formatted_record[RECORD_SIZE + 1];
    
    fd = open("rough.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return;
    }
    
    // Try to lock the record
    if (lock_record(fd, record_num) == -1) {
        close(fd);
        return;
    }
    
    // Read current record
    lseek(fd, record_num * RECORD_SIZE, SEEK_SET);
    read(fd, record, RECORD_SIZE);
    record[RECORD_SIZE] = '\0';
    
    printf("Current record %d: %.*s\n", record_num + 1, 9, record);
    
    // Format new data (pad with spaces and add newline)
    sprintf(formatted_record, "%-9s\n", new_data);
    
    // Simulate processing time
    printf("Modifying record %d to: %s\n", record_num + 1, new_data);
    sleep(3);
    
    // Write modified record
    lseek(fd, record_num * RECORD_SIZE, SEEK_SET);
    write(fd, formatted_record, RECORD_SIZE);
    
    printf("Record %d modified successfully\n", record_num + 1);
    
    // Unlock the record
    unlock_record(fd, record_num);
    close(fd);
}

void display_all_records() {
    int fd;
    char record[RECORD_SIZE + 1];
    
    fd = open("rough.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return;
    }
    
    printf("\nCurrent records:\n");
    for (int i = 0; i < NUM_RECORDS; i++) {
        lseek(fd, i * RECORD_SIZE, SEEK_SET);
        read(fd, record, RECORD_SIZE);
        record[9] = '\0';  // Remove newline for display
        printf("Record %d: %s\n", i + 1, record);
    }
    printf("\n");
    
    close(fd);
}

int main() {
    // Initialize file if it doesn't exist
    if (access("rough.txt", F_OK) != 0) {
        initialize_file();
    }
    
    printf("=== Record Locking Demo ===\n");
    display_all_records();
    
    // Demonstrate record locking by modifying records
    // printf("Modifying record 1\n");
    // modify_record(0, "new1");
    
    printf("Modifying record 2\n");
    modify_record(1, "new2");
    
    // printf("Modifying record 3\n");
    // modify_record(2, "new3");
    
    printf("\nAfter modifications:\n");
    display_all_records();
    
    // printf("You can view the file with: cat records.txt\n");
    
    return 0;
}