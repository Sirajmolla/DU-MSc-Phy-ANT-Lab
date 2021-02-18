// problem 7
// make sure "csplines.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"csplines.c"
// main program to do our job
int main()
{
	double X;
	double x[21]= {0.9, 1.3, 1.9, 2.1, 2.6, 3.0, 3.9, 4.4, 4.7, 5.0, 6.0, 7.0, 8.0, 9.2, 10.5, 11.3, 11.6, 12.0, 12.6, 13.0, 13.3};
    double fx[21] = {1.3, 1.5, 1.85, 2.1, 2.6, 2.7, 2.4, 2.15, 2.05, 2.1, 2.25, 2.3, 2.25, 1.95, 1.4, 0.9, 0.7, 0.6, 0.5, 0.4, 0.25}; 
	FILE*fp=NULL;
	fp=fopen("7.txt","w");
	for (X=0.9;X<=13.3;X+=0.01)
	{
		fprintf(fp,"%lf\t%lf\t%lf\n",X,csplines(21,x,fx,X),lagrange(21,x,fx,X));
	}
}