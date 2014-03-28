#include "Racional.h"

void criar(Racional *rac, int num, int den){
	rac->den = den;
	rac->num = num;
}

void adicao(Racional *v1, Racional *v2, Racional *res){
	res->num = (v1->num * v2->den) + (v2->num * v1->den);
	res->den = v1->den * v2->den;
}

void multiplicacao(Racional *v1, Racional *v2, Racional *res){
	res->num = v1->num * v2->num;
	res->den = v1->den * v2->den;
}