#include <iostream>

#include "Areas.hpp"

void testaRetangulos() {
  Retangulo r0(4, 10);
  Retangulo r1(8, 2);
  AreaSet<Retangulo> areas;
  areas.add(r0);
  areas.add(r1);
  std::cout << areas.getTotalArea() << std::endl;
}

void testaPaises() {
  Pais russia("Russia", 17098246);
  Pais brasil("Brasil", 8515767);
  AreaSet<Pais> areas;
  areas.add(russia);
  areas.add(brasil);
  std::cout << areas.getTotalArea() << std::endl;
}

void testaUmImovel() {
  Imovel imovel;
  imovel.addComodo("sala", 35);
  imovel.addComodo("quarto", 20);
  imovel.addComodo("quarto", 24);
  imovel.addComodo("banheiro", 6);
  imovel.addComodo("banheiro", 5);
  imovel.addComodo("cozinha", 22);
  std::cout << imovel.getArea() << std::endl;
}

void testaDoisImoveis() {
  AreaSet<Imovel> areas;
  Imovel i0;
  i0.addComodo("sala", 35);
  i0.addComodo("quarto", 20);
  i0.addComodo("quarto", 24);
  i0.addComodo("banheiro", 6);
  i0.addComodo("banheiro", 5);
  i0.addComodo("cozinha", 22);
  areas.add(i0);
  Imovel i1;
  i1.addComodo("copa", 26);
  i1.addComodo("quarto", 26);
  i1.addComodo("quarto", 19);
  i1.addComodo("quarto", 18);
  i1.addComodo("banheiro", 6);
  i1.addComodo("banheiro", 5);
  i1.addComodo("banheiro", 5);
  i1.addComodo("cozinha", 16);
  i1.addComodo("sala", 40);
  areas.add(i1);
  std::cout << areas.getTotalArea() << std::endl;
}

template <class T>
void testaAreaMultiplosObjetos() {
  AreaSet<T> areas;
  int numObjetos = 0;
  std::cin >> numObjetos;
  for (int i = 0; i < numObjetos; ++i) {
    T aux;
    std::cin >> aux;
    areas.add(aux);
  }
  std::cout << areas.getTotalArea() << std::endl;
}

template <class T>
void testaLeituraObjetos() {
  T aux;
  std::cin >> aux;
  std::cout << aux << std::endl;
}

int main() {
  char testType = 0;
  std::cin >> testType;
  switch (testType) {
    case '1':
      testaPaises();
      break;
    case '2':
      testaRetangulos();
      break;
    case '3':
      testaUmImovel();
      break;
    case '4':
      testaDoisImoveis();
      break;
    case 'a':
      testaLeituraObjetos<Retangulo>();
      break;
    case 'b':
      testaLeituraObjetos<Pais>();
      break;
    case 'c':
      testaLeituraObjetos<Imovel>();
      break;
    case 'r':
      testaAreaMultiplosObjetos<Retangulo>();
      break;
    case 'p':
      testaAreaMultiplosObjetos<Pais>();
      break;
    case 'i':
      testaAreaMultiplosObjetos<Imovel>();
      break;
    default:
      std::cout << "Teste desconhecido: " << testType << std::endl;
  }
}