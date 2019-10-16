#ifndef ANIMATION_HPP_INCLUDED
#define ANIMATION_HPP_INCLUDED


#include <list>
#include <SFML/Graphics.hpp>


class Animation{
    private:
        float frame;
        float speed;
        std::vector<sf::IntRect> frames;
    public:
        sf::Sprite sprite;
        Animation();
        Animation(sf::Texture &t,int x,int y,int w, int h,int count,float Speed);
        void update();
        bool isEnd();
        sf::Sprite getSprite();
};
#endif // ANIMATION_HPP_INCLUDED
