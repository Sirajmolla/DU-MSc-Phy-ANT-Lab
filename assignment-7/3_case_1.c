#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j,N=10000,max=10;
    double M[N];
    //srand(time(0));
    for(i=0;i<N;++i) {
        M[i]=((double)rand()/RAND_MAX)*max;
    }
    //frequncy distribution within bin width
    double h=0.1; //width of interval
    int bin=10*max; //10 intervals of width 0.1 in [0:1]
    int freq[bin]; 
    for(j=0;j<bin;++j) {
        freq[j]=0;
        for(i=0;i<N;i++) {
            //frequncy of RN within bin width
            if((M[i]>=j*h)&&(M[i]<(j+1)*h)) {
                freq[j]++;
            }   
        }
    }
    // stroing frequncy distribution
    FILE*fp=NULL;
    fp=fopen("3c1a.txt","w");
    for(j=0;j<bin;++j) {
        fprintf(fp,"%lf\t%d\n",j*h,freq[j]);
    }
    //Correlation Checks
    FILE*fp1=NULL;
    fp1=fopen("3c1b.txt","w");
    for(i=0;i<N-2;++i) {
        fprintf(fp1,"%lf\t%lf\t%lf\n",M[i],M[i+1],M[i+2]);  
    }
}