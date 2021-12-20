#pragma once

#include "System.h"
#include "GameState.h"

class GameSystem : public System {
public:
  void update(entt::registry&) override;
  void printHP(entt::registry&);
  void printActionList(entt::registry&);

private:
  void gameStateObserve(entt::registry&);
};