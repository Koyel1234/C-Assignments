//Random Number Generation
//to obtain maximum of a set of values
//problem no.-(11)
#include<stdio.h>
#include<math.h>
int main()
{
	FILE*fp;
	fp=fopen("Random number generation (11).dat","w");
	int i;
	float g(float);
	float a,b,h,x[500],max,k;
	printf("\nEnter lower limit = ");
	scanf("%f",&a);
	printf("\nEnter upper limit = ");
	scanf("%f",&b);
	h=(b-a)/500;
	printf("500 values of g(x) : \n");
	fprintf(fp,"500 values of g(x) : \n");
	for(i=0;i<500;i++)
	{
		x[i]=g(a+(i*h));
		printf("\t%f",x[i]);
		fprintf(fp,"\t%f",x[i]);
		if(i%7==0)
		printf("\n");
		if(i%7==0)
		fprintf(fp,"\n");
	}
	max=x[0];
	k=a;
	for(i=1;i<500;i++)
	{
		if(x[i]>max)
		{
		max=x[i];
		k=a+(i*h);
	    }
	}
	printf("\nMaximum value is = %f",max);
	printf("\nCorresponding x= %f",k);
	fprintf(fp,"\nMaximum value is = %f",max);
	fprintf(fp,"\nCorresponding x= %f",k);
	return 0;
	fclose(fp);
}
float g(float x)
{
	float y;
	y=(x*cos(x))+(log(1+x))+(atan(x));
	return y;
}
