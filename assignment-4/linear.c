// it contains the linear equations solving functions
// (gauss elimination, gauss elimination with partial pivoting and gauss jordan)
// use #include"linear.c" in the program you wished to use this

// displaying the matrix
//Parameters: (n) no of eq or rows,mat[n][n+1]
void printmat(int n,double mat[n][n+1]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            printf("%.2lf\t",mat[i][j]);
        }
        printf("\n");
    } 
}
//Gaussian Elimination
//Parameters: (n) no of eq/rows,mat[n][n+1],x[n]
void gausselim(int n,double A[n][n+1],double x[]){
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
//Gaussian Elimination with Partial Pivoting
//Parameters: (n) no of eq/rows,mat[n][n+1],x[n]
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
//Gauss Jordan method with Partial Pivoting
//Parameters: (n) no of eq/rows,mat[n][n+1],x[n]
void gaussjordan(int n,double A[n][n+1],double x[]){
    int i,j,k;
    for(i=0;i<n;i++){
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
        //Begin the Gauss Jordan
        for (k=0;k<n;k++)
        {
            if (k!=i){   
                double term;
                term=A[k][i]/A[i][i];
                for (j=0;j<=n;j++)
                {
                    A[k][j]=A[k][j]-term*A[i][j];
                }
            }
        }        
    }
    
    if (A[n-1][n-1]==0){
        printf("\nSorry! No unique solution exists.");
    }
    else{
        printf("\nThe diagonal augmented matrix:\n");
        printmat(n,A);
        // getting the x array
        for (i=0;i<n;i++){
            x[i]=A[i][n]/A[i][i];
        }  
        printf("\nThe solution of linear equations:\n");
        for(i=0;i<n;i++){
            printf(" x[%d]= %.2lf\n",i+1,x[i]);
        }  
    }       
}