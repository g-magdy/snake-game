#include "Game.h"

Game::Game()
{
    gameIsRunning = true;
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

        snake.body.push_back(Vector2Subtract(snake.body.back(), snake.direction));
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

void Game::gameOver()
{
    cout << "GAME OVER\n";
    gameIsRunning = false;
}