#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid = fork();
    if(pid<0){
        cout<<"Fork failed"<<endl;
        return 1;
    }else if(pid==0){//child process
        cout<<"Executing Child processs : ( Opening Brave Browser )"<<endl;
        sleep(2);
       execlp("brave","brave");
       return 0;
    }else{
        cout<<"Parent process waiting for child process completion"<<endl;
        wait(NULL);
        cout<<"Parent process finished"<<endl;
    }

    

    return 0;
}
