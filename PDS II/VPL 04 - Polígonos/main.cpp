/**
 * Este arquivo nao deve ser editado! Ele somente executa os testes.
 */
#include <iostream>

#include "polygon.h"

Point* readPoint() {
  int x, y;
  std::cin >> x;
  std::cin >> y;
  return new Point(x, y);
}

RightRectangle* readRectangle() {
  int botLeftX, botLeftY, topRightX, topRightY;
  std::cin >> botLeftX;
  std::cin >> botLeftY;
  std::cin >> topRightX;
  std::cin >> topRightY;
  RightRectangle *r =
    new RightRectangle(botLeftX, botLeftY, topRightX, topRightY);
  return r;
}

RightSquare* readSquare() {
  int botLeftX, botLeftY, side;
  std::cin >> botLeftX;
  std::cin >> botLeftY;
  std::cin >> side;
  RightSquare *s = new RightSquare(botLeftX, botLeftY, side);
  return s;
}

void readPolygons(std::vector<Polygon*>& polygons) {
  char type;
  while (std::cin >> type) {
    switch(type) {
      case 'p':
        polygons.push_back(readPoint());
        break;
      case 'r':
        polygons.push_back(readRectangle());
        break;
      case 's':
        polygons.push_back(readSquare());
        break;
      default:
        std::cerr << "Invalid type\n";
        exit(1);
    }
  }
}

unsigned testCountContainsOrigin() {
  std::vector<Polygon*> polygons;
  readPolygons(polygons);
  Point origin(0, 0);
  unsigned count = 0;
  for (Polygon *p: polygons) {
    if (p->contains(origin)) {
      count++;
    }
  }
  return count;
}

unsigned testCountSquare(RightSquare *s) {
  std::vector<Polygon*> polygons;
  readPolygons(polygons);
  unsigned count = 0;
  for (Polygon *p: polygons) {
    if (*p == *s) {
      count++;
    }
  }
  return count;
}

unsigned hasEqualFigures() {
  std::vector<Polygon*> polygons;
  readPolygons(polygons);
  for (unsigned i = 0; i < polygons.size() - 1; i++) {
    for (unsigned j = i+1; j < polygons.size(); j++) {
      if (*polygons[i] == *polygons[j]) {
        return true;
      }
    }
  }
  return false;
}

int main () {
  char type;
  std::cin >> type;
  switch (type) {
    case 'o':
      std::cout << testCountContainsOrigin();
      break;
    case 's':
      std::cout << testCountSquare(new RightSquare(-2, -2, 4));
      break;
    case 'e':
      std::cout << hasEqualFigures();
      break;
    default: std::cerr << "Invalid type\n";
  }
  return 0;
}