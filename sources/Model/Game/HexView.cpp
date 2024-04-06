#include "Hex.h"
#include "HexView.h"
//#include "GameField.h"

Polygon HexView::GenerateHexagon(double x, double y, double hex_size, double scale) {
  std::vector<Point> ans;
  for (int i = 0; i < 6; i++) {
    double i_x = cos(2 * kPi / 6 * i) * hex_size * scale + x;
    double i_y = sin(2 * kPi / 6 * i) * hex_size * scale + y;
    ans.push_back(Point(i_x, i_y));
  }
  for (int i = 0; i < ans.size(); i++) {
    ans[i].rotate({x, y}, rotation_angle);
  }
  return ans;
}

HexView::HexView(const Hex &hex,
                 double x,
                 double y,
                 int scale,
                 double clickable_polygon_k,
                 double hex_size)
    : hex(hex),
      x(x),
      y(y),
      scale(scale),
      clickable_polygon_k(clickable_polygon_k) {
  Polygon polygon = GenerateHexagon(x, y, hex_size, scale);
  my_polygon = polygon;
  polygon.scale(polygon.center(), clickable_polygon_k);
  my_clickable_polygon = polygon;
  q_polygon = PTOQP(my_polygon);
  q_clickable_polygon = PTOQP(my_clickable_polygon);
}

HexView::HexView(const Hex &hex,
                 std::pair<double, double> center,
                 int scale,
                 double clickable_polygon_k,
                 double hex_size) : HexView(hex, center.first, center.second, scale, clickable_polygon_k){

}

QPolygon HexView::PTOQP(Polygon &polygon) {
  QPolygon ans;
  for (int i = 0; i < polygon.verticesCount(); i ++) {
    ans << QPoint(polygon.getVert(i).x, polygon.getVert(i).y);
  }
  return ans;
}

void HexView::Draw(QPainter &painter) {
  QBrush fill_brush;
  fill_brush.setStyle(Qt::SolidPattern);
  QPainterPath local_path;
  local_path.addPolygon(q_polygon);
  fill_brush.setColor(hex.GetColor());
  painter.fillPath(local_path, fill_brush);
}

Polygon HexView::QPTOP(QPolygon &polygon) {
  std::vector<Point> ans;
  for (auto point : polygon) {
    ans.push_back(Point(point.x(), point.y()));
  }
  return ans;
}

void HexView::Click(int x, int y) {
  if (my_clickable_polygon.containsPoint(Point(x, y))) {
    std::cerr << "click on: " << hex.GetTypeString() << std::endl;
  }
}
