#pragma once
#include <raylib.h>

class Food
{
private:
    Vector2 position;
    Texture2D texture;

public:
    /// @brief Creates a food object
    Food();
    
    /// @brief Draws a food object in a random position
    void draw();

    /// @brief Return 2 random ints from 0 to cellCount - 1 inclusive
    Vector2 generateRandomPosition();
    
    /// @brief free texture from memory
    ~Food();
};