#pragma once

#include "CharacterState.h"

struct CharacterStateComponent {
public:
  explicit CharacterStateComponent(CharacterState type) : m_state(type) {}
  CharacterState getState() const { return m_state; }
  void setState(CharacterState state) { m_state = state; }

private:
  CharacterState m_state;
};
