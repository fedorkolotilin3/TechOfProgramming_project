#include "EditTextWidget.h"

EditTextWidget::EditTextWidget() : QTextEdit() {

}

EditTextWidget::EditTextWidget(std::string string) : QTextEdit(QString(string.data())) {

}

EditTextWidget::EditTextWidget(std::string string, QWidget* widget) : QTextEdit(QString(string.data()), widget){

}
