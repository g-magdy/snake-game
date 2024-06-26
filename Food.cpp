#include "Food.h"

Food::Food()
{
    position = generateRandomPosition();

    Image img = LoadImage("food.png");
    texture = LoadTextureFromImage(img);
    UnloadImage(img);
}

void Food::draw()
{
    DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
}

Vector2 Food::generateRandomPosition() 
{
    return {(float)GetRandomValue(0, cellCount - 1), (float) GetRandomValue(0, cellCount - 1)};
}

Food::~Food()
{
    // UnloadTexture(texture);
    // for some reason, running this produces a segmentation fault.

    //* and another problem: there is a memory leak in X11 !!!
    //* it turns out after some debugging with 
    //* valgrind --leak-check=full ./game
    //* and using a blank template .. the output of valgrind points to libX11 file
}