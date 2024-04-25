#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/*

The difference in behavior between fork() and vfork() is due to how they 
handle the creation of the child process.

1) fork() :
creates a separate copy of the parent process.
This means that after the fork() call, both the parent and child processes are running independently.
The OS decides which process runs first based on its scheduling algorithm. 
Therefore, it's not guaranteed which process will run first, the parent or the child.


2) vfork() :
does not create a separate copy of the parent's address space. 
Instead, it suspends the parent process until the child process calls _exit() or exec(). 
This means that the child process runs in the address space of the parent. 
Since the parent is suspended until the child process completes, 
the child process will always run first in a vfork() scenario.


*/
using namespace std;

int main() {
    pid_t pid = vfork();
    if(pid<0){
        cout<<"Fork failed"<<endl;
        return 1;
    }else if(pid==0){//child process
        cout<<"Executing Child processs : ( Opening Brave Browser )"<<endl;
        sleep(2);
       execlp("brave","brave",NULL);
       return 0;
    }else{
        cout<<"Parent process waiting for child process completion"<<endl;
        wait(NULL);
        cout<<"Parent process finished"<<endl;
    }

    

    return 0;
}
