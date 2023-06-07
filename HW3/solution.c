#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

long int factorial(long int number) {
    long int result = 1;
    for (int n = 1; n <= number; ++n) {
        result *= n;
    }
    return result;
}

long int fibonacci(long int number) {
    long int first = 0, second = 1;
    if (number == 0) {
        return first;
    }
    if (number == 1) {
        return second;
    }
    for (int i = 2; i <= number; ++i) {
        second = first + second;
        first = second - first;
    }        
    return second;
}

int main(int argc, char const* argv[]) {
    long int number;
    if (argc < 2) {
        printf("\033[91mNo number is specified\n\033[0m");
        return 0;
    }
    number = strtol(argv[1], NULL, 10);
    if (number < 0 || number > 20) {
        printf("\033[91mExpected a number from 0 to 20\n\033[0m");
        return 0;
    }

    pid_t child_pid = -2;
    int child_status;
    if ((child_pid = fork()) == -1) {
        printf("\033[91mForking error\n\033[0m");
        return -1;
    }
    if (child_pid == 0) {
        // We are in the child process.
        printf("\033[96m%ld! = %ld\n", number, factorial(number));

        // Mock pause.
        printf("\033[96m -- child mock pause begin --\n");
        sleep(2);
        printf("\033[96m -- child mock pause end   --\n");

        exit(0);
    } else {
        printf("\033[95mF(%ld) = %ld\n", number, fibonacci(number));
        printf("\033[95mWaiting for the child process...\n");
        wait(&child_status);
        printf("\033[95mChild exit status: %d\n", child_status);
        printf("\033[0m");
    }
    return 0;
}
