#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED


#include "Entity.hpp"

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

    public:
        Game();
        void gameStart();
};


#endif // GAME_HPP_INCLUDED



