// problem 4
// biological system there are n species of animals and m sources of food
#include <stdio.h>
#include <math.h>

// product of matrix Cmn = Amo X bom
void PROD(int m,int o,int n,int a[m][o],int b[o][n],int c[m][n])
{
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            c[i][j]=0;
            for(int k=0;k<o;++k)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];  
            }
        }
    }   
}
void species(int A[3][4],int X[4][1], int Bi[3][1], int index)
{
    int Xj[4][1];
    // copying X elements into Xj
    for (int x=0;x<4;++x)
    {
        for (int y=0;y<4;++y)
        {
            Xj[x][y]=X[x][y];
        }
    }
    int i,j,k,n=0,flag=0;
    int AX[3][1];
    do
    {
        Xj[index][0]++;
        n++;
        PROD(3,4,1,A,Xj,AX);
        for(i=0;i<3;++i)
        {
            if(AX[i][0]>Bi[i][0]){
            flag=1;
            n--;
            break;
            }
        }
    }while(flag==0);
    printf("For species %d maximum can be added: %d\n",(index+1), n);
}

int main()
{ 
    // given initial conditions for our system
    int A[3][4]={{1,2,0,3},{1,0,2,2},{0,0,1,1}};
    int B[3][1]={{3500},{2700},{900}};
    int X[4][1]={{1000},{500},{350},{400}};

    printf("(a) Is there sufficient food to satisfy the average daily consumption?\n");
    int ax[3][1];
    PROD(3,4,1,A,X,ax);
    if (ax<B){printf("Yes. There is sufficient food.\n");}
        else{printf("No. There isn't sufficient food.\n");}

    printf("\n");

    printf("(b) Individual increase of each species satisfying food supply:\n");
    species(A,X,B,0); //for species 1
    species(A,X,B,1); //for species 2
    species(A,X,B,2); //for species 3
    species(A,X,B,3); //for species 4

    printf("\n");

    printf("(c) Individual increase of each species when 1 is extinct:\n");
    int Xc[4][1]={{0},{500},{350},{400}};
    species(A,Xc,B,1); //for species 2
    species(A,Xc,B,2); //for species 3
    species(A,Xc,B,3); //for species 4
 
    printf("\n");

    printf("(d) Individual increase of each species when 2 is extinct:\n");
    int Xd[4][1]={{1000},{0},{350},{400}};
    species(A,Xd,B,0); //for species 1
    species(A,Xd,B,2); //for species 3
    species(A,Xd,B,3); //for species 4
}