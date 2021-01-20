// NIRMAL SINGH-19026762040
// ANT LAB ASSIGNMENT 01 PROBLEM 02
// make sure file matops.c is in same directory
#include<stdio.h>
#include<math.h>
#include"matops.c"
// function to generate the matrices
void input_matrix(int n,double A[10][10],double B[10][10])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            A[i][j]=(double)i/(double)(i+j);
            B[i][j]=(double)j/(double)(i+j);
        }
    }  
}
// main program to calculate the commutator
int main()
{
    int n=4;
    double a[10][10],b[10][10],ab[10][10],ba[10][10],com[10][10];
    input_matrix(n,a,b);

    printf("printing the matrix a:\n");
    print_matrix(n,a);
    printf("\nprinting the matrix b:\n");
    print_matrix(n,b);

    product_matrix(n,a,b,ab);   //commutator 1st term
    product_matrix(n,b,a,ba);   //commutator 2nd term
    subtraction_matrix(n,ab,ba,com);
    printf("\ncommutator c=[a,b]=ab-ba:\n");
    print_matrix(n,com);
}
/*
OUTPUT:
printing the matrix a:
0.50    0.33    0.25    0.20
0.67    0.50    0.40    0.33
0.75    0.60    0.50    0.43
0.80    0.67    0.57    0.50

printing the matrix b:
0.50    0.67    0.75    0.80
0.33    0.50    0.60    0.67
0.25    0.40    0.50    0.57
0.20    0.33    0.43    0.50

commutator c=[a,b]=ab-ba:
-1.43   -0.82   -0.44   -0.18
-0.82   -0.20   0.18    0.44
-0.44   0.18    0.56    0.82
-0.18   0.44    0.82    1.08

real    0m0.004s
user    0m0.003s
sys     0m0.000s
*/