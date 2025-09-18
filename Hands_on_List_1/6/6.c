/*
==========================================================================
Name : 6.c
Author : Prateek Kumar Yadav
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <unistd.h>

int main() {
    char buffer[256];
    ssize_t bytesRead;

    // Read from STDIN (file descriptor 0)
    // reading input from command line and storing inside the buffer
    // 0 means STDIN i.e. FD=0
    bytesRead = read(0, buffer, sizeof(buffer));
    if (bytesRead > 0) {
        // Write to STDOUT (file descriptor 1)
        // 1 means STDOUT i.e. FD=1
        write(1, buffer, bytesRead);
    }

    return 0;
}
/*
==========================================================================
Output : 
		    prateek@Prateek-Kumar 6 % gcc 6.c
            prateek@Prateek-Kumar 6 % ./a.out
            hello testing input using STDIN 
            hello testing input using STDIN
==========================================================================
*/

/*
ssize_t is a data type in C used to represent the number of bytes read or written by system calls like read() and write().

- It stands for "signed size type."
- It is similar to size_t, but signed (can be negative).
- A positive value indicates the number of bytes successfully read or written.
- A value of -1 indicates an error.

read() is a system call that reads data from a file descriptor. File descriptor 0 refers to standard input (STDIN).
write() is a system call that writes data to a file descriptor. File descriptor 1 refers to standard output (STDOUT).
The program typically uses a buffer (e.g., char buffer[1024];) to temporarily store the data read from STDIN.
The program calls read(0, buffer, sizeof(buffer)); to read input from the user.
It then calls write(1, buffer, bytesRead); to write the same data to the output.
This approach does not use any C library functions like printf() or scanf(), only low-level system calls.
*/
