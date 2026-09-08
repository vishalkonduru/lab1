#include <stdio.h> 
int main() { 
int a, b, max; 
printf("Enter two numbers: "); 
scanf("%d %d", &a, &b); 
if (a > b) 
max = a; 
else 
max = b; 
printf("Maximum is: %d\n", max); 
return 0; 
} 