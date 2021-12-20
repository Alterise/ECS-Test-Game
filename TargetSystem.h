#pragma once

#include "System.h"

class TargetSystem : public System {
public:
  void update(entt::registry&) override;
  static void setTargetByNumber(entt::registry& registry, entt::entity l_entity, int number);
};