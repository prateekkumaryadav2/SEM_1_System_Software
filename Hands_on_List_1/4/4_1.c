/*
==========================================================================
Name : 4_1.c
Author : Prateek Kumar Yadav
Description : Write a program to open an existing file with read write mode.
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd = open("file_41.txt", O_RDWR);
    if (fd == -1) perror("open");
    printf("File opened with file descriptor no. %d\n", fd);
    close(fd);
}
/*
O_RDWR opens the file for both reading and writing.
If the file does not exist, open() will fail and return -1.
*/

/*
==========================================================================
Output : 
		    prateek@Prateek-Kumar 4 % touch file_41.txt
            prateek@Prateek-Kumar 4 % cc 4_1.c         
            prateek@Prateek-Kumar 4 % ./a.out          
            File opened with file descriptor no. 3
==========================================================================
*/