#include<stdio.h>
#include<math.h>

double x[]={1,2,3,4,5,6,7};
double y[]={4,5,8,16,30,38,70};
double sig[]={2,2,3,3,4,5,5};
double b=0.498;
int n=7;
// returning location of min value of array
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
double chisq(double a){
    double sum=0;
    int i;
    for(i=0;i<n;i++)
        sum=sum+pow((y[i]-a*exp(b*x[i]))/sig[i],2);
    return sum;
}

int main()
{
  double a,h=0.001;

  // for plotting X2 vs a
  FILE*fp=NULL;
  fp=fopen("fora.txt","w");
  for (a=1;a<3;a+=0.01) {
    //printf("%lf\t%lf\n",a,chisq(b));
    fprintf(fp,"%lf\t%lf\n",a,chisq(a));
  }
  int steps=0;
  // calculating the total steps
  for (a=1;a<2.5;a+=0.001)
    steps++;
  // for minimum X2
  double chi[steps],A[steps];
  int i=0;
  for (a=1;a<2.5;a+=h) {
    A[i]=a;
    chi[i]=chisq(a);
    //printf("%d\t%.3lf\t%.3lf\n",i,A[i],chi[i]);
    i++;
  }
  // index of min chi square value
  int index=point(steps,chi);
  printf("value of minimum chi square: %lf\n",chi[index]);
  printf("for min Chi square and given b= %.3lf value of a= %.3lf\n",b,A[index]);

  // for minimum X2+1
  for (int i=0;i<steps;++i) {
      if (fabs((chi[index]+1)-chi[i])<=0.01) {
          printf("for value of X2+1= %lf value of a= %.3lf\n",chi[i],A[i]);
      }
  }
  // for minimum X2+4
  for (int i=0;i<steps;++i) {
      if (fabs((chi[index]+4)-chi[i])<=0.015) {
          printf("for value of X2+4= %lf value of a= %.3lf\n",chi[i],A[i]);
      }
  }
  // for minimum X2+1
  for (int i=0;i<steps;++i) {
      if (fabs((chi[index]+9)-chi[i])<=0.025) {
          printf("for value of X2+9= %lf value of a= %.3lf\n",chi[i],A[i]);
      }
  }
}