//Matrices and Determinnt
//To ckeck whether a dquare matrix of order m is upper triangular or not
//Prob. no.-(4)
#include<stdio.h>
main()
{
	FILE*fp;
	fp=fopen("Matrices and determinant (4).dat","w");
	int m,i,j,flag=0;
	float A[50][50];
	printf("\nEnter the order of matrix = ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
		    printf("\nEnter (%d,%d)th element = ",i+1,j+1);
			scanf("%f",&A[i][j]);	
		}
	}
    for(i=0;i<m;i++)
    {
    	for(j=0;j<m;j++)
    	{
    		if(A[i][j]!=0)
    		flag=1;
    		break;
		}
	}
	fprintf(fp,"The given matrix :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			fprintf(fp," \t%0.1f",A[i][j]);
		}
		fprintf(fp,"\n");
	}
	if(flag==0)
	fprintf(fp,"\nMatrix is upper triangular.");
	else
	fprintf(fp,"\nMatrix is not upper triangular.");
	return 0;
	fclose(fp);
}
