//Random Number Generation
//to calculate value of constant of a given pmf
//problem no.-(8)
#include<stdio.h>
#include<math.h>
int main()
{
	FILE*fp;
	fp=fopen("Random number generation (8).dat","w");
	int i;
	float p=0,c;
	float tot_pmf(int);
	for(i=5;i<=15;i++)
	{
		p=p+tot_pmf(i);
	}
	c=((float)(1))/p;
	printf("c=%f",c);
	fprintf(fp,"the required value of c = %f",c);
	return 0;
	fclose(fp);
}
float tot_pmf(int x)
{
	float y;
	int fact(int);
	y=((exp(-2))*(pow(2,x)))/fact(x);
	return y;
}
int fact(int a)
{
	int k=1,i;
	for(i=1;i<=a;i++)
	{
		k=(k*i);
	}
	return k;
}
