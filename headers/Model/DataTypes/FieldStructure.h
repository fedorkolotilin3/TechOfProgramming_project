#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_DATATYPES_FIELDSTRUCTURE_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_DATATYPES_FIELDSTRUCTURE_H_

#include "File.h"
#include "Hex.h"
#include <vector>
#include <rapidxml.hpp>
#include <rapidxml_print.hpp>

using namespace rapidxml;

class FieldStructure : public File {
 public:
  inline static   std::unordered_map<std::string, HexType> hex_parser = {
      {"Forest", HexType::Forest},
      {"Field", HexType::Field},
      {"Empty", HexType::Empty},
      {"Mountain", HexType::Mountain},
      {"Pasture", HexType::Pasture},
      {"Quarry", HexType::Quarry},
  };
  explicit FieldStructure(const std::string &source_path);
  std::vector<std::pair<Hex, std::pair<int, int>>> GetContent();
  void SetContent(std::vector<std::pair<Hex, std::pair<int, int>>>& vector);
  void Print(std::vector<char> vector_1);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_DATATYPES_FIELDSTRUCTURE_H_
