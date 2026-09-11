#include <stdio.h>

struct PCB

{

int pid;

char state[20];

int priority;

int program_counter;

};

int main()

{

struct PCB p = {101, "Ready", 1, 100};

printf("Process ID: %d\n", p.pid);

printf("Process State: %s\n", p.state);

printf("Priority: %d\n", p.priority);

printf("Program Counter: %d\n", p.program_counter);

return 0;

}
