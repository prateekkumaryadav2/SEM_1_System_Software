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

/*
In Linux, the priority of a running program is determined by two main values: the nice value and the real-time priority. 

Checking the priority of a running program using

--> Using top
The top command provides a real-time, dynamic view of a system's running processes. In the output, you should look for two columns:

PR (Priority): This column displays the actual scheduling priority of the process. A lower number indicates a higher priority.

NI (Nice Value): This column shows the process's nice value. The nice value is a user-adjustable number that influences the priority.

The relationship between the nice value and the PR value for normal, non-real-time processes is typically PR = 20 + NI.

--> Using ps
The ps command provides a snapshot of the current processes. To view the priority and nice value, you can use the following command:

ps -o pid,ni,pr,comm

This command will output a list of processes with their Process ID (PID), Nice Value (NI), Priority (PR), and command name.
*/ 
// ==============================
/*
-->Nice Value
The nice value is a number that ranges from -20 to 19.

A nice value of -20 is the highest possible priority.

A nice value of 19 is the lowest priority.

The default nice value is 0.

A process with a lower nice value receives a larger time slice, meaning it gets more CPU time than processes with a higher nice value.

-->Real-time Priority
Linux also supports real-time scheduling priorities, which are separate from nice values. 

By default, real-time priority ranges from 0 to 99. 

A process with a real-time priority will always have a higher priority than any normal, non-real-time process, regardless of its nice value.
*/

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