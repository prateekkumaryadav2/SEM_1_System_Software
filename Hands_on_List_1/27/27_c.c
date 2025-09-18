/*
==========================================================================
Name : 27_c.c
Author : Prateek Kumar Yadav
Description : Write a program to execute ls -Rl by the following 
              system calls      
              c. execle
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  printf("Executing 'ls -rl'\n");
  // Using execle to execute ls -rl
  char *env[] = {
    "PATH=/bin:/usr/bin", 
    NULL
  };
  // like execl() but with custom environment
  execle("/bin/ls", "ls", "-rl", NULL, env);
  // This will run the env command with only in its defined environment.
  // This line will only be execute if execl fails
  perror("execl failed");
  return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 27 % cc 27_c.c
          prateek@Prateek-Kumar 27 % ./a.out  
          Executing 'ls -rl'
          total 96
          -rwxr-xr-x@ 1 prateek  staff  33656 Sep  3 15:06 a.out
          -rw-r--r--@ 1 prateek  staff   1009 Sep  3 15:06 27_c.c
          -rw-r--r--@ 1 prateek  staff   1272 Sep  3 15:01 27_b.c
          -rw-r--r--@ 1 prateek  staff   1132 Sep  3 14:55 27_a.c
==========================================================================
*/