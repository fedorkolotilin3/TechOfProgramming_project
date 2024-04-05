//
// Created by fedorkolotilin on 13.03.24.
//
#include "TextWidget.h"

TextWidget::TextWidget() : QLabel() {
}

TextWidget::TextWidget(std::string string) : QLabel(string.data()){

}

