/*
==========================================================================
Name : 13.c
Author : Prateek Kumar Yadav
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select). 
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int retval;

    // Set up the file descriptor set.
    FD_ZERO(&readfds);
    FD_SET(0, &readfds); // 0 is the file descriptor for STDIN

    // Set up the timeout: 10 seconds
    timeout.tv_sec = 10;
    // need to set both
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN for up to 10 seconds...\n");
    // This program uses select() to wait for input on STDIN.
    retval = select(1, &readfds, NULL, NULL, &timeout);
    // waits for up to 10 seconds for input on STDIN.

    if (retval == -1) {
        perror("select()");
    } else if (retval) {
        printf("Data is available on STDIN!\n");
    } else {
        printf("No data within 10 seconds.\n");
    }
    return 0;
}

/*
==========================================================================
Output : 
            prateek@Prateek-Kumar 13 % cc 13.c
            prateek@Prateek-Kumar 13 % ./a.out
            Waiting for input on STDIN for up to 10 seconds...
            hey
            Data is available on STDIN!
            prateek@Prateek-Kumar 13 % ./a.out
            Waiting for input on STDIN for up to 10 seconds...
            No data within 10 seconds.
======================================================================
*/