#pragma once

enum class SpellType { HEAL, BANE };

struct Spell {
  explicit Spell(SpellType type, int value = 0) : m_type(type), m_value(value) {}

  SpellType m_type;
  int m_value;
};

template <>
struct std::hash<Spell> {
  size_t operator()(const Spell& p) const {
    return std::hash<SpellType>()(p.m_type) ^ std::hash<int>()(p.m_value)
  }
};
