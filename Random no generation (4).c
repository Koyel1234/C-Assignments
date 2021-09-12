//Random Number Generation
//to generate a random sample from chi-square distribution wsith given df
//problem no.-(4)
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	FILE*fp;
	fp=fopen("Random Number Generation (4).dat","w");
	int n,i,m,j;
	float u1,u2,v,x[50];
	printf("\nEnter df of chi-square = ");
	scanf("%d",&m);
	fprintf(fp,"DF of chi-square variale is %d",m);
	printf("\nEnter sample size = ");
	scanf("%d",&n);
	srand(time(0));
	printf("\nThe sample of size %d from chi-square with df %d is :\n",n,m);
	fprintf(fp,"\nThe sample of size %d from chi-square with df %d is :\n",n,m);
	for(i=0;i<n;i++)
	{
		x[i]=0;
		for(j=0;j<m;j++)
		{
		u1=((float)(rand()))/RAND_MAX;
		u2=((float)(rand()))/RAND_MAX;
		v=(sqrt(-2*log(u1)))*cos(2*3.14*u2);
		x[i]=x[i]+(v*v);
	    }
		printf("\t%f\n",x[i]);
		fprintf(fp,"\t%f\n",x[i]);
	}
	return 0;
	fclose(fp);
}
