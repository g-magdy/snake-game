#pragma once
#include "Food.h"
#include "Snake.h"
#include "Constants.h"

/// @brief a class that is a container for all the game objects.
/// it also serves as the game brain.
class Game
{
public:
    Game();

    Food food;
    Snake snake;
    bool gameIsRunning;
    bool gameisOver;

    void draw();
    void update();
    void checkCollisionWithFood();
    void checkCollisionWithEdges();
    void checkCollisionWithBody();
    void gameOver();
};
