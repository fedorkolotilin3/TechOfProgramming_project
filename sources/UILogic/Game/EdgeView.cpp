#include <QPainterPath>
#include "EdgeView.h"

EdgeView::EdgeView(Point vertex_1, Point vertex_2, int scale, double clickable_scale, double size) :
    vertex_1(vertex_1), vertex_2(vertex_2), scale(scale), clickable_scale(clickable_scale), size(size)
{
  x = (vertex_1.x + vertex_2.x) / 2;
  y = (vertex_1.y + vertex_2.y) / 2;
  QTransform rotation_trandform;
  Point ordering = vertex_2 - vertex_1;
  double angle = acos(ordering.normieredPoint().scalMult({1, 0}));
  angle *= my_sign(asin(ordering.normieredPoint().vecMult({1, 0})));
//  std::cerr << "angle: " << angle << std::endl;
  rotation_trandform.rotateRadians(-angle);
  texture = QImage("../Data/edge_texture.png").scaled(image_width * scale, image_height * scale).transformed(rotation_trandform);
  my_clickable_area = Circle({x, y}, scale * clickable_scale);
}

void EdgeView::Draw(QPainter &painter) {
  if (draw_mode) {
    QBrush fill_brush;
    fill_brush.setStyle(Qt::SolidPattern);
    QPainterPath local_path;
    local_path.addEllipse(QPointF(x, y), my_clickable_area.radius(), my_clickable_area.radius());
    QColor color;
    fill_brush.setColor(color.red());
    painter.fillPath(local_path, fill_brush);
    return;
  }
  painter.drawImage(x - texture.width() / 2, y - texture.height() / 2, texture);
}

void EdgeView::Click(int x, int y) {
  if (my_clickable_area.containsPoint(Point(x, y))) {
    draw_mode ^= 1;
    std::cerr << "click on edge" << std::endl;
  }
}
