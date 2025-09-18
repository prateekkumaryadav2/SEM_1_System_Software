/*
==========================================================================
Name : 26_b.c
Author : Prateek Kumar Yadav
Description : Write a program to execute an executable program.    
              b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 3rd Sep, 2025.
==========================================================================
*/

/* sample.c
==========================================================================
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Hello, %s!\n", argv[1]);
  return 0;
}
==========================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  printf("Executing './sample.out Prateek'\n");
  // Using execl to execute sample.out with "Prateek" as argument
  execl("./sample.out", "sample.out", "Prateek", NULL);
  // This line will only be execute if execl fails
  perror("execl failed");
  return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 26 % cc 26_b.c
          prateek@Prateek-Kumar 26 % ./a.out  
          Executing './sample.out Prateek'
          Hello, Prateek!
==========================================================================
*/