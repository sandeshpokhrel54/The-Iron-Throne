#ifndef GAME_H
#define GAME_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"
#include"Anime.h"
#include"music.h"
#include"Opponent.h"


class Game
{
    public:
        Game(); //ctor
        void Run();



    private:
        void Draw();      // draws all objects on the screen
        void Update();     // updates the screen with inputs
        void ProcessEvents(); // process events taken
       //void HandleInput();

    private:
       // sfml elements of the game

        sf::RenderWindow Screen;
        sf::Font font;
        sf::Font font2;
        sf::View view;
        sf::RectangleShape Intro;
        sf::Texture intro;
        sf::Text introText;
        sf::FloatRect introRect;

        sf::RectangleShape MainMenu;
        sf::Texture mainmenu;
        sf::CircleShape menuSelect;
        sf::Texture selecTexture;
        sf::Vector2f menuPos;

        sf::RectangleShape Options;
        sf::Texture options;

        sf::RectangleShape Mode;
        sf::Texture ModeTexture;
        sf::Text Campaign;
        sf::Text Multiplayer;
        sf::FloatRect CampaignRect;
        sf::FloatRect MultiRect;

        sf::RectangleShape CharSelect;
        sf::Texture CharSelectPage;
        sf::RectangleShape Selector;
        sf::RectangleShape Selector2;
        sf::Texture selector;
        sf::Texture selector2;
        sf::Vector2f selectorPos;
        sf::Vector2f selectorPos2;

        sf::RectangleShape ArenaSelect;
        sf::Texture ArenaSelectxtr;
        sf::Texture ArenaTxtr[4];
        sf::CircleShape ArenaSelector;
        sf::Vector2f ArenaPos;

        sf::RectangleShape Arena;
        sf::Texture player1Texture[4];

        sf::RectangleShape transit;
        sf::RectangleShape transit2;
        sf::Texture Transit[3];

        sf::Text levelText;
        sf::Text winText;

        sf::RectangleShape over;
        sf::Texture overT;
        sf::Texture winsT;
        sf::Texture over2;

        // userdefined non sfml elements

        float level; // levels of the game

        // booleans to toggle between levels
        bool showlevel15;
        bool showlevel2;
        bool showlevel25;
        bool showlevel3;
        bool showlevel35;


        float  health;
        float opphealth;

        // booleans to reset game on every exit
        bool newgame;
        bool oppnewgame;

        int counter;     //counters for round toggle and single execution within loops
        int levCounter;

        bool resurrect;  // boolean for player life resurrection

        sf::Clock clock;  // clock and delta-time for animation purpose
        float dt;

        enum State  // states to toggle from intro to game and back
        {
            INTRO,MAINMENU,OPTIONS,MODE,SINGLE,MULTI,CHARACTERS,ARENA,TRANSITION,PLAYING1,LEVEL,PLAYING2,CELEBRATION1,CELEBRATION2,OVER,VictoryA,VictoryB
        };
        State state;
        bool acceptInput; // player input gates
        bool acceptInput2; // opponent player input gates
        bool OppUpdate;   // updates opponent player for multiplayer mode
        bool f; // sound toggle boolean
        int x;    // integer for debug purpose //didn't comment for not risking the program
        music sounds,extrasounds; // sound objects

        Player player1;  // player objects
        Player opponent1;
        Opponent Opponent1; // opponent objects derived from player



};


#endif // GAME_H
