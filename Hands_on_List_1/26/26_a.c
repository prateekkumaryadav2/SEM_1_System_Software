/*
==========================================================================
Name : 26_a.c
Author : Prateek Kumar Yadav
Description : Write a program to execute an executable program.    
              a. use some executable program
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  printf("Executing => echo 'Hey executing echo command';\n");
  // we have to mention the path where the command is stored in the system
  execl("/bin/echo", "echo", "Hey executing echo command", NULL);
  // This line will only be execute if execl fails
  perror("execl failed");
  return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 26 % cc 26_a.c
          prateek@Prateek-Kumar 26 % ./a.out  
          Executing => echo 'Hey executing echo command';
          Hey executing echo command
==========================================================================
*/