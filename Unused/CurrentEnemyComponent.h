#pragma once

#include "CharacterType.h"

class CurrentEnemyComponent {
public:
  explicit CurrentEnemyComponent(CharacterType type) : m_type(type) {}

  CharacterType getType() const { return m_type; }
  void setType(CharacterType type) { m_type = type; }

private:
  CharacterType m_type;
};
