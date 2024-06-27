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

    void readKey();

    void draw();
    void update();

    void reset();

    bool contains(Vector2 vec);

    ~Snake();
};