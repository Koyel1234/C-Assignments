//Random Number Generaion
//to generate a random sample from normal distribution with given mean and variance and calculate some probabilies
//problem no.-(3)
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
float m,v;
int main()
{
	FILE*fp;
	fp=fopen("Random Number Generation (3).dat","w");
	int i,n;
	float u1,u2,x[100],sample[100],pr1,pr2,pr3;
	float cdf(float,float);
	float cdf1(float,float);
	printf("\nEnter mean = ");
	scanf("%f",&m);
	printf("\nEnter variance = ");
	scanf("%f",&v);
	printf("\nEnter sample size = ");
	scanf("%d",&n);
	srand(time(0));
	printf("The sample of size %d from N(%f,%f) is : \n",n,m,v);
	fprintf(fp,"The sample of size %d of N(%f,%f) is : \n",n,m,v);
	for(i=0;i<n;i++)
	{
		u1=((float)(rand()))/RAND_MAX;
		u2=((float)(rand()))/RAND_MAX;
		x[i]=(sqrt(-2*log(u1)))*cos(2*3.14*u2);
		sample[i]=m+((sqrt(v))*x[i]);
		printf("\t%f\n",sample[i]);
		fprintf(fp," \t%f\n",sample[i]);
	}
	pr2=0.5+cdf1(0,((7-m)/sqrt(v)));
	pr1=1-pr2;
	pr3=cdf(2,6);
	printf("\n(i)Pr[x>7]=%f",pr1);
	printf("\n(ii)Pr[x<7]=%f",pr2);
	printf("\n(iii)P[2<=X<=6]=%f",pr3);
	fprintf(fp,"\n(i)Pr[x>7]=%f",pr1);
	fprintf(fp,"\n(ii)Pr[x<7]=%f",pr2);
	fprintf(fp,"\n(iii)P[2<=X<=6]=%f",pr1);
	return 0;
	fclose(fp);
}
float cdf(float x,float y)
{
    float a,b,I1,I2;
	float simp(float,float,int);
	int n;
	a=x;
	b=y;
	n=2;
	I1=simp(a,b,n);
	I2=simp(a,b,n+2);
	while(fabs(I1-I2)>0.00001)
	{
		I1=I2;
		n=n+2;
		I2=simp(a,b,n+2);
	}
	return I1;
}
float cdf1(float x,float y)
{
    float a,b,I1,I2;
	float simp1(float,float,int);
	int n;
	a=x;
	b=y;
	n=2;
	I1=simp1(a,b,n);
	I2=simp1(a,b,n+2);
	while(fabs(I1-I2)>0.00001)
	{
		I1=I2;
		n=n+2;
		I2=simp1(a,b,n+2);
	}
	return I1;
}
float simp(float a,float b,int n)
{
	float h,I;
	float f(float);
	int i;
	h=(b-a)/n;
	I=f(a)+f(b);
	for(i=1;i<=n-1;i=i+2)
	{
		I=I+(2*f(a+i*h));
	}
	for(i=2;i<=n-2;i=i+2)
	{
		I=I+(4*f(a+i*h));
	}
	I=I*(h/3);
	return I;
}
float simp1(float a,float b,int n)
{
	float h,I;
	float f1(float);
	int i;
	h=(b-a)/n;
	I=f1(a)+f1(b);
	for(i=1;i<=n-1;i=i+2)
	{
		I=I+(2*f1(a+i*h));
	}
	for(i=2;i<=n-2;i=i+2)
	{
		I=I+(4*f1(a+i*h));
	}
	I=I*(h/3);
	return I;
}
float f(float x)
{
	float y;
	y=(((float)(1))/(sqrt(2*3.14*v)))*exp((((float)(-1))/(2*sqrt(v)))*(pow((x-m),2)));
	return y;
}
float f1(float x)
{
	float y;
	y=(((float)(1))/(sqrt(2*3.14)))*exp((-x*x)/2);
	return y;
}
