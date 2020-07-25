#ifndef ANIME_H
#define ANIME_H
#include<SFML/Graphics.hpp>
#include"music.h"

class Anime
{
    public:


        Anime(sf::Texture* texture,sf::Vector2u imageCount,float switchTime);
        ~Anime();
        void Update(int row,float deltaTime,bool faceRight);
        sf::IntRect getUVrect();


    private:
         sf::Vector2u imageCount,currentImage;
         float totalTime;
         sf::Texture* playertxtr;
         float switchTime;
         sf::IntRect uvRect;


};

#endif // ANIME_H
