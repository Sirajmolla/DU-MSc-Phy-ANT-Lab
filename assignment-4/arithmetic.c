// Rewriting the <linear.c> to add 3-digit chopping and rounding arithmetic
// use #include"arithmetic.c" in the program you wished to use this

// displaying the matrix
void printmat(int n,double mat[n][n+1]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            printf("%lf\t",mat[i][j]);
        }
        printf("\n");
    } 
}
// three digit chopping or truncating
double truncating(double x)
{
    double y,z;
    y=x*1000.0;
    z=floor(y);
    return z/1000.0;
}
// three digit rounding arithmetic
double rounding(double x)
{
    double y,z;
    y=(x*1000.0)+.5;
    z=floor(y);
    return z/1000.0;
}

// Gaussian elimination with three digit chopping
void gausschopping(int n,double A[n][n+1],double x[]){
    int i,j,k;
    for(i=0;i<n-1;i++){
        // swapping rows if the diagonal is zero
        if (A[i][i]==0){
            for(k=i+1;k<n;k++)
            {
                if (A[k][i]!=0){
                    for(j=0;j<=n;j++){
                        double temp;
                        temp=A[i][j];
                        A[i][j]=A[k][j];
                        A[k][j]=temp;
                    }
                }
            }
        }
        //Begin the Gauss Elimination
        for(k=i+1;k<n;k++)
        {
            double term;
            term=truncating(A[k][i]/A[i][i]);
            for(j=0;j<=n;j++){
                A[k][j]=truncating(A[k][j]-term*A[i][j]);
            }
        }        
    }
    printf("\nThe upper triangular matrix:\n");
    printmat(n,A);
    if (A[n-1][n-1]==0){
        printf("\nSorry! No unique solution exists.");
    }
    else{
        //Start with the back-substitution
        for(i=n-1;i>=0;i--){
            x[i]=A[i][n];
            for(j=i+1;j<n;j++){
                x[i]=truncating(x[i]-A[i][j]*x[j]);
            }
            x[i]=truncating(x[i]/A[i][i]);
        } 
        printf("\nThe solution of linear equations:\n");
        for(i=0;i<n;i++){
            printf(" x[%d]= %lf\n",i+1,x[i]);
        }
    }          
}

// Gaussian elimination with three digit rounding
void gaussround(int n,double A[n][n+1],double x[]){
    int i,j,k;
    for(i=0;i<n-1;i++){
        // swapping rows if the diagonal is zero
        if (A[i][i]==0){
            for(k=i+1;k<n;k++)
            {
                if (A[k][i]!=0){
                    for(j=0;j<=n;j++){
                        double temp;
                        temp=A[i][j];
                        A[i][j]=A[k][j];
                        A[k][j]=temp;
                    }
                }
            }
        }
        //Begin the Gauss Elimination
        for(k=i+1;k<n;k++)
        {
            double term;
            term=rounding(A[k][i]/A[i][i]);
            for(j=0;j<=n;j++){
                A[k][j]=rounding(A[k][j]-term*A[i][j]);
            }
        }        
    }
    printf("\nThe upper triangular matrix:\n");
    printmat(n,A);
    if (A[n-1][n-1]==0){
        printf("\nSorry! No unique solution exists.");
    }
    else{
        //Start with the back-substitution
        for(i=n-1;i>=0;i--){
            x[i]=A[i][n];
            for(j=i+1;j<n;j++){
                x[i]=rounding(x[i]-A[i][j]*x[j]);
            }
            x[i]=rounding(x[i]/A[i][i]);
        } 
        printf("\nThe solution of linear equations:\n");
        for(i=0;i<n;i++){
            printf(" x[%d]= %lf\n",i+1,x[i]);
        }
    }          
}
// Gaussian elimination with partial pivoting
void gausspivot(int n,double A[n][n+1],double x[]){
    int i,j,k;
    for(i=0;i<n-1;i++){
        //Partial Pivoting
        for(k=i+1;k<n;k++){
            //If the diagonal element (absolute value) is smaller than any of the terms below it
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
    printf("\nThe upper triangular matrix:\n");
    printmat(n,A);
    if (A[n-1][n-1]==0){
        printf("\nSorry! No unique solution exists.");
    }
    else{
        //Start with the back-substitution
        for(i=n-1;i>=0;i--){
            x[i]=A[i][n];
            for(j=i+1;j<n;j++){
                x[i]=x[i]-A[i][j]*x[j];
            }
            x[i]=x[i]/A[i][i];
        } 
        printf("\nThe solution of linear equations:\n");
        for(i=0;i<n;i++){
            printf(" x[%d]= %.2lf\n",i+1,x[i]);
        }
    }          
}