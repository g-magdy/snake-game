#include <raylib.h>
#include <iostream>
#include "Food.h"
// Color {r, g, b, alpha}
// 0 (transparent) <= alpha <= 255 (opaque)

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

const int cellSize = 30;
const int cellCount = 25; 

const int windowSize = cellSize * cellCount;

int main()
{
    InitWindow(windowSize, windowSize, "Snake Game");

    //! important: if you create textures before the InitWindow()
    //! you'll get segmentation fault

    // create game objects here
    Food f1;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // handle events here

        // update objects here

        BeginDrawing();
        ClearBackground(green);
        
        // draw here
        f1.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}