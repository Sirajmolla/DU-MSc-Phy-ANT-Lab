// it contains the interpolation functions
// (lagrange and neville methods)
// use #include"interpolation.c" in the program you wished to use this


//function to calculate Lagrange interpolated value
double lag(int n,double X[],double Y[],double x)
{
    // n=no of points (n-1=order of interpolation)
    double sum=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        // initiating product part
        double prod=1;
        for(j=0;j<n;j++)
        {
            if(j!=i)
            prod=prod*(x-X[j])/(X[i]-X[j]);
        }
        sum=sum+prod*Y[i];
    }
    return sum;
}
//function to calculate neville interpolated value
double nev(int n,double X[],double Y[],double x)
{
    // n=no of points (n-1=order of interpolation)
    double Q[n][n];
    int i,j;
    // initialising null matrix
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            Q[i][j] = 0.0;
        }
        Q[i][0] = Y[i]; //setting first column as Y(or P0) values
    }
    for (i=1;i<n;i++) //i=1 since first col is P0
    {
        for (j=1;j<=i;j++)
        {
            Q[i][j]=((x-X[i-j])*(Q[i][j-1])-(x-X[i])*(Q[i-1][j-1]))/(X[i]-X[i-j]);
        }
    }
    return (Q[n-1][n-1]);
}