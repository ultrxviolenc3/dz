#include <stdio.h>
#include <math.h>
int nf; 
int sign(double x)
{
if(x>0)return 1;
else if(x<0)return -1;
return 0;
}
double g1(double x)
{
nf++;
return (x-1)*(x-1)*(x-1)*(x-1)*(x-1)*(x-1)-1;
}
double g5(double x)
{
nf++;
return exp(x*x+7*x-30)-1;
}
double g11(double x)
{
nf++;
return x*x*x+log(1+x);
}
int root_bis(double *x, double a, double b,
double (*f)(double), double epsilon)
{
double fa,fb,fc,c;
int ifa,ifb,ifc,k;
fa=f(a); fb=f(b);
if(fabs(fa)<epsilon){*x=a; return 1;}
if(fabs(fb)<epsilon){*x=b; return 1;}
ifa=sign(fa); ifb=sign(fb);
if(ifa*ifb != -1) return 0;
for(k=1; fabs(b-a)>epsilon && fabs(b-a)>epsilon*fabs(a+b)/2; k++)
{
c=(a+b)/2;
fc=f(c); ifc=sign(fc);
if(fabs(fc)<epsilon){*x=c; return k+1;}
if(ifc*ifa==1){a=c; fa=fc;}
else {b=c; fb=fc;}
}
*x=c; 
return k; 
}
int main()
{
	FILE*fp=fopen("output2.txt","w");
double x; int res1,res5,res11; 
double x1=2.0,x5=3.0,x11=0.0;
nf=0;
res1=root_bis(&x,1,3,g1,1.e-15);
fprintf(fp,"Задание номер 2\n");
if(res1)
{
fprintf(fp,"x=%lg\nчисло итераций=%d\n",x,res1-1);
fprintf(fp,"число обращений к функции=%d\n",nf);
fprintf(fp,"абсолютная погрешность=%lg\nотносительная погрешность=%lg\n",fabs(x1-x),fabs(x/x1-1));
}
else
{
fprintf(fp,"метод не применим\n");
}
nf=0;
res5=root_bis(&x,2,4,g5,1.e-15);
fprintf(fp,"Задание номер 9\n");
if(res5)
{
fprintf(fp,"x=%lg\nчисло итераций=%d\n",x,res5-1);
fprintf(fp,"число обращений к функции=%d\n",nf);
fprintf(fp,"абсолютная погрешность=%lg\nотносительная погрешность=%lg\n",fabs(x5-x),fabs(x/x5-1));
}
else
{
fprintf(fp,"метод не применим\n");
}
nf=0;
res11=root_bis(&x,0,1,g11,1.e-15);
fprintf(fp,"Задание номер 13\n");
if(res11)
{
fprintf(fp,"x=%lg\nчисло итераций=%d\n",x,res11-1);
fprintf(fp,"число обращений к функции=%d\n",nf);
fprintf(fp,"абсолютная погрешность=%lg\nотносительная погрешность=%lg\n",fabs(x11-x),fabs(x/x11-1));
}
else
{
fprintf(fp,"метод не применим\n");
}
return 0;
}
