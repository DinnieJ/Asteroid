#include "Entity.hpp"

Entity::Entity(){
    life = 1;
}

void Entity::init(Animation &a,int X,int Y,float ang,int radius){
        anim = a;
        x = X;
        y = Y;
        angle = ang;
        r = radius;
}



void Entity::draw(sf::RenderWindow* window){
    anim.sprite.setPosition(x,y);
    anim.sprite.setRotation(angle+90);
    window->draw(anim.getSprite());

    sf::CircleShape circle(r);
    circle.setFillColor(sf::Color(255,0,0,170));
    circle.setPosition(x,y);
    circle.setOrigin(r,r);
}


