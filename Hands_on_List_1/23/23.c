/*
==========================================================================
Name : 23.c
Author : Prateek Kumar Yadav
Description : Write a program to create a Zombie state of 
              the running program
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
    printf("Child process with PID = %d\n", getpid());
    // Child terminates immediately
    printf("Child process is terminating\n");
    exit(0);
  }else{  // Parent process
      printf("Parent created child with PID = %d\n", pid);
      /*
      --> Look for processes with Z state
      ps aux | grep Z
      
      --> Shows process state
      ps -o pid,ppid,state,comm
      */
     
      // Parent sleeps for 30 seconds without calling wait() and
      // During this time, child becomes a zombie
      printf("Parent going to sleep for 30 seconds\n");
      sleep(30);
      
      printf("Parent waking up and exits\n");
      // When parent exits, init process will clean up the zombie
  }
  
  return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 23 % cc 23.c
          prateek@Prateek-Kumar 23 % ./a.out
          Parent created child with PID = 9932
          Parent going to sleep for 30 seconds
          Child process with PID = 9932
          Child process is terminating
          Parent waking up and exits

prateek           9516   0.0  0.0 410724096   1440 s003  S+    8:40PM   0:00.00 grep Z
prateek           9509   0.0  0.0        0      0 s002  Z+    8:40PM   0:00.00 <defunct>
==========================================================================
*/