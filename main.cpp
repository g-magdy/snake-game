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

int currentFPS = 30;

const deque<Vector2> initialSnakeBody = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};

double lastUpdate = GetTime();

const double initialInterval = 0.2;

// as this gets smaller, the game gets faster.
double interval = initialInterval;



enum GameState
{
    PLAYING,
    PAUSED,
    GAMEOVER
};

int main()
{
    InitWindow(windowSize, windowSize, "Snake Game");
    GameState state = PLAYING;
    //! important: if you create textures before the InitWindow()
    //! you'll get segmentation fault

    const char *title = "Retro Snake";
    const char *pause_msg = "Press P to Pause, Press Esc to Exit";

    // create game objects here
    Game game;

    SetTargetFPS(currentFPS);
    while (!WindowShouldClose())
    {
        // handle events here
        if (state == PLAYING)
            game.snake.readKey();

        if (game.gameisOver)
            state = GAMEOVER;

        if (state == PLAYING && IsKeyPressed(KEY_P))
        {
            state = PAUSED;
        }
        else if (state == PAUSED && IsKeyPressed(KEY_P))
        {
            state = PLAYING;
        }
        else if (state == GAMEOVER && IsKeyPressed(KEY_ENTER))
        {
            state = PLAYING;
            game.gameisOver = false;
            game.gameIsRunning = true;
            interval = initialInterval;
            game.snake.reset();
            game.food.reset();
        }

        // update objects here
        double curr = GetTime();
        if (curr - lastUpdate >= interval && state == PLAYING)
        {
            lastUpdate = curr;
            game.update();
        }

        BeginDrawing();
        ClearBackground(green);
        // draw here

        DrawRectangleLinesEx(
            Rectangle{offset - 5, offset - 5, playWindowSize + 10, playWindowSize + 10},
            5, darkGreen);

        game.draw();

        DrawText("Retro Snake", offset - 5, 20, 40, darkGreen);
        DrawText(TextFormat("Score: %i", game.snake.body.size() - initialSnakeBody.size()), windowSize - 3 * offset, 20, 40, darkGreen);
        
        if (state == PLAYING)
            DrawText("Press P to Pause, Press Esc to Exit", offset, windowSize - 50, 30, darkGreen);
        else if (state == PAUSED)
        {
            DrawText("PAUSED", windowSize/2 - 120, windowSize/2 - 300, 60, darkGreen);
            DrawText("Press P to Continue, Press Esc to Exit", offset, windowSize - 50, 30, darkGreen);
        }
        else
        {
            DrawText("GAME OVER", windowSize/2 - 180, windowSize/2 - 300, 60, darkGreen);
            DrawText("Press Enter to Start again, Press Esc to Exit", offset, windowSize - 50, 30, darkGreen);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}