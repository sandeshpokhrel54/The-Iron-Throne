#include "Player.h"
#include "Game.h"

Player::Player(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed,sf::Vector2f playerPosition,bool faceRight):anime1(texture,imageCount,switchTime)
{
    body.setSize(sf::Vector2f(300.0f,450.0f));
    body.setOrigin(150.0f,225.0f);
    body.setPosition(playerPosition);
    lastPressed=' ';
    OppState=' ';

    hitCount=0;
    counter=0;
    lifecounter=0;
    row=0;
    health=100;
    this->faceRight=faceRight;
    this->speed=speed;
    y=9;

    Rhealth.setPosition(playerPosition.x,playerPosition.y-300); //red health bar
    Rhealth.setFillColor(sf::Color::Red);
    Rhealth.setSize(sf::Vector2f(200.0,30.0));
    Rhealth.setOrigin(50,15);
    Ghealth.setPosition(playerPosition.x,playerPosition.y-300); //green health bar
    Ghealth.setFillColor(sf::Color::Green);
    Ghealth.setSize(sf::Vector2f(200.0,30.0));
    Ghealth.setOrigin(50,15);



}

int Player::getRow()
{
    return row;
}

void Player::setTexture(sf::Texture* txtr)
{
    body.setTexture(txtr);      //fighter texture
}

 float Player::Update(float deltaTime,bool &acceptInput,bool &newgame)
        {
            if(newgame)  //if a user selects newgame after completing one;
            {
                health=100;
                body.setPosition(200.0,820.0f);
                newgame=false;
            }
            if(health>=0)
            {
                Ghealth.setSize(sf::Vector2f(health*2,30.0));  //green health bar sets size according to health
            }
            else
            {
                Ghealth.setSize(sf::Vector2f(0.0f,30.0f));
            }
            sf::Vector2f movement=sf::Vector2f (0.0f,0.0f);
            if(acceptInput){
            if(row!=9 && row!=10)  //9=player about to fall and 10=fall down
            {
            row=0;         //0=stand
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
            {
                movement.x-=20.0f;
                faceRight=false;
                row=1;   //1=walk

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                movement.x+=20.0f;
                row=1;      //1=walk
                faceRight=true;

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)|| lastPressed=='W')
            {
                lastPressed='W';
                row=3;      //3=jump
                counter++;
                if(counter>3)
                {
                    row=0;  //0=stand
                    counter=0;
                    acceptInput=false;
                    lastPressed=' ';
                }


            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                row=2; //crouch

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I)|| lastPressed=='I')
            {
                lastPressed='I';
                //action.punchmissed();
                row=4;      //4=punch
                if(faceRight)
                    movement.x+=7.0f;
                else
                    movement.x-=7.0f;

                counter++;
                if(counter>6)
                {
                 acceptInput=false;
                 lastPressed=' ';
                 row=0; //0=stand
                 counter=0;
                }

            }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J)|| lastPressed=='J')
             {
                 lastPressed='J';
                 //action.kickmissed();
                 row=7;  //7=round kick
                 if(faceRight)
                    movement.x+=7.0f;
                 else
                    movement.x-=7.0f;

                counter++;
                if(counter>6)
                {
                 acceptInput=false;
                 lastPressed=' ';
                 row=0;
                 counter=0;
                }

             }

              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O)||lastPressed=='O')
             {
                 lastPressed='O';
                 //action.punchmissed();
                 row=5;  //5=punch
                if(faceRight)
                    movement.x+=3.0f;
                else
                    movement.x-=3.0f;

                counter++;
                if(counter>6)
                {
                 acceptInput=false;
                 lastPressed=' ';
                 row=0;
                 counter=0;
                }

             }


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K)|| lastPressed=='K')
            {
                    //action.kickmissed();
                   lastPressed='K';
                   row=6; //6=kick
                 if(faceRight)
                    movement.x+=3.0f;
                 else
                    movement.x-=3.0f;

                 counter++;
                if(counter>6)
                {
                 acceptInput=false;
                 lastPressed=' ';
                 row=0;
                 counter=0;
                }

            }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V) ||lastPressed=='V')
            {
                row=8;  //8=block
                lastPressed='V';
                counter++;
                if(counter>3){

                acceptInput=false;
                lastPressed=' ';
                row=0;
                counter=0;
                }
            }

            }
             if(row==9)  //9= about to fall
           {
                counter++;
                if(counter>6)
                {
                    hitCount++;
                    if(hitCount>2)
                    {
                        row=10;  //fall down
                        action.thud();
                        movement.x-=10.0f;
                        hitCount=0;
                    }
                    else
                    {
                        row=0;
                    }
                        counter=0;
                }
            }

           if(row==10)  //fall down
        {
            counter++;
            if(counter>6)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                {
                row=11;  //about to stand up
                counter=0;
                }
            }
        }

        if(row==11)  //11=about to stand up
        {
           counter++;
           if(counter>6)
           {
            row=0;
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
        else    //false acceptinput condition
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I)||sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O)||sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J)||sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K))
            {
                acceptInput=false;
            }
            else
                acceptInput=true;

        }
       return health;
    }

