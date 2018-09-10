
// A simple C program with format 
// string vulnerability 
#include<stdio.h> 
  
int main(int argc, char** argv) 
{ 
    char buffer[100]; 
    strncpy(buffer, argv[1], 100); 
  
    // We are passing command line 
    // argument to printf 
    printf(buffer); 
  
    return 0; 
} 
