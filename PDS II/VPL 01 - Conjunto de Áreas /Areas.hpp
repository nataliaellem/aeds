#ifndef AREAS_H
#define AREAS_H

#include <map>
#include <string>
#include <vector>
#include <iostream>


template <class T> class AreaSet {
  std::vector<T> areas;
  public:

    void add(T e) {
      this->areas.push_back(e);
    }

    int getTotalArea() const {
      int total = 0;
      for (T elem : areas){
        total += elem.getArea();
      }
      return total;
    }
};


class Pais {

  std::string nome;
  int area;
  public:

    Pais(std::string n = "Brasil", int a=8515767): nome(n), area(a) {}
   
    int getArea() const {
      return this->area;
    }
   
    std::string getNome() const {
      return this->nome;
    }
   
    friend std::istream &operator >> (std::istream &input, Pais &p) {
      input >> p.nome >> p.area;
      return input;
    }
    
    friend std::ostream &operator << (std::ostream &output, Pais &p) {
      output << p.nome << " contem " << p.area << "km^2";
      return output;
    }
};


class Retangulo {
  int lado;
  int altura;
  public:
    
    Retangulo(int l=0, int a=0) {
      this->lado = l;
	  	this->altura = a;
    }
		
    int getArea() const {
	  	int area = (this->lado) * (this->altura);
      return area;
    }
    
    friend std::istream &operator >> (std::istream &input, Retangulo &r) {
      input >> r.lado >> r.altura;
      return input;
    }
   
    friend std::ostream &operator << (std::ostream &output, Retangulo &r) {
      output << "Rect(" << r.lado << " * " << r.altura << ")";
      return output;
    }
};


class Imovel {
  std::map<std::string, int> comodos; 
  public:
    
    int getArea() const {
			int area = 0;
      for (auto iter = comodos.begin(); iter != comodos.end(); iter++){
				int a = iter->second;
				area += a;
			}
      return area;
    }
    
    void addComodo(std::string nomeComodo, int areaComodo) {
      unsigned int numComodos = comodos.size();
      std::string nomeChave = nomeComodo + "_" + std::to_string(numComodos);
      comodos[nomeChave] = areaComodo;
    }
    
    friend std::istream &operator >> (std::istream &input, Imovel &m) {
      int numComodos;
      input >> numComodos;
      for (int i = 0; i < numComodos; i++) {
        std::string nomeComodo;
        int areaComodo;
        input >> nomeComodo >> areaComodo;
        m.addComodo(nomeComodo, areaComodo);
      }
      return input;
    }
    
    friend std::ostream& operator << (std::ostream& output, const Imovel& im) {
      for (auto iter = im.comodos.begin(); iter != im.comodos.end(); ++iter) {
        output << iter->first << ": " << iter->second << std::endl;
      }
      return output;
    }
};

#endif