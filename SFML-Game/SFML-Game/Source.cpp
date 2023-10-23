#include "Game.h"
#include "Menu.h"
int main()
{   
    //Init srand
    srand(static_cast<unsigned>(time(NULL)));
    //Init Game engine
    Game game;




    while (game.running())
    {   
        //Menu
        if (game.screen == 0)
        {
            game.menuUpdate();
            game.menuRender();
            continue;
        }
        //Name
        if (game.screen == 1)
        {
            game.nameUpdate();
            game.nameRender();
            continue;
        }
        //Game
        if (game.screen == 2)
        {
            game.update();
            game.render();
            continue;
        }
        //Over
        if (game.screen == 3)
        {
            game.overUpdate();
            game.overRender();
            continue;
        }
        //Leader
        if (game.screen == 4)
        {
            game.leaderUpdate();
            game.leaderRender();
            continue;
        }
        //Tuto
        if (game.screen == 5)
        {
            game.tutoUpdate();
            game.tutoRender();
        }
        if (game.screen == 6)
        {
            game.creditUpdate();
            game.creditRender();
        }
    }

    return 0;
}        
