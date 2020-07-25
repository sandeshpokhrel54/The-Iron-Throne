
#include "Anime.h"

Anime::Anime(sf::Texture* texture,sf::Vector2u imageCount,float switchTime)
{
    this->imageCount=imageCount;
    this->switchTime=switchTime;
    currentImage.x=0;
    totalTime=0.0f;
    playertxtr=texture;


}

Anime::~Anime()
{

}

void Anime::Update(int row,float deltaTime,bool faceRight)
{
     uvRect.width=playertxtr->getSize().x/float(imageCount.x);   //width of each player
     uvRect.height=playertxtr->getSize().y/float(imageCount.y);  //height of each player

    currentImage.y=row;

    totalTime+=deltaTime;
    if(row>0 && row!=10){

    if(totalTime>=switchTime)
    {
     totalTime-=switchTime;
     currentImage.x++;

        if(currentImage.x>=imageCount.x)
        {
                    currentImage.x=0;
        }
    }
    }

    uvRect.top=currentImage.y*uvRect.height;

    if(faceRight)
    {
        uvRect.left=currentImage.x*abs(uvRect.width);
        uvRect.width=abs(uvRect.width);
     }
    else
    {
        uvRect.left=(currentImage.x+1)*abs(uvRect.width);
        uvRect.width= -abs(uvRect.width);
    }

}
sf::IntRect Anime::getUVrect()
{
    return uvRect;
}
