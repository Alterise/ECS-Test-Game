#include <entt/entity/entity.hpp>
#include "Character.h"
#include "HitpointComponent.h"
#include "CharacterTypeComponent.h"
#include "DamageComponent.h"
#include "TargetComponent.h"

entt::entity Character::create(entt::registry& registry, CharacterType type, int hpAmount,
                               int damage) {
  const auto entity = registry.create();

  registry.emplace<HitpointComponent>(entity, hpAmount);
  registry.emplace<CharacterTypeComponent>(entity, type);
  registry.emplace<DamageComponent>(entity, damage);

  registry.emplace<TargetComponent>(entity);
  return entity;
}