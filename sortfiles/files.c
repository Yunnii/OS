#include<stdio.h>
#include<stdlib.h>

struct dinmas
{
	int	*mas;
	int	maxlength;
	int	length;
};

int merge(struct dinmas *dintemp,int lb,int split,int ub)
{
	int pos1=lb;
	int pos2=split+1;
	int pos3;
	struct dinmas tempmas={0,ub-lb+1,0};
	tempmas.mas=(int*)malloc(tempmas.maxlength*sizeof(int));
	if (tempmas.mas==NULL)
	{
		printf("Not avaliable memory for creating membuf in mergesort");
		return  2;
	}
	
	while(pos1<=split && pos2<=ub)
	{
		if(dintemp->mas[pos1]<dintemp->mas[pos2])
			tempmas.mas[pos3++]=dintemp->mas[pos1++];
		else 
			tempmas.mas[pos3++]=dintemp->mas[pos2++];
	}
	for (pos3 = 0; pos3 < ub-lb+1; pos3++)
		dintemp->mas[lb+pos3] = tempmas.mas[pos3];
	free(tempmas.mas);
	return 0;
}
int mergeSort(struct dinmas *dintemp,int lb,int ub)
{
	if (lb<ub)
	{
		int split=(int)((lb+ub)/2);
		if (mergeSort(dintemp,lb,split)==2) return 2;
		if (mergeSort(dintemp,split+1,ub)==2) return 2;
		return merge(dintemp,lb,split,ub);
	}
	return 0;	
}

int main(int argc,char **argv)
{
	if(argc<3)
	{
		printf("Too less parametrs.In and out files \n");
		exit(1);
	}
	FILE *handle=0;
	int	fnumb=argc-2;
	int	temp;
	int	schital;
	int ErrNum=0;
	struct dinmas sortmas={0,10,0};
	sortmas.mas=(int*)malloc(sortmas.maxlength*sizeof(int));
	if (sortmas.mas==NULL)
	{
		printf("Not avaliable memory for creating membuf");
		exit(1);
	}
	for( ; ErrNum==0 && fnumb!=0 && (handle=fopen(argv[fnumb],"r"));fnumb--)
	{
		while(EOF!=(schital=fscanf(handle,"%d",&temp)))
		{
			if(schital==0)
			{
				ErrNum=1;
				break;
			}
			if(sortmas.length==sortmas.maxlength)
			{
				sortmas.maxlength*=2;
				int *tempmas=(int*)realloc(sortmas.mas,sortmas.maxlength);
				if (tempmas==NULL)
				{
					ErrNum=2;
					break;
				}
				sortmas.mas=tempmas;
			}
			sortmas.mas[sortmas.length]=temp;
			sortmas.length++;
		}
		fclose(handle);
	}
	if(fnumb!=0 && ErrNum==0)
		ErrNum=3;
	if (ErrNum==0)
	//sortirovka(&sortmas);
		if (mergeSort(&sortmas,0,sortmas.length)==0)
			if(handle=fopen(argv[argc-1],"w"))
			{
				for(int i=0;i<sortmas.length;i++)
					fprintf(handle,"%d\n",sortmas.mas[i]);
				fclose(handle);
			}
			else	ErrNum=4;
	free(sortmas.mas);

	switch(ErrNum)
	{
		case 1:
			printf("Error input file format %s",argv[fnumb+1]);
			break;
		case 2:
			printf("Not avalliable free memory");
			break;
		case 3:
			printf("Can't open file %s",argv[fnumb]);
			break;
		case 4:
			printf("Can't open output file %s", argv[argc-1]);
		case 0:
			break;
	}
	return	0;
}
