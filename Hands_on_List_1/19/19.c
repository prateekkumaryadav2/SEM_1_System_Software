/*
==========================================================================
Name : 19.c
Author : Prateek Kumar Yadav
Description : Write a program to find out time taken to execute getpid 
              system call. Use time stamp counter
Date: 2nd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

/*
==========================================================================
rdtsc is supported by x86/x64 architecture assembly instructions,
clock_gettime() is equivalent operator on ARM architecture instead of TSC
==========================================================================
*/

int main() {
    struct timespec start, end;
    pid_t pid;
    long long elapsed_ns;
    
    // starting the count
    clock_gettime(CLOCK_MONOTONIC, &start);
    pid = getpid();
    // stopping the count
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    // long long to ensure proper arithmetic with large numbers, forcing to use 64 bit multiplication
    long long time_in_ns = (end.tv_sec - start.tv_sec) * (long long)1000000000 + (end.tv_nsec - start.tv_nsec);
    
    printf("Process ID of this process is %d\n", pid);
    printf("For getting 'getpid()' of this process takes %lld nanoseconds\n", time_in_ns);

    return 0;
}
/*
==========================================================================
Output : 
          prateek@Prateek-Kumar 19 % cc 19.c
          prateek@Prateek-Kumar 19 % ./a.out
          Process ID of this process is 3487
          For getting 'getpid()' of this process takes 0 nanoseconds
==========================================================================
*/