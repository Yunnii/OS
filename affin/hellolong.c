#include<stdio.h>
#include<time.h>

int main()
{
        int sixe=1000;
	int a[1000][1000];
	int summator=0;
	clock_t s1=clock();
	for(int k=0;k<size;k++)
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				summator+=a[i][j];
		return 0;
}