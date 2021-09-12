//Numerical Analysis
//to obtain positive root correct upto 5 decimal places by iteration method
//problem no.-(5)
#include<stdio.h>
#include<math.h>
main()
{ 
    FILE*fp;
    fp=fopen("Numerical Analysis (5).dat","w");
	float x0,r1,r2;
	float phi(float);
	float phi_1st_derivative(float);
	printf("\nEnter initial root = ");
	scanf("%f",&x0);
	printf("\nGiven initial root = %f",x0);
	fprintf(fp,"Given initial root = %f",x0);
	if(fabs(phi_1st_derivative(x0))<1)
	{
	r1=phi(x0);
	r2=phi(r1);
	while(fabs(r1-r2)>0.000001)
	{
		r1=r2;
		r2=phi(r1);
	}
	printf("\nThe required real root = %f",r1);
	fprintf(fp,"\nThe required real root = %f",r1);
    }
    else
    {
    	printf("\nThis initial root can't be used.");
    	fprintf(fp,"\nThis initial root can't be used.");
	}
	return 0;
	fclose(fp);
}
float phi(float x)
{
	float y;
	y=(exp(x)-1)/2;
	return y;
}
float phi_1st_derivative(float x)
{
	float y;
	y=exp(x)-2;
	return y;
}
