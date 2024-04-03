#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAMEMANAGER_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAMEMANAGER_H_

class GameManager {

 public:
  void DoTurn();
  void RollDice();
  void GiveSources();
  void BuidObject();
  GameField BuildField();
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAMEMANAGER_H_
