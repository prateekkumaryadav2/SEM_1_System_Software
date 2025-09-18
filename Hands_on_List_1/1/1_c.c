/*
==========================================================================
Name : 1_c.c
Author : Prateek Kumar Yadav
Description : Create the following types of a files using 
            (i) shell command 
            (ii) system call    
            c. FIFO (mkfifo Library Function or mknod system call)
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
    const char *fifo_path = "my_fifo";
    // mkfifo(fifo_path, 0666) creates a FIFO special file with read/write permissions for everyone.

    // returns 0 on success, -1 on error.
    if (mkfifo(fifo_path, 0666) == 0) printf("FIFO created successfully.\n");
    else perror("mkfifo");
    // The value 0666 is an octal (base 8) number that sets file permissions in Unix-like systems.

    // 0 at the start means octal.
    // 6 means read (4) + write (2) = 6.
    // The three digits represent permissions for: owner, group, and others.
    // So, 0666 means:
    // Owner: read & write
    // Group: read & write
    // Others: read & write
    // No execute permissions are given.

    // how to execute
    // cat < myfifo2
    // echo "using myfifo2" > myfifo2
}

/*
==========================================================================
Output :
        --> Terminal-1 
        prateek@Prateek-Kumar 1 % cc 1_c.c
        prateek@Prateek-Kumar 1 % ./a.out 
        FIFO created successfully.
        prateek@Prateek-Kumar 1 % cat < my_fifo
        hey there using my_fifo

        --> Terminal-2
        prateek@Prateek-Kumar 1 % echo "hey there using my_fifo" > my_fifo
        
--> using shell
        --> Terminal-1
        prateek@Prateek-Kumar 1 % mkfifo my_fifo_sh 
        prateek@Prateek-Kumar 1 % cat < my_fifo_sh 
        hey there using my_fifo_sh

        --> Terminal-2
        prateek@Prateek-Kumar 1 % echo "hey there using my_fifo_sh" > my_fifo_sh
==========================================================================
*/
