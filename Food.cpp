#include "Food.h"

Food::Food()
{
    position = generateRandomPosition();
    std::cout << "Initial Position of food is (" << position.x << ", " << position.y << ")" << std::endl;

    Image img = LoadImage("food.png");
    texture = LoadTextureFromImage(img);
    UnloadImage(img);
    
}

void Food::draw()
{
    // DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, YELLOW);
    int drawX = static_cast<int>(position.x) * cellSize;
    int drawY = static_cast<int>(position.y) * cellSize;
    std::cout << "Drawing food at: (" << position.x << ", " << position.y << ") -> Pixel Coordinates: (" << drawX << ", " << drawY << ")" << std::endl;
    DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
}

Vector2 Food::generateRandomPosition() 
{
    Vector2 pos = {static_cast<float>(GetRandomValue(0, cellCount - 1)), static_cast<float>(GetRandomValue(0, cellCount - 1))};
    std::cout << "Generated random position: (" << pos.x << ", " << pos.y << ")" << std::endl;
    return pos;
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