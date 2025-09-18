/*
==========================================================================
Name : 27_e.c
Author : Prateek Kumar Yadav
Description : Write a program to execute ls -Rl by the following 
              system calls      
              e. execvp
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  printf("Executing 'ls -rl'\n");
  // Using execvp to execute ls -rl
  char *args[] = {
    "ls",
    "-rl", 
    NULL
  };
  // arguments as array
  // Takes program name (not full path) - searches PATH automatically
  execvp("ls", args);
  // This line will only be execute if execl fails
  perror("execl failed");
  return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 27 % cc 27_e.c
          prateek@Prateek-Kumar 27 % ./a.out  
          Executing 'ls -rl'
          total 112
          -rwxr-xr-x@ 1 prateek  staff  33656 Sep  3 16:24 a.out
          -rw-r--r--@ 1 prateek  staff    918 Sep  3 16:23 27_e.c
          -rw-r--r--@ 1 prateek  staff   1321 Sep  3 16:24 27_d.c
          -rw-r--r--@ 1 prateek  staff   1374 Sep  3 15:33 27_c.c
          -rw-r--r--@ 1 prateek  staff   1197 Sep  3 15:33 27_b.c
          -rw-r--r--@ 1 prateek  staff   1132 Sep  3 14:55 27_a.c
==========================================================================
*/