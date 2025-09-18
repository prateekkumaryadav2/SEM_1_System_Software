/*
==========================================================================
Name : 27_b.c
Author : Prateek Kumar Yadav
Description : Write a program to execute ls -Rl by the following 
              system calls      
              b. execlp
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  printf("Executing 'ls -rl'\n");
  // Using execlp to execute ls -rl
  execlp("ls", "ls", "-rl", NULL);
  // p-> path search
  // Runs ls -l by searching PATH for ls (eg, /bin/ls).
  // This line will only be execute if execl fails
  perror("execl failed");
  return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 27 % cc 27_b.c
          prateek@Prateek-Kumar 27 % ./a.out  
          Executing 'ls -rl'
          total 96
          -rwxr-xr-x@ 1 prateek  staff  33512 Sep  3 14:59 a.out
          -rw-r--r--@ 1 prateek  staff   1129 Sep  3 14:59 27_b.c
          -rw-r--r--@ 1 prateek  staff   1132 Sep  3 14:55 27_a.c
==========================================================================
*/