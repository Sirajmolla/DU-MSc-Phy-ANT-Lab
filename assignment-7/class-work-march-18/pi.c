#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
// generating random numbers b/w range
double randnum(double min, double max) {
    double random = ((double)rand())/(double)RAND_MAX;
    return (max-min)*random + min;
}
// calculating mean of an array
double mean(int N,double arr[N]) {
    double sum=0;
    for (int i=0;i<N;++i)
        sum += arr[i];
    return sum/N;
}
// calculating dispersion relation of an array
double dispersion(int N,double arr[N]) {
    double avg,std=0;
    avg=mean(N,arr);
    for (int i=0;i<N;++i)
        std += pow((arr[i]-avg),2);
    return sqrt(std/(N-1));
}
// adding the error from each expt
double std(int N,double arr[N]) {
    double sum=0;
    for(int i=0;i<N;++i)
        sum += (arr[i]*arr[i]);
    return sqrt(sum)/N;
}

void main()
{
    int i,j,n=1000;
    int M=10;   // repeating the expt. M times
    double x[n],y[n],z[n];
    double As=4,area[M],sigma[M];

    FILE*fp=NULL;
    fp=fopen("pi10.txt","w");
    srand(time(0));
    //calculating the area multiple times
    for (j=0;j<M;++j) {
        double Naccept=0;
        for (i=0;i<n;++i) {
            x[i]=randnum(-1,1);
            y[i]=randnum(-1,1);
            z[i]=pow(x[i],2)+pow(y[i],2);
            if (z[i]<=1){
                Naccept++;
            }
        }
        area[j]=As*Naccept/n;
        sigma[j]=sqrt(Naccept*(1-Naccept/n))*As/n;
        //printf("M[%d]\t%lf\t%lf\n",j+1,area[j],sigma[j]);
        fprintf(fp,"%d\t%lf\t%lf\n",j+1,area[j],sigma[j]);
    }
    //Correlation Checks
    FILE*fp1=NULL;
    fp1=fopen("xy.txt","w");
    for(i=0;i<n;++i) {
        fprintf(fp1,"%lf\t%lf\n",x[i],y[i]);  
    }
    printf("\nTotal performed expt:%d\n",M);
    printf("mean: %lf\tbinomial std deviation: %lf\n",mean(M,area),std(M,sigma));
    printf("dispersion in mean: %lf\n",dispersion(M,area));
}