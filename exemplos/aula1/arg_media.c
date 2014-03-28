#include <stdio.h>
#include <stdlib.h> 

int main (int argc, char *argv[])
{
	int a, b;

	if (argc != 3) {   /* testa qtde de parâmetros */
		printf("Qtde de parâmetros inválida!\n");
		return -1;
	}

	a = atoi(argv[1]);   /* converte arg. 2 para int */
	b = atoi(argv[2]);   /* converte arg. 3 para int */

	printf("media = %d\n", (a+b)/2);

	return 0;
}
