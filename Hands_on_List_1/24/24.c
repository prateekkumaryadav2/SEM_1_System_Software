/*
==========================================================================
Name : 24.c
Author : Prateek Kumar Yadav
Description : Write a program to create an orphan process.
Date: 2nd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  pid_t pid;
  pid = fork();
  if (pid == 0) { // Child process
    printf("Child process with PID %d, and parent with PId = %d\n", getpid(),getppid());
    // printf("original parent PID: %d\n", );
    
    // Sleep to ensure that parent exits first
    sleep(2);
    
    // Init process (PID 1) adopts the orphan child
    printf("Child waking up from sleep, now Parent is with PID = %d\n",getppid());

    // Child continues running for a while as orphan
    printf("Orphan child sleeping for 10 seconds now as a orphan\n");
    sleep(10);
    
    printf("child terminated\n");
    exit(0);
  }
  else {  // Parent process
    printf("Parent with PID = %d, created a child process with PID = %d\n", getpid(), pid);
    // here parent is not waiting for child's exit code and exists first making child orphan

    // Parent exits before child - creates orphan
    exit(0);  
  }
  /*
  Zombie: Child dies, parent doesn't collect exit status
  Orphan: Parent dies, child continues running (adopted by init)
  */
  return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 24 % cc 24.c
          prateek@Prateek-Kumar 24 % ./a.out
          Parent with PID = 1342, created a child process with PID = 1343
          Child process with PID 1343, and parent with PId = 1342
          prateek@Prateek-Kumar 24 % Child waking up from sleep, now Parent is with PID = 1
          Orphan child sleeping for 10 seconds now as a orphan
          child terminated
========================================================
*/