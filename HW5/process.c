#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10


int main(int argc, char *argv[]) {
    char *input_pipe_file_name = argv[1];
    char *output_pipe_file_name = argv[2];
    setbuf(stdout, NULL);
    int child_pid;
    if ((child_pid = fork()) == -1) {
        return -1;
    }
    if (child_pid == 0) {
        char output_buffer[BUFFER_SIZE];
        ssize_t output_buffer_size;
        int input_fd = open(output_pipe_file_name, O_RDONLY);
        if (input_fd < 0) {
            exit(-1);
        }
        while (1) {
            output_buffer_size = read(input_fd, output_buffer, BUFFER_SIZE);
            if (output_buffer_size > 0) {
                write(STDOUT_FILENO, output_buffer, output_buffer_size);
            }
        }
    } else {
        char input_buffer[BUFFER_SIZE];
        ssize_t input_buffer_size;
        while (1) {
            input_buffer_size = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
            if (input_buffer_size > 0) {
                int output_fd = open(input_pipe_file_name, O_WRONLY|O_TRUNC);
                if (output_fd < 0) {
                    continue;
                }
                write(output_fd, input_buffer, input_buffer_size);
                close(output_fd);
            }
        }
    }
    return 0;
}
