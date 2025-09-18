/*
==========================================================================
Name : inflp.c
Author : Prateek Kumar Yadav
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory. 
Date: 3rd Sep, 2025.
==========================================================================
*/

#include<stdio.h>
int main(void){
  for(;;);
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 2 % cc inflp.c -o inflp
          prateek@Prateek-Kumar 2 % ./inflp &          
          [1] 5535
          prateek@Prateek-Kumar 2 % ps -j
          USER      PID  PPID  PGID   SESS JOBC STAT   TT       TIME COMMAND
          prateek  4071  4065  4071      0    0 Ss   s001    0:00.11 /bin/zsh -il
          prateek  5535  4071  5535      0    1 RN   s001    0:08.07 ./inflp
          prateek  4840  4839  4840      0    1 S+   s002    0:00.06 -zsh
          prateek@Prateek-Kumar 2 % ps -j 5535
          USER      PID  PPID  PGID   SESS JOBC STAT   TT       TIME COMMAND
          prateek  5535  4071  5535      0    1 RN   s001    0:18.56 ./inflp
          prateek@Prateek-Kumar 2 % kill 5535
          [1]  + terminated  ./inflp    
          prateek@Prateek-Kumar 2 % ps -j 5535
          USER   PID  PPID  PGID   SESS JOBC STAT   TT       TIME COMMAND
          prateek@Prateek-Kumar 2 % ps -j     
          USER      PID  PPID  PGID   SESS JOBC STAT   TT       TIME COMMAND
          prateek  4071  4065  4071      0    0 Ss   s001    0:00.12 /bin/zsh -il
          prateek  4840  4839  4840      0    1 S+   s002    0:00.06 -zsh
==========================================================================
*/

