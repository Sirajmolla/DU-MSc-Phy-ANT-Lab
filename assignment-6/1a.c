// case I : no error or all sigma[i] are zeros
#include<stdio.h>
#include<math.h>

int main()
{
    int i,n=10; // no of points
    double x[]={1,2,3,4,5,6,7,8,9,10};
    double y[]={2.8,3.6,2.8,3.5,4.2,5.1,6.6,8.6,10.8,14.2};

    FILE*fp=NULL;
    fp=fopen("1a.txt","w");
    // summing
    double X=0,Y=0,XY=0,X2=0;
    for(i=0;i<n;i++)
    {
        X  += x[i];
        X2 += x[i]*x[i];
        Y  += y[i];
        XY += x[i]*y[i];
    }
    // expected values
    X  /= n;
    X2 /= n;
    Y  /= n;
    XY /= n;

    double a0,a1;   // unknowns to find
    a0=(Y*X2-X*XY)/(X2-X*X);
    a1=(XY-X*Y)/(X2-X*X);
    printf("The coefficients a0=%lf\ta1=%lf\n",a0,a1);
    // calculating the fitted points
    for (i=0;i<n;i++){ 
        y[i]=a0+a1*x[i];
        fprintf(fp,"%lf\t%lf\n",x[i],y[i]);
    }
}