void Player::UpdateOpp(float deltaTime,Player& player1,bool& OppUpdate,float &lev,bool &oppnewgame) //single player mode update opponent
{
    if(oppnewgame)
    {
        body.setPosition(sf::Vector2f(1400.f,820.f));
        health=100;
        y=9;  //this is difficulty factor
        oppnewgame=false;
    }
    if(health>=0){
        Ghealth.setSize(sf::Vector2f(health*2,30.0));
    }  //green health bar
    if(health<=0)
    {

        lev=lev+0.5;
        health=100;
        y-=1;
        body.setPosition(1400.f,820.f);
        player1.body.setPosition(200.0f,820.0f);
    }

    distance=body.getPosition().x-player1.getPosition().x;
    sf::Vector2f movement=sf::Vector2f (0.0f,0.0f);
    if(OppState==' ')
        x=rand();  //random number

    if(OppUpdate)
  {
    if(row!=9 && row!=10 && row!=11 && player1.row!=10)  //row 9=about to fall down,10=fall down,11=about to stand up
    {
        row=0; //row 0=stand
        if(distance<=220)
    {
        switch(x%y)             //remainder 0 to 8 in level 1
        {                         //0 to 6 in  level 2
        case 0:                     //0 to 4 in level 3
            row=6;
            //action.kickmissed();      //6=kick
            OppState='!';
            counter++;
            movement.x=-7.0f;
            if(counter>6)
                {
                    OppState=' ';
                    OppUpdate=false;
                    counter=0;
                }
            break;

        case 1:
            row=5;  //5=punch
            //action.punchmissed();
            OppState='!';
            counter++;
            movement.x=-7.0f;
            if(counter>6)
                {
                    OppState=' ';
                    OppUpdate=false;
                    counter=0;
                }
            break;

        case 2:
            row=7; //7=round kick
            //action.kickmissed();

            OppState='!';
            movement.x=-7.0f;
            counter++;
            if(counter>3)
                {
                    OppState=' ';
                    counter=0;
                }
            break;

        case 3:
            row=4;  //4=punch
            //action.punchmissed();
            counter++;
            OppState='!';
            movement.x=-7.0f;
            if(counter>6)
                {
                    OppState=' ';
                    OppUpdate=false;
                    counter=0;
                }

            break;


        case 4:

             row=8;     //8=block
            counter++;
            OppState='!';
            movement.x=3.0f;
            if(counter>6)
                {
                    OppState=' ';
                    OppUpdate=false;
                    counter=0;
                }

            break;

         case 5:

            row=1; //1=walk
            OppState='!';
            movement.x=7.0f;
            counter++;
            if(counter>3)
                {
                    OppState=' ';
                    OppUpdate=false;
                    counter=0;
                }
            break;


         case 6:
            row=8;  //8=block
            OppState='!';
            movement.x=7.0f;
             counter++;
            if(counter>3)
                {
                    OppState=' ';
                    OppUpdate=false;
                    counter=0;
                }
            break;

         case 7:
            OppState='!';
            row=1;   //1=walk
            movement.x=+3.0f;
             counter++;
            if(counter>3)
                {
                    OppState=' ';
                    OppUpdate=false;
                    counter=0;
                }
            break;

         case 8:
            OppState='!';
            //action.punchmissed();
            row=4;  //4=punch
            movement.x=-3.0f;
             counter++;
            if(counter>6)
                {
                    OppState=' ';
                    OppUpdate=false;
                    counter=0;
                }
            break;
        }
    }

    else            //distance>=220
        {
            switch(x%2)
            {
            case 0:
                 OppState='!';
                 row=1;              //walk
                 movement.x=-15.0f;
                 counter++;
                if(counter>6)
                {
                    OppState=' ';
                    OppUpdate=false;
                    counter=0;
                    row=0;
                }
                break;

            case 1:
                OppState='!';
                row=1;      //walk
                movement.x=-10.0f;
                counter++;
                if(counter>6)
                {
                    OppState=' ';
                    OppUpdate=false;
                    counter=0;
                    row=0;
                }
                break;

            }
        }
    }
  }

   else             //oppUpdate==false
  {
      counter++;
      row=0;
      if(counter>y)
      {
          OppUpdate=true;
          counter=0;
      }

  }


    if(player1.row==10)
        {
            row=1;
            if(distance<=200)
            movement.x=+10;
        }

    if(row==9)
        {
            counter++;
            if(counter>6)
            {
                 hitCount++;
                    if(hitCount>2)
                    {
                        row=10;
                        movement.x=10.0f;
                        hitCount=0;
                    }
                    else
                    {
                        row=0;
                    }
                 movement.x=+5.0f;
                 counter=0;
            }
        }

      if(row==10)
        {
            counter++;
            if(counter>6)
            {
                row=11;
                counter=0;

            }
        }

      if(row==11)
      {
          counter++;
          if(counter>3)
          {
              row=0;
              counter=0;
          }
      }

    anime1.Update(row,deltaTime,faceRight);
    body.setTextureRect(anime1.getUVrect());
    body.move(movement);

}


 void Player::Draw(sf::RenderWindow& Screen)
        {


            Screen.draw(body);
            Screen.draw(Rhealth);  //red health bar
            Screen.draw(Ghealth);  //green health bar


        }

