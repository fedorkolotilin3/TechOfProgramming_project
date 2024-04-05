#include "GameField.h"

GameField::GameField(std::string field_path) : f(field_path), structure(f.GetContent()){
    for (int i = 0; i < structure.size(); i++) {


//      auto loc_polygon = He(HexView::GenerateHexagon(HexView::ConvertCoords(structure[i].second, field_scale), field_scale));
//      this->.push_back(loc_polygon);
//      this->click_polygons.push_back(PolygonResize(loc_polygon, clickable_polygon_k));
    }
}

void GameField::MousePressEvent(QMouseEvent* event) {
  for (int i = 0; i < hexes.size(); i++) {
    Point event_point(event->x(), event->y());
    if (hexes[i].GetMPolygonClickable().containsPoint(event_point)) {
      hexes[i].OnClick();
    }
  }
}
