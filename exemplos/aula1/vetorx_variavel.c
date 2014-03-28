#include <stdio.h>

void altera(int vet[], int x)
{
  	vet[0] = -1;
  	x = -1;
}


int main(void)
{
  	int vet[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  	int x = 0;

  	altera(vet, x);
  	printf("vet[0] = %d\n", vet[0]);
  	printf("x = %d", x);

  	return 0;
}
