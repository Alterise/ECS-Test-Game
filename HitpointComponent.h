#pragma once

class HitpointComponent {
public:
  explicit HitpointComponent(int hitpoints)
      : m_hitpoints(hitpoints), m_hitpointsMax(hitpoints) {}

  HitpointComponent() = default;

  void removeHitpoints(int hitpoints) {
    m_hitpoints -= hitpoints >= m_hitpoints ? m_hitpoints : hitpoints;
  }

  void addHitpoints(int hitpoints) {
    m_hitpoints +=
        hitpoints + m_hitpoints >= m_hitpointsMax ? m_hitpointsMax - m_hitpoints : hitpoints;
  }

  int getHitpoints() const { return m_hitpoints; }

private:
  int m_hitpoints = 0;
  int m_hitpointsMax = 0;
};