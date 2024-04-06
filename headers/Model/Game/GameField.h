
#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_GAMEFIELD_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_GAMEFIELD_H_

#include <QPainter>
#include "FieldStructure.h"
#include "HexView.h"
#include "VertexView.h"

class GameField {
  inline static Point vec_x = {0.5, sqrt(3) / 2};
  inline static Point vec_y = {0.5, -sqrt(3) / 2};
  inline static int rotation_angle = -30;
  int center_x = 700;
  int center_y = 370;
  int scale = 20;
  double split_k = 1.05;
  double clickable_polygon_k = 0.6;
  std::vector<HexView> hexes;
  std::vector<VertexView> vertices;
  std::vector<std::pair<Hex, std::pair<int, int>>> struct_vector;
  void ConstructField();
 public:
  GameField();
  GameField& operator=(const GameField& other) = default;
  GameField(int center_x, int center_y, int scale = 40, double split_k = 1.05, double clickable_polygon_k = 0.6);
  void Draw(QPainter& painter);
  void Click(int x, int y);
  void ShuffleHexes();
  Point ConvertCoords(std::pair<int, int> pair, double split_k, double field_scale);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_GAMEFIELD_H_
