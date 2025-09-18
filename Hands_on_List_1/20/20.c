/*
==========================================================================
Name : 20.c
Author : Prateek Kumar Yadav
Description : Find out the priority of your running program. 
              Modify the priority with nice command
Date: 2nd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
  pid_t pid = getpid();
  int current_priority, new_priority;
  
  // Reset errno before getpriority call
  errno = 0;  
  // errno helps to distinguis between -1 priority and -1 for error
  // if error occurs then only eerno gets changed
  current_priority = getpriority(PRIO_PROCESS, pid);
  if (errno != 0) {
    perror("getpriority");
    return 1;
  }
  
  printf("Current priority of this process is %d (nice value)\n", current_priority);
  
  // increasing priority by 2
  nice(2);
  printf("Priority increased by 2\n");
  new_priority = getpriority(PRIO_PROCESS, pid);
  
  // Reset errno before getpriority call
  errno = 0;
  // distinguising -1 priority from error -1
  if (new_priority == -1 && errno != 0) {
    perror("nice");
    return 1;
  }
  
  printf("New priority of this process is %d (nice value)\n", new_priority);
  return 0;
}

/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 20 % cc 20.c
          prateek@Prateek-Kumar 20 % ./a.out
          Current priority of this process is 0 (nice value)
          Priority increased by 2
          New priority of this process is 2 (nice value)
==========================================================================
*/