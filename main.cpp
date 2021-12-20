#include <iostream>
#include <entt/entity/registry.hpp>
#include <chrono>

#include "Character.h"
#include "CharacterTypeComponent.h"
#include "GameStateComponent.h"
#include "DamageSystem.h"
#include "GameSystem.h"
#include "TargetSystem.h"

DamageSystem damageSystem;
TargetSystem aggressionSystem;
GameSystem gameSystem;

void update(entt::registry& registry) {
  aggressionSystem.update(registry);
  gameSystem.printActionList(registry);
  damageSystem.update(registry);
  gameSystem.update(registry);
}

int main() {
  srandom(std::chrono::system_clock::now().time_since_epoch().count());

  entt::registry registry;
  const auto gameStateEntity = registry.create();
  registry.emplace<GameStateComponent>(gameStateEntity, GameState::IN_PROGRESS);
  auto mainCharacter = Character::create(
      registry, CharacterType(CharacterPersonality::MAIN_CHARACTER, CharacterParty::FRIEND),
      100, 10);
  Character::create(registry,
                    CharacterType(CharacterPersonality::APPRENTICE, CharacterParty::FRIEND),
                    100, 10);
  Character::create(registry,
                    CharacterType(CharacterPersonality::OGRE, CharacterParty::ENEMY), 70, 15);
  Character::create(registry,
                    CharacterType(CharacterPersonality::RAT, CharacterParty::ENEMY), 30, 3);
  Character::create(registry,
                    CharacterType(CharacterPersonality::RAT, CharacterParty::ENEMY), 30, 3);

  gameSystem.printHP(registry);

  auto gameState = GameState::IN_PROGRESS;
  int switcher;
  int turnCounter = 1;
  while (gameState == GameState::IN_PROGRESS) {
    auto charactersView = registry.view<CharacterTypeComponent>();
    std::cout << "\n==== Turn " << turnCounter << " ====\n";
    std::cout << "\nActions:\n"
              << "1 - Attack\n"
              << "2 - Change target\n"
              << "3 - Exit\n"
              << "Input: ";

    std::cin >> switcher;
    switch (switcher) {
    case 1: {
      break;
    }
    case 2: {
      int number;
      std::cout << "\nChoose your enemy target:\n";
      gameSystem.printHP(registry);
      std::cout << "Input: ";
      std::cin >> number;
      if (number > 0) {
        TargetSystem::setTargetByNumber(registry, mainCharacter, number);
      } else {
        std::cout << "Wrong input\n";
      }
      continue;
    }
    case 3: {
      std::cout << "\nExiting..." << std::endl;
      return 0;
      break;
    }
    default: {
      std::cout << "\nWrong input" << std::endl;
    }
    }
    update(registry);
    turnCounter++;

    auto view = registry.view<GameStateComponent>();
    for (const auto& [entity, state] : view.each()) {
      gameState = state.getState();
    }

    if (gameState == GameState::WIN) {
      std::cout << "\nYou've WON, CONGRATS!" << std::endl;
    } else if (gameState == GameState::DEFEAT) {
      std::cout << "\nMission failed, we'll get em next time..." << std::endl;
    }
  }
}