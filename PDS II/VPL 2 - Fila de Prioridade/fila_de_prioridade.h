#pragma once

#include <string>

using std::string;

// Este módulo implementa uma fila de prioridade.
// Os elementos da fila são std::string, e estão associados a uma dada prioridade.
// As prioridades são inteiros maiores ou iguais a zero.
// O item com a maior prioridade é o primeiro da fila.
// OBS: Os itens são armazenados na memória em uma lista encadeada.

// Define como cada nó da lista encadeada é implementado.
// Cada nó armazena um elemento da fila e sua respectiva prioridade.
// É definido aqui, mas só é implementado no arquivo FilaDePrioridade.cpp
struct No;

class FilaDePrioridade {
 public:
  // Constrói uma fila vazia.
  FilaDePrioridade();

  // Retorna o elemento de maior prioridade.
  // PRECONDIÇÃO: a fila tem pelo menos um elemento.
  string primeiro() const;

  // Retorna o número de elementos na fila.
  int tamanho() const;

  // Testa se a fila está vazia.
  bool vazia() const;

  // Remove o elemento de maior prioridade.
  // PRECONDIÇÃO: a fila tem pelo menos um elemento.
  void RemoverPrimeiro();

  // Insere um elemento s fila com prioridade p;
  // OBS: Pode haver repetição de elementos.
  // Neste caso, os elementos podem ter prioridades iguais ou diferentes. 
  void Inserir(int p, string s);

  // Remove todos os elementos da fila.
  void Limpar();

 private:
  // Número de elementos da fila.
  int tamanho_;  

  // Ponteiro para o primeiro da lista encadeada. 
  // Quando tamanho_ == 0, o valor deste ponteiro é nullptr.
  No* primeiro_;  
};