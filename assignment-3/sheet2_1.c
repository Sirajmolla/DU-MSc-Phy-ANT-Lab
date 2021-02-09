// sheet 2 problem 1
// make sure "interpolation.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"interpolation.c"
#define pi 3.141592

int main()
{
	int i,n=3;
 	double x[]={1,1.25,1.6};
 	double y[n],X=1.4;

 	printf("[Part a] f(x)=sin(pi*x)\n");
 	for(i=0;i<n;i++)
 	{
 		y[i]=sin(pi*x[i]);
 	}
 	printf("\nP2(x)=%f\n",lag(n,x,y,X));
 	printf("with error:%f\n",fabs(lag(n,x,y,X)-sin(pi*X)));

 	printf("\n[Part b] f(x)=pow(x-1,0.3333)\n");
 	for(i=0;i<n;i++) 
 	{
 		y[i]=pow(x[i]-1,0.3333);
 	}

 	printf("\nP2(x)=%f\n",lag(n,x,y,X));
 	printf("with error:%f\n",fabs(lag(n,x,y,X)-pow(X-1,0.3333)));
 	
 	printf("\n[Part c] f(x)=log10(3*x-1)\n");
 	for(i=0;i<n;i++)
 	{
 		y[i]=log10(3*x[i]-1);
 	}
 	printf("\nP2(x)=%f\n",lag(n,x,y,X));
 	printf("with error:%f\n",fabs(lag(n,x,y,X)-log10(3*X-1)));

 	printf("[Part d] f(x)=exp(2*x)-x\n");
 	for(i=0;i<n;i++)
 	{
 	y[i]=exp(2*x[i])-x[i];
 	}

 	printf("\nP2(x)=%f\n",lag(n,x,y,X)); 
 	printf("with error:%f\n",fabs(lag(n,x,y,X)-(exp(2*X)-X)));
} 