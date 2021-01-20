// problem 6
// make sure "integral.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"integral.c"
#define pi 3.1415927

double f(double theta,double z){
    return cos(z*cos(theta))*pow(sin(theta),5);
}
double J2(double z){
    return pow(z,2)/(pow(2,3)*factorial(2))*simpson13(f,z,0,pi);
}

int main()
{
  float a=0,b=10;	// range of roots
  printf("USING BISECTION METHOD\n");
  bisection(J2,a,b);   // using bisection function
  printf("\nUSING SECANT METHOD\n");
  secant(J2,a,b);   // using secant function
}