#include <iostream>

#include "GameSystem.h"
#include "HitpointComponent.h"
#include "TargetComponent.h"
#include "CharacterTypeComponent.h"
#include "GameStateComponent.h"

const std::unordered_map<CharacterPersonality, std::string> PersonalityToString{
    {CharacterPersonality::MAIN_CHARACTER, "Main Character"},
    {CharacterPersonality::OGRE, "Ogre"},
    {CharacterPersonality::RAT, "Rat"},
    {CharacterPersonality::APPRENTICE, "Apprentice"},
    {CharacterPersonality::NONE, "Nobody"}};

void GameSystem::printHP(entt::registry& registry) {
  auto charactersView = registry.view<HitpointComponent, CharacterTypeComponent>();
  std::cout << std::endl;
  int i = 1;
  for (const auto& [entity, hitpoints, type] : charactersView.each()) {
    std::cout << i++ << ". " << PersonalityToString.at(type.getType().getPersonality()) << " has " << hitpoints.getHitpoints()
              << " HP\n";
  }
}

void GameSystem::printActionList(entt::registry& registry) {
  auto charactersView =
      registry.view<CharacterTypeComponent, TargetComponent>();
  std::cout << std::endl;
  for (const auto& [entity, type, target] : charactersView.each()) {
    std::cout << PersonalityToString.at(type.getType().getPersonality()) << " ATTACKED ";
    if (registry.valid(target.get())) {
      std::cout << PersonalityToString.at(
                       registry.get<CharacterTypeComponent>(target.get()).getType().getPersonality())
                << std::endl;
    } else {
      std::cout << "Nobody" << std::endl;
    }
  }
  std::cout << std::endl;
}

void GameSystem::gameStateObserve(entt::registry& registry) {
  bool finished = false;
  auto view = registry.view<CharacterTypeComponent>();
  bool foundMainCharacter = false;
  for (const auto& [entity, type] : view.each()) {
    if (type.getType().getPersonality() == CharacterPersonality::MAIN_CHARACTER) {
      foundMainCharacter = true;
    }
  }

  if (!foundMainCharacter) {
    auto gameVariablesView = registry.view<GameStateComponent>();
    for (const auto& [entity2, state] : gameVariablesView.each()) {
      state.setState(GameState::DEFEAT);
      finished = true;
    }
  }

  int isEnemiesAlive = false;
  if (!finished) {
    auto charactersView = registry.view<CharacterTypeComponent>();
    for (const auto& [entity, type] : charactersView.each()) {
      if (type.getType().getParty() == CharacterParty::ENEMY) {
        isEnemiesAlive = true;
        break;
      }
    }

    if (!isEnemiesAlive) {
      auto gameVariablesView = registry.view<GameStateComponent>();
      for (const auto& [entity, state] : gameVariablesView.each()) {
        state.setState(GameState::WIN);
      }
    }
  }
}

void GameSystem::update(entt::registry& registry) {
  printHP(registry);
  gameStateObserve(registry);
}