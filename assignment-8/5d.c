#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int c,c1,c2;
double dx,dy,dr;
//calculating distance dN = x[N]-x[0]
double dN(int N,double arr[N]) {
    return (arr[N-1]-arr[0]);
}
// generating uniform random numbers b/w [0:1] N times
void rwalk(int N,double x[N],double y[N])
{
    int i,j=1,k=1;
    double u[N],h=0.1,K=0.1;
    c1=0,c2=0; // initial value count
    x[0]=0.0;y[0]=0.0;
    for (int i=0;i<N;++i) {
        u[i]=((double)rand()/(double)RAND_MAX);
        //printf("u[%d]:\t%lf\n",i,u[i]);
        if(u[i]<=0.25) {
            x[j]=x[j-1]-h;
            c1++;j++;
        }
        else if (u[i]>0.25 && u[i]<=0.5) {
            x[j]=x[j-1]+h;
            c1++;j++;
        }
        else if(u[i]>0.5 && u[i]<0.75) {
            y[k]=y[k-1]+K;
            c2++;k++;
        }
        else {
            y[k]=y[k-1]-K;
            c2++;k++;
        }
    }
    // rejecting extra value in either array
    if (c1>c2)
        c=c2;
    else
        c=c1;

    dx=dN(c,x);
    dy=dN(c,y);
    dr=sqrt(dx*dx+dy*dy);
}
// calculating mean of an array
double mean(int N,double arr[N]) {
    double sum=0;
    for (int i=0;i<N;++i)
        sum += arr[i];
    return sum/N;
}
// calculating dispersion relation of an array
double sigma(int N,double arr[N]) {
    double avg,std=0;
    avg=mean(N,arr);
    for (int i=0;i<N;++i)
        std += pow((arr[i]-avg),2);
    return sqrt(std/(N-1));
}
int main()
{
    int i,j,N=10000,n=100;
    double x[N],y[N];
    srand(time(0));

    FILE*fp=NULL;
    fp=fopen("5d1.txt","w");
    FILE*fp1=NULL;
    fp1=fopen("5d2.txt","w");
    double d1[N],d2[N],d3[N],d4[N],d5[N];
    double dxn[N],dyn[N],tot[N],drn[N],dr2n[N];
    double sig1[N],sig2[N];
    int k=0;
    for (i=10;i<N;i++) {
        for (j=0;j<n;j++) {
            rwalk(i,x,y);
            d1[j]=dx;
            d2[j]=dy;
            d3[j]=dx+dy;
            d4[j]=dr;
            d5[j]=d4[j]*d4[j];
        }
        dxn[k]=mean(n,d1);
        dyn[k]=mean(n,d2);
        tot[k]=mean(n,d3);
        drn[k]=mean(n,d4);
        dr2n[k]=mean(n,d5);
        sig1[k]=sigma(n,d4);
        sig2[k]=sigma(n,d5);
        fprintf(fp,"%d\t%.4lf\t%.4lf\t%.4lf\n",i,dxn[k],dyn[k],tot[k]);
        fprintf(fp1,"%d\t%lf\t%lf\t%lf\t%lf\t%lf\n",i,drn[k],sig1[k],dr2n[k],sig2[k],drn[k]*drn[k]);
        k++;
    }
}