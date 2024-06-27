#include "Game.h"

void Game::draw()
{
    snake.draw();
    food.draw();
}

void Game::update()
{
    snake.update();
    checkCollisions();

}

void Game::checkCollisions()
{
    // detect if the snake ate the food
    cout << "food: " << food.position.x << " " << food.position.y << endl;
    cout << "head: " << snake.body.front().x << " " << snake.body.front().y << endl;

    if (Vector2Equals(snake.body.front(), food.position))
    {
        food.position = food.generateRandomPosition();
        snake.body.push_back(snake.body.back());
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
    }

}