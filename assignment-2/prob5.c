// problem 5
// make sure "integral.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"integral.c"
#define pi 3.1415927

// function to be intgrated fxz(x,z)
double fxz(double x,double z){
    return cos(z*cos(x));
}
// function which root is needed J0(z)
double J0(double z){
    return 1/(2*pi)*simpson13(fxz,z,0,2*pi);
}
// main program to do neccessary job
int main()
{
  float a=0,b=12;	// range of roots
  secant(J0,a,b);	// using secant function
}