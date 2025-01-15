#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>

#include "entity.h"

class Player : public Entity {
public:
  int8_t Controller;

  Player();
  Player(int8_t Player_Number);
};

#endif
