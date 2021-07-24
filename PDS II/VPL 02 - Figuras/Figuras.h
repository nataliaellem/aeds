#ifndef FIGURAS_H
#define FIGURAS_H

#include <iostream>
#include <cmath>
#include <vector>

class Figure {
  public:   
    virtual bool contains(double x, double y) const = 0;
    virtual ~Figure() {}
};


class Rectangle: public Figure {
  public:
    Rectangle(double xx, double yy, double ll, double aa):
      _x(xx), _y(yy), _l(ll), _a(aa) {}

    bool contains(double x, double y) const {

      if (x >= this->_x && y >= this->_y){
        double x_largura = this->_x + this->_l;
        double y_altura = this->_y + this->_a;
        if (x <= x_largura && y <= y_altura){
          return true;
        }
      }
      return false;
    }
    const double _x; ///< Coordenada X do lado inferior-esquerdo do retangulo
    const double _y; ///< Coordenada Y do lado inferior-esquerdo do retangulo
    const double _l; ///< Largura do Retangulo
    const double _a; ///< Altura do Retangulo
};



class Circle: public Figure {
  public:
  
    Circle(double xx, double yy, double rr): _x(xx), _y(yy), _r(rr) {}
   
    bool contains(double x, double y) const {
      double distancia_x, distancia_y;
      if (this->_x >= x){
        distancia_x = this->_x - x;
      }
      else if (this->_x < x){
        distancia_x = x - this->_x;
      }
      if (this->_y >= y){
        distancia_y = this->_y - y;
      }
      else if (this->_y < y){
        distancia_y = y - this->_y;
      }
      double distancia = sqrt((distancia_x * distancia_x) + (distancia_y * distancia_y));
      if (distancia <= this->_r){
        return true;
      }
      return false;
    }
    const double _x; ///< Coordenada X do centro do circulo
    const double _y; ///< Coordenada Y do centro do circulo
    const double _r; ///< O raio do circulo
};

class CompositeFigure: public Figure {
  public:

    const Figure *_f1;
    const Figure *_f2;
    bool _op;

    CompositeFigure(const Figure& f1, const Figure& f2, bool op){
      this->_f1 = &f1;
      this->_f2 = &f2;
      this->_op = op;
    }

    bool contains(double x, double y) const {
      if (this->_op == true) { // Significa que as figuras vão ser somadas
        bool contains_f1 = this->_f1->contains(x, y);
        bool contains_f2 = this->_f2->contains(x, y);
        return (contains_f1 || contains_f2);
      }
      else { // Significa que é f1 - f2
        bool contains_f1 = this->_f1->contains(x, y);
        bool contains_f2 = this->_f2->contains(x, y);
        return (contains_f1 && !(contains_f2));
      }
    }

};


Figure* operator+(const Figure& lhs, const Figure& rhs) {
  
  CompositeFigure *f = new CompositeFigure(lhs, rhs, true);


  return f;
}


Figure* operator-(const Figure& lhs, const Figure& rhs) {

  CompositeFigure *f = new CompositeFigure(lhs, rhs, false);
  
  return f;
}

#endif