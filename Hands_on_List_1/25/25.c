/*
==========================================================================
Name : 25.c
Author : Prateek Kumar Yadav
Description : Write a program to create three child processes. 
              The parent should wait for a particular child 
              (use waitpid system call).
Date: 2nd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  pid_t pid1, pid2, pid3;
  int status;
  pid1 = fork();
  if(pid1 == 0){
    printf("child 1 with pid = %d and parent PID = %d\n",getpid(), getppid());
    // sleep for 2s
    sleep(2);
    printf("child 1 exits\n");
    exit(0);
  }else{
    pid2 = fork();  
    if(pid2 == 0){
      printf("child 2 with pid = %d and parent PID = %d\n",getpid(), getppid());
      // sleep for 5s
      sleep(5);
      printf("child 2 exits\n");
      exit(0);
    }else{ 
      pid3 = fork();  
      if(pid3 == 0){
        printf("child 3 with pid = %d and parent PID = %d\n",getpid(), getppid());
        // sleep for 10s
        sleep(10);
        printf("child 3 exits\n");
        exit(0);
      }else{
        // kept variable sleep to show that paret waits fir that particular child
        // waiting for child 3 with this exit code
        waitpid(pid3,NULL,0);
        printf("parent with pid = %d\n",getpid());
        printf("parent exits\n");
        exit(0);
      }
    }
  }  
  return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 25 % cc 25.c
          prateek@Prateek-Kumar 25 % ./a.out
          child 1 with pid = 1189 and parent PID = 1188
          child 2 with pid = 1190 and parent PID = 1188
          child 3 with pid = 1191 and parent PID = 1188
          child 1 exits
          child 2 exits
          child 3 exits
          parent with pid = 1188
          parent exits
==========================================================================
*/