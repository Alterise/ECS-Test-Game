#pragma once

class DamageComponent {
public:
  explicit DamageComponent(int amount) : m_amount(amount) {}

  int getAmount() const { return m_amount; }

private:
  int m_amount;
};