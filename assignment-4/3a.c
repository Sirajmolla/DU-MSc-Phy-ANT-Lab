// problem 3a
// make sure "arithmetic.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"arithmetic.c"

int main()
{
    int i,n=2;	// no of equations
    //Declare a matrix to store the user given matrix
    double a[2][3]={
                        {58.9,0.03,59.2},
                        {-6.10,5.31,47.0}
                    };
    //Declare an array to store the solution of equations
    double x[n];
    printf("The augmented matrix for part a:\n");
    printmat(n,a);  // augmented matrix
    printf("\n(i) Gauss Elimination with three digit chopping:\n");
    gausschopping(n,a,x);   // for three digit chopping
    printf("\n\n");
    printf("(ii) Gauss Elimination with three digit rounding:\n");
    gaussround(n,a,x);   // for three digit rounding
    printf("\n\n");
    printf("(iii) Gauss Elimination with partial pivoting:\n");
    gausspivot(n,a,x);   // for partial pivoting
}