#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	FILE*fp;
	fp=fopen("Random no generation(1).dat","w");
	int n,i,j,N,a[100];
	float p,u,k;
	printf("\nEnter p= ");
	scanf("%f",&p);
	printf("\nEnter n= ");
	scanf("%d",&n);
	printf("\nEnter sample size = ");
	scanf("%d",&N);
	srand(time(0));
	printf("The sample from Bin(%d,%f) of size %d is: ",n,p,N);
	fprintf(fp,"The sample from Bin(%d,%f) of size %d is: ",n,p,N);
	for(i=1;i<=N;i++)
	{
		a[i]=0;
	    for(j=1;j<=n;j++)
	    {
		    u=((float)(rand()))/RAND_MAX;
		    if(u<=p)
		    k=1;
		    else
		    k=0;
		    a[i]=a[i]+k;
	    }
	    printf("\n\t%d",a[i]);
	    fprintf(fp,"\n\t%d",a[i]);
    }
	return 0;
	fclose(fp);
}
