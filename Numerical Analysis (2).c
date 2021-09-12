//Numerical Analysis
//to obtain value of fuanction by Lagrange's interpolation formula
//problem no.-(2)
#include<stdio.h>
main()
{
	FILE*fp;
	fp=fopen("Numericl Analysis (2).dat","w");
	int n,i,j;
	float y[50],ey[50],given_y,reqd_ey=0,prod;
	printf("\nEnter number of data points = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf(" y[%d]=",i+1);
		scanf("%f",&y[i]);
		printf(" exp(y)[%d]=",i+1);
		scanf("%f",&ey[i]);
	}
	printf("\nEnter value of y= ");
	scanf("%f",&given_y);
	for(i=0;i<n;i++)
	{
		prod=1;
		for(j=0;j<n;j++)
		{
			if(j!=i)
			prod=prod*((given_y-y[j])/(y[i]-y[j]));
		}
		reqd_ey=reqd_ey+(ey[i]*prod);
	}
	printf("\nRequired value of exp(0.1545)=%f",reqd_ey);
	fprintf(fp,"Required value of exp(0.1545)=%f",reqd_ey);
	return 0;
	fclose(fp);
}
