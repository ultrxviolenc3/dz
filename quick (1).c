#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quick(int *mas,int l,int r)
{ if(l>=r)
	{return;}
	int pivot=mas[(l+r)/2];
	int i=l;
	int j=r;
	int t;
	while(i<=j)
	{
		while(mas[i]<pivot) i++; 
		while(mas[j]>pivot)j--;
		if(i<=j)
		{
			t=mas[i];
			mas[i]=mas[j];
			mas[j]=t;
			i++;
			j--;
			}
		}
	if(l<j)
	quick(mas,l,j);
	if(r>i)
	quick(mas,i,r);
	}
int main()
	{  clock_t cstart,cend;
		FILE*fp=fopen("input.txt","w");
		 FILE*fout=NULL;
		int *mas=NULL;
		int n,i;
		int a;
printf("Введите количество элементов\n");
		scanf("%d",&n);
		printf("Выберите какой массив будет сортироваться\n 1.Массив вида 1 -1 2 -2 3 -3\n 2.Массив со случайными числами\n");
		scanf("%d",&a);
		switch(a)
		{ case 1: 
			for(i=1;i<=n/2;i++)
		      {
			      fprintf(fp,"%d %d ",i,-i);
			      } 
			case 2:
			   srand(time(NULL));
		       for(i=0;i<=n;i++)
		     {
                 fprintf(fp,"%d ",rand()); 
                 }
			}
		mas=(int*)malloc(n*sizeof(int));
		fclose(fp);
		fp=fopen("input.txt","r");
		for(i=0;i<n;i++)
		{
			fscanf(fp,"%d",&mas[i]);
			
			}
			cstart=clock();
			quick(mas,0,n-1);
			cend=clock();
			double t=((double)(cend-cstart))/CLOCKS_PER_SEC;
			fout=fopen("output.txt","w");
		for(int i=0; i<n;i++)
		{
			fprintf(fout,"%d ",mas[i]);
			}
			printf("Время сортировки\n");
			printf(" %f",t);
			return 0;
		}
