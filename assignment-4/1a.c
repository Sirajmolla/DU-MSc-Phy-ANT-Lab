// problem 1a
// make sure "linear.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"linear.c"

int main()
{
    int i,n=4;  // no of equations
    //Declare a matrix to store the user given matrix
    double a[4][5]={
                        {1,-1,2,-1,-8},
                        {2,-2,3,-3,-20},
                        {1,1,1,0,-2},
                        {1,-1,4,3,4}
                    };
    //Declare an array to store the solution of equations
    double x[n];
    printf("The augmented matrix:\n");
    printmat(n,a);  // printing the augmented matrix
    gausselim(n,a,x);   // Perform Gauss Elimination 
}