/**
 * Este arquivo nao deve ser editado. Ele contem as definicoes das
 * operacoes que devem ser implementadas.
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

// Forward declaration of Point. It's necessary because Point is used in the
// definition of class Polygon. However, Polygon is also used in the definition
// of Point (due to the inheritance).
class Point;

/**
 * \class Polygon
 *
 * \brief Implementation of a Polygon Abstract Data Type. A polygon is formed
 * by a set of points. These points determine its boundaries. This class is
 * abstract. The concrete implementations of different polygons determine how
 * these points are organized. Nevertheless, every instance of Polygon must
 * know how to be converted into a vector of points.
 */
class Polygon {
  public:
    // The virtual destructor, because this class is abstract.
    virtual ~Polygon() {}
    /**
     * \brief Determines if the polygon contains a given point.
     * \param a point that we verify if is contained in the polygon.
     * \return True if the polygon contains p
     */
    virtual bool contains(const Point& p) const = 0;
    /**
     * \brief Convertion of a polygon into a vector of points.
     */
    operator const std::vector<Point>&() const { return limits; }
    /**
     * \brief Streaming operator that defines how the polygon must be printed
     * into some output.
     */
    friend std::ostream& operator << (std::ostream &out, const Polygon &poly);
  protected:
    /**
     * \brief The list of points that make up the polygon. The important
     * contract of this data structure is that the polygon contains an edge
     * from limits[i] to limits[i+1], and from limits[size-1] to limits[0].
     */
    std::vector<Point> limits;
};

/**
 * \brief Comparison between polygons.
 * \param lhs the left-hand side of the comparison.
 * \param rhs the right-hand side of the comparison.
 * \return true if lhs and rhs represent the same polygon.
 */
bool operator == (const Polygon &lhs, const Polygon &rhs);

/**
 * \class Point
 *
 * \brief a Point is the simplest type of polygon.
 */
class Point: public Polygon {
  public:
    /**
     * \brief The constructor creates a point with coordenates xx and yy.
     */
    Point(int xx, int yy);
    /**
     * \brief Determines if this point contains another point p.
     * \return true if these two points are the same, i.e., have the same
     * coordinates.
     */
    bool contains(const Point& p) const;
    /**
     * \brief prints the point into the stream as a pair (xx, yy)
     */
    friend std::ostream& operator << (std::ostream &out, const Point &p);

    const int x; ///< The X coordinate of the point
    const int y; ///< The Y coordinate of the point
};

/**
 * \class Rectangle
 *
 * \brief a right Rectangle is a polygon that is uniquely determined by two
 * points.
 * The edges of this rectangle are parallel with the carthesian axes.
 */
class RightRectangle: public Polygon {
  public:
    /**
     * \brief the constructor that creates a rectangle bounded by x0, x1, y0
     * and y1.
     */
    RightRectangle(int x0, int y0, int x1, int y1);
    /**
     * \brief Determines if the rectangle contains point p.
     * \return true if the coordinates of p lay inside the bounds x0, x1, y0
     * and y1
     */
    bool contains(const Point& p) const;
};

/**
 * A right square is a particular kind of right rectangle. It's sides have
 * equal lengths.
 */
class RightSquare: public RightRectangle {
  public:
    /**
     * \brief the constructor that will create a Right rectantle with lower
     * left corner at (botLeftXX, botLeftYY), and upper right corner at
     * (botLeftXX + side, botLeftYY + side)
     */
    RightSquare(int botLeftXX, int botLeftYY, double side):
      RightRectangle(botLeftXX, botLeftYY, botLeftXX + side, botLeftYY + side) {
    }
};

#endif