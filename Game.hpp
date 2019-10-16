#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED


#include "Entity.hpp"
#include "Asteroid.hpp"
#include "Player.hpp"
#include <iostream>
#include <time.h>
class Game{
    private:
        int width;
        int height;
        sf::RenderWindow* window;
        sf::Texture background;
        sf::Texture player;
        sf::Texture explosion;
        sf::Texture small_explosion;
        sf::Texture rock;
        sf::Texture small_rock;
        sf::Texture bullet;
        sf::Sprite sBackground;
        Player* p;

    public:
        Game();
        void gameStart();
        bool isCollided(Entity* a,Entity* b);
        ~Game();
};


#endif // GAME_HPP_INCLUDED



