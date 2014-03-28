#include <stdio.h>
#include <stdlib.h>

#include "Racional.h"

int main(){
	Racional r1, r2, r3, r4;

	criar(&r1, 1, 2);
	criar(&r2, 1, 2);

	adicao(&r1, &r2, &r3);
	printf("%d/%d\n", r3.num, r3.den);

	multiplicacao(&r1, &r2, &r4);
	printf("%d/%d\n", r4.num, r4.den);	

	return 0;
}