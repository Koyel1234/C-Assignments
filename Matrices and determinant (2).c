//Matrices and determinant
//to obtain inverse of A and to show product of A and inverse of A is unity
//problem no.-(2)
#include<stdio.h>
#include<math.h>
main()
{
	FILE*fp;
	fp=fopen("Matrices and determinant (2).dat","w");
	int i,j,k,r;
	float a[20][20],b[20][20],I[20][20],c[20][20],x[10],temp;
	printf("\nEnter the order of square matrix= ");
	scanf("%d",&r);
	printf("\nEnter the elements of matrix A :\n");
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=r;j++)
		{
			printf("\nEnter a[%d][%d]= ",i,j);
			scanf("%f",&a[i][j]);
			if(i==j)
			I[i][j]=1;
			else
			I[i][j]=0;
		}
	}
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=r;j++)
		{
		    b[i][j]=a[i][j];
	    }
	}
	printf("The given matrix is :\n");
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=r;j++)
		{
			printf("\t%f",a[i][j]);
		}
		printf("\n");
	}
	fprintf(fp,"The given matrix is :\n");
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=r;j++)
		{
			fprintf(fp,"\t%f",a[i][j]);
		}
		fprintf(fp,"\n");
	}
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=r;j++)
		{
			if(i!=j)
			{
				temp=a[j][i]/a[i][i];
				for(k=1;k<=r;k++)
			    {
				    a[j][k]=a[j][k]-(temp*a[i][k]);
				    I[j][k]=I[j][k]-(temp*I[i][k]);
			    }
			}
		}
	}
	for(i=1;i<=r;i++)
	{
		temp=a[i][i];
		for(j=1;j<=r;j++)
		{
			a[i][j]=a[i][j]/temp;
			I[i][j]=I[i][j]/temp;
		}
	}
	printf("\nThe inverse is :\n");
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=r;j++)
		{
			printf("\t%0.4f",I[i][j]);
		}
		printf("\n");
	}
	fprintf(fp,"\nThe inverse is :\n");
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=r;j++)
		{
			fprintf(fp,"\t%f",I[i][j]);
		}
		fprintf(fp,"\n");
	}
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=r;j++)
		{
			c[i][j]=0;
			for(k=1;k<=r;k++)
			c[i][j]=c[i][j]+(b[i][k]*I[k][j]);
		}
	}
	printf("\nA*inverse(A) = \n");
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=r;j++)
		{
			printf("\t%f",c[i][j]);
		}
		printf("\n");
	}
	fprintf(fp,"\nA*inverse(A)= \n");
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=r;j++)
		{
			fprintf(fp,"\t%f",c[i][j]);
		}
		fprintf(fp,"\n");
	}
	for(i=1;i<=r;i++)
	{
		printf("\nEnter b[%d]= ",i);
		scanf("%f",&b[i]);
	}
	for(i=1;i<=r;i++)
	{
		x[i]=0;
		for(j=1;j<=r;j++)
		{
			x[i]=x[i]+(I[i][j]*b[j]);
		}
	}
	printf("\nThe solution is:\n");
	printf("\tx=%f,\ty=%f,\tz=%f",x[1],x[2],x[3]);
	fprintf(fp,"\nThe solution is:\n");
	fprintf(fp,"\tx=%f,\ty=%f,\tz=%f",x[1],x[2],x[3]);
	return 0;
	fclose(fp);
}
