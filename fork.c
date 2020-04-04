
#include <stdio.h> 
  
int main() 
{ 
    // Creating  child  one 
    int c1 = fork(); 
  
    /* Creating the second child but First child 
     also executes the line and  then creates 
     grandchild.*/ 
    int c2 = fork(); 
  
    if (c1 > 0 && c2 > 0) 
    { 
        printf("parent\n\n\t"); 
        printf("%d %d \t\n", c1, c2); 
        printf(" my id is %d \n\t", getpid()); 
        printf(" my parentid is %d \n\t", getppid()); 
    } 
    else if (c1 == 0 && c2 > 0) 
    { 
        printf("\nchild one \n\t"); 
        printf("%d %d \n\t", c1, c2); 
        printf("my id is %d  \n\t", getpid()); 
        printf(" my parentid is %d \n\t", getppid());
        printf("\n\n\n\t IAM THE GRANDCHILD OF my parent HENCE, MY PARENT ID IS SAME"); 
    } 
    else if (c1 > 0 && c2 == 0) 
    { 
        printf("\nchild two \n\t"); 
        printf("%d %d \n\t", c1, c2); 
        printf("\nmy id is %d  \n\t", getpid()); 
        printf(" \nmy parentid is %d \n\t", getppid());
        
    } 
    
    return 0; 
} 

