#ifndef CONTADOR_DE_PALAVRAS_H
#define CONTADOR_DE_PALAVRAS_H

#include <list>

#include "Palavra.hpp"

using std::list;

// Implementa um contador de palavras
class ContadorDePalavras {
  public:
	  // Inicializa o contador com uma lista vazia de palavras.
	  ContadorDePalavras();

		// Adiciona uma *ocorrência* da palavra armazenada em s.
	  void Adicionar(string s);

		// Imprime as palavras ordenadas lexicograficamente,
		// seguidas do número de ocorrências registradas.
	  void ImprimirOrdenado();
  private:
	  // Lista *ordenada* de palavras.
	  list<Palavra> _lista_de_palavras;
};

#endif  // CONTADOR_DE_PALAVRAS_H