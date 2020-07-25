#include "Game.h"

Game::Game():Screen(sf::VideoMode(1680,1080),"The Iron Throne",sf::Style::Default),player1(&player1Texture[0],sf::Vector2u(6,12),0.01f,1.0f,sf::Vector2f(200.0f,820.0f),true),opponent1(&player1Texture[2],sf::Vector2u(6,12),0.01f,1.0f,sf::Vector2f(1400.0f,820.0f),false),Opponent1(&player1Texture[2],sf::Vector2u(6,12),0.01f,1.0f,sf::Vector2f(1400.0f,820.0f),false)
{
    //ctor initialized players, screens and opponent objects

        state=State::INTRO;
        Screen.setFramerateLimit(8);

        Intro.setSize(sf::Vector2f(1680.f,1080.0f));  //intro page elements   (elements: txtr, shapes, size, position and all)
        intro.loadFromFile("intro.png");
        Intro.setTexture(&intro);

        font.loadFromFile("crackman.ttf");    //fonts
        font2.loadFromFile("font2.ttf");
        introText.setString("Press Space to continue!");
        introText.setFont(font);
        introText.setCharacterSize(100);
        introText.Bold;
        introText.setFillColor(sf::Color::White);   //intro texts and size and co-ordinates...
        introRect= introText.getLocalBounds();
        introText.setOrigin(introRect.left+introRect.width/2.0f,introRect.top+introRect.height/2.0f);
        introText.setPosition(1680/2.f,1080/1.2f);


        mainmenu.loadFromFile("main_menu.png");   //main-menu page elements
        MainMenu.setTexture(&mainmenu);
        MainMenu.setSize(sf::Vector2f(1680.0f,1080.0f));

        menuPos=sf::Vector2f(1080.0f,700.0f);       //main-menu texture and navigator for main menu
        menuSelect.setPosition(menuPos);
        selecTexture.loadFromFile("mainmenusign.png");
        menuSelect.setTexture(&selecTexture);
        menuSelect.setRadius(50.0f);


        Options.setSize(sf::Vector2f(1680.f,1080.f));   //Options page elements // basically the image textr only
        options.loadFromFile("options.png");
        Options.setTexture(&options);

        Mode.setSize(sf::Vector2f(1680.0f,1080.0f)); // Mode select page elements
        ModeTexture.loadFromFile("Mode.png");
        Mode.setTexture(&ModeTexture);

        Campaign.setString("Campaign");   // Campaign mode with text objects
        Campaign.setFont(font);
        Campaign.setCharacterSize(100);
        Campaign.setPosition(100.0f,900.0f);
        CampaignRect=Campaign.getLocalBounds();

        Multiplayer.setString("Multiplayer");  // multiplayer mode text objects
        Multiplayer.setFont(font);
        Multiplayer.setCharacterSize(100);
        Multiplayer.setPosition(950.0f,900.0f);
        MultiRect=Multiplayer.getLocalBounds();



        CharSelectPage.loadFromFile("CharSelect.png");  // character select page elements
        CharSelect.setTexture(&CharSelectPage);
        CharSelect.setSize(sf::Vector2f(1680.0f,1080.0f));
        selectorPos=sf::Vector2f(125.0f,320.0f);         // rectangle shape used as navigator here
        Selector.setPosition(selectorPos);
        selector.loadFromFile("selectChar.png");         // navigators txtr and elements
        Selector.setTexture(&selector);
        Selector.setSize(sf::Vector2f(345.0f,525.0f));

        selectorPos2=sf::Vector2f(485.0f,320.0f);     // navigator for multiplayer mode (txtr,size and position)
        Selector2.setPosition(selectorPos2);
        selector2.loadFromFile("selectChar2.png");
        Selector2.setTexture(&selector2);
        Selector2.setSize(sf::Vector2f(345.0f,525.0f));


        ArenaPos=sf::Vector2f(700.0f,120.0f);                 // Arena page elements
        ArenaSelect.setSize(sf::Vector2f(1680.f,1080.f));     // Arena Select Navigator
        ArenaSelectxtr.loadFromFile("Arena_Select.png");      //navigators txtr
        ArenaSelect.setTexture(&ArenaSelectxtr);
        ArenaSelector.setTexture(&selecTexture);
        ArenaSelector.setRadius(50.0f);
        ArenaSelector.setPosition(ArenaPos);

        ArenaTxtr[0].loadFromFile("arena1.png");             // arena page txtr
        ArenaTxtr[1].loadFromFile("arena3.png");
        ArenaTxtr[2].loadFromFile("arena2.png");
        Arena.setSize(sf::Vector2f(1680.f,1080.f));


        player1Texture[0].loadFromFile("jinn211.png");
        player1Texture[1].loadFromFile("vader-jinn.png");
        player1Texture[2].loadFromFile("chhota_hulk1.png");   // players txtrs
        player1Texture[3].loadFromFile("purple-dress01.png");
        player1Texture[0].setSmooth(true);
        player1Texture[1].setSmooth(true);                    // to avoid image pixels showing up
        player1Texture[2].setSmooth(true);
        player1Texture[3].setSmooth(true);
        opponent1.setTexture(&player1Texture[2]);

        Transit[0].loadFromFile("Transit2.png");              // for story like experience , story in campaign mode
        Transit[1].loadFromFile("Transit1.png");              //just image txtr for story
        transit.setSize(sf::Vector2f(1680.0f,1080.0f));
        transit.setTexture(&Transit[0]);
        transit2.setTexture(&Transit[1]);

        levelText.setFont(font2);                        //text for level 1,2,3
        levelText.setCharacterSize(100);
        levelText.setFillColor(sf::Color::White);        // level text objects to show up at every level
        levelText.setPosition(200.0,400.0);
        levelText.setString("Level 1\n\nPress Space to Continue...");

        winText.setFont(font2);
        winText.setCharacterSize(50);                    // game over texts
        winText.setFillColor(sf::Color::White);
        winText.setPosition(100.0,100.0);


        over.setSize(sf::Vector2f(1680.0f,1080.0f));         // game over txtrs
        overT.loadFromFile("over.png");
        over2.loadFromFile("over2.png");


        winsT.loadFromFile("hero-wins.png");


        acceptInput=true;
        acceptInput2=true;
        newgame=false;
        oppnewgame=false;                              // booleans for toggling input from player
        OppUpdate=true;
        counter=0;
        levCounter=0;

        level=1;
        resurrect=true;
        showlevel2=true;                           // more booleans, but they are for level toggling , life toggling and so on.
        showlevel3=true;
        showlevel15=true;
        showlevel25=true;
        f = false;     //index for  round voice toggle

        sounds.playtheme();   // music starts with game




}


