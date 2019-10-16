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
    window->setMouseCursorVisible(false);
    srand(time(0));

    /**Load all the texture from the image**/
    std::cout<<"Loading texture..."<<std::endl;

    if(!background.loadFromFile("images/background.jpg")){
        return;
    };
    if(!player.loadFromFile("images/spaceship.png")){
        return;
    };

    if(!explosion.loadFromFile("images/explosions/type_C.png")){
        return;
    };

    if(!small_explosion.loadFromFile("images/explosions/type_B.png")){
        return;
    };

    if(!rock.loadFromFile("images/rock.png")){
        return;
    };
    if(!small_rock.loadFromFile("images/rock_small.png")){
        return;
    };

    if(!bullet.loadFromFile("images/fire_blue.png")){
        return;
    };


    std::cout<<"Set background..."<<std::endl;
    player.setSmooth(true);
    background.setSmooth(true);
    sBackground.setTexture(background);

    std::cout<<"Load animations..."<<std::endl;

    /**Get the animation by spliting frame in png file, basically, making the entity become a moving image**/
    Animation sExplosion(explosion,0,0,256,256,48,0.5);
    Animation sSmall_explosion(small_explosion,0,0,192,192,64,0.5);
    Animation sRock(rock,0,0,64,64,16,0.2);
    Animation sSmall_rock(small_rock,0,0,64,64,16,0.2);
    Animation sBullet(bullet,0,0,32,64,16,0.8);
    Animation sPlayer(player,40,0,40,40,1,0);
    Animation sPlayer_move(player,40,40,40,40,1,0);

    /**Array store all the entities of the game**/
    std::list<Entity*> entities;

    /**initial first 3 asteroids**/
    for(int i = 0;i<20;i++){
        Asteroid* a = new Asteroid();
        a->init(sRock,rand()%width,rand()%height,rand()%360,25);
        entities.push_back(a);
    }
    /**initial player**/

    p = new Player();
    p->init(sPlayer,width/2,height/2,0,20);
    entities.push_back(p);

    std::cout<<"Start game!\n"<<std::endl;

    /**Main game flow**/
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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            p->angle+=3;
            //std::cout<<"Turn right"<<std::endl;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            p->angle-=3;
            //std::cout<<"Turn left"<<std::endl;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            p->nitro = 1;
            p->anim = sPlayer_move;
            //std::cout<<"Thurst!"<<std::endl;
        }else {
            p->nitro = 0;
            p->anim = sPlayer;
        }
        /**Check for collision**/
        for(auto a:entities){
            for(auto b:entities){

                /**Case where player collide with the asteroid**/
                if(a->name=="player" && b->name=="asteroid"){
                    if(isCollided(a,b)){
                        b->life = 0;
                        Entity* e = new Entity();
                        e->init(sSmall_explosion,a->x,b->y);
                        e->name="explosion";
                        entities.push_back(e);
                        p->init(sPlayer,width/2,height/2,0,20);
                        p->dx = 0;
                        p->dy = 0;
                    }
                }
            }
        }

        for(auto e:entities){
            if(e->name=="explosion"){
                if(e->anim.isEnd()){
                    e->life = 0;
                }
            }
        }
        for(auto i=entities.begin();i!=entities.end();)
        {
          auto *e = *i;

          e->update(width,height);
          e->anim.update();

          if (e->life==false) {i=entities.erase(i); delete e;}
          else i++;
        }
        window->clear();
        window->draw(sBackground);
        for(auto i:entities){
            i->draw(window);
        }
        window->display();
    }
}
bool Game::isCollided(Entity* a, Entity* b){
    return (b->x - a->x)*(b->x - a->x)+
         (b->y - a->y)*(b->y - a->y)<
         (a->r + b->r)*(a->r + b->r);
}
Game::~Game(){
    std::cout<<"Closing the game"<<std::endl;
    window->close();
    std::cout<<"Game closed"<<std::endl;
}
