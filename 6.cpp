#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid;

    // execl
    pid = fork();
    if (pid == 0) {
        execl("/bin/ls", "ls", "-l", NULL);
        perror("execl");
        _exit(1);
    }
    wait(NULL);

    // execv
    pid = fork();
    if (pid == 0) {
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);
        perror("execv");
        _exit(1);
    }
    wait(NULL);

    // execle
    pid = fork();
    if (pid == 0) {
        char *envp[] = {NULL};
        execle("/bin/ls", "ls", "-l", NULL, envp);
        perror("execle");
        _exit(1);
    }
    wait(NULL);

    // execve
    pid = fork();
    if (pid == 0) {
        char *args[] = {"ls", "-l", NULL};
        char *envp[] = {NULL};
        execve("/bin/ls", args, envp);
        perror("execve");
        _exit(1);
    }
    wait(NULL);

    // execlp
    pid = fork();
    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        _exit(1);
    }
    wait(NULL);

    // execvp
    pid = fork();
    if (pid == 0) {
        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);
        perror("execvp");
        _exit(1);
    }
    wait(NULL);

    return 0;
}






/*


Cleanup Actions: When you use exit, it not only terminates the process but also performs cleanup actions such as flushing I/O buffers and closing files. This behavior may not be desired in the context of exec calls where you want the process to terminate immediately without any additional actions.
Function Calls: exit will also invoke any functions registered with atexit or on_exit before terminating the process. If you want to bypass these registered functions, _exit should be used instead.
In general, when using exec calls, it's more common to use _exit to ensure that the child process terminates immediately and does not execute any additional code from the original program after the exec call.


*/