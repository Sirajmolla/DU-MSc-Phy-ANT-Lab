#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j,N=100000;
    double r[N],x[N];
    double a=0,b=10;
    srand(time(0));
    for(i=0;i<N;++i) {
        r[i]=((double)rand()/RAND_MAX);
        x[i]=-log(1-r[i]);
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
    fp=fopen("2a.txt","w");
    for(j=0;j<bin1;++j) {
        fprintf(fp,"%lf\t%d\n",j*h1,rf[j]);
    }
    //frequncy distribution within bin width
    double h2=0.01; //width of interval
    int bin2=100*6; //100 intervals of width 0.1 in [0:10]
    int xf[bin2]; 
    for(j=0;j<bin2;++j) {
        xf[j]=0;
        for(i=0;i<N;i++) {
            //frequncy of RN within bin width
            if((x[i]>=j*h2)&&(x[i]<(j+1)*h2)) {
                xf[j]++;
            }   
        }
    }
    // stroing frequncy distribution
    FILE*fp2=NULL;
    fp2=fopen("2b.txt","w");
    for(j=0;j<bin2;++j) {
        fprintf(fp2,"%lf\t%d\n",j*h2,xf[j]);
    }
}