sf::Vector2f Player::getSize()
{
    return body.getSize();
}

sf::Vector2f Player::getPosition()
{
    return body.getPosition();
}
 void Player::setPosition(sf::Vector2f position)
 {
     body.setPosition(position);

 }


bool Player::isColliding(Player &other)
{
    sf::Vector2f distance;

    distance.x=abs(body.getPosition().x-other.getPosition().x);
    distance.y=abs(body.getPosition().y-other.getPosition().y);
    if(distance.x<100 && distance.y<300)
    {
        body.move(-20.0f,0.0f);
        other.body.move(20.0f,0.0f);
    }

   if(distance.x<200 && distance.y<300)
    {
        if((other.row<8 || other.row==9) && (row<8 || row==9))
            {

            if(row>3 && row<8)
            {
                if (row == 5 )
                    action.punchlanded();

                if (row == 4)
                    action.punchlanded2();

                if (row==6)
                    action.kicklanded1();

                if (row = 7)
                    action.kicklanded2();

                other.row=9;
                reaction.grunt1();
                other.health-=10.0f;
            }

            if(other.row>3 && other.row<8)
            {
                if (other.row == 4 )
                    action.punchlanded();

                if (other.row == 5)
                    action.punchlanded2();

                if (other.row==6)
                    action.kicklanded1();

                if (other.row = 7)
                    action.kicklanded2();
                row=9;
                reaction.grunt2();
                health-=1.0f;
            }

            }
            //std::cout<<"Health : "<<health<<std::endl;
            //std::cout<<"Other Health : "<<other.health<<std::endl;
        return true;
    }

    else
    {
        return false;
    }

}

void Player::PlayerStatic(int stateRow, float deltaTime)
{
    anime1.Update(stateRow,deltaTime,faceRight);
    body.setTextureRect(anime1.getUVrect());
}

float& Player::getHealth()
{
    return health;
}
