//
// Created by fedorkolotilin on 23.03.24.
//
#include "Hex.h"

Hex::Hex(HexType hex_type) : type(hex_type) {
}

std::string Hex::GetTypeString() const {
  return names[static_cast<int>(type)];
}

Qt::GlobalColor Hex::GetColor() const {
  return colors[static_cast<int>(type)];
}

Hex Hex::GetRandom() {
  auto type = static_cast<HexType>(rand() % 5 + 1);
  return {type};
}

std::string Hex::GetTextureSource() const {
  return texture_sources[static_cast<int>(type)];
}

//std::string Hex::GetTypeString(int ind) {
//  return names[(rand() % 5) + 1];
//}
