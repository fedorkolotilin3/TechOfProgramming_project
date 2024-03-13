//
// Created by fedorkolotilin on 13.03.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_UILOGIC_HUB_STARTACTIVITY_H_
#define TP_PROJECT_FIODORKOLOTILIN_UILOGIC_HUB_STARTACTIVITY_H_

#include "Activity.h"

class StartActivity : Activity{
 public:
   int Launch();
   StartActivity(int& argc, char** argv);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_UILOGIC_HUB_STARTACTIVITY_H_
