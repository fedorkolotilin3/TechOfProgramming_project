#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_UICLASSES_TEXTWIDGET
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_UICLASSES_TEXTWIDGET

#include <QLabel>
class TextWidget : public QLabel {
 public:
  TextWidget();
  TextWidget(std::string string);
  TextWidget(std::string string, QWidget* widget);
};
#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_UICLASSES_TEXTWIDGET