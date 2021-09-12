//Random Number Generation
//to obtain random sample of t-distribution of given df
//problm no.-(5) 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	FILE*fp;
	fp=fopen("Random number generation (5).dat","w");
	int m,n,i,j;
	float u1,u2,u3,u4,x[100],y[100],z[100],v;
	printf("\nEnter df of t distribution = ");
	scanf("%d",&m);
	fprintf(fp,"DF of t distribution is %d",m);
	printf("\nEnter size of sample =");
	scanf("%d",&n);
	srand(time(0));
	printf("\nThe sample of size %d from t distribution with df %d is :\n",n,m);
	fprintf(fp,"\nThe sample of size %d from t distribution with df %d is :\n",n,m);
	for(i=0;i<n;i++)
	{
		u1=((float)(rand()))/RAND_MAX;
		u2=((float)(rand()))/RAND_MAX;
		x[i]=(sqrt(-2*log(u1)))*cos(2*3.14*u2);
		y[i]=0;
		for(j=0;j<m;j++)
		{
		u3=((float)(rand()))/RAND_MAX;
		u4=((float)(rand()))/RAND_MAX;
		v=(sqrt(-2*log(u3)))*cos(2*3.14*u4);
		y[i]=y[i]+(v*v);
		}
		z[i]=x[i]/((sqrt(y[i]))/n);
		printf("\t%f\n",z[i]);
		fprintf(fp,"\t%f\n",z[i]);
	}
	return 0;
	fclose(fp);
}
