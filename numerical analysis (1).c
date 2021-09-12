//Numerical Ananlysis 
//Calculation of real root using Newton-Raphson method
//problem no.- (1)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
	FILE*fp;
	fp=fopen("Numerical analysis (1).dat","w");
	float x0,r1,r2;
	float f(float);
	float fd(float);
	float check(float);
	printf("\nEnter the initial rt= ");
	scanf("%f",&x0);
	if((check(x0))<1)
	{
	r1=x0-((f(x0))/(fd(x0)));
	r2=r1-((f(r1))/(fd(r1)));
	while(fabs(r1-r2)>0.0001)
	{
		r1=r2;
		r2=r1-((f(r1))/(fd(r1)));
	}
	printf("\nRequired root in the neighbourhood of %f=%f",x0,r1);
	fprintf(fp,"Required root in the neighbourhood of %f=%f",x0,r1);
    }
    else
    {
    	printf("\nThis initial root can't be used.'");
    	fprintf(fp,"\nThis initial root can't be used.'");
	}
	return 0;
	fclose(fp);
}
float f(float x)
{
	float y;
	y=(2*x)-(log10(x))-7;
	return y;
}
float fd(float x)
{
	float y;
	y=2-((log(10))/x);
	return y;
}
float check(float x)
{
	float y;
	float fd2(float);
	y=((f(x))*(fd(x)))/pow((fd2(x)),2);
	return y;
}
float fd2(float x)
{
	float y;
	y=fabs(((float)(1))/(x*x*(log(10))));
	return y;
}
