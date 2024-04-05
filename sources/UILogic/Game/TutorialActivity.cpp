#include "TutorialActivity.h"
#include "TextWidget.h"
#include "TutorialWidget.h"

int TutorialActivity::Launch()  {
//  widget_container->ShowMaximized();
  return this->Activity::Launch();
}
TutorialActivity::TutorialActivity() : Activity() {
  layout = new QVBoxLayout;
  widget_container = new Widget;

  layout->addWidget(new TutorialWidget());

  widget_container->setLayout(layout);
}
