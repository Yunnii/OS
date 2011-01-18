#include<stdio.h>
#include<time.h>

int main()
{
        int size=1000;
	int a[1000][1000];
	int summator=0;
	clock_t s1=clock();
	int k,i,j;
	for(k=0;k<size;k++)
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
				//summator+=a[i][j];
				a[i][j]=0;
		return 0;
}
