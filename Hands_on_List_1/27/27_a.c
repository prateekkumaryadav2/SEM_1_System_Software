/*
==========================================================================
Name : 27_a.c
Author : Prateek Kumar Yadav
Description : Write a program to execute ls -Rl by the following 
              system calls      
              a. execl
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  printf("Executing 'ls -rl'\n");
  // Using execl to execute ls -rl
  // Showing files in long listing format (detailed info) in reverse order(Z-->A).
  // null at the end helps to let execl know to stop reading arguments here
  execl("/bin/ls", "ls", "-rl", NULL);
  // This line will only be execute if execl fails
  perror("execl failed");
  return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 27 % cc 27_a.c
          prateek@Prateek-Kumar 27 % ./a.out  
          Executing 'ls -rl'
          total 80
          -rwxr-xr-x@ 1 prateek  staff  33512 Sep  3 14:52 a.out
          -rw-r--r--@ 1 prateek  staff    907 Sep  3 14:52 27_a.c
==========================================================================
*/