#pragma once
#include "Constants.h"

class Snake
{
public:
    // double ended queue
    deque<Vector2> body;

    Direction currentDirection;

    Vector2 direction;

    Snake();

    void draw();
    void update();

    ~Snake();
};