#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pipe1[2];   // Parent -> Child
    int pipe2[2];   // Child -> Parent
    pid_t pid;

    char parent_msg[] = "Hello Child!";
    char child_msg[] = "Hello Parent!";
    char buffer[100];

    // Create two pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1)
    {
        perror("pipe");
        return 1;
    }

    // Create child process
    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
    {
        // ================= PARENT PROCESS =================

        close(pipe1[0]);   // Parent doesn't read from pipe1
        close(pipe2[1]);   // Parent doesn't write to pipe2

        // Send message to child
        write(pipe1[1], parent_msg, strlen(parent_msg) + 1);
        printf("Parent sent: %s\n", parent_msg);

        // Read response from child
        read(pipe2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);

        // Close remaining ends
        close(pipe1[1]);
        close(pipe2[0]);

        wait(NULL);
    }
    else
    {
        // ================= CHILD PROCESS =================

        close(pipe1[1]);   // Child doesn't write to pipe1
        close(pipe2[0]);   // Child doesn't read from pipe2

        // Read message from parent
        read(pipe1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        // Send response to parent
        write(pipe2[1], child_msg, strlen(child_msg) + 1);
        printf("Child sent: %s\n", child_msg);

        // Close remaining ends
        close(pipe1[0]);
        close(pipe2[1]);
    }

    return 0;
}
