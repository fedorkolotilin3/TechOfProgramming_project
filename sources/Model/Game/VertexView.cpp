#include <QPainterPath>
#include "VertexView.h"

VertexView::VertexView(double x,
                       double y,
                       int scale,
                       double clickable_scale,
                       double size)
                   : x(x), y(y), scale(scale), clickable_scale(clickable_scale), size(size)
                   {
  my_circle = Circle({x, y}, size * scale);
  my_clickable_Circle = Circle({x, y}, size * scale * clickable_scale);
}

void VertexView::Draw(QPainter &painter) {

//  QBrush fill_brush;
//  fill_brush.setStyle(Qt::SolidPattern);
//  QPainterPath local_path;
////  local_path.addEllipse(my_circle.center().x, my_circle.center().y, my_circle.radius(), my_circle.radius());
//  local_path.addEllipse(QPointF(x, y), my_circle.radius(), my_circle.radius());
//  QColor color;
//  fill_brush.setColor(color.red());
//  painter.fillPath(local_path, fill_brush);
  QImage image("../Data/single_picture.png");
  painter.drawImage(x - image.width() / 2, y - image.height() / 2, image);
}

void VertexView::Click(int x, int y) {
  if (my_circle.containsPoint(Point(x, y))) {
    std::cerr << "click on vertex" << std::endl;
  }
}
