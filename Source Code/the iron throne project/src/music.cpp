#include"music.h"


music::music()
{
    //loading music files:songs to be played as background or as themes

    if(!theme1.openFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\demons.ogg"))
    {
            std::cout<<"theme music not loaded"<<std::endl;
    }

    //loading music for arenas

    if(!ingame1.openFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\Naruto.ogg"))
    {
            std::cout<<"theme music not loaded"<<std::endl;
    }

    if(!ingame2.openFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\arena2.ogg"))
    {
            std::cout<<"theme music not loaded"<<std::endl;
    }

    if(!ingame3.openFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\vader.ogg"))
    {
            std::cout<<"theme music not loaded"<<std::endl;
    }


    //multiplayer music loading
    if(!p2.openFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\Pulp.ogg"))
    {
            std::cout<<"theme music not loaded"<<std::endl;
    }


    //loading action sound files to the buffer

    if(!bufferTrans.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\transition.ogg"))
            {
                std::cout<<"buffer load error"<<std::endl;
            }

    if(!bufferCursorMove.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\cursor.wav"))
            {
                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferCursorSelect.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\cursorSelect.wav"))
            {
                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferRound1.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\round1.wav"))
            {
                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferRound2.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\round2.wav"))
            {
                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferFinalRound.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\finalround.wav"))
            {
                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferKick1.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\kick1.wav"))
            {

                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferKick2.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\kick2.wav"))
            {

                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferPunchLanded1.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\PUNCH.wav"))
            {

                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferKickMiss.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\kickmiss.wav"))
            {

                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferPunchMiss.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\punchmiss.wav"))
            {

                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferGrunt1.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\grunt1.wav"))
            {


                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferGrunt2.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\grunt2.wav"))
            {

                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferThud.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\thud.wav"))
            {

                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferKO.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\ko.wav"))
            {
                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferArenaTrack.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\arenaselect.wav"))
            {
                std::cout<<"buffer load error"<<std::endl;
            }
        if(!bufferCSTrack.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\characterselect.wav"))
            {
                std::cout<<"buffer load error"<<std::endl;
            }

        if(!bufferPunchLanded2.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\punch1.wav"))
            {

                std::cout<<"buffer load error"<<std::endl;
            }
        if(!bufferVLaugh.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\haha.wav"))
            {
                std::cout<<"buffer load error"<<std::endl;
            }


        if (!bufferMulp.loadFromFile("C:\\Users\\dell\\Desktop\\project_sounds\\mulp.wav"))
        {

            std::cout<<"buffer load error"<<std::endl;
        }

            punchland2.setBuffer(bufferPunchLanded2);
            thuds.setBuffer(bufferThud);
            grunts2.setBuffer(bufferGrunt2);
            grunts1.setBuffer(bufferGrunt1);
            punchmiss.setBuffer(bufferPunchMiss);
            kickmiss.setBuffer(bufferKickMiss);
            punchland1.setBuffer(bufferPunchLanded1);
            kickland2.setBuffer(bufferKick2);
            kickland1.setBuffer(bufferKick1);

}

 void music::playtheme()
    {
        ingame3.stop();
        ingame1.stop();
        ingame2.stop();
        p2.stop();
        theme1.setVolume(20.f);
        theme1.play();
        theme1.setLoop(true);

    }

void music::cursorMove()
    {

        hit.setBuffer(bufferCursorMove);
        hit.play();


    }


void music::cursorSelect()
    {

        hit.setBuffer(bufferCursorSelect);
        hit.play();


    }

void music::round1()
{

    hit.setBuffer(bufferRound1);
    hit.play();

}

void music::round2()
{
    hit.setBuffer(bufferRound2);
    hit.play();
}

void music::finalRound()
{
    hit.setBuffer(bufferFinalRound);
    hit.play();

}

void music::punchlanded()
{

    punchland1.play();

}

void music::kicklanded1()
{

    kickland1.play();

}

void music::kicklanded2()
{

    kickland2.play();
}

void music::kickmissed()
{

    kickmiss.play();

}

void music::punchmissed()
{

    punchmiss.play();

}

void music::punchlanded2()
{

    punchland2.play();

}


void music::grunt1()
{

    grunts1.play();

}

void music::grunt2()
{

    grunts2.play();

}

void music::thud()
{

    thuds.play();

}


void music::arenatrack()
{
    hit.setBuffer(bufferArenaTrack);
    hit.play();


}

void music::cstrack()
{
    hit.setBuffer(bufferCSTrack);
    hit.play();

}

void music::victorylaugh()
{
    hit.setBuffer(bufferVLaugh);
    hit.play();

}


void music::ko()
{
    hit.setBuffer(bufferKO);
    hit.play();

}


void music::multip()
{

    hit.setBuffer(bufferMulp);
    hit.play();
}

void music::story()
{
    theme1.stop();
    hit.setBuffer(bufferTrans);
    hit.play();
}

void music::Arena1()
{
    theme1.stop();
    ingame1.setVolume(80.f);
    ingame1.play();
    ingame1.setLoop(true);
}

void music::Arena2()
{
    ingame1.stop();
    ingame2.setVolume(50.f);
    ingame2.play();
    ingame2.setLoop(true);

}

void music::Arena3()
{
    ingame2.stop();
    ingame3.setVolume(50.f);
    ingame3.play();
    ingame3.setLoop(true);
}


void music::twop()
{
    theme1.stop();
    p2.setVolume(50.f);
    p2.play();
    p2.setLoop(true);
}


