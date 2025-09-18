/*
==========================================================================
Name : 18_b.c
Author : Prateek Kumar Yadav
Description : Write a program to perform Record locking.    
    b. Implement read lock     
Create three records in a file. Whenever you access a particular record, first lock it then read/access to avoid race condition. 
Date: 7th Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define RECORD_SIZE 10  // Each record is 10 characters (including newline)
#define NUM_RECORDS 3

void initialize_file() {
    int fd = open("18.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    // Writing exactly 3 records: abc, mno, xyz
    write(fd, "abc      \n", RECORD_SIZE);  // Padded to 10 chars
    write(fd, "mno      \n", RECORD_SIZE);
    write(fd, "xyz      \n", RECORD_SIZE);
    
    close(fd);
    printf("File initialized with assigned records\n");
}

int read_lock_record(int fd, int record_num) {
    struct flock lock;
    
    // Read lock (shared lock)
    lock.l_type = F_RDLCK;        
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    
    printf("Attempting to acquire READ LOCK on record %d\n", record_num + 1);
    
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        printf("Failed to acquire read lock on record %d\n", record_num + 1);
        return -1;
    }
    
    printf("READ LOCK acquired on record %d\n", record_num + 1);
    return 0;
}

void unlock_record(int fd, int record_num) {
    struct flock lock;
    
    // Unlocking
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    
    fcntl(fd, F_SETLK, &lock);
    printf("READ LOCK released on record %d\n", record_num + 1);
}

void read_record(int record_num) {
    int fd;
    char record[RECORD_SIZE + 1];
    
    fd = open("18.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return;
    }
    
    // Trying to acquire read lock
    if (read_lock_record(fd, record_num) == -1) {
        close(fd);
        return;
    }
    
    // Read the current record
    lseek(fd, record_num * RECORD_SIZE, SEEK_SET);
    read(fd, record, RECORD_SIZE);
    record[RECORD_SIZE] = '\0';
    
    printf("Reading record %d: %.*s\n", record_num + 1, 9, record);
    
    printf("Processing record data\n");
    // Simulating processing time
    sleep(10);
    
    printf("Record %d read operation completed\n", record_num + 1);
    
    // Releasing the read lock
    unlock_record(fd, record_num);
    close(fd);
}

int main() {
    // Initialize file if it doesn't exist
    if (access("18.txt", F_OK) != 0) {
        initialize_file();
    }
    printf("Reading record 2 with READ LOCK\n");
    read_record(1);  
    return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 18 % cc 18_b.c
          prateek@Prateek-Kumar 18 % ./a.out  
          Reading record 2 with READ LOCK
          Attempting to acquire READ LOCK on record 2
          READ LOCK acquired on record 2
          Reading record 2: mno      
          Processing record data (simulating 3 seconds)...
          Record 2 read operation completed
          READ LOCK released on record 2
==========================================================================
*/