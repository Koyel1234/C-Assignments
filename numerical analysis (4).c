//Numerical Analysis
//To compute value of integral by trapezoidal rule
//problem no.-(4)
#include<stdio.h>
#include<math.h>
main()
{
	FILE*fp;
	fp=fopen("Numrical Analysis (4).dat","w");
	int i,n;
	float a,b,I1,I2;
	float trap(float,float,int);
	printf("\nEnter lower limit = ");
	scanf("%f",&a);
	printf("\nEnter upper limit = ");
	scanf("%f",&b);
	I1=trap(a,b,n);
	I2=trap(a,b,n+1);
	while(fabs(I1-I2)>0.001)
	{
		I1=I2;
		n=n+1;
		I2=trap(a,b,n+1);
	}
	printf("The required value of the integral = %f",I1);
	fprintf(fp,"The required value of the integral = %f",I1);
	printf("\nThe number of intervals should be %d or %d",n,n+1);
	fprintf(fp,"\nThe number of intervals should be %d or %d",n,n+1);
}
float trap(float a,float b,int n)
{
	
	int i;float h,I;
	float g(float);
	h=(b-a)/n;
	I=g(a)+g(b);
	for(i=1;i<n;i++)
	{
		I=I+(2*g(a+(i*h)));
	}
	I=I*(h/2);
	return I;
}
float g(float x)
{
	float y;
	y=sin(x)-log(x)+exp(x);
	return y;
}
