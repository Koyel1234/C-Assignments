#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main()
{
	FILE*fp;
	fp=fopen("Random no generation (2).dat","w");
	int i,j,a[100],N;
	float l,pdt,u;
	printf("\nEnter l= ");
	scanf("%f",&l);
	printf("\nEnter sample size = ");
	scanf("%d",&N);
	srand(time(0));
	printf("\nThe sample from Poi(%f) of size %d is :\n",l,N);
	fprintf(fp,"The sample from Poi(%f) of size %d is :\n",l,N);
	for(i=1;i<=N;i++)
	{
		j=0;
		pdt=1;
		while(pdt>exp(-l))
		{
			u=((float)(rand()))/RAND_MAX;
			pdt=pdt*u;
			j++;
		}
		a[i]=j;
		printf("\t%d\n",a[i]);
        fprintf(fp,"\t%d\n",a[i]);
    }
    return 0;
    fclose(fp);
}
