// problem 1b
// make sure "linear.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"linear.c"

int main()
{
    int i,n=5;  // no of equations
    //Declare a matrix to store the user given matrix
    double a[5][6]={
                        {2,1,-1,1,-3,7},
                        {1,0,2,-1,1,2},
                        {0,-2,-1,1,-1,-5},
                        {3,1,-4,0,5,6},
                        {1,-1,-1,-1,1,3}
                    };
    //Declare an array to store the solution of equations
    double x[n];
    printf("The augmented matrix:\n");
    printmat(n,a);  // printing the augmented matrix
    gausselim(n,a,x);   // Perform Gauss Elimination 
}