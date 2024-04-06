#pragma once
#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MY_GEOMETRY_H
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MY_GEOMETRY_H

#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using std::sqrt;
using std::vector;

const double kPi = acos(-1);

double my_abs(double val);

bool isEqual(double num1, double num2);

int my_sign(double val);


struct Point {
  double x;
  double y;
  bool is_infinite = false;

  Point(double x = 0, double y = 0);

  bool operator==(Point point) const;

  bool operator!=(Point point) const;

  Point(bool is_infinite1);

  Point(const Point &point);

  Point &operator-=(Point point);

  Point &operator=(Point point);

  Point &operator+=(Point point);

  double scalMult(Point point) const;

  double vecMult(Point point) const;
  Point &operator*=(double koef);

  Point &operator/=(double koef);

  Point operator+(Point rhs) const;

  Point operator-(Point rhs) const;

  Point operator*(double rhs) const ;

  Point operator/(double rhs) const;

  double len() const ;

  Point ortogonalPoint(int scal_sign);

  void rotateVec(double angle);

  void rotate(Point center, double angle);
  void reflect(Point center);

  void scale(Point center, double coefficient);

  Point normieredPoint() const;
};

std::istream &operator>>(std::istream &is, Point &point);

std::ostream &operator<<(std::ostream &os, Point point);

struct Line {
  Point point_1;
  Point point_2;

  Line(const Point point_1, const Point point_2);

  Line(Point start_p, double angle_k);

  Line(double angle_k, double delta_y);

  bool contains(Point point) const;

  bool isParallel(const Line &line) const;

  bool operator==(const Line &line) const;
  bool operator!=(const Line &line) const;

  Point directionVector() ;
};

void reflect(Point &point, const Line &axis) ;

Point intersection(Line l1, Line l2);

bool inSegment(Point point, Point segment_begin, Point segment_end);

bool intersects(Point segment_1_begin, Point segment_1_end, Point segment_2_begin, Point segment_2_end) ;

double dist(Point point, Line line);

struct Shape {
  virtual double perimeter() const = 0;
  virtual double area() const = 0;
  virtual bool operator==(const Shape &another) const = 0;
  virtual bool operator!=(const Shape &another) const = 0;
  virtual bool isCongruentTo(const Shape &another) const = 0;
  virtual bool isSimilarTo(const Shape &another) const = 0;
  virtual bool containsPoint(Point point) const = 0;
  virtual void rotate(Point center, double angle) = 0;
  virtual void reflect(Point center) = 0;
  virtual void reflect(const Line &axis) = 0;
  virtual void scale(Point center, double coefficient) = 0;
  virtual ~Shape() = default;
};
struct Polygon : Shape {
  vector<Point> vertices;

  Polygon();

  Polygon(const vector<Point> &vertices);

  template <typename... T>
  Polygon(T... vertices);

  Polygon(std::initializer_list<Point> list);

  Point center();

  int verticesCount() const;

  vector<Point> getVertices() const;

  bool isConvex() const;

  ~Polygon() override = default;

  double perimeter() const override ;

  double area() const override;

  void reverse();

  bool operator==(const Shape &another) const override;

  bool operator!=(const Shape &another) const override;

  bool isCongruentTo(const Shape &another) const override;

  Point getVert(int ind) const;

  void SetVectors(int ind1, int ind2, const Polygon &another, vector<Point*> &vectors) const;

  bool isSimilarToPolygon(const Polygon &another) const;

  bool isSimilarTo(const Shape &another) const override;

  bool containsPoint(Point point) const override;

  void rotate(Point center, double angle) override;

  void reflect(Point center) override ;

  void reflect(const Line &axis) override;

  void scale(Point center, double coefficient) override;
};

struct Ellipse : Shape {
  Point f1;
  Point f2;
  double dist;

  Ellipse();
  Ellipse(Point f_1, Point f_2, const double &dist);

  std::pair<Point, Point> focuses() const;

  std::pair<Line, Line> directrices() const;

  double eccentricity() const;

  double perimeter() const override;

  double area() const override;

  bool equals(const Ellipse &another) const;

  bool operator==(const Shape &another) const override;

  bool operator!=(const Shape &another) const override;

  bool isCongruentTo(const Shape &another) const override;

  bool isSimilarTo(const Shape &another) const override;

  bool containsPoint(Point point) const override;

  void rotate(Point center, double angle) override;

  void reflect(Point center) override;

  void reflect(const Line &axis) override;

  void scale(Point center, double coefficient) override ;

  ~Ellipse() = default;
};

struct Circle : Ellipse {
  Circle();
  Circle(Point f_1, double radius);

  Point center();

  double radius();
};

struct Rectangle : Polygon {
  std::pair<Point, Point> vert_find(Point vert1, Point vert2, double rel);

  Rectangle(Point vert1, Point vert2, double rel);

  Point center();

  std::pair<Line, Line> diagonals();
};
struct Square : Rectangle {
  Square(Point vert1, Point vert2);

  Circle circumscribedCircle();

  Circle inscribedCircle();
};
struct Triangle : Polygon {
  Point _a = vertices[0];
  Point _b = vertices[1];
  Point _c = vertices[2];
  using Polygon::Polygon;

  Point centroid();

  Circle circumscribedCircle();

  Circle inscribedCircle();

  Point orthocenter();

  Line EulerLine();

  Circle ninePointsCircle();
};

/*

1) Пробелы между методами и дебаг вывод, ссылки рядом с типом    //ok
6: без комментариев - мат константы                              //ok
2) Неп назв перем и мет                                          //ok
3) const Point - не имеет смысла, т.к. копируется                //ok
136: magic const                                                 //ok
4) Лучше использовать dynamic_cast через попытку приведения указателей - try catch слишком энергоёмкая штука   //ok
5) 327-336 - копипаста - вынеси в отдельные методы получения методов //ok
6) Следи за const, например contatins point должно быть const    //ok
7) Окружность девяти точек вычисляется неправильно

 */

#endif // TP_PROJECT_FIODORKOLOTILIN_HEADERS_MY_GEOMETRY_H