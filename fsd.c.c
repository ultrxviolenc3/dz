#include <stdio.h>
void printBits_double(void *a) //функция которая представляет числа с плавающей точкой в битовом представлении
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
int main(void)
{
double x=1.0, b,c; int i=0;
do
{
printf("%d: %le\n",i,x);
printBits_double(&x); printf("\n"); //вызов функции печати битового представления  для х
b=1+x; //считаем b 
printBits_double(&b); printf("\n");//вызов функции печати битового представления  для х
x/=2.0; i--; //делим переменную х на 2 уменьшая ее степень на 1
c=1+x;
}
while( c>1.0 );//цикл будет выполняться пока х не равен 0 или с>1
b=1+x; 
printBits_double(&b); printf("\n");
return 0;
}
