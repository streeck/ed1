#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *vetor1, *vetor2;
	int n, i;
	printf("Digite o tamanho dos vetores: ");
	scanf("%d", &n);
	
	vetor1 = (int *) malloc (n*sizeof(int));
 	if (vetor1 == NULL)
	{	
		printf("Memoria nao alocada");
		exit(1);
	}
	
	// zera elementos do vetor1
	for(i=0; i<n; i++)
		vetor1[i] = 0;
	
	vetor2 = (int *) calloc (n, sizeof(int));
 	if (vetor2 == NULL)
	{	
		printf("Memoria nao alocada");
		exit(1);
	}
	
	// imprime elementos do vetor1
	for(i=0; i<n; i++)
		printf("%d ", vetor1[i]);

	printf("\n");

	// imprime elementos do vetor2
	for(i=0; i<n; i++)
		printf("%d ", vetor2[i]);

	printf("\n");
	
	free(vetor1);
	free(vetor2);
	return 0;
}
