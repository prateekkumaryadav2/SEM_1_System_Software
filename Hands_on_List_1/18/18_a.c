/*
==========================================================================
Name : 18_a.c
Author : Prateek Kumar Yadav
Description : Write a program to perform Record locking.    
    a. Implement write lock     
Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition. 
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define RECORD_SIZE 10  // Each record is 10 characters (including newline)
#define NUM_RECORDS 3

// initialzing the file with our defined 3 records
void initialize_file() {
    int fd = open("18.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    // Writting exactly 3 records: abc, mno, xyz
    // Padded to make the content of size 10 chars
    write(fd, "abc      \n", RECORD_SIZE);  
    write(fd, "mno      \n", RECORD_SIZE);
    write(fd, "xyz      \n", RECORD_SIZE);
    
    close(fd);
    printf("File initialized with assigned records\n");
}

// applying record lock
int lock_record(int fd, int record_num) {
    struct flock lock;
    
    // aiming to apply a Write lock
    lock.l_type = F_WRLCK;        
    lock.l_whence = SEEK_SET;

    // multiplying with record number will tell us how much record we want to shift further to apply our record lock so that we can move further with our task of changing/modifying the value
    lock.l_start = record_num * RECORD_SIZE;

    // apply lock for a lenght of 10 records which is our record size
    lock.l_len = RECORD_SIZE;
    
    printf("Attempting to lock record %d...\n", record_num + 1);
    
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        printf("Failed to lock record %d - already locked by another process\n", record_num + 1);
        return -1;
    }
    
    printf("Record %d locked successfully\n", record_num + 1);
    return 0;
}

void unlock_record(int fd, int record_num);

void modify_record(int record_num, char *new_data) {
    int fd;
    // +1 for'\0'
    char record[RECORD_SIZE + 1];
    char formatted_record[RECORD_SIZE + 1];
    
    fd = open("18.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return;
    }
    
    // applying for record lock
    if (lock_record(fd, record_num) == -1) {
        close(fd);
        return;
    }
    
    // Reading the current record
    // starting from initial position now moving to record position we are interested in modifying
    lseek(fd, record_num * RECORD_SIZE, SEEK_SET);
    read(fd, record, RECORD_SIZE);
    record[RECORD_SIZE] = '\0';
    
    printf("Current record %d: %.*s\n", record_num + 1, 9, record);
    
    // Format new data (padding with spaces and adding a newline)
    sprintf(formatted_record, "%-9s\n", new_data);
    
    printf("Modifying record %d to: %s\n", record_num + 1, new_data);
    // adding sleep to demonstate exclusive-ness showing that it is working
    sleep(10);
    
    // updating the modified record
    lseek(fd, record_num * RECORD_SIZE, SEEK_SET);
    // writing the new record
    write(fd, formatted_record, RECORD_SIZE);
    
    printf("Record number %d modified successfully\n", record_num + 1);
    
    // releasing the record lock
    unlock_record(fd, record_num);
    close(fd);
}

void unlock_record(int fd, int record_num) {
    struct flock lock;
    
    // unlocking
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    
    fcntl(fd, F_SETLK, &lock);
    printf("Record %d unlocked\n", record_num + 1);
}

int main() {
    // checking if file exists
    if (access("18.txt", F_OK) != 0) {
        initialize_file();
    }
    printf("Modifying record 1\n");
    modify_record(0, "new1");
    return 0;
}

/*
==========================================================================
Output : 
            prateek@Prateek-Kumar 18 % cc 18_a.c
            prateek@Prateek-Kumar 18 % ./a.out  
            File initialized with assigned records
            Modifying record 1
            Attempting to lock record 1...
            Record 1 locked successfully
            Current record 1: abc      
            Modifying record 1 to: new1
            Record number 1 modified successfully
            Record 1 unlocked
            prateek@Prateek-Kumar 18 % cat 18.txt
            new1     
            mno      
            xyz 

--> if other enters
            prateek@Prateek-Kumar 18 % ./a.out
            File initialized with assigned records
            Modifying record 1
            Attempting to lock record 1...
            Failed to lock record 1 - already locked by another process            
==========================================================================
*/