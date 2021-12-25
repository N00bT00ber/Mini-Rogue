// Game.cpp

#include "Game.h"
#include "utilities.h"
#include <iostream>
#include "actors.h"
using namespace std;


Game::Game(int goblinSmellDistance)
{
    m_dungeon = new dungeon;

}
Game::~Game()
{
    delete m_dungeon;
}


void Game::play()
{
    m_dungeon->display("");
    cout << "Press q to exit game." << endl;
    Player* Player = m_dungeon->get_Player();
    int record = 0;
    int level = 0;
    if(Player == nullptr)
    {
        return;
    }
    else
    {
        for(;;)
    {
        char move = getCharacter();
        if (move == 'q' or m_dungeon->get_Player()->get_dead() == true)
        {
            break;
        }
        else if(move == ' ')
        {
            m_dungeon->attack_player();
        }
        else if(record == 1)
        {
            Player->equip_weapon(move);
            record = 0;
        }
            
        else if(move == 'w' or move == 'i' or move == 'r') // if any of those values are met open the inventory
        {
            
            Player->display_inventory();
            record = 1;                 // keeps track of the inventory once another imput is made then it goes back to screen
          //  Player->equip_weapon(move);
        }
        else if(move == ARROW_LEFT)
        {
            Player->move(3) ;
            m_dungeon->attack_player();
            m_dungeon->display("");
        }
        else if(move == ARROW_RIGHT)
        {
            Player->move(4) ;
            m_dungeon->attack_player();
            m_dungeon->display("");
        }
        else if(move == ARROW_UP)
        {
            Player->move(1) ;
            m_dungeon->attack_player();
            m_dungeon->display("");
        }
        else if(move == ARROW_DOWN)
        {
            Player->move(2);
            m_dungeon->attack_player();
            m_dungeon->display("");
        }
        else if(move == 'g' and (m_dungeon->object_check(Player->get_row(),Player->get_col()) == '?' or m_dungeon->object_check(Player->get_row(),Player->get_col()) == ')')) /// FIX
        {
            m_dungeon->object_interactor(Player->get_row(),Player->get_col()); // wield item
        }
        else if(move == 'g' and m_dungeon->object_check(Player->get_row(),Player->get_col()) == '>') // move up a level BUG MUST FIX
        {
            level++;
            m_dungeon->new_level(level);
            m_dungeon->display("");
          //  cout << Player->get_row() << endl;
           // cout << Player->get_col() << endl;
            
        }
        else if(move == 'c')
        {
            Player->update_Max_hitpoints(30);
            Player->set_hitpoints(50);
            Player->set_armor(20);
            Player->set_strength(20);
            Player->set_dexterity(20);
            m_dungeon->display("");
            
        }
        else if(move == 'g' and m_dungeon->object_check(Player->get_row(),Player->get_col()) == '&')
        {
            cout << "you have collecected the Golden idol!"<< endl;
            break;
        }
        else if(Player->get_dead() == true)
        {
            cout << "you died."<< endl;
            break;
        }
        else
        {
            Player->move(5); // no move
            m_dungeon->attack_player();
            m_dungeon->display("");
            
        }
        
    }
        cout << endl;
        cout << " game over." << endl;
}
}


