#include <stdio.h>
void printBits_float(void *c)
{
int i; unsigned x;
x=*(unsigned *)c;
for(i=31; i>=0; i--)
{ if((x&((unsigned)1<<i))!=0) printf("1");
	else printf("0");
	if(i==31) printf(" ");
	if(i==23) printf(" ");
	}
}
int main ()
{
float a=0.0,b=0.0; //неопред 	
a=a/b;
printBits_float(&a); 
printf("\n");
printf("%lf",a);
return 0;
}
