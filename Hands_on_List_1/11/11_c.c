/*
==========================================================================
Name : 11_b.c
Author : Prateek Kumar Yadav
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.    
        c. use fcntl
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd1 = open("dummy11.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd1 == -1) {
        perror("open");
        return 1;
    }
    // F_DUPFD is a command used with the fcntl() system call in C to duplicate a file descriptor.

    // fcntl() with F_DUPFD lets you specify the minimum value for the new file descriptor.

    // Duplicates fd to the lowest available file descriptor number greater than or equal to minfd.

    // Duplicate the file descriptor using fcntl
    int fd2 = fcntl(fd1, F_DUPFD, 0); // 0 means use the lowest available fd
    if (fd2 == -1) {
        perror("fcntl");
        close(fd1);
        return 1;
    }

    // Write using the first descriptor
    const char *msg1 = "Written using fd1 (using fcntl)\n";
    if (write(fd1, msg1, strlen(msg1)) == -1) {
        perror("write fd1");
    }

    // Write using the duplicated descriptor
    const char *msg2 = "Written using fd2 (using fcntl)\n";
    if (write(fd2, msg2, strlen(msg2)) == -1) {
        perror("write fd2");
    }

    close(fd1);
    close(fd2);

    return 0;
}
 
/* Note
dup(): returns the lowest available file descriptor. 

dup2(): lets you specify the exact file descriptor number to use

fcntl(): with F_DUPFD lets you specify a minimum value for the new file descriptor.
*/

/*
==========================================================================
Output : 
            prateek@Prateek-Kumar 11 % cat dummy11.txt
            Written using fd1
            Written using fd2
            Written using fd1 (using dup2)
            Written using fd2 (using dup2)
            prateek@Prateek-Kumar 11 % cc 11_c.c      
            prateek@Prateek-Kumar 11 % ./a.out
            prateek@Prateek-Kumar 11 % cat dummy11.txt
            Written using fd1
            Written using fd2
            Written using fd1 (using dup2)
            Written using fd2 (using dup2)
            Written using fd1 (using fcntl)
            Written using fd2 (using fcntl)
==========================================================================
*/