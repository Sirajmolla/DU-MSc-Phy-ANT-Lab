// problem 1 and 2
// make sure "csplines.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"csplines.c"

// main program to do our job
int main()
{
	double X;
	double x[]={0,1,2,3};
	double y[]={exp(0),exp(1),exp(2),exp(3)};
	FILE*fp=NULL;
	fp=fopen("csp.txt","w");
	for (X=0;X<=3;X+=0.01)
	{
		fprintf(fp,"%lf\t%lf\t%lf\t%lf\n",X,lagrange(4,x,y,X),csplines(4,x,y,X),exp(X));
	}
}