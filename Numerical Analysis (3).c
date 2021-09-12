//Numerical Analysis
//to obtain value of integral by Simpson's one third rule
//problem no.-(3)
#include<stdio.h>
#include<math.h>
main()
{
	FILE*fp;
	fp=fopen("Numerical Analysis (3).dat","w");
	int n;
	float a,b,I1,I2;
	float simp(float,float,int);
	printf("\nEnter upper limit = ");
	scanf("%f",&b);
	printf("\nEnter lower limit = ");
	scanf("%f",&a);
	n=2;
	I1=simp(a,b,n);
	I2=simp(a,b,n+2);
	while(fabs(I1-I2)<0.00001)
	{
		I1=I2;
		n=n+2;
		I2=simp(a,b,n+2);
	}
	printf("\nThe value of the integral is %f",I1);
	fprintf(fp,"The value of the integral is %f",I1);
	return 0;
	fclose(fp);
}
float simp(float a,float b,int n)
{
	int i;
	float h,I=0;
	float f(float);
	h=(b-a)/n;
	I=f(a)+f(b);
	for(i=1;i<n;i=i+2)
	{
		I=I+f(a+(i*h));
	}
	for(i=2;i<(n-1);i=i+2)
	{
		I=I+f(a+(i*h));
	}
	I=I*(h/3);
	return I;
}
float f(float x)
{
	float y;
	y=exp(x*tan(x));
	return y;
}
