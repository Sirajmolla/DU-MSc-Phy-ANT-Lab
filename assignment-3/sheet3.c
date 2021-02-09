// sheet 3 problem 1 & 2
// make sure "interpolation.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"interpolation.c"

int main()
{
    int i;
    double x;
    FILE*fp=NULL;
    FILE*fp1=NULL;
    fp=fopen("sheet3lag.txt","w");   // using lagrange
    fp1=fopen("sheet3nev.txt","w");  // using neville
    // initialing array for given table
    double X[]={1,4,5,10};
    double Y[]={1,0.25,0.2,0.1};
    // getting data to plot the function
    for (x=0.5;x<=10;x+=0.1)
    {
        fprintf(fp,"%lf\t%lf\t%lf\t%lf\t%lf\n",x,lag(2,X,Y,x),lag(3,X,Y,x),lag(4,X,Y,x),1/x);
        fprintf(fp1,"%lf\t%lf\t%lf\t%lf\t%lf\n",x,nev(2,X,Y,x),nev(3,X,Y,x),nev(4,X,Y,x),1/x);
    }
}