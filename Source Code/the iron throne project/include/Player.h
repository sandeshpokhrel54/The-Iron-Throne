#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include"Anime.h"


class Player
{
    public:
        Player(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed,sf::Vector2f playerPosition,bool faceRight);
        float Update(float deltaTime,bool& acceptInput,bool& newgame);
        void UpdateOpp(float deltaTime,Player &player1,bool& OppUpdate,float &lev,bool &oppnewgame);
        void PlayerStatic(int stateRow, float deltaTime);
        void Draw(sf::RenderWindow& Screen);
        void setPosition(sf::Vector2f position);
        bool isColliding(Player &other);
        void setTexture(sf::Texture* txtr);
        int getRow();
        float& getHealth();
        sf::Vector2f getSize();
        sf::Vector2f getPosition();


    protected:
        sf::RectangleShape body;
        Anime anime1;
        int counter;
        int counter2;
        int hitCount;
        bool faceRight;
        float speed;
        char lastPressed;
        char OppState;
        int lifecounter;
        int x; // x state of Opponent
        int y; // difficulty in 1vCPU
        float distance;
        int row;
        float health;


        sf::RectangleShape Ghealth;
        sf::RectangleShape Rhealth;
        music action,reaction;

};

#endif