void Game::Run()

{
    while(Screen.isOpen())   // this is everything happening basically while screen is open
    {

        Update();              // updates as player inputs. Most of the game events
        Draw();                // draws the updates
        ProcessEvents();       // not much here just few events of the windows are processed like resize, close
    }
}

void Game::ProcessEvents()    //events of the window (screen) processed
{
    sf::Event event;
    dt=clock.restart().asSeconds();
    while(Screen.pollEvent(event))
    {

        switch(event.type)
        {
            case event.Closed:
                Screen.close();
                break;

        }

    }
}

void Game::Update()  //update actions
                    // now the long ride starts
{

    if(state==State::INTRO)   // intro state update conditions
        {


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
           sounds.cursorSelect();   //music for cursor select
              state=State::MAINMENU;  // state transferred to main-menu
        }
        }

    if(state==State::MAINMENU)  // mainmenu of the game
        {

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)&& menuPos.y>350)
        {
           sounds.cursorMove();                                         //cursor move music
            menuPos.y-=180.0f;                                          //too many if for navigating between the game states
            menuSelect.setPosition(menuPos);                            // menu selector navigation
        }

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && menuPos.y<700)
        {
            sounds.cursorMove();                                        // menu selector navigation
            menuPos.y+=180.0f;
            menuSelect.setPosition(menuPos);
        }

        if(menuPos.y==700.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {

            sounds.cursorSelect();                                       //quits the game
            Screen.close();
        }

        if(menuPos.y==520.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
           sounds.cursorSelect();                //enter pressed music
            state=State::OPTIONS;                //input option selected
        }

        if(menuPos.y==340.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            sounds.cursorSelect();
            state=State::MODE;                  //moves to the mode select page
        }

    }

    if(state==State::MODE)                     // mode select page to go single player or multiplayer
    {
       sf::Vector2i Mouse;
       Mouse=sf::Mouse::getPosition(Screen);
       Multiplayer.setFillColor(sf::Color::White);
       Campaign.setFillColor(sf::Color::White);


       if(Mouse.x>Campaign.getPosition().x && Mouse.x<(Campaign.getPosition().x+CampaignRect.width))        //mouse pointer navigation for selection
       {
           if(Mouse.y>Campaign.getPosition().y && Mouse.y<(Campaign.getPosition().y+CampaignRect.height))
           {
                sounds.cursorMove();
               Campaign.setFillColor(sf::Color::Red);  //text color changed
               if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        sounds.cursorSelect();
                        state=State::SINGLE;           //state changed to single player mode
                    }
           }
       }

       if(Mouse.x>Multiplayer.getPosition().x && Mouse.x<(Multiplayer.getPosition().x +MultiRect.width))
       {
           if(Mouse.y>Multiplayer.getPosition().y && Mouse.y<(Multiplayer.getPosition().y+MultiRect.height))
           {
               sounds.cursorMove();
               Multiplayer.setFillColor(sf::Color::Red);                //text color changed
               if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        sounds.cursorSelect();
                        state=State::MULTI;                      //state changed to multi-player mode
                    }
           }
       }

    }

    if(state==State::SINGLE)   //in single player state
      {

            state=State::TRANSITION;   //state transferred immediately
            player1.setTexture(&player1Texture[0]);  //why this state ??
            Arena.setTexture(&ArenaTxtr[0]);  // selects the arena and player for single player mode
            sounds.story();


      }

     if(state==State::MULTI)   //state tranferred to multiplayer and shifted immediately to characters select stage
      {
            extrasounds.cstrack();
            state=State::CHARACTERS;
            counter=0;
      }



    if(state==State::TRANSITION)                //for single player mode
    {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
            {
                    transit2.setSize(sf::Vector2f(1680.0f,1080.0f));                                    //just two pages of images basically for story like feeling
                    transit2.setTexture(&Transit[1]);
                   //texture changed
                counter++;                         // counter to check enter pressed twice before state change
                if(counter==2)
                {
                    state=State::LEVEL;               //toggles to level display state
                    sounds.Arena1();
                    counter=0;
                    transit2.setSize(sf::Vector2f(0.0f,0.0f));
                }

            }

    }
    if(state==State::LEVEL)                     //only for single player mode
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            {
                sounds.round1();             //music for round 1
                state=State::PLAYING1;        // state transferred to gameplay -single player as selected before
            }


    }

      if(state==State::ARENA)     //arena selection is only available for two player mode
    {

//for multiplayer arena choose option


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {

            sounds.cursorSelect();  //escapes back to mainmenu
           state=State::MAINMENU;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)&& ArenaPos.y>150)
        {
            sounds.cursorMove();
            ArenaPos.y-=360.0f;                  //arena navigation with music
            ArenaSelector.setPosition(ArenaPos);
        }

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && ArenaPos.y<800)
        {
            sounds.cursorMove();
            ArenaPos.y+=360.0f;                      //arena navigation with music
            ArenaSelector.setPosition(ArenaPos);

        }

         if(ArenaPos.y==120 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            sounds.cursorSelect();

             Arena.setTexture(&ArenaTxtr[0]);
             state=State::PLAYING2;                           //arena selected and proceeds to playing

             extrasounds.multip();
             sounds.twop();
        }

        if(ArenaPos.y==480 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {

            sounds.cursorSelect();

            Arena.setTexture(&ArenaTxtr[1]);
            state=State::PLAYING2;                       //arena selected and proceeds to playing

            extrasounds.multip();                          //some more music
            sounds.twop();
        }

        if(ArenaPos.y==840 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
           sounds.cursorSelect();

            Arena.setTexture(&ArenaTxtr[2]);
            state=State::PLAYING2;                           //arena selected and proceeds to playing

            extrasounds.multip();
            sounds.twop();
        }
    }

    if(state==State::CHARACTERS)       //character selection is only available for two player mode
    {
        if(counter==1) // counter for both players character selection     //counter 0 at start
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)&& selectorPos2.x>=150)
        {
           sounds.cursorMove();
            selectorPos2.x-=360.0f;                        //character navigation left
            Selector2.setPosition(selectorPos2);
        }

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && selectorPos2.x<=1000)
        {
            sounds.cursorMove();
            selectorPos2.x+=360.0f;                     //character navigation right
            Selector2.setPosition(selectorPos2);
        }

        //character selection with enter pressed
        //opponent player txtr set

        if(selectorPos2.x==125 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {

            sounds.cursorSelect();
            Opponent1.setTexture(&player1Texture[0]);
            state=State::ARENA;
             extrasounds.arenatrack();
        }

        if(selectorPos2.x==485 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            sounds.cursorSelect();
            Opponent1.setTexture(&player1Texture[1]);
            state=State::ARENA;
             extrasounds.arenatrack();
        }

        if(selectorPos2.x==845 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            sounds.cursorSelect();
            Opponent1.setTexture(&player1Texture[2]);
            state=State::ARENA;
             extrasounds.arenatrack();
        }

        if(selectorPos2.x==1205 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            sounds.cursorSelect();
            Opponent1.setTexture(&player1Texture[3]);
            state=State::ARENA;
             extrasounds.arenatrack();
        }
        }

        else{
                   //player1 character select navigation
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)&& selectorPos.x>=150)
        {
            sounds.cursorMove();
            selectorPos.x-=360.0f;
            Selector.setPosition(selectorPos);
        }

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && selectorPos.x<=1000)
        {
            sounds.cursorMove();
            selectorPos.x+=360.0f;
            Selector.setPosition(selectorPos);
        }

        //character selection with enter pressed
        //player1 txtr set

        if(selectorPos.x==125 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {

           sounds.cursorSelect();
             player1.setTexture(&player1Texture[0]);
             counter=1; //counter set for opponent to choose player
        }

        if(selectorPos.x==485 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            sounds.cursorSelect();
            player1.setTexture(&player1Texture[1]);
            counter=1;
        }

        if(selectorPos.x==845 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            sounds.cursorSelect();
            player1.setTexture(&player1Texture[2]);
            counter=1;
        }

        if(selectorPos.x==1205 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            sounds.cursorSelect();
            player1.setTexture(&player1Texture[3]);
            counter=1;
        }
        }




         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
         {

         sounds.cursorSelect();
          state=State::MAINMENU;          //escape to main menu    // basically the back button
         }

    }





    if(state==State::OPTIONS)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
        sounds.cursorSelect();
        state=State::MAINMENU;
        }
    }

    if(state==State::VictoryA || state==State::VictoryB)
    {
//in game transitions
// one player standing and the other one down for round toggling

        if(state==State::VictoryA)   //victoryA for standing player
        {

            player1.PlayerStatic(0,dt);
            opponent1.PlayerStatic(10,dt);

            counter++;
            if(counter>25)
            {
                player1.getHealth()=(100-player1.getHealth())/2+player1.getHealth();
                if (level == 1.5 || level == 2.5)
                {
                    if(f==true)
                    {
                        sounds.finalRound();
                        f=false;


                    }
                    else
                    {

                    sounds.round2();
                    f=true;
                    }
                }
                state=State::PLAYING1;
                counter=0;
            }
        }

        if(state==State::VictoryB)   //victory B for standing opponent
        {
            player1.PlayerStatic(10,dt);
            opponent1.PlayerStatic(0,dt);
            player1.setPosition(sf::Vector2f(200.0f,820.0f));

            counter++;
            if(counter>25)
            {
                if (level == 1.5 || level == 2.5)
                {
                    if(f==true)
                    {
                        sounds.finalRound();
                        f=false;


                    }
                    else
                    {

                    sounds.round2();
                    f=true;
                    }
                }
                state=State::PLAYING1;
                counter=0;
            }
        }
    }



    if(state==State::PLAYING1)          //vs CPU mode
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
             level=1;        //after celebration all reset to default
            showlevel2=true;
            showlevel3=true;
            showlevel15=true;
            showlevel25=true;
            newgame=true;
            oppnewgame=true;
            resurrect=true;
            state=State::MAINMENU;  //again to mainmenu
            sounds.playtheme();
            opponent1.setTexture(&player1Texture[2]);
            levelText.setString("Level 1\n\nPress Space to Continue...");

        }

        health=player1.Update(dt,acceptInput,newgame);
        opponent1.UpdateOpp(dt,player1,OppUpdate,level,oppnewgame);
        player1.isColliding(opponent1);

        if(health<=0 && resurrect==true)
        {
            state=State::VictoryB;
            player1.getHealth()=100;
            health=100;
            opponent1.getHealth()=(100-opponent1.getHealth())/2+opponent1.getHealth();
            resurrect=false;
            sounds.ko();

        }

        if(level==1.5 && showlevel15==true)
        {

           state=State::VictoryA;
           showlevel15=false;
           sounds.ko();




        }

        if(level==2.0 && showlevel2==true)                //level 2
        {

            if (levCounter == 0)
            {

                sounds.ko();

            }

            state=State::VictoryA;
             levCounter++;
             if(levCounter==2){
                levelText.setString("Level 2\n\nPress Space to Continue...");
                sounds.Arena2();
                Arena.setTexture(&ArenaTxtr[2]);
                opponent1.setTexture(&player1Texture[3]);
                player1.getHealth()=(100-player1.getHealth())/2+player1.getHealth();
                state=State::LEVEL;
                resurrect=true;
                f=false;
                showlevel2=false;        //display level 2 text only once
                levCounter=0;


             }
        }

        if(level==2.5 && showlevel25==true)
        {
            state=State::VictoryA;
            showlevel25=false;
            sounds.ko();


        }
        else if(level==3.0 && showlevel3==true)       //level 3
        {
            if (levCounter == 0)   //check it
            {
                sounds.ko();
            }

            state=State::VictoryA;
            levCounter++;
            if(levCounter==2){

                levelText.setString("Level 3\n\nPress Space to Continue...");
                sounds.Arena3();
                Arena.setTexture(&ArenaTxtr[1]);
                opponent1.setTexture(&player1Texture[1]);
                player1.getHealth()=(100-player1.getHealth())/2+player1.getHealth();
                state=State::LEVEL;
                resurrect=true;
                showlevel3=false;       //display level 2 text only once
                levCounter=0;


            }
        }
        else if(level==4.0 || (health<=0 && resurrect==false))
        {

            state=State::CELEBRATION1;
            sounds.victorylaugh();

        }

    }
    if(state==State::CELEBRATION1)
    {
        if(level==4)    //cpu lost
            {
            winText.setString("VICTORY !!!\n Press Space to Continue");
             over.setTexture(&winsT);


            }
        else if(health<=0)  //player health is zero
            {
                winText.setString("Bites the Dust !!! \n Press Space to Continue ");
                player1.getHealth()=100;     //to prevent entering this scope
                over.setTexture(&overT);
            }
            level=1;        //after celebration all reset to default
            showlevel2=true;
            showlevel15=true;
            showlevel25=true;
            showlevel3=true;
            newgame=true;
            oppnewgame=true;
            resurrect=true;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            state=State::MAINMENU;  //again to mainmenu
            sounds.playtheme();
            opponent1.setTexture(&player1Texture[2]);
            levelText.setString("Level 1\n\nPress Space to Continue...");

    }

        if(state==State::PLAYING2)      //two player mode
    {


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            level=1;        //after celebration all reset to default
            showlevel2=true;
            showlevel15=true;
            showlevel25=true;
            showlevel3=true;
            newgame=true;
            oppnewgame=true;
            resurrect=true;
            state=State::MAINMENU;  //again to mainmenu
            sounds.playtheme();
            opponent1.setTexture(&player1Texture[2]);
            levelText.setString("Level 1\n\nPress Space to Continue...");

        }

        health=player1.Update(dt,acceptInput,newgame);
        opphealth=Opponent1.UpdatePlayer2(dt,acceptInput2,oppnewgame);
        player1.isColliding(Opponent1);
        if(health<=0 || opphealth<=0)
        {
            state=State::CELEBRATION2;
            extrasounds.victorylaugh();
        }
    }
    if(state==State::CELEBRATION2)
    {


        if(health<=0)
        {

            winText.setString("Player 2 Won!");
        }
        if(opphealth<=0)
        {

            winText.setString("Player 1 Won!");
        }
        newgame=true;       //reset to default
        oppnewgame=true;
        over.setTexture(&over2);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {


        state=State::MAINMENU;
        sounds.playtheme();
        }     //again to mainmenu
    }
}

