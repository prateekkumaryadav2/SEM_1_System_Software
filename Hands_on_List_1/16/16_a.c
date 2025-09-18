/*
==========================================================================
Name : 16_a.c
Author : Prateek Kumar Yadav
Description : Write a program to perform mandatory locking.    
              a. Implement write lock
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file_16.txt", O_WRONLY | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct flock lock;
    // Declares a flock structure to specify the lock details.
    lock.l_type = F_WRLCK;    // Write lock(exclusive lock)
    lock.l_whence = SEEK_SET; // From the beginning of the file
    lock.l_start = 0;         // Start of the lock
    lock.l_len = 0;           // Lock the whole file

    printf("Trying to acquire write lock...\n");
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl - locking failed");
        close(fd);
        return 1;
    }

    printf("Write lock acquired. Press Enter to release lock...\n");
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

-> when other not accessing
    prateek@Prateek-Kumar 16 % ./a.out
    Trying to acquire write lock...
    Write lock acquired. Press Enter to release lock...

-> when other inside CS
    prateek@Prateek-Kumar 16 % ./a.out
    Trying to acquire write lock...
    fcntl - locking failed: Resource temporarily unavailable

======================================================================
*/

/*
fcntl(fd, F_SETLK, &lock)
Attempts to acquire the write lock.

If the lock is acquired, the function returns 0.
If another process already holds a conflicting lock (e.g., another write lock or a read lock), it returns -1 and sets errno to EACCES or EAGAIN.
*/