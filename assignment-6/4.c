#include<stdio.h>
#include<math.h>
double average(int i,int j,int k,double x[k])
{int l;double sum=0,X;
    for(l=0;l<k;l++)
    {
        sum+=pow(x[l],i+j);
    }
    X=sum/k;
    return X;
}
double average1(int i,int k,double x[k],double y[k])
{int l;double sum=0,X;
    for(l=0;l<k;l++)
    {
        sum=sum+(pow(x[l],i)*y[l]);
    }
    X=sum/k;
    return X;
}

void gausspivot(int n,double A[n][n+1],double x[]){
    int i,j,k;
    for(i=0;i<n-1;i++){
        //Partial Pivoting
        for(k=i+1;k<n;k++){
            //If the diagonal element is less than the terms below it
            if(fabs(A[i][i])<fabs(A[k][i])){
                //Swap the rows in the matrix
                for(j=0;j<=n;j++){                
                    double temp;
                    temp=A[i][j];
                    A[i][j]=A[k][j];
                    A[k][j]=temp;
                }
            }
        }
        //Begin the Gauss Elimination
        for(k=i+1;k<n;k++)
        {
            double term;
            term=A[k][i]/A[i][i];
            for(j=0;j<=n;j++){
                A[k][j]=A[k][j]-term*A[i][j];
            }
        }        
    }
    //Start with the back-substitution
    for(i=n-1;i>=0;i--){
        x[i]=A[i][n];
        for(j=i+1;j<n;j++){
            x[i]=x[i]-A[i][j]*x[j];
        }
        x[i]=x[i]/A[i][i];
    }       
}
int main()
{
    int N=19;   // no of datapoints
    int n=8; // order of matrix
    int i,j,k;
    double x[19]={0,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09,0.1,0.11,0.12,0.13,0.14,0.15,0.16,0.17,0.18};
    double y[19]={0.2,0.231895,0.264668,0.289191,0.332345,0.368007,0.403062,0.43739,0.472877,0.508413,0.543893,0.579221,0.614274,0.648984,0.683257,0.717008,0.717008,0.782653,0.814414};
    double A[n][n+1];
    // part A of augmented matrix [A:b] 
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            A[i][j]=average(i,j,N,x);
        }
    }
    // part b of augmented matrix [A:b]
    for(i=0;i<n;i++) {
        A[i][n]=average1(i,N,x,y);
    }
    double a[n],yf[N]; //yf[N] is fitted values
    // finding the coefficients
    gausspivot(n,A,a);
    printf("The coefficients for order [%d] are:\n",n-1);
    for(i=0;i<n;i++){
        printf(" a[%d]= %.3lf\n",i,a[i]);
    } 

    FILE*fp=NULL;
    fp=fopen("2.txt","w");
    // defining the polynomial
    k=0;
    while(k<N)
    {   
        double sum=0;
        for (i=0;i<n;++i) {
            sum += a[i]*pow(x[k],i);
        }
        yf[k]=sum;
        fprintf(fp,"%.3lf\t%lf\n",x[k],yf[k]);
        k++;
    }
    // calculating the chi square
    double chi=0;
    for (i=0;i<N;++i)
        chi += (yf[i]-y[i])*(yf[i]-y[i]);
    printf("Chi square for order [%d]:%lf\n",n-1,chi);
}