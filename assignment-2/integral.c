// it contains functions to evaluate the integration and roots
// (trapezidal,simson,bisection, secant)
// use #include"integral.c" in the program you wished to use this

//Function to perform factorial
double factorial(int n)
{
  int i;
  double fact=1;
  for(i=n;i>=1;i--)
  {
    fact=fact*i;
  }
  return fact;
}
/*************************************************/
/***************TRAPEZOIDAL METHOD***************/
/************ONE VARIABLE EXPRESSION************/
/*************************************************/
double trap(double f(double x),double a,double b)
{
    int i,n=2;  // starting with two interval
    double integral,answer,x,h,sum,accuracy=0.00001;
    do{
        integral=answer;
        h=fabs(b-a)/n;
        sum=0;
        for(i=1;i<n;++i)
        {
            x=a+i*h;
            sum=sum+f(x);
        }
        answer=(h/2)*(f(a)+f(b)+2*sum);
        n++;
    }while(fabs(answer-integral)>=accuracy);
  return answer;
}
/*************************************************/
/***************TRAPEZOIDAL METHOD***************/
/************TWO VARIABLE EXPRESSION************/
/*************************************************/
double trapezoidal(double f(double x,double var),double var,double a,double b)
{
    int i,n=2;  // starting with two interval
    double integral,answer,x,h,sum,accuracy=0.00001;
    do{
        integral=answer;
        h=fabs(b-a)/n;
        sum=0;
        for(i=1;i<n;++i)
        {
            x=a+i*h;
            sum=sum+f(x,var);
        }
        answer=(h/2)*(f(a,var)+f(x,var)+2*sum);
        n++;
    }while(fabs(answer-integral)>=accuracy);
  return answer;
}
/*************************************************/
/***************SIMPSON'S 1/3 METHOD***************/
/*************ONE VARIABLE EXPRESSION*************/
/*************************************************/
double simp13(double f(double x),double a,double b)
{
    int i,n=2;  // starting with two interval
    double integral,answer,x,h,sum,accuracy=0.00001;
    do{
        integral=answer;
        h=fabs(b-a)/n;
        sum=0;
        for(i=1;i<n;++i)
        {
            x=a+i*h;
            if(i%2==0){
                sum=sum+2*f(x);
            }
            else{
                sum=sum+4*f(x);
            }
        }
        answer=(h/3)*(f(a)+f(b)+sum);
        n=n+2;
    }while(fabs(answer-integral)>=accuracy);
  return answer;
}
/*************************************************/
/***************SIMPSON'S 1/3 METHOD***************/
/**************TWO VARIABLE EXPRESSION************/
/*************************************************/
double simpson13(double f(double x,double var),double var,double a,double b)
{
    int i,n=2;  // starting with two interval
    double integral,answer,x,h,sum,accuracy=0.00001;
    do{
        integral=answer;
        h=fabs(b-a)/n;
        sum=0;
        for(i=1;i<n;++i)
        {
            x=a+i*h;
            if(i%2==0){
                sum=sum+2*f(x,var);
            }
            else{
                sum=sum+4*f(x,var);
            }
        }
        answer=(h/3)*(f(a,var)+f(b,var)+sum);
        n=n+2;
    }while(fabs(answer-integral)>=accuracy);
  return answer;
}
/*************************************************/
/***************ROOT FINDING***************/
/*************BISECTION METHOD*************/
/*************************************************/
double bisection(double f(double x),float a,float b)
{
  double x,xm,xl,xr,accuracy=0.00001,xinc=0.5,z;
  for (x=a;x<=b;x+=xinc)
    {
      if (f(x)*f(x+xinc)<=0)
      {
        xl=x;
        xr=x+xinc;
        do
        {
          xm=(xl+xr)/2.0;
          if (f(xm)*f(xl)>=0)
          {
            xl=xm;
          }
          if (f(xm)*f(xl)<=0)
          {
            xr=xm;
          }
          z=fabs((xl-xr)/(xl+xr));
        }
        while(z>accuracy);
        printf("\nroot=%f\tf(xm)=%f\tz=%f\taccuracy=%f\n",xm,f(xm),z,accuracy);
      }
    }
}
/*************************************************/
/***************ROOT FINDING***************/
/***************SECANT METHOD***************/
/*************************************************/
double secant(double f(double x), double a, double b)
{
    
    double x1,x2,x3; // x1 starting point a, x2 tending from a to b
    for(x1=a;x1<=b;x1=x1+0.01)
    {
        x2=x1+0.01;
        if(f(x1)*f(x2)<=0)
        {
            do{
                x3=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
                x1=x2;
                x2=x3;
            }while(fabs(f(x3))>0.00001);
            printf("\nIn the interval: %.3lf and %.3lf\n",x1,x2);
            printf("The root is: %.4lf\n",x3);
        }
    }
}
