#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
	int i,j,count,N=1000;
	int r[N],freq[N];	
	// part a
	int a=5,r0=1,m=37;	// given values
	for(i=0;i<N;i++) {
		r[0]=r0;
		r[i+1]=(a*r[i])%m;
		freq[i]=-1;
	}
	// part b
	for (i=0;i<N;i++) {
		count=1;
		for(j=i+1;j<N;j++) {
    		if(r[i]==r[j]) {
    			count++;
    			freq[j]=0;
    		}
    	}
    	if(freq[i]!=0) {
    		freq[i]=count;
		}
	}
	FILE*fp=NULL;
	fp=fopen("1a.txt","w");
	// stroing the frequecy distribution
 	for (i=0;i<N;i++) {
  		if(freq[i]!= 0) {
  			fprintf(fp,"%d\t%d\n",r[i],freq[i]);
		}		
  	}
  	//Correlation Checks
    FILE*fp1=NULL;
    fp1=fopen("1b.txt","w");
    for(i=0;i<N-1;++i) {
        fprintf(fp1,"%d\t%d\n",r[i],r[i+1]);  
    }
  	// part c
  	for(i=0;i<N;i++) {
		for(j=i+1;j<N;j++) {
			if (r[i]==r[j]) {
				printf("The periodicity of the random no: %d\n",j);
				exit(0);
			}
		}
	}
}
