#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void heap(int mas[],int n,int i)
{ int big=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && mas[l]>mas[big])
	big=l;
	if(r<n && mas[r] > mas[big])
	big=r;
	if( big!=i)
	{ int t=mas[i];
		mas[i]=mas[big];
		mas[big]=t;
		heap(mas,n,big);
		
		}
	}
void sort( int mas[], int n)
{
	for( int i=n/2-1;i>=0;i--)
	heap(mas,n,i);
	for(int i=n-1; i>0;i--)
	{
		int t=mas[0];
		mas[0]=mas[i];
		mas[i]=t;
		heap(mas,i,0);
		}
	}
	int main()
	{  clock_t cstart,cend;
		FILE*fp=fopen("input.txt","w");
		 FILE*fout=NULL;
		int *mas=NULL;
		int n,i;
		printf("Введите количество элементов массива\n");
		scanf("%d",&n);
		for(i=1;i<=n/2;i++)
		{
			fprintf(fp,"%d %d ",i,-i);
			}
		mas=(int*)malloc(n*sizeof(int));
		fclose(fp);
		fp=fopen("input.txt","r");
		for(i=0;i<n;i++)
		{
			fscanf(fp,"%d",&mas[i]);
			
			}
			cstart=clock();
			sort(mas,n);
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
