/*
1. `WIFEXITED(status)` is a macro used to check if a child process terminated normally.
2. It takes the status value returned by the `wait` system call as an argument.
3. Returns true if the child process exited using the `exit` system call or returned from `main`.
4. You can use `WEXITSTATUS(status)` to extract the exit status of the child process when `WIFEXITED(status)` returns true.
5. If `WIFEXITED(status)` returns false, it means the child process did not terminate normally, possibly due to a signal.

*/

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main(){
    pid_t pid;
    pid = fork();

    if(pid<0){
        cout<<"Fork Failed"<<endl;
        return 1;
    }else if(pid==0){
        cout<<"Chid process is running "<<endl;
        sleep(2);
        _exit(50);
    }else{
        cout<<"Parent waiting for child "<<endl;
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            cout<<"Child exited with status : "<<WEXITSTATUS(status)<<endl;

        }else cerr << "Child process did not exit normally" << endl;
        cout<<"Parent Completed it's execution"<<endl;
    }
    return 0;
}