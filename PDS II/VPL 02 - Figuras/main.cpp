#include <iostream>
#include <assert.h>     /* assert */

#include "Figuras.h"

/**
 * \brief Arquivo de testes.
 *
 * Atencao: este arquivo nao deve ser alterado! Sua alteracao (a fim de passar
 * pelos testes sem que o trabalhos seja efetivamente feito) pode inclusiver
 * levar a anulacao do trabalho entregue.
 */

void testaExemplo0() {
  Figure* A = new Rectangle(1, 1, 3, 3);
  Figure* B = new Circle(4.5, 2.5, 1.5);
  Figure* C = *A + *B;
  assert(C->contains(2.0, 2.0));
  assert(!C->contains(2.0, 0.0));
  Figure* D = *A - *B;
  assert(!D->contains(4.0, 2.0));
  assert(D->contains(2.0, 3.0));
  Figure* E = new Circle(3.5, 2.5, 1.5);
  Figure* F = new Rectangle(3, 0, 3, 3);
  Figure* G = *F - *E;
  assert(!G->contains(4.0, 2.0));
  assert(G->contains(5.0, 1.0));
  Figure* H = *D + *G;
  assert(!H->contains(4.0, 2.0));
  assert(H->contains(5.0, 1.0));
  assert(H->contains(2.0, 3.0));
  std::cout << "Teste 0 passa.";
  delete A;
  delete B;
  delete C;
  delete D;
  delete E;
  delete F;
  delete G;
  delete H;
}

void testaExemplo1() {
  Figure* f0 = new Rectangle(0, 3, 8, 2);
  Figure* f1 = new Rectangle(3, 0, 2, 8);
  Figure* f2 = new Circle(4, 4, 1);
  Figure* f3 = *f0 + *f1;
  Figure* f4 = *f3 - *f2;
  assert(f3->contains(4.0, 4.0));
  assert(!f4->contains(4.0, 4.0));
  assert(f4->contains(1.0, 4.0));
  assert(f4->contains(4.0, 7.0));
  assert(!f4->contains(6.0, 1.0));
  std::cout << "Teste 1 passa.";
  delete f0;
  delete f1;
  delete f2;
  delete f3;
  delete f4;
}

void testaExemplo2() {
  Figure* f0 = new Rectangle(1, 2, 5, 5);
  Figure* f1 = new Rectangle(2, 3, 3, 3);
  Figure* f2 = new Circle(3.5, 4.5, 3.5);
  Figure* f3 = new Circle(3.5, 4.5, 1.0);
  Figure* f4 = *f0 - *f1;
  Figure* f5 = *f2 - *f4;
  Figure* f6 = *f5 - *f3;
  assert(f6->contains(0.5, 4.0));
  assert(!f6->contains(1.5, 6.5));
  assert(!f6->contains(3.0, 5.0));
  assert(f6->contains(3.5, 1.5));
  std::cout << "Teste 2 passa.";
  delete f0;
  delete f1;
  delete f2;
  delete f3;
  delete f4;
  delete f5;
  delete f6;
}

void testaRetangulo() {
  double px, py, rx, ry, lado, altura;
  std::cin >> px >> py >> rx >> ry >> lado >> altura;
  // Vamos ler um retangulo com canto inferior esquerdo na coordenada
  // (rx, ry) e dimensoes dadas pelas variaveis lado e altura:
  Rectangle r(rx, ry, lado, altura);
  std::cout << r.contains(px, py) << std::endl;
}

void testaCirculo() {
  // Vamos ler um circulo de centro (cx, cy). O tamanho do circulo serah
  // definido pela variavel raio.
  double px, py, cx, cy, raio;
  std::cin >> px >> py >> cx >> cy >> raio;
  Circle c(cx, cy, raio);
  // Vamos verificar se o ponto (px, py) estah contido dentro do circulo
  std::cout << c.contains(px, py) << std::endl;
}

Figure* readFigure() {
  char figType;
  std::cin >> figType;
  switch (figType) {
    case 'r': {
      double rx, ry, lado, altura;
      std::cin >> rx >> ry >> lado >> altura;
      return new Rectangle(rx, ry, lado, altura);
    }
    case 'c': {
      double cx, cy, raio;
      std::cin >> cx >> cy >> raio;
      return new Circle(cx, cy, raio);
    }
    default:
      return NULL;
  }
}

void testaUniao() {
  double px, py;
  std::cin >> px >> py;
  Figure *f0 = readFigure();
  Figure *f1 = readFigure();
  Figure *f2 = *f0 + *f1;
  std::cout << f2->contains(px, py) << std::endl;
  delete f0;
  delete f1;
  delete f2;
}

void testaDiferenca() {
  double px, py;
  std::cin >> px >> py;
  Figure *f0 = readFigure();
  Figure *f1 = readFigure();
  Figure *ff = *f0 - *f1;
  std::cout << ff->contains(px, py) << std::endl;
  delete f0;
  delete f1;
  delete ff;
}

void testaQuatroOperacoes() {
  double px, py;
  std::cin >> px >> py;
  const Figure *f0 = readFigure();
  const Figure *f1 = readFigure();
  const Figure *f2 = readFigure();
  const Figure *f3 = readFigure();
  const Figure *f4 = *f0 - *f1;
  const Figure *f5 = *f2 - *f4;
  const Figure *f6 = *f5 - *f3;
  std::cout << f6->contains(px, py) << std::endl;
  delete f0;
  delete f1;
  delete f2;
  delete f3;
  delete f4;
  delete f5;
  delete f6;
}

void testaLoop() {
  const Figure *f0 = readFigure();
  const Figure *f1 = readFigure();
  const Figure *f2 = readFigure();
  const Figure *f3 = *f0 + *f1;
  const Figure *f4 = *f3 - *f2;
  for (double x = 0.0; x < 8.0; x += 1.0) {
    for (double y = 0.0; y < 8.0; y += 1.0) {
      std::cout << " " << f4->contains(x, y);
    }
  }
  std::cout << std::endl;
  delete f0;
  delete f1;
  delete f2;
  delete f3;
  delete f4;
}

int main() {
  char testType = 0;
  std::cin >> testType;
  switch (testType) {
    case 'r':
      testaRetangulo();
      break;
    case 'c':
      testaCirculo();
      break;
    case 'u':
      testaUniao();
      break;
    case 'd':
      testaDiferenca();
      break;
    case '0':
      testaExemplo0();
      break;
    case '1':
      testaExemplo1();
      break;
    case '2':
      testaExemplo2();
      break;
    case '4':
      testaQuatroOperacoes();
      break;
    case 'l':
      testaLoop();
      break;
    default:
      std::cout << "Teste desconhecido: " << testType << std::endl;
  }
}