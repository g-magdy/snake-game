#include "Game.h"

Game::Game()
{
    gameIsRunning = true;
    gameisOver = false;
}

void Game::draw()
{
    snake.draw();
    food.draw();
}

void Game::update()
{
    if(gameIsRunning)
    {
        snake.update();
        checkCollisionWithFood();
        checkCollisionWithEdges();
        checkCollisionWithBody();
    }
}

void Game::checkCollisionWithFood()
{
    // detect if the snake ate the food
    if (Vector2Equals(snake.body.front(), food.position))
    {
        cout << "Snake Ate Food!\n";
        // generate a new food position that is out of the snake
        do
        {
            food.position = food.generateRandomPosition();
        } while (snake.contains(food.position));

        snake.body.push_back(snake.body.back());
    }
}

void Game::checkCollisionWithEdges()
{
    //detect collisions with edges
    if (snake.body[0].x >= cellCount || snake.body[0].x <= -1)
        gameOver();

    if (snake.body[0].y >= cellCount || snake.body[0].y <= -1)
        gameOver();
}

void Game::checkCollisionWithBody()
{
    for (int i = 1; i < snake.body.size(); i++)
    {
        if (Vector2Equals(snake.body[i], snake.body[0]))
            gameOver();
    }
}

void Game::gameOver()
{
    cout << "GAME OVER\n";
    gameIsRunning = false;
    gameisOver = true;
}