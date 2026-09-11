#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char command[50];

    while (1) {
        printf("mini-shell> ");
        scanf("%49s", command);

        if (strcmp(command, "exit") == 0)
            break;

        if (fork() == 0) {
            // Child process
            execlp(command, command, NULL);

            // Only reached if execlp fails
            perror("execlp");
            return 1;
        } else {
            // Parent process
            wait(NULL);
        }
    }

    return 0;
}
