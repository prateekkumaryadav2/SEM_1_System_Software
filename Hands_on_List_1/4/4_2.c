/*
==========================================================================
Name : 4_1.c
Author : Prateek Kumar Yadav
Description : Write a program to open an existing file with read write mode. 
            With O_EXCL flag also. 
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// touch file_4.txt

int main(void) {
    int fd = open("file_42.txt", O_CREAT | O_EXCL, 0666);
    if (fd == -1) perror("open");
    printf("File opened with file descriptor no. %d\n", fd);
    close(fd);
}
/*
The O_CREAT flag is used with the open() system call in C to create a file if it does not already exist.

If the specified file does not exist, open() will create it.
If the file already exists, open() just opens it (unless combined with O_EXCL).
When using O_CREAT, you must also provide a third argument specifying the file permissions (e.g., 0666).

the O_EXCL flag is used with the O_CREAT flag in the open() system call in C.

When both O_CREAT | O_EXCL are used together, open() will fail if the file already exists.
This is useful for safely creating new files and avoiding overwriting existing ones.
*/

/*
==========================================================================
Output : 
		    prateek@Prateek-Kumar 4 % ls   
            4_1.c           4_2.c           a.out           file_41.txt
            prateek@Prateek-Kumar 4 % cc 4_2.c
            prateek@Prateek-Kumar 4 % ./a.out 
            File opened with file descriptor no. 3
==========================================================================
*/