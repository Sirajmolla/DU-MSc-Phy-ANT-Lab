#include<stdio.h>
#include<math.h>

double x[]={1,2,3,4,5,6,7};
double y[]={4,5,8,16,30,38,70};
double sig[]={2,2,3,3,4,5,5};
double a=2.101;
int n=7;
// returning location of min value of an array
int point(int size,double array[])
{
  int index=0,i;
  double n;
  if (size!=1) {
    n=array[0];
    for (i=1;i<size;i++) {
        if (array[i]<n) {
            n=array[i];
            index=i;
        }
    }
  }
  return index;
}
// returning Chi square (X2) value
double chisq(double b){
    double sum=0;
    int i;
    for(i=0;i<n;i++)
        sum=sum+pow((y[i]-a*exp(b*x[i]))/sig[i],2);
    return sum;
}

int main()
{
  double b,h=0.0001;   //earlier h=0.001

  // for plotting X2 vs b
  FILE*fp=NULL;
  fp=fopen("forb.txt","w");
  for (b=0;b<0.6;b+=0.01) {
    //printf("%lf\t%lf\n",b,chisq(b));
    fprintf(fp,"%lf\t%lf\n",b,chisq(b));
  }
  int steps=0;
  // calculating the total steps
  for (b=0.45;b<0.55;b+=h)
    steps++;
  // for minimum X2
  double chi[steps],B[steps];
  int i=0;
  for (b=0.45;b<0.55;b+=h) {
    B[i]=b;
    chi[i]=chisq(b);
    //printf("%d\t%.4lf\t%lf\n",i,B[i],chi[i]);
    i++;
  }
  // index of min chi square value
  int index=point(steps,chi);
  printf("value of minimum chi square: %lf\n",chi[index]);
  printf("for min Chi square and given a= %.3lf value of b= %.3lf\n",a,B[index]);

  // for minimum X2+1
  for (int i=0;i<steps;++i) {
      if (fabs((chi[index]+1)-chi[i])<=0.011) {
          printf("for value of X2+1= %lf value of b= %.4lf\n",chi[i],B[i]);
      }
  }
  // for minimum X2+4
  for (int i=0;i<steps;++i) {
      if (fabs((chi[index]+4)-chi[i])<=0.01) {
          printf("for value of X2+4= %lf value of b= %.4lf\n",chi[i],B[i]);
      }
  }
  // for minimum X2+1
  for (int i=0;i<steps;++i) {
      if (fabs((chi[index]+9)-chi[i])<=0.03) {
          printf("for value of X2+9= %lf value of b= %.4lf\n",chi[i],B[i]);
      }
  }
}