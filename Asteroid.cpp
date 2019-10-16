#include "Asteroid.hpp"



Asteroid::Asteroid()
{
    dx = rand()%8-4;
    dy = rand()%8-4;
    name = "asteroid";
}

void Asteroid::update(int width,int height){
    x+=dx;
    y+=dy;
    if(x>width) x = 0;
    if(x<0) x = width;
    if(y>height) y = 0;
    if(y<0) y = height;
}
