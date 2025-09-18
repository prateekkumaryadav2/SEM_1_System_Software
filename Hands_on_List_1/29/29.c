/*
==========================================================================
Name : 29.c
Author : Prateek Kumar Yadav
Description : Write a program to get scheduling policy and modify 
              the scheduling policy (SCHED_FIFO, SCHED_RR)
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

// to know scheduling policy
void print_policy(int policy) {
  switch(policy) {
    case SCHED_OTHER:
      printf("Normal time-sharing scheduling\n");
      break;
    case SCHED_FIFO:
      printf("FIFO scheduling\n");
      break;
    default:
      printf("Unknown policy: %d\n", policy);
  }
}

int main() {
    pid_t pid = getpid();
    int current_policy;
    struct sched_param param;

    // Getting the current scheduling policy of this process
    current_policy = sched_getscheduler(pid);
    if(current_policy == -1){
      perror("sched_getscheduler");
      return 1;
    }
    
    printf("Current scheduling policy = ");
    print_policy(current_policy);
    
    // Set priority for real-time scheduling
    param.sched_priority = 10;

    /*
    SCHED_FIFO is a real-time scheduling policy so Real-time policies require priorities in the range 1-99 (on most systems) and Priority 0 is reserved for SCHED_OTHER (normal scheduling)
    */

    // changing to to SCHED_FIFO
    printf("\nChanging to SCHED_FIFO...\n");
    if(sched_setscheduler(pid, SCHED_FIFO, &param) == -1){
      printf("Failed to set SCHED_FIFO: %s\n", strerror(errno));
      printf("(Requires root privileges)\n");
    }else{
      printf("Successfully changed to SCHED_FIFO with priority %d\n", param.sched_priority);

      // Verifying the change
      current_policy = sched_getscheduler(pid);
        printf("New policy is ");
      print_policy(current_policy);
    }
    
    return 0;
}

/*
==========================================================================
Output : 
--> in Linux
          prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss$ vim change_scheduling.c
          prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss$ cc change_scheduling.c
          prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss$ sudo ./a.out
          Current scheduling policy = Normal time-sharing scheduling

          Changing to SCHED_FIFO...
          Successfully changed to SCHED_FIFO with priority 10
          New policy is FIFO scheduling
==========================================================================
*/