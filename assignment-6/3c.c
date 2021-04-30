#include<stdio.h>
#include<math.h>

double x[]={1,2,3,4,5,6,7};
double y[]={4,5,8,16,30,38,70};
double sig[]={2,2,3,3,4,5,5};
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
double chisq(double a,double b){
    double sum=0;
    int i;
    for(i=0;i<n;i++){
        sum=sum+pow((y[i]-a*exp(b*x[i]))/sig[i],2);
    }
    return sum;
}

int main()
{
  double a,b;
  int steps=0;
  for (a=1;a<3;a+=0.01) {
      for (b=0;b<0.6;b+=0.01) {
        steps++;
      }
  }

  // for plotting X2 vs b
  FILE*fp=NULL;
  fp=fopen("forab.txt","w");

  double A[steps],B[steps],chi[steps];
  int i=0;
  for (a=1;a<3;a+=0.01) {
      for (b=0;b<0.6;b+=0.01) {
        A[i]=a;
        B[i]=b;
        chi[i]=chisq(a,b); 
        //printf("%d\t%.3lf\t%.3lf\t%lf\n",i,A[i],B[i],chisq(a,b));
        fprintf(fp,"%.3lf\t%.3lf\t%lf\n",A[i],B[i],chisq(a,b));
        i++;
      }
  }
  // index of min chi square value
  int index=point(i,chi);
  printf("value of minimum chi square: %lf\n",chi[index]);
  printf("for min chi square, value of a= %.2lf\tb= %.2lf\n",A[index],B[index]);

  // for minimum X2+1
  for (int i=0;i<steps;++i) {
      if (fabs((chi[index]+1)-chi[i])<=0.009) {
          printf("for value of X2+1= %lf value a= %.2lf b= %.2lf\n",chi[i],A[i],B[i]);
      }
  } 
  // for minimum X2+4
  for (int i=0;i<steps;++i) {
      if (fabs((chi[index]+4)-chi[i])<=0.02) {
          printf("for value of X2+4= %lf value a= %.2lf b= %.2lf\n",chi[i],A[i],B[i]);
      }
  }
  // for minimum X2+9
  for (int i=0;i<steps;++i) {
      if (fabs((chi[index]+9)-chi[i])<=0.02) {
          printf("for value of X2+9= %lf value a= %.2lf b= %.2lf\n",chi[i],A[i],B[i]);
      }
  }
}