#include <stdio.h>

void nao_troca(int x, int y) 
{
  	int aux;
  	aux = x;
  	x = y;
  	y = aux;
	printf("Dentro da funcao nao_troca: x = %d, y = %d\n", x, y);
}

int main(void) 
{
  	int x = 100, y = 200;
  	nao_troca(x, y);
  	printf("Na main: x = %d, y = %d\n", x, y);
	printf("\n\n");

  	return 0;
}
