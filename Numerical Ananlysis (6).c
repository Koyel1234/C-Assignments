//Numerical Analysis
//to obtain value of function by Lagrange's inverse interpolation formula
//problem no.-(6)
#include<stdio.h>
main()
{
	FILE*fp;
	fp=fopen("Numerical Analysis (6).dat","w");
	int n,i,j;
	float x[50],logx[50],given_logx,reqd_x=0,prod;
	printf("\nEnter number of data points = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n x[%d]=",i+1);
		scanf("%f",&x[i]);
		printf("\n log(x)[%d]=",i+1);
		scanf("%f",&logx[i]);
	}
	printf("\nEnter value of logx= ");
	scanf("%f",&given_logx);
	for(i=0;i<n;i++)
	{
		prod=1;
		for(j=0;j<n;j++)
		{
			if(j!=i)
			prod=prod*((given_logx-logx[j])/(logx[i]-logx[j]));
		}
		reqd_x=reqd_x+(x[i]*prod);
	}
	printf("\nRequired value of antilog(%f)=%f",given_logx,reqd_x);
	fprintf(fp,"Required value of antilog(%f)=%f",given_logx,reqd_x);
	return 0;
	fclose(fp);
}
