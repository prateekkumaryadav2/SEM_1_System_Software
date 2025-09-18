/*
==========================================================================
Name : 3.c
Author : Prateek Kumar Yadav
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call 
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
	int fd = creat("myfile.txt", 0666);
	if (fd == -1) perror("creat");
	printf("File 'myfile.txt' created with file descriptor: %d\n", fd);
	close(fd);
}

/*
==========================================================================
Output : 
					prateek@Prateek-Kumar 3 % cc 3.c
					prateek@Prateek-Kumar 3 % ./a.out
					File 'myfile.txt' created with file descriptor: 3
==========================================================================
*/