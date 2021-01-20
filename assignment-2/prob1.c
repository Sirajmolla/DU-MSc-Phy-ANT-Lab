// problem 1
// make sure "integral.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"integral.c"

// defining the function to evaluate
double fx(double x)
{
    return atan(x)/(x*x);
}
int main()
{   
    float a=5,b=10,tra,sim;
    tra=trap(fx,a,b);   // using trapezoidal function
    printf("The integral using trapezoidal Rule is: %lf\n",tra);
    sim=simp13(fx,a,b);   // using simpsons 1/3 function
    printf("The integral using Simpson's Rule is: %lf\n",sim);
}