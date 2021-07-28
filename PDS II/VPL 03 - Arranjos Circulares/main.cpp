#include <iostream>

#include "RingArray.h"

void fer_assert(const bool expr, const char* msg) {
  if (!expr) {
    std::cout << msg << std::endl;
    exit(1);
  }
}

template <class T, unsigned N>
void RingArray<T, N>::add(T value) {
  // TODO: implement this method.
  fer_assert(!this->isFull(), "Erro: anel cheio");
  
  this->buf[this->_last] = value;
  this->quantidade_elementos++;

  if (this->_last == N-2){ //Nesse caso já sabe-se que o array não está cheio
    this->_last = 0;
    return;
  }
  this->_last++;

}

template <class T, unsigned N>
T RingArray<T, N>::get() {
  // TODO: implement this method.
  fer_assert(!isEmpty(), "Erro: anel vazio.");
  T elemen = this->buf[_first];
  this->buf[_first] = -1;

  if (this->_first == N-2){
    this->_first = 0;
  }
  else {
    this->_first ++;
  }
  quantidade_elementos --;
  return elemen;
}

template <class T, unsigned N>
bool RingArray<T, N>::isFull() const {
  // TODO: implement this method.
  if (this->quantidade_elementos == N-1){
    return true;
  }
  
  return false;

}

template <class T, unsigned N>
bool RingArray<T, N>::isEmpty() const {
  // TODO: implement this method.
  if (this->quantidade_elementos == 0){
    return true;
  }
  return false;
}

template <class T>
void test_add_then_get() {
  RingArray<T, 8> r;
  T value;
  while (std::cin >> value) {
    r.add(value);
  }
  while (!r.isEmpty()) {
    std::cout << r.get() << std::endl;
  }
}

template <class T>
void test_add_or_get() {
  RingArray<T, 8> r;
  T value;
  char c;
  while (std::cin >> c) {
    if (c == '+') {
      std::cin >> value;
      r.add(value);
    } else if (c == '-') {
      std::cout << r.get() << std::endl;
    } else {
      std::cout << "Invalid operation\n";
    }
  }
}

int main () {
  char data;
  while (std::cin >> data) {
    switch (data) {
      case 'd': test_add_then_get<double>();
                break;
      case 's': test_add_then_get<std::string>();
                break;
      case 'D': test_add_or_get<double>();
                break;
      case 'S': test_add_or_get<std::string>();
                break;
      default: std::cout << "Invalid type\n";
    }
  }
  return 0;
}