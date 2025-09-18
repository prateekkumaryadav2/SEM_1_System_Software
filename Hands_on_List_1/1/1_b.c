/*
==========================================================================
Name : 2_a.c
Author : Prateek Kumar Yadav
Description : Create the following types of a files using 
            (i) shell command 
            (ii) system call    
            b. hard link (link system call) 
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main(void) {
    const char *target = "dummy.txt";
    const char *linkpath = "hardlink2";
    // link(target, linkpath) creates a hard link named linkpath pointing to target.

    // returns 0 on success, -1 on error.
    if (link(target, linkpath) == 0) printf("Hardlink link created successfully.\n");
    else perror("link");
}

/*
==========================================================================
Output : 
        prateek@Prateek-Kumar 1 % ls
        1_a.c           1_b.c           1_shell_c.sh    a.out           myfifo          soft_link_1
        1_a.sh          1_shell_b.sh    1_syscall_c.c   dummy.txt       myfifo2         softlink2
        prateek@Prateek-Kumar 1 % cc 1_b.c 
        prateek@Prateek-Kumar 1 % ./a.out 
        Hardlink link created successfully.
        prateek@Prateek-Kumar 1 % ls
        1_a.c           1_b.c           1_shell_c.sh    a.out           hardlink2       myfifo2         softlink2
        1_a.sh          1_shell_b.sh    1_syscall_c.c   dummy.txt       myfifo          soft_link_1

--> using shell

        prateek@Prateek-Kumar 1 % chmod +x 1_b.sh
        prateek@Prateek-Kumar 1 % ./1_b.sh       
        prateek@Prateek-Kumar 1 % ls -l hard_link_1
        -rw-r--r--@ 6 prateek  staff  33 Aug 14 15:14 hard_link_1
==========================================================================
*/