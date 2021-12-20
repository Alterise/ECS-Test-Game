#pragma once

class HealComponent {
public:
  HealComponent(int heal) : m_heal(heal) {}

  int getHealAmount() const { return m_heal; }

private:
  int m_heal = 0;
};