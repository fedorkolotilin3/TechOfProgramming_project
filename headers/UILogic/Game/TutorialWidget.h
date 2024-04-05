#include "Widget.h"
class TutorialWidget : public Widget {
 public:
  using Widget::Widget;
  TutorialWidget();
  TutorialWidget(Widget* parent);
  void OnCreate();
  void OnExit();
};