#include <stdio.h>
#include <stdlib.h>

#include "Complexo.h"

int main(){
	Complexo c1, c2, c_res;

	criarComplexo(&c1, 5, 8);
	criarComplexo(&c2, 1, 2);

	somarComplexo(&c1, &c2, &c_res);
	imprimirComplexo(&c_res);

	subtrairComplexo(&c1, &c2, &c_res);
	imprimirComplexo(&c_res);

	multiplicarComplexo(&c1, &c2, &c_res);
	imprimirComplexo(&c_res);

	conjugadoComplexo(&c1, &c_res);
	imprimirComplexo(&c_res);		

	return 0;
}