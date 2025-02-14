#include "Snake.h"
#include "Constants.h"

Snake::Snake()
{
    reset();
}

void Snake::draw()
{
    for (auto segment : body)    
    {
        // RECTANGLE, ROUNDNESS, SEGMENTS, COLOR
        DrawRectangleRounded(Rectangle{offset + segment.x * cellSize, offset + segment.y * cellSize, (float)cellSize, (float)cellSize}, 0.7, 6, darkGreen);
    }
}

void Snake::readKey()
{
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
}

void Snake::reset()
{
    body = initialSnakeBody;
    currentDirection = RIGHT;

    direction = {1, 0};
}

void Snake::update()
{
    body.pop_back();
    body.push_front(Vector2Add(body.front(), direction));
}

Snake::~Snake()
{

}


bool Snake::contains(Vector2 vec)
{
    for (auto segment : body)
        if (Vector2Equals(segment, vec))
            return true;
    return false;
}