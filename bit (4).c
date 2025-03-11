#include <stdio.h>
void printBits_float(void *a)
{
int i; unsigned x;
x=*(unsigned *)a;
for(i=31; i>=0; i--)
{ if((x&((unsigned)1<<i))!=0) printf("1");
	else printf("0");
	if(i==31) printf(" ");
	if(i==23) printf(" ");
	}
}
void printBits_double(void *a)
{
	int i; unsigned long long x;
	x=*(unsigned long long *)a;
	for(i=63;i>=0;i--)
	{ if((x & ((unsigned long long)1<<i))!=0) printf("1");
		else printf("0");
		if(i==63) printf(" ");
		if(i==52) printf(" ");
		}
	}
int main ()
{
float a=0.1875; double c=0.1875;
float b=3.2; double d=3.2;
printf("Число %.4lf тип float\n",a);
printBits_float(&a);
printf("\n");
printf("Число %.1lf тип float\n",b);
printBits_float(&b);
printf("\n");
printf("Число %.4lf тип double\n",c);
printBits_double(&c);
printf("\n");
printf("Число %.1lf тип double\n",d);
printBits_double(&d);
return 0;
}
