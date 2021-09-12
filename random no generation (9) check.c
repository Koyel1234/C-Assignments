//Random Number Generation
//to obtain pmf and pdf for given values of t and x
//problem no.-(9)
#include<stdio.h>
#include<math.h>
int main()
{
	FILE*fp;
	fp=fopen("Random number generation (9).dat","w");
	int x;
	float pmf(int,float);
	float cdf(int,float);
	float t,p1,p2;
	printf("\nEnter value of t = ");
	scanf("%f",&t);
	if(t<=0 || t>=1)
	printf("\nPleasev enter a value of t between 0 and 1.");
	else
	{
	printf("\nEnter value of x = ");
	scanf("%d",&x);
	if(x>=0 && x<=12)
	p1=pmf(x,t);
	else
	p1=0;
	p2=cdf(x,t);
	printf("Given values of theta and x =%f,%d",t,x);
	fprintf(fp,"Given values of theta and x =%f,%d",t,x);
	printf("\nRequired P[X=%d] for given t=%f is %f",x,t,p1);
	printf("\nRequired P[X<=%d] for given t=%f is %f",x,t,p2);
	fprintf(fp,"\nRequired P[X=%d] for given t=%f is %f",x,t,p1);
	fprintf(fp,"\nRequired P[X<=%d] for given t=%f is %f",x,t,p2);
    }
	return 0;
	fclose(fp);
}
float pmf(int x,float t)
{
	float y;
	y=((1-t)*pow(t,x))/(1-pow(t,11));
	return y;
}
float cdf(int x,float t)
{
	int i;
	float p=0;
	if(x>=0 && x<12)
	{
	for(i=0;i<=x;i++)
	{
		p=p+pmf(x,t);
	}
    }
    else if(x>=12)
    p=1;
    return p;
}
