#pragma once

#include <string>

using std::string;

struct No;

class FilaDePrioridade {
 public:
  FilaDePrioridade();

  string primeiro() const;

  int tamanho() const;

  bool vazia() const;

  void RemoverPrimeiro();

  void Inserir(int p, string s);

  void Limpar();

 private:
  int tamanho_;  

  No* primeiro_;  
};