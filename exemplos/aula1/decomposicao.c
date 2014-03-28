#include <stdio.h>

void decomposicao(double x, long *part_int, double *part_frac) 
{
	*part_int = (long) x;
	*part_frac = x - *part_int;
}

int main(void) 
{
  	double numero, p_frac;
	long p_int;

	printf("Informe um numero: ");
	scanf("%lf", &numero);

	decomposicao(numero, &p_int, &p_frac);

  	printf("Parte inteira....: %ld\n", p_int);
  	printf("Parte fracionaria: %lf\n", p_frac);
	printf("\n\n");

  	return 0;
}
