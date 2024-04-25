#include<bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

void work(int i){
    if(i==1){
        cout<<"Child 1"<<endl;
    }else if(i==2)cout<<"Child 2"<<endl;
    else if(i==3)cout<<"Child 3"<<endl;
    else if(i==4)cout<<"Child 4"<<endl;
    else cout<<"Child 5"<<endl;
}

int main(){


    pid_t child_id;
    for(int i=1;i<=5;i++){
        child_id = fork();
        if(child_id==0){
            work(i);
            return 0;
        }else if(child_id<0){
            cout<<"Fork Failed"<<endl;
            return 1;
        }
    }

    for(int i=1;i<=5;i++){
        cout<<wait(NULL)<<" ";
    }
    return 0;
    
}