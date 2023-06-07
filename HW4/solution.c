#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 200


void make_copy(char *source_path, char *dest_path) {
    remove(dest_path);
    struct stat source_stat;
    int source_fd = open(source_path, O_RDONLY);
    if (source_fd < 0 || stat(source_path, &source_stat) == -1) {
        printf("\033[91mInput file is not accessible\n\033[0m");
        return;
    }
    int dest_fd = open(dest_path, O_WRONLY|O_CREAT, source_stat.st_mode);
    if (dest_fd < 0) {
        printf("\033[91mOutput file can not be created\n\033[0m");
        close(source_fd);
        return;
    }
    char buffer[BUFFER_SIZE];
    while (1) {
        ssize_t char_count = read(source_fd, buffer, BUFFER_SIZE);
        if (char_count == -1) {
            printf("\033[91mReading failed\n\033[0m");
            break;
        }
        if (char_count == 0) {
            printf("\033[96mCopy created\n\033[0m");
            break;
        }
        if (write(dest_fd, buffer, char_count) != char_count) {
            printf("\033[91mWriting failed\n\033[0m");
            break;
        }
    }
    close(source_fd);
    close(dest_fd);
}

int main(int argc, char *argv[]) {
    if (argc >= 3) {
        make_copy(argv[1], argv[2]);
    }
    return 0;
}
