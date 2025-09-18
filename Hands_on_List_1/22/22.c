/*
==========================================================================
Name : 22.c
Author : Prateek Kumar Yadav
Description : Write a program, open a file, call fork, and then write 
              to the file by both the child as well as the parent processes. Check output of the file.
Date: 2nd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
  // Opening file for writing (creating if doesn't exist)
  int fd = open("dummy22.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if (fd == -1) {
    perror("open");
    return 1;
  }
  if(!fork()) { // Child process
    char message[] = "written by child process\n";
    if(write(fd, message, strlen(message)) == -1){
      perror("write");
      close(fd);
      return 1;
    }
  }else{  // Parent process
    char message[] = "written by parent process\n";
    if(write(fd, message, strlen(message)) == -1){
      perror("write");
      close(fd);
      return 1;
    }
    // waiting for child to exit first
    wait(NULL);
  }
  close(fd);
  return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 22 % cc 22.c
          prateek@Prateek-Kumar 22 % ./a.out

          <- dummy22.txt ->
l1        written by parent process
l2        written by child process
l3
==========================================================================
*/