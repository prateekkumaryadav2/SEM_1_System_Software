/*
==========================================================================
Name : 11_a.c
Author : Prateek Kumar Yadav
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.    
        a. use dup
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd1 = open("dummy11.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
    // owner, group, others
    // 4 read
    // 2 write
    // 1 execute
    if (fd1 == -1) {
        perror("open");
        return 1;
    }

    // Duplicate the file descriptor
    int fd2 = dup(fd1);
    // duplicates the given file descriptor fd and returns a new file descriptor with the lowest available number
    if (fd2 == -1) {
        perror("dup");
        close(fd1);
        return 1;
    }

    // Write using the first descriptor
    const char *msg1 = "Written using fd1\n";
    if (write(fd1, msg1, strlen(msg1)) == -1) {
        perror("write fd1");
    }

    // Write using the duplicated descriptor
    const char *msg2 = "Written using fd2\n";
    if (write(fd2, msg2, strlen(msg2)) == -1) {
        perror("write fd2");
    }

    close(fd1);
    close(fd2);

    // Check file content
    // printf("Check the contents of dup_test.txt to verify both writes.\n");

    return 0;
}

/*
==========================================================================
Output : 
            prateek@Prateek-Kumar 11 % cat dummy11.txt
            prateek@Prateek-Kumar 11 % cc 11_a.c      
            prateek@Prateek-Kumar 11 % ./a.out        
            prateek@Prateek-Kumar 11 % cat dummy11.txt
            Written using fd1
            Written using fd2
==========================================================================
*/