//Random Number Generation
//to obtain random sample of F distribution with given df
//problem no.-(6)
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	FILE*fp;
	fp=fopen("Random number generation (6).dat","w");
	int p,q,n,i,j;
	float x[100],y[100],z[100],u1,u2,v,u3,u4,w;
	printf("\nEnter the df of numerator = ");
	scanf("%d",&p);
	printf("\nEnter the df of denominator = ");
	scanf("%d",&q);
	fprintf(fp,"DF of numearator = %d",p);
	fprintf(fp,"\nDF of denominator = %d",q);
	printf("\nEnter the sample size = ");
	scanf("%d",&n);
	srand(time(0));
	printf("\nThe sample is : \n");
	fprintf(fp,"\nThe sample of size %d from F distribution with df (%d,%d) is : \n",n,p,q);
	for(i=0;i<n;i++)
	{
		x[i]=0;
		for(j=0;j<p;j++)
		{
			u1=((float)(rand()))/RAND_MAX;
			u2=((float)(rand()))/RAND_MAX;
			v=(sqrt(-2*log(u1)))*cos(2*3.14*u2);
			x[i]=x[i]+(v*v);
		}
		y[i]=0;
		for(j=0;j<q;j++)
		{
			u3=((float)(rand()))/RAND_MAX;
			u4=((float)(rand()))/RAND_MAX;
			w=(sqrt(-2*log(u1)))*cos(2*3.14*u2);
			y[i]=y[i]+(w*w);
		}
		z[i]=(x[i]/p)/(y[i]/q);
		printf("\t%f\n",z[i]);
		fprintf(fp,"\t%f\n",z[i]);
	}
	return 0;
	fclose(fp);
}
