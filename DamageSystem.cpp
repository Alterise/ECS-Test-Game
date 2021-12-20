#include "DamageSystem.h"
#include "HitpointComponent.h"
#include "TargetComponent.h"
#include "CharacterTypeComponent.h"
#include "DamageComponent.h"
#include "GameStateComponent.h"

void DamageSystem::distributeDamage(entt::registry& registry) {
  auto view = registry.view<HitpointComponent, CharacterTypeComponent, DamageComponent,
                            TargetComponent>();
  for (const auto& [l_entity, l_hitpoints, l_type, l_damage, l_target] :
       view.each()) {
    if (registry.valid(l_target.get())) {
      try {
        registry.get<HitpointComponent>(l_target.get())
            .removeHitpoints(l_damage.getAmount());
      } catch (std::out_of_range& ex) {
      }
    }
  }
}
void DamageSystem::deathObserve(entt::registry& registry) {
  std::vector<entt::entity> toDestroy;
  auto view = registry.view<HitpointComponent>();
  for (const auto& [entity, hitpoints] : view.each()) {
    if (!hitpoints.getHitpoints()) {
      toDestroy.push_back(entity);
    }
  }

  for (const auto& entityItem : toDestroy) {
    registry.destroy(entityItem);
  }
}

void DamageSystem::update(entt::registry& registry) {
  distributeDamage(registry);
  deathObserve(registry);
}