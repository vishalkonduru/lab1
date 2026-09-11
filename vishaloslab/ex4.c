#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[100];

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Create child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(pipefd[0]);  // Close reading end

        write(pipefd[1], message, strlen(message) + 1);

        close(pipefd[1]); // Close writing end
    }
    else {
        // Child process
        close(pipefd[1]);  // Close writing end

        read(pipefd[0], buffer, sizeof(buffer));

        printf("Child received: %s\n", buffer);

        close(pipefd[0]);  // Close reading end
    }

    return 0;
}
