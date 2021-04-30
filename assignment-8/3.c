#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// generating random numbers b/w range
float randnum(float min, float max) {
    float random = ((float)rand())/(float)RAND_MAX;
    return (max-min)*random + min;
}
// defining the probability density function
float f(float x) {
    return (3/8.0)*(1+x*x);
}
int main()
{
    int i,j,N=100000;
    float x[N],y[N];
    float fmax=3/4.0;
    srand(time(0));
    for(i=0;i<N;++i) {
        x[i]=randnum(-1,1);
        y[i]=randnum(0,fmax);
    }
    int Naccept=0;
    float X[N],Y[N];
    for(i=0;i<N;i++) { 
        if(y[i]<=f(x[i])) {
            X[i]=x[i];
            Y[i]=y[i];
            Naccept++;
        }
    }
    //printf("%d\n",Naccept);
    FILE*fp=NULL;
    fp=fopen("3a.txt","w");
    for(i=0;i<Naccept;++i) {
        fprintf(fp,"%f\t%f\n",X[i],Y[i]);
    }
}