// sheet 1 problem 1
// make sure "interpolation.c" file is in the same directory
#include<stdio.h>
#include<math.h>
#include"interpolation.c"
int main()
{
    int i;
    FILE*fp=NULL;
    fp=fopen("sheet1.txt","w");
    // initialing array for table 1
	double X1[]={0.5,5,10};
	double Y1[]={2,0.2,0.1};
	// initialing array for table 2
	double X2[]={0.5,1,2,4,5,8,10};
	double Y2[]={2,1,0.5,0.25,0.2,0.125,0.1};
	double x=3;  //value of x for which interpolated value is required

    printf("For table I the interpolated value at x=3 is %lf",lag(3,X1,Y1,x));
    printf("\nFor table II the interpolated value at x=3 is %lf",lag(7,X2,Y2,x));

    for (x=0.5;x<=10;x+=0.1)
    {
    	fprintf(fp,"%lf\t%lf\t%lf\t%lf\n",x,lag(3,X1,Y1,x),lag(7,X2,Y2,x),1/x);
    }
}