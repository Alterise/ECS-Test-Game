#include "TargetSystem.h"
#include "HitpointComponent.h"
#include "TargetComponent.h"
#include "CharacterTypeComponent.h"
#include "DamageComponent.h"
#include "GameStateComponent.h"

#include <limits>

void TargetSystem::update(entt::registry& registry) {
  auto view =
      registry
          .view<HitpointComponent, CharacterTypeComponent, TargetComponent, DamageComponent>();
  for (const auto& [l_entity, l_hitpointComponent, l_characterType, l_target, l_damage] :
       view.each()) {
    if (l_characterType.getType().getPersonality() != CharacterPersonality::MAIN_CHARACTER) {
      if (!registry.valid(l_target.get())) {
        int minHitpointsValue = std::numeric_limits<int>::max();
        entt::entity weakestEnemy = entt::null;
        auto viewEnemy = registry.view<HitpointComponent, CharacterTypeComponent>();
        for (const auto& [r_entity, r_hitpointComponent, r_characterType] : viewEnemy.each()) {
          if (r_hitpointComponent.getHitpoints() < minHitpointsValue &&
              r_characterType.getType().getParty() != l_characterType.getType().getParty()) {
            minHitpointsValue = r_hitpointComponent.getHitpoints();
            weakestEnemy = r_entity;
          }
        }
        l_target.set(weakestEnemy);
      }
    }
  }
}

void TargetSystem::setTargetByNumber(entt::registry& registry, entt::entity l_entity, int number) {
  auto view = registry.view<CharacterTypeComponent>();
  number--;
  number %= view.size();
  int i = 0;
  for (const auto& [r_entity, r_type] : view.each()) {
    if (i++ != number) {
      continue;
    }

    registry.get<TargetComponent>(l_entity).set(r_entity);
    break;
  }
}