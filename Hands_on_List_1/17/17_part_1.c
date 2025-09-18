/*
==========================================================================
Name : 17_part_1.c
Author : Prateek Kumar Yadav
Description : Write a program to simulate online ticket reservation.  Implement write lock  Write a program to open a file, store a ticket number and exit.  Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char buffer[25];
    // intitial ticket numberr
    int initial_ticket = 501;
    
    int fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    // Convert integer to string to store into 
    // file as a human readable text
    sprintf(buffer, "%d\n", initial_ticket);
    write(fd, buffer, strlen(buffer));
    
    printf("Ticketing system initialized with counter = %d number\n", initial_ticket);
    close(fd);
    return 0;
}

/*
==========================================================================
Output : 
            prateek@Prateek-Kumar 17 % cc 17_part_1.c -o part_1
            prateek@Prateek-Kumar 17 % ./part_1                
            Ticketing system initialized with counter = 501 number
======================================================================
*/