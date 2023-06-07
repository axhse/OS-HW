#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILENAME_SIZE 14 + 3


void update_name(char *name, int index) {
    char temp_buffer[100];
    ssize_t num_size = sprintf(temp_buffer, "%d", index);
    sprintf(name + FILENAME_SIZE - num_size, "%d", index);
}

int main(int argc, char *argv[]) {
    char current_name[] = "/tmp/linktest/000";
    char new_name[] = "/tmp/linktest/000";
    mkdir("/tmp/linktest/", 0777);
    int initial_fd = open(current_name, O_CREAT, 0777);
    if (initial_fd < 0) {
        printf("File can not be created\n");
        return 0;
    }
    close(initial_fd);
    int depth = 0;
    while (1) {
        update_name(current_name, depth);
        update_name(new_name, depth + 1);
        if (symlink(current_name, new_name) < 0) {
            break;
        }
        printf("Created:  %s -> %s\n", new_name, current_name);
        int current_fd = open(current_name, O_RDONLY);
        if (current_fd == -1) {
            break;
        }
        printf("Opened :  %s\n", new_name);
        close(current_fd);
        ++depth;
    }
    printf("Link limit count:  %d\n", depth);
    return 0;
}
