#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED
#pragma GCC diagnostic ignored "-fpermissive"

#include<iostream>
#include "Animation.hpp"

class Entity{
    private:
        float x;
        float y;
        float dx;
        float dy;
        float r;
        float angle;
        bool life;
        std::string name;
        Animation anim;
    public:
        Entity();
        Entity(Animation &a,int X,int Y,float ang=0,int radius=1);
        virtual void update();
        void draw(sf::RenderWindow &window);
        virtual ~Entity();
};

#endif // ENTITY_HPP_INCLUDED
