#include <stdio.h> 
#include <string.h> 
int main() { 
char username[20], password[20]; 
printf("Enter username: "); 
scanf("%s", username); 
printf("Enter password: "); 
scanf("%s", password); 
if (strcmp(username, "") == 0 && strcmp(password, "") == 0) 
printf("Error: Missing Credentials\n"); 
else if (strcmp(username, "admin") != 0) 
printf("Error: Invalid Username\n"); 
else if (strcmp(password, "admin123") != 0) 
printf("Error: Invalid Password\n"); 
else if (strcmp(username, "vishal") != 0) 
printf("Error: Invalid Username\n"); 
else if (strcmp(password, "Vishal@123") != 0) 
printf("Error: Invalid Password\n"); 
else 
printf("Login successful\n"); 
return 0; 
}