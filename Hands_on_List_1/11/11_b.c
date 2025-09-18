/*
==========================================================================
Name : 11_b.c
Author : Prateek Kumar Yadav
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.    
        b. use dup2
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

    // Choose a specific file descriptor number (e.g., 100)
    int fd2 = 3;
    // dup2(fd, newfd) duplicates fd to the specific file descriptor number newfd. If newfd is already open, it is closed first.
    if (dup2(fd1, fd2) == -1) {
        perror("dup2");
        close(fd1);
        return 1;
    }

    // Write using the first descriptor
    const char *msg1 = "Written using fd1 (using dup2)\n";
    if (write(fd1, msg1, strlen(msg1)) == -1) {
        perror("write fd1");
    }

    // Write using the duplicated descriptor
    const char *msg2 = "Written using fd2 (using dup2)\n";
    if (write(fd2, msg2, strlen(msg2)) == -1) {
        perror("write fd2");
    }

    close(fd1);
    close(fd2);

    // printf("Check the contents of dup2_test.txt to verify both writes.\n");

    return 0;
}

/*
==========================================================================
Output : 
            prateek@Prateek-Kumar 11 % cat dummy11.txt
            Written using fd1
            Written using fd2
            prateek@Prateek-Kumar 11 % cc 11_b.c      
            prateek@Prateek-Kumar 11 % ./a.out        
            prateek@Prateek-Kumar 11 % cat dummy11.txt
            Written using fd1
            Written using fd2
            Written using fd1 (using dup2)
            Written using fd2 (using dup2)
==========================================================================
*/