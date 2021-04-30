#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j,N=10000;
    double r[N],y[N];
    double a=0,b=10;
    srand(time(0));
    for(i=0;i<N;++i) {
        r[i]=((double)rand()/RAND_MAX);
        y[i]=(b-a)*r[i]+a;
    }
    //frequncy distribution within bin width
    double h1=0.01; //bin width for [0:1]
    int bin1=100;   //100 intervals of width 0.01
    int rf[bin1]; 
    for(j=0;j<bin1;++j) {
        rf[j]=0;
        for(i=0;i<N;i++) {
            //frequncy of RN within bin width
            if((r[i]>=j*h1)&&(r[i]<(j+1)*h1)) {
                rf[j]++;
            }   
        }
    }
    // stroing frequncy distribution
    FILE*fp=NULL;
    fp=fopen("1a.txt","w");
    for(j=0;j<bin1;++j) {
        fprintf(fp,"%lf\t%d\n",j*h1,rf[j]);
    }
    //frequncy distribution within bin width
    double h2=0.1; //width of interval
    int bin2=100; //100 intervals of width 0.1 in [0:10]
    int yf[bin2]; 
    for(j=0;j<bin2;++j) {
        yf[j]=0;
        for(i=0;i<N;i++) {
            //frequncy of RN within bin width
            if((y[i]>=j*h2)&&(y[i]<(j+1)*h2)) {
                yf[j]++;
            }   
        }
    }
    // stroing frequncy distribution
    FILE*fp2=NULL;
    fp2=fopen("test.txt","w");
    for(j=0;j<bin2;++j) {
        fprintf(fp2,"%lf\t%d\n",j*h2,yf[j]);
    }
}