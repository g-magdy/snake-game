#include "Snake.h"
#include "Constants.h"

Snake::Snake()
{
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    currentDirection = RIGHT;

    direction = {1, 0};
}

void Snake::draw()
{
    for (auto segment : body)    
    {
        // RECTANGLE, ROUNDNESS, SEGMENTS, COLOR
        DrawRectangleRounded(Rectangle{segment.x * cellSize, segment.y * cellSize, (float)cellSize, (float)cellSize}, 0.7, 6, darkGreen);
    }
}

void Snake::update()
{
    body.pop_back();


    if (IsKeyPressed(KEY_UP) && currentDirection != DOWN){
        direction = {0, -1};
        currentDirection = UP;
    }
    else if (IsKeyPressed(KEY_DOWN) && currentDirection != UP){
        direction = {0, 1};
        currentDirection = DOWN;
    }
    else if (IsKeyPressed(KEY_LEFT) && currentDirection != RIGHT){
        direction = {-1, 0};
        currentDirection = LEFT;
    }
    else if (IsKeyPressed(KEY_RIGHT) && currentDirection != LEFT){
        direction = {1, 0};
        currentDirection = RIGHT;
    }

    body.push_front(Vector2Add(body.front(), direction));

}

Snake::~Snake()
{

}