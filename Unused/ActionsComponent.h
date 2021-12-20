#pragma once

class ActionsComponent {
public:
  explicit ActionsComponent(int amount) : m_amount(amount), m_maxAmount(amount) {}

  int getAmount() const { return m_amount; }
  void setAmount(int amount) { m_amount = amount; }
  void resetAmount() { m_amount = m_maxAmount; }
  void performAction() { m_amount -= m_amount > 0 ? 1 : 0; }

private:
  int m_amount;
  int m_maxAmount;
};