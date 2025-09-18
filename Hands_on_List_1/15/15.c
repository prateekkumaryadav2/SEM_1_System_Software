/*
==========================================================================
Name : 15.c
Author : Prateek Kumar Yadav
Description : Write a program to display the environmental variable of the user (use environ).
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>

// gives access to the environment variable array.
extern char **environ;

int main() {
    char **env = environ;
    // The program loops through and prints each environment variable line by line.
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}
/*
printenv or env shell command
*/

/*
==========================================================================
Output : 
            prateek@Prateek-Kumar 15 % cc 15.c
            prateek@Prateek-Kumar 15 % ./a.out
            MallocNanoZone=0
            USER=prateek
            COMMAND_MODE=unix2003
            __CFBundleIdentifier=com.microsoft.VSCode
            PATH=/Library/Java/JavaVirtualMachines/jdk-21.jdk/Contents/Home/bin:/Library/Frameworks/Python.framework/Versions/3.13/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/opt/homebrew/bin:/Library/Java/JavaVirtualMachines/jdk-21.jdk/Contents/Home/bin:/Library/Frameworks/Python.framework/Versions/3.13/bin:/usr/local/mysql-9.3.0-macos15-arm64/bin:/Users/prateek/Library/Application Support/Code/User/globalStorage/github.copilot-chat/debugCommand:/usr/local/mysql-9.3.0-macos15-arm64/bin
            LOGNAME=prateek
            SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.r2k8v1TpAm/Listeners
            HOME=/Users/prateek
            SHELL=/bin/zsh
            TMPDIR=/var/folders/qp/7_hjk6tj0979fxcvwyzmmmq40000gn/T/
            __CF_USER_TEXT_ENCODING=0x1F5:0x0:0x0
            XPC_SERVICE_NAME=0
            XPC_FLAGS=0x0
            ORIGINAL_XDG_CURRENT_DESKTOP=undefined
            SHLVL=1
            PWD=/Users/prateek/Desktop/SEM 1/CSE 513-A : Systems Software/Hands_on_List_1/15
            OLDPWD=/Users/prateek/Desktop/SEM 1/CSE 513-A : Systems Software/Hands_on_List_1
            JAVA_HOME=/Library/Java/JavaVirtualMachines/jdk-21.jdk/Contents/Home
            TERM_PROGRAM=vscode
            TERM_PROGRAM_VERSION=1.103.2
            LANG=en_US.UTF-8
            COLORTERM=truecolor
            GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass.sh
            VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
            VSCODE_GIT_ASKPASS_EXTRA_ARGS=
            VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.js
            VSCODE_GIT_IPC_HANDLE=/var/folders/qp/7_hjk6tj0979fxcvwyzmmmq40000gn/T/vscode-git-f50117c524.sock
            VSCODE_INJECTION=1
            ZDOTDIR=/Users/prateek
            USER_ZDOTDIR=/Users/prateek
            TERM=xterm-256color
            VSCODE_PROFILE_INITIALIZED=1
            _=/Users/prateek/Desktop/SEM 1/CSE 513-A : Systems Software/Hands_on_List_1/15/./a.out
======================================================================
*/