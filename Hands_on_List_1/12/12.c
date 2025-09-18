/*
==========================================================================
Name : 12.c
Author : Prateek Kumar Yadav
Description : Write a program to find out the opening mode of a file. Use fcntl
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("dummy12.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    // F_GETFL is a command used with the fcntl() system call in C to get the file status flags and access mode of an open file descriptor
    int flags = fcntl(fd, F_GETFL);

    // flags is a bitmask containing all the file status flags (including access mode and other options)
    // O_APPEND is a specific bit in that bitmask.
    // The & (bitwise AND) operation checks if that bit is set.

    if (flags == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    int accessMode = flags & O_ACCMODE;
    if (accessMode == O_RDONLY)
        printf("File is opened in read-only mode.\n");
    else if (accessMode == O_WRONLY)
        printf("File is opened in write-only mode.\n");
    else if (accessMode == O_RDWR)
        printf("File is opened in read-write mode.\n");

    if (flags & O_APPEND)
        printf("File is opened in append mode.\n");

    /*
    We cannot use:
      if (accessMode == O_APPEND)

      because accessMode only contains the access mode bits (read-only, write-only, or read-write), not the other flags like O_APPEND.

      O_APPEND is not an access mode; it is an additional flag.
    */

    close(fd);
    return 0;
}

/*
==========================================================================
Output : 
            prateek@Prateek-Kumar 12 % cc 12.c        
            prateek@Prateek-Kumar 12 % ./a.out        
            File is opened in read-write mode.
======================================================================
*/