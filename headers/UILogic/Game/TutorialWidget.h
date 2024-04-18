#include "Widget.h"
#include "GameFieldWidget.h"

class TutorialWidget : public Widget {
  Widget* game_menu;
  Widget* container;
  bool is_menu_active;
 public:
 protected:
  void mousePressEvent(QMouseEvent* event) override;
 public:
  using Widget::Widget;
  TutorialWidget();
  TutorialWidget(Widget* parent);
  void OnCreate();
  void OnExit();
};