#include <stdio.h>
#include <math.h>
double my_exp(double x)
{
double sum=1.0, h, eps=1.e-16; int i=2;
h=x;
do
{
sum+=h;
h*=x/i;
i++;
}
while( fabs(h)>eps );
return sum;
}
int main ()
{ 
	double x,y1,y2,abslr,otnr;
	FILE*fp=fopen("input1.txt","w");
	double mas[]={1,10,40,50,-1,-10,-40,-50,-65};
	fprintf(fp,"  x       exp(x)         Абс.погреш.     Относ.погреш.\n");
	fprintf(fp,"-------------------------------------------------------------\n");
	for(int i=0;i<9;i++)
	{
		x=mas[i];
		y1=my_exp(x);
		y2=exp(x);
		abslr=fabs(y2-y1);
		otnr=fabs((y2-y1)/y2);
		fprintf(fp,"%5.1lf |  %10.5le |  %12.7le |  %12.7le\n",x,y2,abslr,otnr);
		}
	return 0;
	}
