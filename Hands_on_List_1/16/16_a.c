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

    // Declares a flock structure to specify the lock details.
    struct flock lock;
    // Write lock(exclusive lock)
    lock.l_type = F_WRLCK;    
    
    // set lock from the beginning of the file
    // whence means "from where" or "from what place"
    // like our refrence point or starting location
    lock.l_whence = SEEK_SET; 
    // SEEK_SET = "Set position from start"
    
    /*
    --> SEEK_SET = "from the beginning" (whence = start of file)
    --> SEEK_CUR = "from the current position" (whence = current file pointer)
    --> SEEK_END = "from the end" (whence = end of file)
    */

    // Start of the lock from the 0th byte of the file, which is nothing but our starting of file
    lock.l_start = 0;


    // Lock the file 0 bytes from last which also means lock whole file
    lock.l_len = 0;           

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