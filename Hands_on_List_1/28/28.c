/*
==========================================================================
Name : 28.c
Author : Prateek Kumar Yadav
Description : Write a program to get maximum and minimum 
              real time priority
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <sched.h>

int main() {
  printf("For FIFO\n");
  printf("Min = %d, Max = %d", sched_get_priority_min(SCHED_FIFO),sched_get_priority_max(SCHED_FIFO));
  
  printf("\nFor RR\n");
  printf("Min = %d, Max = %d", sched_get_priority_min(SCHED_RR), sched_get_priority_max(SCHED_RR));

  return 0;
}

/*
==========================================================================
Output : 
--> in MacOS
          prateek@Prateek-Kumar 28 % cc 28.c
          prateek@Prateek-Kumar 28 % ./a.out
          For FIFO
          Min = 15, Max = 47
          For RR
          Min = 15, Max = 47%          
--> in Linux
          prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss$ cc scheduling_prio.c
          prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss$ ./a.out
          For FIFO
          Min = 1, Max = 99
          For RR
          Min = 1, Max = 99
==========================================================================
*/