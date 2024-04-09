#include <QPainterPath>
#include "VertexView.h"

VertexView::VertexView(double x,
                       double y,
                       int scale,
                       double clickable_scale,
                       double size)
                   : x(x), y(y), scale(scale), clickable_scale(clickable_scale), size(size)
                   {
  texture = QImage("../Data/single_picture.png").scaled(image_size * scale, image_size * scale);
  my_clickable_Circle = Circle({x, y}, size * scale * clickable_scale);
}

void VertexView::Draw(QPainter &painter) {
  if (draw_mode) {
      QBrush fill_brush;
      fill_brush.setStyle(Qt::SolidPattern);
      QPainterPath local_path;
      local_path.addEllipse(QPointF(x, y), my_clickable_Circle.radius(), my_clickable_Circle.radius());
      QColor color;
      fill_brush.setColor(color.red());
      painter.fillPath(local_path, fill_brush);
    return;
  }
  painter.drawImage(x - texture.width() / 2, y - texture.height() / 2, texture);
}

void VertexView::Click(int x, int y) {
  if (my_clickable_Circle.containsPoint(Point(x, y))) {
    draw_mode ^= 1;
    std::cerr << "click on vertex" << std::endl;
  }
}
