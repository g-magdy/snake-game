#include "Food.h"

const int cellSize = 30;
const int cellCount = 25;

const int windowSize = cellSize * cellCount;

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
    UnloadTexture(texture);
}