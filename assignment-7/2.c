#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j,N=10000;
    double rn[N];
    srand(time(0));
    for(i=0;i<N;++i) {
        rn[i]=((double)rand()/RAND_MAX);
    }
    //frequncy distribution within bin width
    double h=0.001; //width of interval
    int bin=1000;   //100 intervals of width 0.001
    int freq[bin]; 
    for(j=0;j<bin;++j) {
        freq[j]=0;
        for(i=0;i<N;i++) {
            //frequncy of RN within bin width
            if((rn[i]>=j*h)&&(rn[i]<(j+1)*h)) {
                freq[j]++;
            }   
        }
    }
    // stroing frequncy distribution
    FILE*fp=NULL;
    fp=fopen("2c1.txt","w");
    for(j=0;j<bin;++j) {
        fprintf(fp,"%lf\t%d\n",j*h,freq[j]);
    }
    //Correlation Checks
    FILE*fp1=NULL;
    fp1=fopen("2c2.txt","w");
    for(i=0;i<N-2;++i) {
        fprintf(fp1,"%lf\t%lf\t%lf\n",rn[i],rn[i+1],rn[i+2]);  
    }
}