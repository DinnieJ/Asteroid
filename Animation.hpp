#ifndef ANIMATION_HPP_INCLUDED
#define ANIMATION_HPP_INCLUDED


#include <list>
#include <SFML/Graphics.hpp>


class Animation{
    private:
        float frame;
        float speed;
        sf::Sprite sprite;
        std::vector<sf::IntRect> frames;
    public:
        Animation();
        Animation(sf::Texture &t,int x,int y,int w, int h,int count,float speed);
        void update();
        bool isEnd();
};
#endif // ANIMATION_HPP_INCLUDED
