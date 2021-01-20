// problem 4
// make sure "integral.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"integral.c"
#define pi 3.1415927

// function to be intgrated ftx(t,x)
double ftx(double t,double x){
    return cos(pow(x,1.5)*cos(t))*pow(sin(t),3);
}
// function which root is needed Fx(x)
double Fx(double x){
    return simpson13(ftx,x,0,pi);
}
// main program to do neccessary job
int main()
{
	float a=0,b=5; // range of roots
	printf("USING BISECTION METHOD\n");
  	bisection(Fx,a,b);   // using bisection function
  	printf("\nUSING SECANT METHOD\n");
	secant(Fx,a,b);   // using secant function
}