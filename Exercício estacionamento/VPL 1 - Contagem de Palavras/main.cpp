#include <iostream>
#include <string>
#include "ContadorDePalavras.hpp"

using std::cin;
using std::cin;

int main() {
  ContadorDePalavras contador;
  string s;
  cin >> s;
  while (s != ".") {
    contador.Adicionar(s);
    cin >> s;
  }
  contador.ImprimirOrdenado();
  return 0;
}