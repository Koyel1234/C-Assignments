#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main()
{
	int n,k,i,j,count=0;
	float u,x,mean[100],t[100],p,s=(pow(3.14,2))/6;
	printf("\nEnter the number of sets = ");
	scanf("%d",&n);
	printf("\nEnter number of observations in each set = ");
	scanf("%d",&k);
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		mean[i]=0;
		for(j=0;j<k;j++)
		{
			u=((float)(rand()))/RAND_MAX;
		//	printf("\n%f",u);
			x=((log(1+(2*u)))-(log(1-(2*u))))/2;
		//	printf("\n%f",x);
			mean[i]=mean[i]+x;
		//	printf("\n%f",mean[i]);
		}
		mean[i]=mean[i]/k;
		printf("\n%f",mean[i]);
		t[i]=((log(2))-mean[i])*(sqrt(s))/k;
	    if(t[i]>0)
	    count++;
	}
	p=((float)(count))/n;
	printf("\nProportion of positive t-statistics =%d, %f",count,p);
	return 0;
}
