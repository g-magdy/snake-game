#include "Constants.h"
#include "Game.h"
/**
 * These are the global constants. They are declared as "extern" in Constants.h file.
 * To be used in all projects' files. they are only initialized her.
 */

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

const int cellSize = 28;
const int cellCount = 25;
const int offset = 75;

const int playWindowSize = cellSize * cellCount;
const int windowSize = playWindowSize + 2 * offset;

int currentFPS = 60;

const deque<Vector2> initialSnakeBody = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};

double lastUpdate = GetTime();

int main()
{
    InitWindow(windowSize, windowSize, "Snake Game");

    //! important: if you create textures before the InitWindow()
    //! you'll get segmentation fault

    // create game objects here
    Game game;

    SetTargetFPS(currentFPS);
    while (!WindowShouldClose())
    {
        // handle events here
        game.snake.readKey();

        // update objects here
        double curr = GetTime();
        if (curr - lastUpdate >= 0.3)
        {
            lastUpdate = curr;
            game.update();
        }

        BeginDrawing();
        ClearBackground(green);
        DrawRectangleLinesEx(
            Rectangle{offset - 5, offset - 5, playWindowSize + 10, playWindowSize + 10},
            5, darkGreen);

        // draw here
        game.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}