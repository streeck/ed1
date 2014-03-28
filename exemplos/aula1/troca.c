#include <stdio.h>

void troca(int *end_x, int *end_y) 
{
  	int aux;
  	aux = *end_x;
  	*end_x = *end_y;
  	*end_y = aux;
	printf("Dentro da funcao troca: x = %d, y = %d\n", *end_x, *end_y);
}

int main(void) 
{
  	int x = 100, y = 200;
	troca(&x, &y);
  	printf("Na main: x = %d, y = %d\n", x, y);
	printf("\n\n");

  	return 0;
}
