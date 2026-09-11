#include <stdio.h>

#include <unistd.h>

int main()

{

int fd[2];

char message[] = "Hello Child";

char buffer[20];

pipe(fd);

if (fork() > 0)

{

// Parent

printf("Parent is sending: %s\n", message);

write(fd[1], message, sizeof(message));

}

else

{

// Child

read(fd[0], buffer, sizeof(buffer));

printf("Child received: %s\n", buffer);

}


return 0;
}
