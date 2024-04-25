#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        cerr << "Fork failed" << endl;
        return 1;
    } else if (pid == 0) { // Child process
        cout << "Child process executing..." << endl;
        sleep(2); // Simulating some work in the child process
        cout << "Child process completed" << endl;
        return 0;
    } else { // Parent process
        cout << "Parent process waiting for child process to complete..." << endl;
        wait(NULL); // Wait for the child process to finish
        cout << "Parent process completed" << endl;
    }

    return 0;
}
