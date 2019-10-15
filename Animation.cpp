#include "Animation.hpp"

Animation::Animation(){

}

Animation::Animation(sf::Texture &t,int x,int y,int w,int h, int count,float speed){
    frame = 0;
    speed = speed; //speed for switching between the frame
    /**
    split the image into frame based on the image
    **/
    for(int i = 0;i<count;i++){
        frames.push_back(sf::IntRect(x+i*w,y,w,h));
    }

    sprite.setTexture(t);

    /**set the sprite at the middle of the screen*/
    sprite.setOrigin(w/2,h/2);

    /*use the first texture as default*/
    sprite.setTexture(frames[0]);

}

void Animation::update(){
    frame += speed;
    int size = frames.size();
    if(frame >= size){
       frame -= size;
    }
    if(size>0){
        sprite.setTexture( frames[int(frame)] );
    }
}


bool Animation::isEnd(){
    /**
    check if the current frame is the final frame of the list contains all the frames
    **/
    return frame+speed >= frames.size();
}
