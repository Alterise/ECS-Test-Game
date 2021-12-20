#pragma once

#include <utility>

class WeaponComponent {
public:
  explicit WeaponComponent(int damage, int distribution)
      : m_damage(damage), m_distribution(distribution) {}

  std::pair<int, int> getDamageAndDistribution() const {
    return std::make_pair(m_damage, m_distribution);
  }

private:
  int m_damage;
  int m_distribution;
};