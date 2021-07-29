/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include <typeinfo>
#include <cmath>
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
  if (typeid(rhs) == typeid(RightRectangle) || typeid(rhs) == typeid(Point) || typeid(rhs) == typeid(RightSquare)){
    for (Point p : limits_lhs){
      resp = rhs.contains(p);
    }
  }
  if (typeid(lhs) == typeid(RightRectangle) || typeid(lhs) == typeid(Point) || typeid(lhs) == typeid(RightSquare)){
    for (Point p : limits_rhs){
      resp = lhs.contains(p);
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

  Point p1(this->limits[0].x, this->limits[0].y);
  Point p2(this->limits[1].x, this->limits[1].y);
  int x3, x4, y3, y4;
  
  if (this->limits[0].x < this->limits[1].x){
    x3 = this->limits[0].x;
    x4 = this->limits[1].x;
  }
  else if (this->limits[1].x < this->limits[0].x){
    x3 = this->limits[1].x;
    x4 = this->limits[0].x;
  }
  else if (this->limits[1].x == this->limits[0].x){
    x3 = this->limits[1].x;
    x4 = this->limits[1].x;
  }

  if (this->limits[0].y < this->limits[1].y){
    y4 = this->limits[0].y;
    y3 = this->limits[1].y;
  }
  else if (this->limits[1].y < this->limits[0].y){
    y4 = this->limits[1].y;
    y3 = this->limits[0].y;
  }
  else if (this->limits[1].y == this->limits[0].y){
    y4 = this->limits[1].y;
    y3 = this->limits[1].y;
  }
  
  Point p3(x3, y3);
  Point p4(x4, y4);

  // p1, p2, p3 e p4 são os quatro pontos que compõem o retângulo
  return (p.contains(p1) || p.contains(p2) || p.contains(p3) || p.contains(p4));
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