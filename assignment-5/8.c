// problem 8
// make sure "csplines.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"csplines.c"
// main program to do our job
int main()
{
	double X;
	double x[]={-4.09091,-3.28283,-2.67677,-1.9697,-1.56566,-0.959596,-0.757576,-0.151515,0.151515,0.454545,1.26263,2.17172,3.08081,3.88889,4.59596,5};
	double y[]={-1,-0.999997,-0.999847,-0.994657,-0.973183,-0.825242,-0.715999,-0.169667,0.169667,0.479662,0.92584,0.997869,0.999987,1,1,1};
	FILE*fp=NULL;
	fp=fopen("8.txt","w");
	for (X=x[0];X<=x[15];X+=0.01)
	{
		fprintf(fp,"%lf\t%lf\t%lf\n",X,csplines(16,x,y,X),lagrange(16,x,y,X));
	}
}