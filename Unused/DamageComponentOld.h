#pragma once

#include <unordered_map>
#include <utility>

#include "CharacterType.h"

class DamageComponent {
public:
  explicit DamageComponent(std::unordered_map<CharacterType, int>& type)
      : m_damageAmountByCharacterType(std::move(type)) {}

  std::unordered_map<CharacterType, int> getDamageAmountByCharacterType() const {
    return m_damageAmountByCharacterType;
  }

private:
  std::unordered_map<CharacterType, int> m_damageAmountByCharacterType;
};