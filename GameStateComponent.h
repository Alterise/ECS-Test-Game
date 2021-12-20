#pragma once

#include "GameState.h"

struct GameStateComponent {
public:
  explicit GameStateComponent(GameState type) : m_state(type) {}

  GameState getState() const { return m_state; }
  void setState(GameState state) { m_state = state; }

private:
  GameState m_state;
};