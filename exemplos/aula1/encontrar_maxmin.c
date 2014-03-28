#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min); 

int main(void) 
{
	int b[N], i, maior, menor;

	printf("Informe %d numeros: ", N);
	for (i = 0; i < N; i++)
		scanf("%d",&b[i]);

	max_min(b, N, &maior, &menor);

	printf("Maior: %d\n", maior);
	printf("Menor: %d\n", menor);
	printf("\n");

  	return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
	int i;

	*max = *min = a[0];

	for (i = 0; i < n; i++) {
		if (a[i] > *max)
			*max = a[i];
		else if (a[i] < *min)
			*min = a[i];
	}

}

