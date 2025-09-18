/*
==========================================================================
Name : 30.c
Author : Prateek Kumar Yadav
Description : Write a program to run a script at a specific time using a Daemon process
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    if(pid < 0){
        perror("fork failed");
        exit(EXIT_FAILURE);
    }else if(pid > 0){
        printf("Parent: Child created with PID %d\n", pid);
        exit(EXIT_SUCCESS); 
        // parent exits intentionally
    }else{
        // setsid() transforms the child process from a regular process into a true daemon that can run independently in the background, checking time every 25 seconds without being affected by terminal operations
        if(setsid() < 0){
            perror("setsid failed");
            exit(EXIT_FAILURE);
        }
        printf("Child process is Running as a daemon with PID %d\n", getpid());
        while (1) {
            time_t cur_time = time(NULL);
            struct tm *t = localtime(&cur_time);
        // has set the time for 1:01 PM
            if (t->tm_hour == 13 && t->tm_min == 01) {
                printf("DAEMON PROCESS...\n");
                // flash the alert message onto the terminal
                system("sudo ./alert.sh");
                break;
            }
            // for every 25s it checks whether it's time to run
            sleep(25);
        }
    }
    return 0;
}

/*
==========================================================================
Output : 
            prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss/daemon$ chmod +x alert.sh
            prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss/daemon$ ./alert.sh
            hey there
            prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss/daemon$ cc daemon.c
            prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss/daemon$ ./a.out
            Parent: Child created with PID 3696
            Child process is Running as a daemon with PID 3696
            prateek@prateek-QEMU-Virtual-Machine:~/Desktop/ss/daemon$ DAEMON PROCESS...
            hey there
==========================================================================
*/