/*
==========================================================================
Name : 5.c
Author : Prateek Kumar Yadav
Description : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd. 
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd1 = open("file1.txt", O_CREAT | O_EXCL, 0666);
    if (fd1 == -1) perror("open");
    printf("File 1 opened with file descriptor no. %d\n", fd1);

    int fd2 = open("file2.txt", O_CREAT | O_EXCL, 0666);
    if (fd2 == -1) perror("open");
    printf("File 2 opened with file descriptor no. %d\n", fd2);
    
    int fd3 = open("file3.txt", O_CREAT | O_EXCL, 0666);
    if (fd3 == -1) perror("open");
    printf("File 3 opened with file descriptor no. %d\n", fd3);
    
    int fd4 = open("file4.txt", O_CREAT | O_EXCL, 0666);
    if (fd4 == -1) perror("open");
    printf("File 4 opened with file descriptor no. %d\n", fd4);
    
    int fd5 = open("file5.txt", O_CREAT | O_EXCL, 0666);
    if (fd5 == -1) perror("open");
    printf("File 5 opened with file descriptor no. %d\n", fd5);
    
    // Infinite loop
    while (1) {

    }

    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
    close(fd5);
}

/*
gcc 5.c
./a.out & //return a pid
ps -j // details
kill <pid>
*/

/*
==========================================================================
Output : 
--> In Linux
		    prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss$ cc ho1_5.c 
            prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss$ ./a.out &
            [1] 15522
            prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss$ File 1 opened with file descriptor no. 3
            File 2 opened with file descriptor no. 4
            File 3 opened with file descriptor no. 5
            File 4 opened with file descriptor no. 6
            File 5 opened with file descriptor no. 7
            ls -l /proc/15522/fd/
            total 0
            lrwx------ 1 prateek prateek 64 Sep  7 17:12 0 -> /dev/pts/0
            lrwx------ 1 prateek prateek 64 Sep  7 17:12 1 -> /dev/pts/0
            lrwx------ 1 prateek prateek 64 Sep  7 17:12 2 -> /dev/pts/0
            lr-x------ 1 prateek prateek 64 Sep  7 17:12 3 -> /home/prateek/Desktop/ss/file1.txt
            lr-x------ 1 prateek prateek 64 Sep  7 17:12 4 -> /home/prateek/Desktop/ss/file2.txt
            lr-x------ 1 prateek prateek 64 Sep  7 17:12 5 -> /home/prateek/Desktop/ss/file3.txt
            lr-x------ 1 prateek prateek 64 Sep  7 17:12 6 -> /home/prateek/Desktop/ss/file4.txt
            lr-x------ 1 prateek prateek 64 Sep  7 17:12 7 -> /home/prateek/Desktop/ss/file5.txt
            prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss$ kill 15522
==========================================================================
*/