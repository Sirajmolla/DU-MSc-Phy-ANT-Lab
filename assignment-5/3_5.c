// problem 3 and 5
// make sure "csplines.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"csplines.c"
// natural cubic spline function
double f1(double X) {
	double x[4]={0,1,2,3};
	double y[4]={exp(0),exp(1),exp(2),exp(3)};
	return csplines(4,x,y,X);
}
// lagrange interpolated polynomial
double f2(double X) {
	double x[4]={0,1,2,3};
	double y[4]={exp(0),exp(1),exp(2),exp(3)};
	return lagrange(4,x,y,X);
}
// exact function to be integrated
double f3(double X) {
	return exp(X);
}
// clamped cubic spline function
double f4(double X) {
	double F0=1,F1=exp(3); // clamped conditions
    double x[4]={0,1,2,3};
    double y[4]={exp(0),exp(1),exp(2),exp(3)};
	return clamped(4,x,y,F0,F1,X);
}
// main program to do our job
int main()
{
	printf("Integrating the interpolant via simpsons 1/3 rule\n");

	printf("\nusing natural cubic spline: %lf\n",simpson(f1,0,3));
	printf("using lagrange polynomial: %lf\n",simpson(f2,0,3));
	printf("using exact function: %lf\n",simpson(f3,0,3));
	printf("using clamped cubic spline: %lf\n",simpson(f4,0,3));
}