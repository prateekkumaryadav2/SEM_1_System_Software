/*
==========================================================================
Name : 16_b.c
Author : Prateek Kumar Yadav
Description : Write a program to perform mandatory locking.    
              a. Implement read lock
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file_16.txt", O_RDONLY | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct flock lock;
    // Read lock (shared lock)
    lock.l_type = F_RDLCK;    
    // From the beginning of the file
    lock.l_whence = SEEK_SET; 
    // Start of the lock
    lock.l_start = 0;         
    // Lock the whole file
    lock.l_len = 0;           

    printf("Trying to acquire read lock...\n");
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl - locking failed");
        close(fd);
        return 1;
    }

    printf("Read lock acquired. Press Enter to release lock...\n");
    getchar();

    // Unlock
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}

/*
==========================================================================
Output : 
            prateek@Prateek-Kumar 16 % ./a.out   
            Trying to acquire read lock...
            Read lock acquired. Press Enter to release lock...

            // read lock can fail and fcntl returns -1 if another exclusive lock is in place

            prateek@Prateek-Kumar 16 % gcc 16_b.c -o read_lock.out
            prateek@Prateek-Kumar 16 % ./read_lock.out            
            Trying to acquire read lock...
            fcntl - locking failed: Resource temporarily unavailable
======================================================================
*/