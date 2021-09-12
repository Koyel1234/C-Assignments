//Random Number Genearation
//to produce a probability and verifyb a claim
//problem no.-(7)
#include<stdio.h>
#include<math.h>
int main()
{
	FILE*fp;
	fp=fopen("Random number generation (7).dat","w");
	int n=2;
	float a,I1,I2,p;
	float F(float,int);
	printf("\nEnter upper bound = ");
	scanf("%f",&a);
	I1=F(a,n);
	I2=F(a,n+2);
	while(fabs(I1-I2)>0.00001)
	{
		I1=I2;
		n=n+2;
		I2=F(a,n+2);
	}
	printf("\nThe value of the integral = %0.4f",I1);
	fprintf(fp,"The value of the integral = %0.4f",I1);
	p=I1-0.5000;
	printf("\nP[X<%f]-0.5 = %0.4f",a,p);
	fprintf(fp,"\nP[X<%f]-0.5 = %0.4f",a,p);
	if(p=0)
	{
		printf("\nClaim is appropriate.");
		fprintf(fp,"\nClaim is appropriate.");
	}
	else
	{
		printf("\nClaim is not appropriate.");
		fprintf(fp,"\nClaim is not appropriate.");
	}
	return 0;
	fclose(fp);
}
float F(float a,int n)
{
	int i;
	float h,I;
	float f(float);
	h=a/n;
	I=f(0)+f(a);
	for(i=1;i<n;i=i+2)
	{
	    I=I+(2*f(a+(i*h)));	
	}
	for(i=2;i<(n-1);i=i+2)
	{
	    I=I+(4*f(a+(i*h)));	
	}
	I=I*(h/3);
	return I;
}
float f(float x)
{
	float y;
	y=(((float)(1))/54)*((x*x)/exp(x/3));
	return y;
}
