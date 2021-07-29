/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include <typeinfo>
#include "polygon.h"

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {
  // TODO: implement this method.
  std::vector<Point> limits_lhs = lhs.operator const std::vector<Point, std::allocator<Point>> &();
  std::vector<Point> limits_rhs = rhs.operator const std::vector<Point, std::allocator<Point>> &();
  bool resp = false;
  int menor_x, menor_y, maior_x, maior_y;

  // Se lhs for um quadrado ou um retângulo, 
  // serão adicionados os pontos das outras vértices do quadrado/retângulo.

  if (typeid(lhs) == typeid(RightRectangle) || typeid(lhs) == typeid(RightSquare)){
    if (limits_lhs[0].x > limits_lhs[1].x){
      menor_x = limits_lhs[1].x;
      maior_x = limits_lhs[0].x;
    }
    else if (limits_lhs[0].x < limits_lhs[1].x){
      menor_x = limits_lhs[0].x;
      maior_x = limits_lhs[1].x;
    }

    if (limits_lhs[0].y > limits_lhs[1].y){
      menor_y = limits_lhs[1].y;
      maior_y = limits_lhs[0].y;
    }
    else if (limits_lhs[0].y < limits_lhs[1].y){
      menor_y = limits_lhs[0].y;
      maior_y = limits_lhs[1].y;
    }

    Point point1(maior_x, menor_y);
    Point point2(menor_x, maior_y);
    Point point3(menor_x, menor_y);
    Point point4(maior_x, maior_y);

    limits_lhs.push_back(point1);
    limits_lhs.push_back(point2);
    limits_lhs.push_back(point3);
    limits_lhs.push_back(point4);
  }

  // Se rhs for um quadrado ou um retângulo, 
  // serão adicionados os pontos das outras vértices do quadrado/retângulo.

  if (typeid(rhs) == typeid(RightRectangle) || typeid(rhs) == typeid(RightSquare)){
    if (limits_rhs[0].x > limits_rhs[1].x){
      menor_x = limits_rhs[1].x;
      maior_x = limits_rhs[0].x;
    }
    else if (limits_rhs[0].x < limits_rhs[1].x){
      menor_x = limits_rhs[0].x;
      maior_x = limits_rhs[1].x;
    }

    if (limits_rhs[0].y > limits_rhs[1].y){
      menor_y = limits_rhs[1].y;
      maior_y = limits_rhs[0].y;
    }
    else if (limits_rhs[0].y < limits_rhs[1].y){
      menor_y = limits_rhs[0].y;
      maior_y = limits_rhs[1].y;
    }

    Point point1(maior_x, menor_y);
    Point point2(menor_x, maior_y);    
    Point point3(menor_x, menor_y);
    Point point4(maior_x, maior_y);
    limits_rhs.push_back(point1);
    limits_rhs.push_back(point2);
    limits_rhs.push_back(point3);
    limits_rhs.push_back(point4);
  }

  for (int i = 0; i < limits_lhs.size(); i++){
    Point p = limits_lhs[i];
    for (int j = 0; j < limits_rhs.size(); j++){
      Point p2 = limits_rhs[j];
      if (p.contains(p2)){
        resp = true;
        break;
      }
      // Se estiver na ultima posição do vetor e não tiver encontrado um dos pontos do polígono lhs em rhs,
      // significa que os polígonos são diferentes
      if (j == limits_rhs.size() - 1){
        if (!p.contains(p2)){
          return false;
        }
      }
      else {
        resp = false;
      }
    }
  }

  for (int i = 0; i < limits_rhs.size(); i++){
    Point p = limits_lhs[i];
    for (int j = 0; j < limits_lhs.size(); j++){
      Point p2 = limits_rhs[j];
      if (p.contains(p2)){
        resp = true;
        break;
      }
      if (j == limits_lhs.size() - 1){
        if (!p.contains(p2)){
          return false;
        }
      }
      else {
        resp = false;
      }
    }
  }
  return resp;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {
  // TODO: implement this method.
  bool resp;
  if (this->limits[0].x > this->limits[1].x){
    resp = (p.x >= this->limits[1].x && p.x <= this->limits[0].x);
  }
  else {
    resp = (p.x >= this->limits[0].x && p.x <= this->limits[1].x);
  }

    if (this->limits[0].y > this->limits[1].y){
      resp = (p.y >= this->limits[1].y && p.y <= this->limits[0].y);
    }
    else {
      resp = (p.y >= this->limits[0].y && p.y <= this->limits[1].y);
    }
    return resp;
}

Point::Point(int xx, int yy): x(xx), y(yy) {
  // TODO: implement this method.
  this->limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  // TODO: implement this method.
  Point p1(x0, y0);
  Point p2(x1, y1);
  this->limits.push_back(p1);
  this->limits.push_back(p2);
}