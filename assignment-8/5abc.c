#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// generating uniform random numbers b/w [0:1] N times
void rwalk(int N,double x[N],double y[N])
{
    int i,j;
    double u[N],h=1.0,k=1.0;
    // int c1=0,c2=0;
    x[0]=0.0;y[0]=0.0;
    for (int i=1;i<N;++i) {
        u[i]=((double)rand()/(double)RAND_MAX);
        printf("u[%d]:\t%lf\n",i+1,u[i]);
        if(u[i]<=0.25) {
            x[i]=x[i-1]-h;
            //printf("x[i]:%d\t%lf\n",i+1,x[i]);
            //c1++;
        }
        else if (u[i]>0.25 && u[i]<0.5) {
            x[i]=x[i-1]+h;
            //printf("x[i]:%d\t%lf\n",i+1,x[i]);
            //c1++;
        }
        else if(u[i]>0.5 && u[i]<0.75) {
            y[i]=y[i-1]+k;
            //printf("y[i]:%d\t%lf\n",i+1,y[i]);
            //c2++;
        }
        else if(u[i]>0.75 && u[i]<=1.0) {
            y[i]=y[i-1]-k;
            //printf("y[i]:%d\t%lf\n",i+1,y[i]);
            //c2++;
        }
        printf("%d\t%lf\t%lf\n",i+1,x[i],y[i]);

    }
    //printf("x:%d\ty:%d\n",c1,c2);
}
//calculating distance dN = x[N]-x[0]
double dN(int N,double x[N]) {
    return (x[N-1]-x[0]);
}

int main()
{
    int i,N=1000;
    double x[10000],h;
    srand(time(0));

    // part a
    h=1.0;
    FILE*fp=NULL;
    fp=fopen("4a.txt","w");
    uni(N,h,x);
    for(i=0;i<N;++i) {
        fprintf(fp,"%d\t%lf\n",i+1,x[i]);
    }
    printf("part a. The actual distance traveled:%.2f\n",dN(N,x));

    // // part b and c
    FILE*fp1=NULL;
    FILE*fp2=NULL;
    FILE*fp3=NULL;
    FILE*fp4=NULL;
    FILE*fp5=NULL;
    fp1=fopen("4ch.1.txt","w");
    fp2=fopen("4ch1.txt","w");
    fp3=fopen("4ch2.txt","w");
    fp4=fopen("4ch10.txt","w");
    fp5=fopen("4ch50.txt","w");
    for (N=10;N<=10000;++N)
    {
        uni(N,0.1,x);
        fprintf(fp1,"%d\t%lf\t%lf\n",N,dN(N,x),dN(N,x)*dN(N,x));
        uni(N,1.0,x);
        fprintf(fp2,"%d\t%lf\t%lf\n",N,dN(N,x),dN(N,x)*dN(N,x));
        uni(N,2.0,x);
        fprintf(fp3,"%d\t%lf\t%lf\n",N,dN(N,x),dN(N,x)*dN(N,x));
        uni(N,10.0,x);
        fprintf(fp4,"%d\t%lf\t%lf\n",N,dN(N,x),dN(N,x)*dN(N,x));
        uni(N,50.0,x);
        fprintf(fp5,"%d\t%lf\t%lf\n",N,dN(N,x),dN(N,x)*dN(N,x));
    }
}