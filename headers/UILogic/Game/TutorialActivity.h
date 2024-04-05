

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_GAME_TUTORIALACTIVITY_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_GAME_TUTORIALACTIVITY_H_


#include "Activity.h"
#include "Widget.h"

class TutorialActivity : public Activity{
 public:
  int Launch();
  TutorialActivity(int& argc, char** argv);
  TutorialActivity();
};


#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_GAME_TUTORIALACTIVITY_H_
