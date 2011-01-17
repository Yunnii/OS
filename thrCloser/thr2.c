#include <pthread.h>
#include <stdio.h>
#include <time.h>

int lgth=700;
int mas[lgth];
int i=0;
int y=1000000000;
void *func1()
{	
	while(i++<y)
		mas[0]=1;
	puts("1st completed");
	pthread_exit(NULL);
}
void *func2()
{
	while(i++<y)
		mas[lgth-1]=1;
	puts("2st completed");
	pthread_exit(NULL);
}
int main()
{
	clock_t start=clock();
	pthread_t thread1;
	pthread_t thread2;
	int status;
	status=pthread_create(&thread1,NULL,&func1,NULL);
	if (status)
	{
		printf("Can't create 1st thread x_X \n");
		return 1;
	}
	status=pthread_create(&thread2,NULL,&func2,NULL);
	if (status)
	{
		printf("Can't create 2st thread \\*o*\\\n");
		return 1;
	}
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	clock_t end=clock();
	printf("time  = %d clock ticks \n", (int)(end-start));
	return 0;
}
