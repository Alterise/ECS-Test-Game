#pragma once

#include <unordered_set>
#include "Spell.h"

class SpellsComponent {
public:
  explicit SpellsComponent(std::unordered_set<Spell>&& spells) : m_spells(std::move(spells)) {}

  std::unordered_set<Spell> get() const { return m_spells; }

private:
  std::unordered_set<Spell> m_spells;
};