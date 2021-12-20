#pragma once

#include "System.h"

class DamageSystem : public System {
public:
  void update(entt::registry&) override;

private:
  void distributeDamage(entt::registry&);
  void deathObserve(entt::registry&);
};