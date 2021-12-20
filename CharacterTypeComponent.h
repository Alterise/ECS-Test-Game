#pragma once

#include "CharacterType.h"

struct CharacterTypeComponent {
public:
  explicit CharacterTypeComponent(CharacterType type) : m_type(type) {}

  CharacterType getType() const { return m_type; }
  void setType(CharacterType type) { m_type = type; }

private:
  CharacterType m_type;
};
