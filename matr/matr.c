#include<stdio.h>
#include<time.h>

int main()
{
	int size = 1000;
	int a[size][size];
	int summator=0;
	clock_t s1=clock();
	for(int k=0;k<size;k++)
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				summator+=a[i][j];
	clock_t s2=clock();
	for(int k=0;k<size;k++)
		for(int i=0;i<size;i++) 
        	        for(int j=0;j<size;j++)
                	        summator+=a[j][i];	
	clock_t e=clock();
	printf("On raws %d clock ticks\nOn columns %d clock ticks\n",(int)(s2-s1),(int)(e-s2));
	return 0;
}
