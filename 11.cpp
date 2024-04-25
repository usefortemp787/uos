#include<iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
using namespace std;

void alarmHandler(int val){
    cout<<"Alarm Clock triggered"<<endl;
    cout<<val<<endl;
}

int main(){
    signal(SIGALRM,alarmHandler);
    cout<<"Setting alarm clock for 5 seconds"<<endl;
    alarm(5);//alarm will get in 5 seconds
    pause();
    cout<<"Exiting program"<<endl;
    return 0;
}
