#pragma once

#include <entt/entity/entity.hpp>

struct TargetComponent {
public:
  explicit TargetComponent() {}
  entt::entity get() const { return m_target; }
  void set(entt::entity entity) { m_target = entity; }
private:
   entt::entity m_target = entt::null;
};