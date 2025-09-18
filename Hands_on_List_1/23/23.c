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
      wait(NULL);
      // When parent exits, init process will clean up the zombie
  }
  
  return 0;
}

/*

A zombie process is a process that has completed its execution but still has an entry in the process table. It is also known as a "defunct" process.

How a Zombie Process is Created
When a child process finishes its execution, it transitions to a zombie state. In this state, the process's resources (such as memory, files, and I/O) are deallocated, but its entry in the process table remains. The process table entry is maintained to allow the parent process to read its exit status.

A zombie process will only be fully removed from the process table when its parent process retrieves its exit status using a system call like wait() or waitpid(). If the parent process fails to do so, the zombie process will continue to occupy the process table entry, which can eventually lead to system resource issues if many zombies accumulate.

Unlike other processes, a zombie process cannot be killed with a standard kill command. The only way to remove a zombie is to either have its parent process "reap" it (by calling wait()) or to terminate the parent process itself. If the parent process is terminated, the init process (or systemd in modern systems) adopts the zombie and automatically reaps it.
*/

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