#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;
    char message[] = "hello child! message from parent";
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("pipe creation failed");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } 
    else if (pid == 0) {  // Child process
        close(fd[1]);  // Close write end
        int bytesRead = read(fd[0], buffer, sizeof(buffer));
        if (bytesRead > 0) {
            printf("child process:\n");
            printf("received message: %s\n", buffer);
        } else {
            perror("read failed");
        }
        close(fd[0]);
    } 
    else {  // Parent process
        close(fd[0]);  // Close read end
        if (write(fd[1], message, strlen(message) + 1) == -1) {
            perror("write failed");
        } else {
            printf("parent process:\n");
            printf("message sent to child: %s\n", message);
        }
        close(fd[1]);
        wait(NULL);  // Wait for child to finish
    }

    return 0;
}
