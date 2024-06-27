#pragma once
#include "Food.h"
#include "Snake.h"
#include "Constants.h"

/// @brief a class that is a container for all the game objects.
/// it also serves as the game brain.
class Game
{
public:
    Food food;
    Snake snake;

    void draw();
    void update();
    void checkCollisions();
};
