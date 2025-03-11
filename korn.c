#include <stdio.h>
#include <math.h>
int kvadr(double b,double c,double *x1,double *x2)
{
double D;
D=b*b-4*c;
if(D<0) return 0;
*x1=(-b+sqrt(D))/2;
*x2=(-b-sqrt(D))/2;
return 1;
}
int main ()
{
double b; double c;  double x1,x2;
printf("Введите значение b\n");
scanf("%lf",&b);
printf("Введите значение c\n");
scanf("%lf",&c);
if( kvadr( b,c,&x1,&x2)==1)
{
printf("Корни квадратного уравнения x1=%lf x2=%lf\n",x1,x2);
}
else 
printf("Нет действительных корней\n");
return 0;
}
