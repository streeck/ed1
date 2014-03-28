#include <stdio.h>

struct ponto {
  double x;
  double y;
};

typedef struct ponto Ponto;


void nao_troca(Ponto p1, Ponto p2) {
  Ponto aux;
  aux = p1;
  p1 = p2;
  p2 = aux;
}


void troca(Ponto *p1, Ponto *p2) {
  Ponto aux;
  aux = *p1;
  *p1 = *p2;
  *p2 = aux;

}

int main() {
  Ponto p1, p2;

  p1.x = 0.0;
  p1.y = 0.0;

  p2.x = 5.0;
  p2.y = 5.0;

  nao_troca(p1, p2);
  printf("p1.x = %.3lf p1.y = %.3lf\n", p1.x, p1.y);
  printf("p2.x = %.3lf p2.y = %.3lf\n", p2.x, p2.y);

  troca(&p1, &p2);
  printf("p1.x = %.3lf p1.y = %.3lf\n", p1.x, p1.y);
  printf("p2.x = %.3lf p2.y = %.3lf\n", p2.x, p2.y);

  return 0;
}
