#include <stdio.h>
#include "Complexo.h"

void criarComplexo(Complexo *c, double real, double imag){
	c->real = real;
	c->imag = imag;
}
void somarComplexo(Complexo *c1, Complexo *c2, Complexo *res){
	res->real = c1->real + c2->real;
	res->imag = (c1->imag + c2->imag);
}
void subtrairComplexo(Complexo *c1, Complexo *c2, Complexo *res){
	res->real = c1->real - c2->real;
	res->imag = (c1->imag - c2->imag);
}
void multiplicarComplexo(Complexo *c1, Complexo *c2, Complexo *res){
	res->real = ((c1->real * c2->real) - (c1->imag * c2->imag));
	res->imag = ((c1->real * c2->imag) + (c1->imag * c2->real));
}
void conjugadoComplexo(Complexo *c, Complexo *res){
	res->real = c->real;
	res->imag = - c->imag;
}
void imprimirComplexo(Complexo *res){
	printf("(%lf) + (%lf)i\n", res->real, res->imag);
}