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
  if (typeid(rhs) == typeid(RightRectangle)){
    

  }
  else if (typeid(rhs) == typeid(RightSquare)){

  }
  else if (typeid(rhs) == typeid(Point)){
    
  }
  return false;
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
  

  
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  // TODO: implement this method.
  Point p1(x0, y0);
  Point p2(x1, y1);
  this->limits.push_back(p1);
  this->limits.push_back(p2);
}