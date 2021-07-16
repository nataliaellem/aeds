#include "Palavra.hpp"

Palavra::Palavra(string s) : _palavra(s), _ocorrencias(1) {
}

void Palavra::Incrementar() {
  _ocorrencias++;	
}

int Palavra::ocorrencias() const {
  return _ocorrencias;
}

string Palavra::palavra() const {
  return _palavra;
}

bool Palavra::operator<(Palavra& p) const {
  // Simplesmente retorna o valor do operador < da classe String.
	return palavra() < p.palavra();
}