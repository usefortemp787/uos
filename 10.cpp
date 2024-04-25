/*
When you pass 0 to the alarm function, it cancels any previously set alarm.
*/
#include<iostream>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;


void alarmHandler(int time){
    cout<<"Time's up! You did not enter a number within 5 seconds."<<endl;
    exit(1);
}

int main(){

    signal(SIGALRM,alarmHandler);
    cout<<"Enter the input value (Enter within 5 seconds): "<<endl;
    alarm(5);
    int num;
    cin>>num;
    alarm(0); //unsets all alarm after entering the inputs in between 5 seconds
    cout << "You entered: " << num << endl;
    return 0;
}