/*
==========================================================================
Name : 10_a.c
Author : Prateek Kumar Yadav
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.     
    a. check the return value of lseek
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    int fd = open("dummy10.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) perror("open");
    // HEYPRATEEK IMACINTOSH
    // size 11 bcoz to allow space for the null terminator ('\0'), which is automatically added by the string literal in C.
    char data1[11] = "HEYPRATEEK"; // 10 bytes + null terminator
    char data2[11] = "IMACINTOSH"; // 10 bytes + null terminator

    // Write first 10 bytes
    if (write(fd, data1, 10) != 10) {
        perror("write");
        close(fd);
        return 1;
    }

    // Move file pointer by 10 bytes from current position
    off_t seek_offset = lseek(fd, 10, SEEK_CUR);
    // off_t : It is used by functions like lseek() to specify or return a position (offset) within a file.
    if (seek_offset == -1) {
      perror("lseek");
      close(fd);
      return 1;
    }
    // else means successfully written / skipped 10 bytes


    // Always cast off_t to long long and use %lld for portable, correct output as it can give incorrect result
    printf("current seek offset : %lld", (long long)seek_offset);
    
    // Write next 10 bytes
    if (write(fd, data2, 10) != 10) {
      perror("write");
      close(fd);
      return 1;
    }
    printf("current seek offset : %lld", (long long)seek_offset);
    
    close(fd);
    return 0;
}
/*
==========================================================================
Output : 
		    prateek@Prateek-Kumar 10 % gcc 10_a.c
        prateek@Prateek-Kumar 10 % ./a.out 
        current seek offset : 20% 
==========================================================================
*/