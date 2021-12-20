#pragma once

#include <entt/entity/registry.hpp>

class System {
public:
  virtual void update(entt::registry&) = 0;
};
