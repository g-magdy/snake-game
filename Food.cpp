#include "Food.h"

Food::Food()
{
    // ensure that the first food generation is out of the snake's body
    do
    {
        position = generateRandomPosition();
    } while (contain(initialSnakeBody, position));
    
    Image img = LoadImage("food.png");
    texture = LoadTextureFromImage(img);
    UnloadImage(img);
}

void Food::draw()
{
    // DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, YELLOW);
    DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize, WHITE);
}

Vector2 Food::generateRandomPosition()
{
    Vector2 pos = {static_cast<float>(GetRandomValue(0, cellCount - 1)), static_cast<float>(GetRandomValue(0, cellCount - 1))};
    return pos;
}

bool Food::contain(deque<Vector2> d, Vector2 v)
{
    for (auto i : d)
        if (Vector2Equals(i, v))
            return true;
    
    return false;
}

Food::~Food()
{
    // UnloadTexture(texture);
    // for some reason, running this produces a segmentation fault.

    //* and another problem: there is a memory leak in X11 !!!m
    //* it turns out after some debugging with 
    //* valgrind --leak-check=full ./game
    //* and using a blank template .. the output of valgrind points to libX11 file
}