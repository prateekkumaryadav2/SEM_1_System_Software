/*
==========================================================================
Name : 1_a.c
Author : Prateek Kumar Yadav
Description : Create the following types of a files using 
            (i) shell command 
            (ii) system call    
            a. soft link (symlink system call)
Date: 3rd Sep, 2025.
==========================================================================
*/

// system call
#include <unistd.h>
#include <stdio.h>

int main(void) {
    const char *target = "dummy.txt";
    const char *linkpath = "softlink2";
    // symlink(target, linkpath) creates a symbolic link named linkpath pointing to target.

    // If successful, it returns 0; otherwise, it returns -1 and sets errno.
    if (symlink(target, linkpath) == 0) printf("Symbolic link created successfully.\n");
    else perror("symlink");
    return 0;
}

/*
==========================================================================
Output : 
        prateek@Prateek-Kumar 1 % cc 1_a.c
        prateek@Prateek-Kumar 1 % ./a.out 
        Symbolic link created successfully.

--> using shell

        prateek@Prateek-Kumar 1 % ls -l softlink2  
        lrwxr-xr-x@ 1 prateek  staff  9 Sep  3 19:00 softlink2 -> dummy.txt
==========================================================================
*/