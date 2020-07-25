#ifndef MUSIC_H
#define MUSIC_H


#include<SFML\Audio.hpp>
#include<iostream>

class music
{
private:
    sf::Music theme1,ingame1,ingame2,ingame3,p2;
    sf::SoundBuffer bufferPunchLanded1,bufferCursorMove,bufferCursorSelect,bufferRound1,bufferRound2,bufferFinalRound,bufferKick1,bufferKick2,bufferKickMiss,bufferPunchMiss,bufferKO,bufferGrunt1,bufferGrunt2,bufferThud,bufferArenaTrack,bufferPlayEntry,bufferCSTrack,bufferPunchLanded2,bufferVLaugh,bufferMulp,bufferTrans;
    sf::Sound hit,kickland1,kickland2,punchland1,punchland2,kickmiss,punchmiss,grunts1,grunts2,thuds;

public:
    music();
    void playtheme();   //main game theme
    void cursorMove();
    void cursorSelect();
    void round1();
    void round2();
    void finalRound();
    void punchlanded();
    void punchlanded2();
    void kicklanded1();
    void kicklanded2();
    void punchmissed();
    void kickmissed();
    void grunt1();
    void grunt2();
    void thud();

    //fatality
    void ko();


    //arenaselect
    void arenatrack();
    //characterselect
    void cstrack();

    //victory
    void victorylaugh();
    //music arena1
    void Arena1();
    //music arena2;
    void Arena2();
    //void arena3
    void Arena3();

    //test your might
    void multip();

    //avengers theme
    void story();

    //multiplayer
    void twop();


};
#endif // MUSIC_H
