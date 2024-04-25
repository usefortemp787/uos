#include<iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

using namespace std;

int main(){
    cout << "Enter the file name : " << endl;
    char filename[256]; // Assume maximum filename length is 255 characters
    cin.getline(filename, sizeof(filename));

    pid_t pid;
    pid = fork();
    if(pid < 0){
        cout << "Fork failed" << endl;
        return 1;
    } else if(pid == 0){
        execlp("stat", "stat", filename, NULL);
        return 0;
    }
    wait(NULL);
    return 0;
}
