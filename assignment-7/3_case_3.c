#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j,N=10000,max=1,sub=10;//subject
    double ai[N],bi[N],ci[N],di[N],ei[N],fi[N],gi[N],hi[N],ji[N],ki[N],M[N];
    //srand(time(0));
    for(i=0;i<N;++i) {
        ai[i]=((double)rand()/RAND_MAX)*max;
        bi[i]=((double)rand()/RAND_MAX)*max;
        ci[i]=((double)rand()/RAND_MAX)*max;
        di[i]=((double)rand()/RAND_MAX)*max;
        ei[i]=((double)rand()/RAND_MAX)*max;
        fi[i]=((double)rand()/RAND_MAX)*max;
        gi[i]=((double)rand()/RAND_MAX)*max;
        hi[i]=((double)rand()/RAND_MAX)*max;
        ji[i]=((double)rand()/RAND_MAX)*max;
        ki[i]=((double)rand()/RAND_MAX)*max;
        M[i]=ai[i]+bi[i]+ci[i]+di[i]+ei[i]+fi[i]+gi[i]+hi[i]+ji[i]+ki[i];
    }
    //frequncy distribution within bin width
    double h=0.1; //width of interval
    int bin=10*sub*max; //10 intervals of width 0.1 in [0:1]
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
    fp=fopen("3c3a.txt","w");
    for(j=0;j<bin;++j) {
        fprintf(fp,"%lf\t%d\n",j*h,freq[j]);
    }
    //Correlation Checks
    FILE*fp1=NULL;
    fp1=fopen("3c3b.txt","w");
    for(i=0;i<N-2;++i) {
        fprintf(fp1,"%lf\t%lf\t%lf\n",M[i],M[i+1],M[i+2]);  
    }
}