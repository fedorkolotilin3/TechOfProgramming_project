#include "FieldStructure.h"
#include <fstream>
#include <iostream>

std::vector<std::pair<Hex, std::pair<int, int>>> FieldStructure::GetContent() {
  std::vector<std::pair<Hex, std::pair<int, int>>> return_vector;
  xml_document<char> doc;
  try {
    std::ifstream file(("../" + this->source_path).c_str());
    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>( &buffer[0] );
  } catch (parse_error e) {
    std::cerr << e.what() << std::endl;
    return {} ;
  }
  xml_node<> *root_node = doc.first_node();
  for (auto node_ptr = root_node->first_node(); node_ptr; node_ptr = node_ptr->next_sibling()) {
    std::pair<int, int> pair = {std::stoi(node_ptr->first_attribute("x_coord")->value()),
                                std::stoi(node_ptr->first_attribute("y_coord")->value())};
    std::string hex_type_name = node_ptr->first_node()->value();
    HexType hex_type = hex_parser[hex_type_name];
    Hex hex(hex_type);
    return_vector.push_back({hex, pair});
  }
  doc.clear();
  return return_vector;
}

FieldStructure::FieldStructure(const std::string &source_path) : File(source_path) {}

void FieldStructure::SetContent(std::vector<std::pair<Hex, std::pair<int, int>>>& vector) {
  xml_document<char> doc;
  std::ofstream file(("../" + this->source_path).c_str());
  file.clear();
  std::string xml_base = "<List>\n</List>";
  doc.parse<0>(xml_base.data());
  auto doc_begin = doc.first_node();
  for (auto item: vector) {
    auto node = doc.allocate_node( node_element, "Widget", nullptr, 0, 0);
    std::cerr << std::to_string(item.second.first).data() << " " << std::to_string(item.second.second).data() << std::endl;
    node->append_attribute(doc.allocate_attribute(doc.allocate_string("x_coord"),   doc.allocate_string(std::to_string(item.second.first).data())));
    node->append_attribute(doc.allocate_attribute(doc.allocate_string("y_coord"), doc.allocate_string(std::to_string(item.second.second).data())));
    node->append_node(doc.allocate_node(node_element, doc.allocate_string("Type"), doc.allocate_string(item.first.GetTypeString().data()), 0, 0));
    std::cerr << node->first_attribute()->value() << " " << node->last_attribute()->value() << std::endl;
    std::cerr << node->first_node()->type() << " " << node->first_node()->value() << std::endl;
    doc_begin->append_node(node);
  }
  file << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
  rapidxml::print(file, doc);
  std::cout << std::endl;
  file.close();
  doc.clear();
}

