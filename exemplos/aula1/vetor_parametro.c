#include <stdio.h>

#define N_ELEM_1 3
#define N_ELEM_2 4

void le_vet(int vet[], int n_elem)
{
  	int i;
  	for (i = 0; i < n_elem; i++)
	{
    		printf("vet[%d]: ", i);
    		scanf("%d", &vet[i]);
  	}
}

void escreve_vet(int vet[], int n_elem)
{
  	int i;
  	for (i = 0; i < n_elem; i++)
    		printf("vet[%d]: %d\n", i, vet[i]);
}

int main(void)
{
  	int vet1[N_ELEM_1];
  	int vet2[N_ELEM_2];

  	printf("Digite os dados do primeiro vetor\n");
  	le_vet(vet1, N_ELEM_1);

  	printf("\nDigite os dados do segundo vetor\n");
  	le_vet(vet2, N_ELEM_2);

  	printf("\nPrimeiro vetor\n");
  	escreve_vet(vet1, N_ELEM_1);

  	printf("\nSegundo vetor\n");
  	escreve_vet(vet2, N_ELEM_2);

  	return 0;
}
