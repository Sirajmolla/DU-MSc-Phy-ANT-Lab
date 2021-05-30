// USE IT AS A LIBRARY. DON'T TRY TO RUN IT.
//function to calculate Lagrange interpolated value
double lagrange(int n,double X[],double Y[],double x){
    // n=no of points (n-1=order of interpolation)
    double sum=0;
    int i,j;
    for(i=0;i<n;i++){
        // initiating product part
        double prod=1;
        for(j=0;j<n;j++){
            if(j!=i)
            prod=prod*(x-X[j])/(X[i]-X[j]);
        }
        sum=sum+prod*Y[i];
    }
    return sum;
}
//function to calculate natural cubic spline interpolated value
double csplines(int n,double x[],double a[],double X){
    n--;    // no of splines
    double h[n],alpha[n],l[n+1],u[n+1],z[n+1],c[n+1],b[n],d[n];
    double sum;
    int i,j;
    // Step 1
    for (i=0;i<=n-1;++i)
    	h[i]=x[i+1]-x[i];
    // Step 2
    for (i=1;i<=n-1;++i)
        alpha[i]=3*(a[i+1]-a[i])/h[i]-3*(a[i]-a[i-1])/h[i-1];
    // Step 3
    l[0] = 1;
    u[0] = 0;
    z[0] = 0;
    // Step 4
    for (i=1;i<=n-1;++i){
        l[i]=2*(x[i+1]-x[i-1])-h[i-1]*u[i-1];
		u[i]=h[i]/l[i];
		z[i]=(alpha[i]-h[i-1]*z[i-1])/l[i];
    }
    // Step 5
    l[n] = 1;
    z[n] = 0;
    c[n] = 0;
    // Step 6
    for (j=n-1;j>=0;--j){
        c[j]=z[j]-u[j]*c[j+1];
		b[j]=(a[j+1]-a[j])/h[j]-h[j]*(c[j+1]+2*c[j])/3;
		d[j]=(c[j+1]-c[j])/(3*h[j]);
    }
    // Step 7
    for (i=0;i<n+1;++i){
    	if (X>=x[i] && X<x[i+1])
    	{
    		sum=a[i]+b[i]*(X-x[i])+c[i]*pow((X-x[i]),2)+d[i]*pow((X-x[i]),3);
    	}
    }
    return sum;
}
//function to calculate clamped cubic spline interpolated value
double clamped(int n,double x[n],double a[n],double F0,double F1, double X) {
    n--;    // no of splines
    double h[n],alpha[n+1],l[n+1],u[n+1],z[n+1],b[n],c[n+1],d[n];
    int i,j;
    // Step 1
    for(j=0;j<n;j++){
        h[j]=x[j+1]-x[j];
    }
    // Step 2
    alpha[0]=(3*(a[1]-a[0])/h[0])-3*F0;
    alpha[n]=3*F1-3*(a[n]-a[n-1])/h[n-1];
    // Step 3
    for(i=1;i<n;i++){
        alpha[i]=((3/h[i])*(a[i+1]-a[i])-(3/h[i-1])*(a[i]-a[i-1]));
    }
    // Step 4
    l[0]=2*h[0];
    u[0]=0.5;
    z[0]=alpha[0]/l[0];
    // Step 5
    for(i=1;i<n;i++){
        l[i]=2*(x[i+1]-x[i-1])-h[i-1]*u[i-1];
        u[i]=h[i]/l[i];
        z[i]=(alpha[i]-h[i-1]*z[i-1])/l[i];
    }
    // Step 6
    l[n]=h[n-1]*(2-u[n-1]);
    z[n]=(alpha[n]-h[n-1]*z[n-1])/l[n];
    c[n]=z[n];
    // Step 7
    for(j=n-1;j>=0;j--){
        c[j]=z[j]-u[j]*c[j+1];
        b[j]=((a[j+1]-a[j])/h[j])-(h[j]*(c[j+1]+2*c[j])/3);
        d[j]=(c[j+1]-c[j])/(3*h[j]);
    }
    // Step 8
    double sum;
    for (i=0;i<n+1;++i) {
        if (X>=x[i] && X<x[i+1]){
            sum=a[i]+b[i]*(X-x[i])+c[i]*pow((X-x[i]),2)+d[i]*pow((X-x[i]),3);
        }
    }
    return sum;
}
// simpson's 1/3 method
double simpson(double f(double x),double a,double b){
    int i,n=2;  // starting with two interval
    double integral,answer,x,h,sum,accuracy=0.00001;
    do{
        integral=answer;
        h=fabs(b-a)/n;
        sum=0;
        for(i=1;i<n;++i){
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