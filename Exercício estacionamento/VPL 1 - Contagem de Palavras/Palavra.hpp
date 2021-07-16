#ifndef PALAVRA_H
#define PALAVRA_H

#include <string>

using std::string;

// Representa uma palavra que aparece no texto.
class Palavra {
  public:
	  // Cria uma palavra com uma ocorrência.
	  Palavra(string s);

		// Incrementa o número de ocorrências de uma palavra.
	  void Incrementar();

    // Retorna uma string que representa a palavra.
    string palavra() const;

		// Retorna o número de ocorrências da palavra.
		int ocorrencias() const;

    // Testa se a palavra do objeto é lexicograficamente menor que p.
		// OBS: Isso é importante na hora de ordenar as palavras.
    bool operator<(Palavra& p) const;

  private:
    // String que representa uma palavra.
	  string _palavra;

		// Número de ocorrências da palavra no texto.
	  int _ocorrencias;
};

#endif  // PALAVRA_H