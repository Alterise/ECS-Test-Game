#pragma once

enum class CharacterPersonality { MAIN_CHARACTER, APPRENTICE, RAT, OGRE, NONE };

enum class CharacterParty { FRIEND, ENEMY };

class CharacterType {
public:
  CharacterType(CharacterPersonality type, CharacterParty party)
      : m_personality(type), m_party(party) {}

  CharacterPersonality getPersonality() const { return m_personality; }

  CharacterParty getParty() const { return m_party; }

private:
  CharacterPersonality m_personality;
  CharacterParty m_party;
};