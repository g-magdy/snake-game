#pragma once

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <deque>
using namespace std;

// Color {r, g, b, alpha}
// 0 (transparent) <= alpha <= 255 (opaque)

extern Color green;
extern Color darkGreen;

extern const int cellSize;
extern const int cellCount;
extern const int offset;
extern const int playWindowSize;
extern const int windowSize;

extern double interval;
extern const double initialInterval;

extern const deque<Vector2> initialSnakeBody;

/// @brief to determine the current direction of the snake progress
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
