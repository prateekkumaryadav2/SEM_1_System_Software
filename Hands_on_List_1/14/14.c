/*
==========================================================================
Name : 14.c
Author : Prateek Kumar Yadav
Description : Write a program to find the type of a file.    
        a. Input should be taken from command line.    
        b. program should be able to identify any type of a file.   
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;
    if (stat(argv[1], &fileStat) < 0) {
        perror("stat");
        return 1;
    }

    if (S_ISREG(fileStat.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(fileStat.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(fileStat.st_mode))
        printf("Symbolic link\n");
    else if (S_ISCHR(fileStat.st_mode))
        printf("Character device\n");
    else if (S_ISBLK(fileStat.st_mode))
        printf("Block device\n");
    else if (S_ISFIFO(fileStat.st_mode))
        printf("FIFO (named pipe)\n");
    else if (S_ISSOCK(fileStat.st_mode))
        printf("Socket\n");
    else
        printf("Unknown file type\n");

    return 0;
}

/*
==========================================================================
Output : 
            prateek@Prateek-Kumar 14 % gcc 14.c           
            prateek@Prateek-Kumar 14 % ./a.out file_14.txt
            Regular file

            prateek@Prateek-Kumar 14 % ln -s file_14.txt softlink
            prateek@Prateek-Kumar 14 % ln file_14.txt hardlink 
            prateek@Prateek-Kumar 14 % mkdir dummydir
            prateek@Prateek-Kumar 14 % mkfifo myfifo

            prateek@Prateek-Kumar 14 % ./a.out dummydir          
            Directory
            prateek@Prateek-Kumar 14 % ./a.out softlink
            Regular file
            prateek@Prateek-Kumar 14 % ./a.out hardlink 
            Regular file
            prateek@Prateek-Kumar 14 % ./a.out myfifo                
            FIFO (named pipe)
======================================================================
*/