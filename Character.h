#pragma once

#include <entt/entity/registry.hpp>
#include <unordered_map>
#include <unordered_set>

#include "CharacterType.h"

namespace Character {
entt::entity create(entt::registry&, CharacterType, int = 100, int damage = 0);
}