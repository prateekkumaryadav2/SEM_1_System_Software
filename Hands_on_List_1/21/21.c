/*
==========================================================================
Name : 21.c
Author : Prateek Kumar Yadav
Description : Write a program, call fork and print the parent and 
              child process id.
Date: 2nd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid;
  pid=fork(); 
  /* fork
  --> return child's pid in parent process, 
  --> return 0 in child process 
  --> return -1 on error
  */

  if(!pid) { // Child process
    printf("Child process ID = %d, Parent PID = %d\n", getpid(), getppid());
  }else{  // Parent process
    printf("Parent process ID = %d, Child process ID = %d\n", getpid(), pid);
    // Waiting for child process to complete execution, by collecting child's exit status
    wait(NULL);
  }
  return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 21 % cc 21.c
          prateek@Prateek-Kumar 21 % ./a.out
          Parent process ID = 7106, Child process ID = 7107
          Child process ID = 7107, Parent PID = 7106
==========================================================================
*/