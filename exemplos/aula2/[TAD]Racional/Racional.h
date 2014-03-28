#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED

typedef struct ${
	int num;
	int den;
} Racional;

void criar(Racional *rac, int num, int den);
void adicao(Racional *v1, Racional *v2, Racional *res);
void multiplicacao(Racional *v1, Racional *v2, Racional *res);

#endif // RACIONAL_H_INCLUDED