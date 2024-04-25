#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void print_stat(const char *filename) {
    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    std::cout << "Statistics using stat for file '" << filename << "':\n";
    std::cout << "Size: " << file_stat.st_size << " bytes\n";
    std::cout << "Owner UID: " << file_stat.st_uid << "\n";
    std::cout << "Last access time: " << ctime(&file_stat.st_atime);
    std::cout << "Last modification time: " << ctime(&file_stat.st_mtime);
    std::cout << "Last status change time: " << ctime(&file_stat.st_ctime);
}

int main(int argc,char* argv[]) {
    const char *filename = argv[1];
    print_stat(filename);
    return 0;
}
