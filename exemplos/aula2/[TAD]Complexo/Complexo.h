#ifndef COMPLEXO_H_INCLUDED
#define COMPLEXO_H_INCLUDED

typedef struct ${
	double real;
	double imag;
} Complexo;

void criarComplexo(Complexo *c, double real, double imag);
void somarComplexo(Complexo *c1, Complexo *c2, Complexo *res);
void subtrairComplexo(Complexo *c1, Complexo *c2, Complexo *res);
void multiplicarComplexo(Complexo *c1, Complexo *c2, Complexo *res);
void conjugadoComplexo(Complexo *c, Complexo *res);
void imprimirComplexo(Complexo *res);

#endif // COMPLEXO_H_INCLUDED