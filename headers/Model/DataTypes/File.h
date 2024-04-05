//
// Created by fedorkolotilin on 23.03.24.
//
#include <fstream>

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_DATATYPES_FILE_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_DATATYPES_FILE_H_
class File {
 protected:
  std::string source_path;
 public:
  File(std::string source_path);
//  void Read();
//  void Write();
};
#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_DATATYPES_FILE_H_
