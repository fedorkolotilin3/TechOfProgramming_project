#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_HEX_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_HEX_H_

#include <algorithm>
#include <QInternal>

enum class HexType {
  Empty = 0, Forest = 1, Mountain = 2, Quarry = 3, Pasture = 4, Field = 5
};

class Hex {
  HexType type;
  inline static std::vector<std::string> names = {"Empty", "Forest", "Mountain", "Quarry", "Pasture", "Field"};
  inline static std::vector<Qt::GlobalColor> colors = {Qt::white, Qt::darkGreen, Qt::gray, Qt::red, Qt::green, Qt::yellow,};
 public:
  Hex(HexType hex_type);
  std::string GetTypeString();
  Qt::GlobalColor GetColor();
  static Hex GetRandom();
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_HEX_H_
