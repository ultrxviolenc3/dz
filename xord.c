#include <stdio.h>
#include <math.h>
int nf; 
int sign(double x)
{
if(x>0)return 1;
else if(x<0)return -1;
return 0;
}
double g2(double x)
{
nf++;
return x*x*x+4*x*x-10;
}
double g9(double x)
{
nf++;
return x*x +(x-1)*(x-1)*(x-1)*(x-1)*(x-1);
}
double g13(double x)
{
nf++;
return x*x*x*x-sin(x);
}
int root_chords(double *x, double a, double b,
double (*f)(double), double epsilon)
{
double fa,fb,fc,c[2];
int i=0,ifa,ifb,ifc,k;
c[0]=a; c[1]=b; fa=f(a); fb=f(b);
if(fabs(fa)<epsilon){*x=a; return 1;}
if(fabs(fb)<epsilon){*x=b; return 1;}
ifa=sign(fa); ifb=sign(fb);
if(ifa*ifb != -1) return 0;
for(k=1; fabs(c[1]-c[0])>epsilon; k++)
{
i=!i;
c[i]=(a*fb-b*fa)/(fb-fa);
fc=f(c[i]); ifc=sign(fc);
if(fabs(fc)<epsilon){*x=c[i]; return k+1;}
if(ifc*ifa==1){a=c[i]; fa=fc;}
else {b=c[i]; fb=fc;}
}
*x=c[i]; 
return k; 
}
int main()
{
	FILE*fp=fopen("output1.txt","w");
double x; int res2,res9,res13; 
double x2=1.3652300134140969,x9=0.3459548158482420,x13=0.0;
nf=0;
res2=root_chords(&x,0,2,g2,1.e-15);
fprintf(fp,"Задание номер 2\n");
if(res2)
{
fprintf(fp,"x=%lg\nчисло итераций=%d\n",x,res2-1);
fprintf(fp,"число обращений к функции=%d\n",nf);
fprintf(fp,"абсолютная погрешность=%lg\nотносительная погрешность=%lg\n",fabs(x2-x),fabs(x/x2-1));
}
else
{
fprintf(fp,"метод не применим\n");
}
nf=0;
res9=root_chords(&x,0,2,g9,1.e-15);
fprintf(fp,"Задание номер 9\n");
if(res9)
{
fprintf(fp,"x=%lg\nчисло итераций=%d\n",x,res9-1);
fprintf(fp,"число обращений к функции=%d\n",nf);
fprintf(fp,"абсолютная погрешность=%lg\nотносительная погрешность=%lg\n",fabs(x9-x),fabs(x/x9-1));
}
else
{
fprintf(fp,"метод не применим\n");
}
nf=0;
res13=root_chords(&x,0,1,g13,1.e-15);
fprintf(fp,"Задание номер 13\n");
if(res13)
{
fprintf(fp,"x=%lg\nчисло итераций=%d\n",x,res13-1);
fprintf(fp,"число обращений к функции=%d\n",nf);
fprintf(fp,"абсолютная погрешность=%lg\nотносительная погрешность=%lg\n",fabs(x13-x),fabs(x/x13-1));
}
else
{
fprintf(fp,"метод не применим\n");
}
return 0;
}
