#include "Game.hpp"

Game::Game(){
    width = 1920;
    height = 1080;
    window = new sf::RenderWindow();
}

void Game::gameStart(){
    /**create the fullscreen window and set max frame rate to 60**/
    window->create(sf::VideoMode(width,height,32),"Asteroid",sf::Style::Fullscreen);
    window->setFramerateLimit(60);

    /**Load all the texture from the image**/
    background.loadFromFile("images/background.jpg");
    player.loadFromFile("images/spaceship.png");
    explosion.loadFromFile("images/explosions/type_C.png");
    small_explosion.loadFromFile("images/explosions/type_B.png");
    rock.loadFromFile("images/rock.png");
    small_rock.loadFromFile("images/rock_small.png");
    bullet.loadFromFile("images/fire_blue.png");

    player.setSmooth(true);
    background.setSmooth(true);
    sBackground.setTexture(background);

    Animation sExplosion(explosion,0,0,256,256,48,0.5);
    Animation sSmall_explosion(small_explosion,0,0,192,192,64,0.5);
    Animation sRock(rock,0,0,64,64,16,0.2);
    Animation sSmall_rock(small_rock,0,0,64,64,16,0.2);
    Animation sBullet(bullet,0,0,32,64,16,0.8);
    Animation sPlayer(player,40,0,40,40,1,0);
    Animation sPlayer_move(player,40,40,40,40,1,0);


    std::list<Entity*> entities;
    while(window->isOpen()){
        sf::Event ev;
        while(window->pollEvent(ev)){
            if(ev.type == sf::Event::Closed){
                window->close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window->close();
        }
        window->clear();
        window->draw(sBackground);
        window->display();
    }
    window->close();
}
