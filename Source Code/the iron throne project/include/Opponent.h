#ifndef OPPONENT_H
#define OPPONENT_H

#include <Player.h>


class Opponent : public Player
{
    public:
         Opponent(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed,sf::Vector2f playerPosition,bool faceRight);
         float UpdatePlayer2(float deltaTime, bool& acceptInput2,bool& oppnewgame);
         ~Opponent();

    protected:

    private:
};

#endif // OPPONENT_H
