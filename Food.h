#pragma once
#include "Constants.h"

class Food
{
private:
    Texture2D texture;

public:
    Vector2 position;
    
    /// @brief Creates a food object
    Food();

    /// @brief Draws a food object in a random position
    void draw();

    /// @brief Return 2 random ints from 0 to cellCount - 1 inclusive
    Vector2 generateRandomPosition();
    
    /// @brief free texture from memory
    ~Food();
};