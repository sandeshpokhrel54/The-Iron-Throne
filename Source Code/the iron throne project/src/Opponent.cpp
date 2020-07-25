#include "Opponent.h"

Opponent::Opponent(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed,sf::Vector2f playerPosition,bool faceRight):Player(texture,imageCount,switchTime,speed,playerPosition,faceRight)
{
    //ctor
}

Opponent::~Opponent()
{
    //dtor
}

float Opponent::UpdatePlayer2(float deltaTime, bool& acceptInput2,bool &oppnewgame)  //2 player mode update player 2
{
            if(oppnewgame)          //if a user selects newgame after completing one;
            {
                health=100;
                body.setPosition(sf::Vector2f(1400.f,820.f));
                oppnewgame=false;
            }
            if(health>=0){
            Ghealth.setSize(sf::Vector2f(health*2,30.0));  //green health bar
            }
            sf::Vector2f movement=sf::Vector2f (0.0f,0.0f);
            if(acceptInput2)
        {
            if(row!=9 && row!=10)  //row 9=about to fall down and 10= fall down
            {
            row=0;  //stand
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
            {
                movement.x-=20.0f;
                faceRight=false;
                row=1;  //walk

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                movement.x+=20.0f;
                row=1;  //walk
                faceRight=true;

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)|| lastPressed=='!')
            {
                lastPressed='!';
                row=3;  //jump
                counter++;
                if(counter>3)
                {
                    row=0;
                    counter=0;
                    acceptInput2=false;
                    lastPressed=' ';
                }


            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                row=2;//crouch

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1)|| lastPressed=='1')
            {
                lastPressed='1';

                row=4;  //punch
                if(faceRight)
                    movement.x+=7.0f;
                else
                    movement.x-=7.0f;

                counter++;
                if(counter>6)
                {
                 acceptInput2=false;
                 lastPressed=' ';
                 row=0;  //stand
                 counter=0;
                }

            }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2)|| lastPressed=='2')
             {
                 lastPressed='2';
                 row=7;  //round kick
                 if(faceRight)
                    movement.x+=7.0f;
                 else
                    movement.x-=7.0f;

                counter++;
                if(counter>6)
                {
                 acceptInput2=false;
                 lastPressed=' ';
                 row=0;  //stand
                 counter=0;
                }

             }

              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad5)||lastPressed=='5')
             {
                 lastPressed='5';
                 row=5;  //punch
                if(faceRight)
                    movement.x+=3.0f;
                else
                    movement.x-=3.0f;

                counter++;
                if(counter>6)
                {
                 acceptInput2=false;
                 lastPressed=' ';
                 row=0;  //stand
                 counter=0;
                }

             }


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad4)|| lastPressed=='4')
            {
                   lastPressed='4';
                   row=6;  //kick
                 if(faceRight)
                    movement.x+=3.0f;
                 else
                    movement.x-=3.0f;

                 counter++;
                if(counter>6)
                {
                 acceptInput2=false;
                 lastPressed=' ';
                 row=0;  //stand
                 counter=0;
                }

            }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad0) ||lastPressed=='0')
            {
                row=8;  //block
                lastPressed='0';
                counter++;
                if(counter>3){

                acceptInput2=false;
                lastPressed=' ';
                row=0;  //stand
                counter=0;
                }
            }

            }
             if(row==9)  //about to fall down
           {
                counter++;
                if(counter>6)
                {
                    hitCount++;
                    if(hitCount>2)
                    {
                        row=10;  //fall down
                        movement.x-=10.0f;
                        hitCount=0;
                    }
                    else
                    {
                        row=0;//stand
                    }
                        counter=0;
                }
            }

           if(row==10)  //fall down
        {
            action.thud();
            counter++;
            if(counter>6)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                {
                row=11;  //about to stand up
                counter=0;
                }
            }
        }

        if(row==11)  //about to stand up
        {
           counter++;
           if(counter>6)
           {
            row=0; //stand
            counter=0;
           }
        }

        if(body.getPosition().x<0)
            {
                movement.x=0;
                body.setPosition(body.getPosition().x+1,body.getPosition().y);
            }
        if(body.getPosition().x>1680)
        {
            movement.x=0;
            body.setPosition(body.getPosition().x-1,body.getPosition().y);

        }

            anime1.Update(row,deltaTime,faceRight);
            body.setTextureRect(anime1.getUVrect());
            body.move(movement);

    }
        else
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)||sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)||sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)||sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5))
            {
                acceptInput2=false;
            }
            else
                acceptInput2=true;

        }

        return health;
}
