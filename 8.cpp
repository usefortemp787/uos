/*

Here's a comparison of the `exit` and `kill` system calls in Linux in tabular format:

| Feature              | exit System Call                                                                                  | kill System Call                                    |
|----------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| Purpose              | Terminates the calling process and returns an exit status to the parent process.                  | Sends a signal to a specified process or group of processes. |
| Parameters           | Accepts an exit status code that is returned to the parent process.                               | Accepts a process ID (PID) or a process group ID (PGID) along with a signal number. |
| Signal Handling      | Does not affect signal handling; registered signal handlers are not called.                       | Sends the specified signal to the target process or process group, which may be caught and handled by a signal handler. |
| Impact on Parent     | Notifies the parent process of the termination and returns the exit status.                       |  Does not directly notify the parent process; the signal may be caught or ignored by the target process. |
| Cleanup Actions      | Performs standard cleanup actions, such as closing file descriptors and flushing buffers.         | Does not perform any cleanup actions; the target process must handle the signal appropriately. |
| Effect on Process    | Immediately terminates the process without giving it a chance to block or handle the termination. | Allows the target process to catch or ignore the signal, or take other actions in response to the signal. |
| Return Value         | Does not return a value; control is transferred to the parent process.                            | Returns 0 on success, or -1 if an error occurs (e.g., invalid PID or signal number). |



*/


#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;


void signalHandler(int signal){
    cout<<"Received Signal : "<<signal<<endl;
}

int main(){
    pid_t pid;
    pid = fork();

    if(pid<0){
        cout<<"Fork Failed"<<endl;
        return 1;
    }else if(pid==0){
        signal(SIGUSR1,signalHandler);
        cout<<"Child process is running"<<endl;
        cout<<"Child process is stuck in loop"<<endl;
        while (true)
        {
            sleep(2);
        }
    }else{
        cout<<"Parent process is waiting for child..."<<endl;
        sleep(5);
        cout<<"Sending signal to child process to terminate"<<endl;
        int res = kill(pid,SIGUSR1);
        if(res==0){
            cout<<"Signal successfully send to child"<<endl;
        }else {
            cout<<"Failed to send signal to child process"<<endl;
        }
    }
    return 0;

}