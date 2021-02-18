// problem 4
// make sure "csplines.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"csplines.c"
// main program to do our job
int main()
{
    double X,F0=1,F1=exp(3); // clamped conditions
    double x[]={0,1,2,3};
    double y[]={exp(0),exp(1),exp(2),exp(3)};
    FILE*fp=NULL;
    fp=fopen("clamp.txt","w");
    for (X=0;X<3;X+=0.01)
    {
        fprintf(fp,"%lf\t%lf\t%lf\n",X,clamped(4,x,y,F0,F1,X),exp(X));
    }
}