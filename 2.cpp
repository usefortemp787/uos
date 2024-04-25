#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid = vfork();

    if (pid == -1) {
        cerr << "Error in vfork" << endl;
        return 1;
    }

    if (pid == 0) {  // Child process
        cout << "Enter your username: ";
        string username;
        cin >> username;
        _exit(0);  // Terminate the child process
    } else {  // Parent process
        wait(NULL);  // Wait for the child process to finish
        cout << "Enter your password: ";
        string password;
        cin >> password;
        cout << "Login successful!" << endl;
    }

    return 0;
}
