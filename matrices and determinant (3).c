//Matrices and Determinant
//To obtain two matrices L and M from given square matrix A of order m such that A=L-M with L symmetric and M skew-symmetric
//Prob. no.-(3)
#include<stdio.h>
main()
{
	FILE*fp;
	fp=fopen("Matrices and Determinant (3).dat","w");
	int m,i,j;
	float A[50][50],A_trans[50][50],L[50][50],M[50][50];
	printf("\nEnter the order of the matrix = ");
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
			A_trans[i][j]=A[j][i];
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			L[i][j]=(((float)(1))/2)*(A[i][j]+A_trans[i][j]);
			M[i][j]=(((float)(1))/2)*(A_trans[i][j]-A[i][j]);
		}
	}
	printf("\nThe given matrix A is :\n");
	fprintf(fp,"The given matrix A is :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			printf(" %f",A[i][j]);
			fprintf(fp," %f",A[i][j]);
		}
		printf("\n");
		fprintf(fp,"\n");
	}
	printf("\nThe symmetric matrix L is :\n");
	fprintf(fp,"\nThe symmetric matrix L is :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			printf(" %f",L[i][j]);
			fprintf(fp," %f",L[i][j]);
		}
		printf("\n");
		fprintf(fp,"\n");
	}
	printf("\nThe skew-symmetric matrix M is :\n");
	fprintf(fp,"\nThe skew-symmetric matrix M is :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			printf(" %f",M[i][j]);
			fprintf(fp," %f",M[i][j]);
		}
		printf("\n");
		fprintf(fp,"\n");
	}	
	return 0;
}