void Game::Draw()  //self explanatory
{
        Screen.clear();  // clears the screen

              //draws everything as per the state
        if(state==State::INTRO)
        {
            Screen.draw(Intro);
            Screen.draw(introText);
        }

        if(state==State::MAINMENU)
        {
            Screen.draw(MainMenu);
            Screen.draw(menuSelect);
        }

         if(state==State::OPTIONS)
        {
            Screen.draw(Options);
        }
        if(state==State::LEVEL)
        {
            Screen.draw(Arena);
            Screen.draw(levelText);
        }

        if(state==State::MODE)
        {
            Screen.draw(Mode);
            Screen.draw(Campaign);
            Screen.draw(Multiplayer);
        }


        if(state==State::CHARACTERS)
        {
            Screen.draw(CharSelect);
            Screen.draw(Selector);
            Screen.draw(Selector2);
        }

        if(state==State::ARENA)
        {
            Screen.draw(ArenaSelect);
            Screen.draw(ArenaSelector);
        }

        if(state==State::TRANSITION)
        {

            Screen.draw(transit);
            Screen.draw(transit2);
        }
        if(state==State::CELEBRATION1)
        {

            Screen.draw(over);
            Screen.draw(winText);
        }
        if(state==State::CELEBRATION2)
        {

            Screen.draw(over);
            Screen.draw(winText);
        }

        if(state==State::VictoryA || state==State::VictoryB)
        {
            Screen.draw(Arena);
            player1.Draw(Screen);
            opponent1.Draw(Screen);

        }


        if(state==State::PLAYING1)
        {
            Screen.draw(Arena);
            if(player1.getRow()==9)
            {
                player1.Draw(Screen);
                opponent1.Draw(Screen);
            }
            else
            {
                opponent1.Draw(Screen);
                player1.Draw(Screen);
            }
        }

           if(state==State::PLAYING2)
        {
            Screen.draw(Arena);
            if(player1.getRow()==9)
            {
                player1.Draw(Screen);
                Opponent1.Draw(Screen);
            }
            else
            {
                Opponent1.Draw(Screen);
                player1.Draw(Screen);
            }
        }


        Screen.display(); //displays on the screen
}


