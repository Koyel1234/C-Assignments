//Matrices and Determinant
//if multiplication is possible to obtain the product matrix else any suitable message
//Prob. no.-(1)
#include<stdio.h>
#include<conio.h>
main()
{
	FILE*fp;
	fp=fopen("Matrices and determinant (1).dat","w");
	int m,n,p,q,i,j,k;
	float A[50][50],B[50][50],Prod[50][50];
	printf("\nEnter number of rows of matrix A = ");
	scanf("%d",&m);
	printf("\nEnter number of columns of matrix A = ");
	scanf("%d",&n);
	printf("\nEnter number of rows of matrix B = ");
	scanf("%d",&p);
	printf("\nEnter number of rows of matrix B = ");
	scanf("%d",&q);
	if(n!=p)
	{
		printf("\nAs number of column of matrix A is not equal to number of rows of matrix B matrices are not multiplicable.");
		fprintf(fp,"As number of column of matrix A is not equal to number of rows of matrix B matrices are not multiplicable.");
    }
	else
	{
		printf("\nAs number of column of matrix A is equal to number of rows of matrix B matrices are multiplicable.");
		fprintf(fp,"\nAs number of column of matrix A is equal to number of rows of matrix B matrices are multiplicable.");
		printf("\nEntry of matrix A :\n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("\nEnter (%d,%d)th element of matrix A = ",i+1,j+1);
				scanf("%f",&A[i][j]);
			}
		}
		printf("\nEntry of matrix B :\n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
			{
				printf("\nEnter (%d,%d)th element of matrix B = ",i+1,j+1);
				scanf("%f",&B[i][j]);
			}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<q;j++)
			{
				Prod[i][j]=0;
				for(k=0;k<n;k++)
				{
					Prod[i][j]=Prod[i][j]+(A[i][k]*B[k][j]);
				}
			}
		}
		fprintf(fp,"\nThe matrix A is:\n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				fprintf(fp," \t%0.1f",A[i][j]);
			}
			fprintf(fp,"\n");
		}
		fprintf(fp,"\nThe matrix B is:\n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
			{
				fprintf(fp," \t%0.1f",B[i][j]);
			}
			fprintf(fp,"\n");
		}
		fprintf(fp,"\nThe product matrix is:\n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<q;j++)
			{
				fprintf(fp," \t%f",Prod[i][j]);
			}
			fprintf(fp,"\n");
		}
	}
	return 0;
	fclose(fp);
}
