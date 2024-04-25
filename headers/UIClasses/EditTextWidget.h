#include <QTextEdit>
class EditTextWidget : public QTextEdit {
 public:
  EditTextWidget();
  EditTextWidget(std::string string);
  EditTextWidget(std::string string, QWidget* widget);
};