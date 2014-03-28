/* Inverte uma série numérica (versão com ponteiros) */

#include <stdio.h>

#define N 10

int main (void)
{
	int a[N], *p;

	printf("Informe %d números: ", N);
	for (p = a; p < a + N; p++)
		scanf("%d", p);

	printf("Em ordem inversa:");
	for (p = a + N - 1; p >= a; p--)
		printf(" %d", *p);
	printf("\n");

	return 0;
}
