#include <stdio.h>
#include <math.h>
double mysin(double x)
{ double sum=0.0,eps=1.e-16,h;	
	int i=0;
	h=x;
	do
	{ sum+=h;
		h=(-x*x/((2*i+2)*(2*i+3)))*h;
		i++;
		}
	while(fabs(h)>eps);
	return sum;
	
	}
	int main ()
	{
		double x[]={1,2,3,10,20,40,50,-1,-2,-3,-10,-20,-40,-50}; 
		double t; 
		double c; double absl; double otn;
		FILE*f=fopen("output2.txt","w");
		fprintf(f," x                 sin(x)            Абс.погреш.          Отн.погреш\n");    
		fprintf(f,"--------------------------------------------------------------------------\n");
		for(int i=0;i<14;i++)
		{ c=mysin(x[i]);
			t=sin(x[i]);
			absl=fabs(c-t);
			if(t!=0)
			{
				otn=fabs((c/t)-1);
				}
			else otn=0;
			fprintf(f," %-10lg| %-20lg| %-20lg| %-20lg\n",x[i],c,absl,otn);
			
			}
		return 0;
		}
