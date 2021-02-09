// sheet 2 problem 2
// make sure "interpolation.c" file is in the same directory
#include <stdio.h>
#include <math.h>
#include"interpolation.c"

int main()
{
	int i,n=4;
    double X=1.5,err1,err2;
	double x1[]={-2,-1,0,1,2};
	double x2[]={0,1,2,4,5};
    double a[n],b[n];
    for(i=0;i<n;i++)
    {
        a[i]=pow(3,x1[i]);
    }
    for(i=0;i<n;i++)
    {
        b[i]=pow(x2[i],0.5);
    }
	printf("Using Neville the approx. value for part (a): %lf and for part (b): %lf\n",nev(n,x1,a,X),nev(n,x2,b,X));
	// calculating the abs error
    err1=fabs(nev(n,x1,a,X)-pow(3,X));
    err2=fabs(nev(n,x2,b,X)-pow(X,0.5));
	printf("and the accuracy in part (a): %lf and in part (b): %lf\n",err1,err2);
}