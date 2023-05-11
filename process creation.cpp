#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("Child process: pid=%d, parent pid=%d\n", getpid(), getppid());
    } else {
        printf("Parent process: pid=%d, child pid=%d\n", getpid(), pid);
    }
    return 0;
}
