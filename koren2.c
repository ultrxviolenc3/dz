#include <stdio.h>
#include <math.h>
int sgn(double x) {
if (x>0) return 1;
if (x<0) return -1;
return 0;
}
int kvadr(double b,double c,double *x1p,double *x2p)
{
double D;
D=b*b-4*c;
if(D<0) return 0;
*x1p=-(b+sgn(b)*sqrt(D))/2;
*x2p=-2*c/(b+sgn(b)*sqrt(D));
return 1;
}
int main ()
{
double b; double c; double x1p; double x2p; double x1,x2; 
while(1)
{printf("x1\n");
scanf("%lf",&x1);
printf("x2\n");
scanf("%lf",&x2);
b=-(x1+x2); c=x1*x2;
if(x1==0)
{ break;
	}
if( kvadr( b,c,&x1p,&x2p)==1)
{
printf("Absolutnaya x1 %0.20lg x2 %0.20lf\n",fabs(x1-x1p),fabs(x2-x2p));
printf("Otnosit x1 %0.20lg x2 %0.20lg\n",fabs((x1p/x1)-1),fabs((x2p/x2)-1));
}
else 
printf("Нет действительных корней\n");
}
return 0;
}
