// sheet 2 problem 4
// make sure "interpolation.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"interpolation.c"

int main()
{
    int i,n=3;
    double X=0,root[10];
    // initialing array for given table
    double x[]={0.3,0.4,0.5,0.6};
    double ex[]={0.740818,0.670320,0.606531,0.548812};
    for(i=0;i<=n;i++)
    {
        root[i]=x[i]-ex[i];
    }
    printf("The approx. soltion is: %f\n",nev(n,root,x,X));
}