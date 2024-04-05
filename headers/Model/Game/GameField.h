
#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_GAMEFIELD_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_GAMEFIELD_H_

#include <QPoint>
#include <QMouseEvent>
#include "FieldStructure.h"
#include "HexView.h"
#include "EdgeView.h"
#include "VertexView.h"

class GameField : public QObject{
  Q_OBJECT
 public slots:
  void MousePressEvent(QMouseEvent* event);
 private:
  const double kPi = acos(-1);
  const int field_center_x = 700;
  const int field_center_y = 370;
  const int field_scale = 75;
  const double split_k = 1.05;
  const double clickable_polygon_k = 0.6;
  FieldStructure f;
  std::vector<std::pair<Hex, std::pair<int, int>>> structure;
  std::vector<HexView> hexes;
  std::vector<EdgeView> edges;
  std::vector<VertexView> vertices;

 public:
  GameField(std::string field_path);

};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_GAMEFIELD_H_
