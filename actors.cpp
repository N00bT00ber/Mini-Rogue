#include <iostream>
#include "actors.h"
#include "dungeon.h"

using namespace std;

actors::actors(dungeon* dung ,int row, int col): m_dungeon(dung), m_row(row), m_col(col)
{

}
actors::~actors()
{
}


Player::Player(dungeon* dung ,int row, int col): m_row(row), m_col(col),my_dungeon(dung), actors(dung,row,col)
{
    m_strength = MAX_INITIAL_PLAYER_STRENGTH;
    m_dexterity = MAX_INITIAL_PLAYER_DEXTERITY;
    m_armor = MAX_INITIAL_PLAYER_ARMOR;
    m_hitpoints = MAX_INITIAL_PLAYER_HITPOINTS;
    updated_Max_hitpoints = MAX_INITIAL_PLAYER_HITPOINTS;
    m_sleep = INITIAL_PLAYER_SLEEP_TIME;
    m_dead = false;
    vector<objects*> inventory;
    add_to_inventory(new ShortSword(m_row,m_col));
    my_weapon = new ShortSword(m_row,m_col);
    
}
void Player::set_row(int r)
{
    m_row = r;
}
void Player::set_col(int c)
{
    m_col = c;
}
int Player::get_strength() const
{
    return m_strength;
}
int Player::get_dexterity() const
{
    return m_dexterity;
}
int Player::get_armor() const
{
    return m_armor;
}
int Player::get_hitpoints() const
{
    return m_hitpoints;
}
int Player::get_sleep() const
{
    return m_sleep;
}
bool Player::get_dead() const
{
    if(m_hitpoints <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Player::set_strength(int strength)
{
    m_strength = m_strength + strength;
}
void Player::set_dexterity(int dexterity)
{
    m_dexterity += dexterity;
}
void Player::set_armor(int armor)
{
    m_armor += armor;
}
void Player::update_Max_hitpoints(int increase)
{
    updated_Max_hitpoints+= increase;
}
void Player::set_hitpoints(int hitpoints)
{
    if(m_hitpoints>= updated_Max_hitpoints)
    {
    }
    else
    {
    m_hitpoints += hitpoints;
    }
}
void Player::set_sleep(int sleep)
{
    if (m_sleep > 0)
    {
        if(sleep > m_sleep)
        {
            m_sleep = sleep;
        }
        else
        {
            
        }
    
    }
    else
    {
        m_sleep += sleep;
    }
}
void Player::move(int instructions)
{
    if(instructions == 1) // up
    {
     if(my_dungeon->getCellStatus(m_row - 1, m_col) == ' ') // if it is an empty space move up
     {
         my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
         my_dungeon->setCellStatus(m_row-1, m_col,'@') ;
         m_row = m_row-1;//update the players location
     }
     else if(my_dungeon->getCellStatus(m_row - 1, m_col) == 'G' or my_dungeon->getCellStatus(m_row - 1, m_col) == 'B' or my_dungeon->getCellStatus(m_row - 1, m_col) == 'D' or my_dungeon->getCellStatus(m_row - 1, m_col) == 'S')
     {
         my_dungeon->monster_killer(m_row - 1,m_col);
     }

     else if(my_dungeon->getCellStatus(m_row -1, m_col) == '>' or my_dungeon->getCellStatus(m_row -1, m_col) == ')' or my_dungeon->getCellStatus(m_row -1, m_col) == '?' or my_dungeon->getCellStatus(m_row -1, m_col) == '&') // if player is walking into an object simply allow player to walk over it
     {
         my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
         my_dungeon->setCellStatus(m_row-1, m_col,'@') ;
         m_row = m_row-1;//update the players location;
     }
     else
     {
         
     }
    }
    else if(instructions == 2) // down
    {
        if(my_dungeon->getCellStatus(m_row + 1, m_col) == ' ') // if it is an empty space move up
        {
            my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
            my_dungeon->setCellStatus(m_row+ 1, m_col,'@') ;
            m_row = m_row + 1;//update the players location
        }
        else if(my_dungeon->getCellStatus(m_row + 1, m_col) == 'G' or my_dungeon->getCellStatus(m_row + 1, m_col) == 'B' or my_dungeon->getCellStatus(m_row + 1, m_col) == 'D' or my_dungeon->getCellStatus(m_row + 1, m_col) == 'S')
        {
            my_dungeon->monster_killer(m_row +1,m_col);
        }
        else if(my_dungeon->getCellStatus(m_row +1, m_col) == '>' or my_dungeon->getCellStatus(m_row +1, m_col) == ')' or my_dungeon->getCellStatus(m_row +1, m_col) == '?' or my_dungeon->getCellStatus(m_row +1, m_col) == '&') // if player is walking into an object simply allow player to walk over it
        {
            my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
            my_dungeon->setCellStatus(m_row+1, m_col,'@') ;
            m_row = m_row+1;//update the players location;
        }
        else
        {
            
        }
    }
    else if(instructions == 3) // left
    {
        if(my_dungeon->getCellStatus(m_row, m_col -1) == ' ') // if it is an empty space move up
        {
            my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
            my_dungeon->setCellStatus(m_row, m_col -1,'@') ;
            m_col = m_col -1; //update the players location
        }
        else if(my_dungeon->getCellStatus(m_row, m_col-1) == 'G' or my_dungeon->getCellStatus(m_row, m_col-1) == 'B' or my_dungeon->getCellStatus(m_row, m_col-1) == 'D' or my_dungeon->getCellStatus(m_row, m_col-1) == 'S')
        {
            my_dungeon->monster_killer(m_row,m_col-1);
        }
        else if(my_dungeon->getCellStatus(m_row, m_col-1) == '>' or my_dungeon->getCellStatus(m_row, m_col-1) == ')' or my_dungeon->getCellStatus(m_row, m_col-1) == '?' or my_dungeon->getCellStatus(m_row , m_col- 1) == '&') // if player is walking into an object simply allow player to walk over it
        {
            my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
            my_dungeon->setCellStatus(m_row, m_col- 1,'@') ;
            m_col = m_col-1;//update the players location;
        }
        else
        {
            
        }
    }
    else if(instructions == 4) // right
    {
        if(my_dungeon->getCellStatus(m_row, m_col +1) == ' ') // if it is an empty space move up
        {
            my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
            my_dungeon->setCellStatus(m_row, m_col + 1,'@') ;
            m_col = m_col +1; //update the players location
        }
        else if(my_dungeon->getCellStatus(m_row, m_col+1) == 'G' or my_dungeon->getCellStatus(m_row, m_col+1) == 'B' or my_dungeon->getCellStatus(m_row, m_col+1) == 'D' or my_dungeon->getCellStatus(m_row, m_col+1) == 'S')
        {
            my_dungeon->monster_killer(m_row,m_col+1);
        }
        else if(my_dungeon->getCellStatus(m_row, m_col+1) == '>' or my_dungeon->getCellStatus(m_row, m_col+1) == ')' or my_dungeon->getCellStatus(m_row, m_col+1) == '?' or my_dungeon->getCellStatus(m_row , m_col+1) == '&') // if player is walking into an object simply allow player to walk over it
        {
            my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
            my_dungeon->setCellStatus(m_row, m_col+ 1,'@') ;
            m_col = m_col + 1;//update the players location;
        }
        else
        {
                   
        }
    }
    else
    {
        //stay in place
    }
}
void Player::drop_weapon()
{}
string Player::get_actor() const
{
    return "Player";
}
Player::~Player()
{
    for(int i = 0; i < inventory.size(); i++)
    {
        delete inventory[i];
    }
    inventory.clear();
}
int Player::get_row() const
{
    return m_row;
}

int Player::get_col() const
{
    return m_col;
}
bool Player::add_to_inventory(objects* add)
{
    if(inventory.size() <= 25)
    {
        inventory.push_back(add);
        return true;
    }
    else
    {
        cout << "inventory full" << endl;
        return false;
    }
}
void Player::equip_weapon(char location) //UPDATE TO READ SCROLLS
{
    char tracker = 'a';
    int i = 0;
    while(i < inventory.size()-1) // fixes memmory leak issue make everything dependent on size
    {
        if(tracker == location)
        {
            my_weapon = inventory[i];
            break;
        }
        else
        {
            
        }
        tracker++;
        i++;
    }
    if(location > tracker)
    {
        my_dungeon->display("");
       return;
    }
    
    if(inventory[i]->identifier() == "ScrollOfEnhanceHealth")
    {
        updated_Max_hitpoints+= inventory[i]->get_health();
        string info = inventory[i]->getAction();
        my_dungeon->display(info);
        inventory.erase(inventory.begin()+ i);
        my_weapon = inventory[0]; // default weapon back to short sword after reading scroll
    }
    else if(inventory[i]->identifier() == "ScrollOfEnhanceDexterity")
    {
        set_dexterity(inventory[i]->getDexterity());
        string info = inventory[i]->getAction();
        my_dungeon->display(info);
        inventory.erase(inventory.begin()+ i); //  memory leak, yes but i dont want my code crashing if i delete in the middle so one pointer or two is worth it
        my_weapon = inventory[0]; // default weapon back to short sword after reading scroll
    }
    else if(inventory[i]->identifier() == "ScrollOfImproveArmor")
    {
        set_armor(inventory[i]->get_armor());
        string info = inventory[i]->getAction();
        my_dungeon->display(info);
        inventory.erase(inventory.begin()+ i);
        my_weapon = inventory[0]; // default weapon back to short sword after reading scroll
    }
    else if(inventory[i]->identifier() == "ScrollOfRaiseStrength")
    {
        set_strength(inventory[i]->get_strength());
        string info = inventory[i]->getAction();
        my_dungeon->display(info);
        inventory.erase(inventory.begin()+ i);
        my_weapon = inventory[0]; // default weapon back to short sword after reading scroll
    }
    else if(inventory[i]->identifier() == "ScrollOfTeleportation")
    {

        for(;;)
        {
            int new_r = randInt(0, 17);
            int new_c = randInt(0, 69);
            if(my_dungeon->getCellStatus(new_r, new_c) == ' ')
            {
                my_dungeon->setCellStatus(m_row, m_col, ' ');
                m_row = new_r;
                m_col = new_c;
                my_dungeon->setCellStatus(new_r, new_c, '@');
                break;
            }
            else
            {
                
            }
        }
        string info = inventory[i]->getAction();
        my_dungeon->display(info);
        inventory.erase(inventory.begin()+ i);
        my_weapon = inventory[0]; // default weapon back to short sword after reading scroll
    }
    else
    {
        string info = inventory[i]->identifier();
        string new_string = "you are now wielding ";
        new_string += (info + ".");
       my_dungeon->display(new_string);
    }
}
void Player::display_inventory()
{
    clearScreen();
    cout << "   Inventory:" << endl;
    char tracker ='a';
    for(int i =0; i < inventory.size();i++)
    {
        cout<< "   " << tracker << ". " << inventory[i]->identifier() << endl;
        tracker++;
    }
}
objects* Player::get_weapon() const
{
    return my_weapon;
}








Bogeymen::Bogeymen(dungeon* dung ,int row, int col): m_row(row), m_col(col),my_dungeon(dung), actors(dung,row,col)
{
    m_hitpoints = randInt(5,10);
    m_strength = randInt(2, 3);
    m_dexterity = randInt(2,13);
    m_sleep = 0;
    m_dead = false;
    m_armor = BOGEYMEN_ARMOR;
    weapon = new ShortSword(m_col,m_row);
    
}
int Bogeymen::get_strength() const
{
    return m_strength;
}
int Bogeymen::get_dexterity() const
{
    return m_dexterity;
}
int Bogeymen::get_armor() const
{
    return m_armor;
}
int Bogeymen::get_hitpoints() const
{
    return m_hitpoints;
}
int Bogeymen::get_sleep() const
{
    return m_sleep;
}
bool Bogeymen::get_dead() const
{
    if(m_hitpoints <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Bogeymen::set_strength(int strength)
{
    m_strength = m_strength + strength;
}
void Bogeymen::set_dexterity(int dexterity)
{
    m_dexterity += dexterity;
}
void Bogeymen::set_armor(int armor)
{
    m_armor += armor;
}
void Bogeymen::set_hitpoints(int hitpoints)
{
    m_hitpoints += hitpoints;
}
void Bogeymen::set_sleep(int sleep)
{
       if (m_sleep > 0)
    {
        if(sleep > m_sleep)
        {
            m_sleep = sleep;
        }
        else
        {
            
        }
    
    }
    else
    {
        m_sleep += sleep;
    }
}
void Bogeymen::move(int instructions)
{
    {
     if((my_dungeon->getCellStatus(m_row - 1, m_col) == ' ' or my_dungeon->getCellStatus(m_row -1, m_col) == '>' or my_dungeon->getCellStatus(m_row -1, m_col) == ')' or my_dungeon->getCellStatus(m_row -1, m_col) == '?' or my_dungeon->getCellStatus(m_row -1, m_col) == '&') and (my_dungeon->getCellStatus(m_row - 2, m_col) == '@' or  my_dungeon->getCellStatus(m_row - 3, m_col) == '@' or my_dungeon->getCellStatus(m_row -4, m_col) == '@' or my_dungeon->getCellStatus(m_row - 5, m_col) == '@')) // if it is an empty space and actor is within range  move up
     {
         my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
         my_dungeon->setCellStatus(m_row-1, m_col,'B') ;
         m_row = m_row-1;
     }
     
     else if(my_dungeon->getCellStatus(m_row - 1, m_col) == '@')
     {
       //  my_dungeon->monster_killer(m_row-1, m_col);
     }
    else
    {
        //do nothing
    }
    }
     
    {
        if((my_dungeon->getCellStatus(m_row +1, m_col) == ' ' or my_dungeon->getCellStatus(m_row +1, m_col) == '>' or my_dungeon->getCellStatus(m_row +1, m_col) == ')' or my_dungeon->getCellStatus(m_row +1, m_col) == '?' or my_dungeon->getCellStatus(m_row +1, m_col) == '&') and (my_dungeon->getCellStatus(m_row + 2, m_col) == '@' or  my_dungeon->getCellStatus(m_row + 3, m_col) == '@' or my_dungeon->getCellStatus(m_row +4, m_col) == '@' or my_dungeon->getCellStatus(m_row + 5, m_col) == '@')) // if it is an empty space and actor is within range  move up
         {
             my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
             my_dungeon->setCellStatus(m_row+1, m_col,'B') ;
             m_row = m_row+1;
         }
         
         else if(my_dungeon->getCellStatus(m_row + 1, m_col) == '@')
         {
            // my_dungeon->monster_killer(m_row+1, m_col);
         }
        else
        {
            //do nothing
        }
    }
    
    {
        if((my_dungeon->getCellStatus(m_row, m_col -1) == ' ' or my_dungeon->getCellStatus(m_row, m_col-1) == '>' or my_dungeon->getCellStatus(m_row, m_col- 1) == ')' or my_dungeon->getCellStatus(m_row, m_col-1) == '?' or my_dungeon->getCellStatus(m_row, m_col-1) == '&') and (my_dungeon->getCellStatus(m_row , m_col- 2) == '@' or  my_dungeon->getCellStatus(m_row, m_col-3) == '@' or my_dungeon->getCellStatus(m_row , m_col -4) == '@' or my_dungeon->getCellStatus(m_row, m_col-5) == '@')) // if it is an empty space and actor is within range  move up
         {
             my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
             my_dungeon->setCellStatus(m_row, m_col-1,'B') ;
             m_col = m_col-1;
         }
         
         else if(my_dungeon->getCellStatus(m_row, m_col-1) == '@')
         {
            // my_dungeon->monster_killer(m_row, m_col-1);
             
         }
        else
        {
            //do nothing
        }
    }
    
    {
       if((my_dungeon->getCellStatus(m_row, m_col +1) == ' ' or my_dungeon->getCellStatus(m_row, m_col+1) == '>' or my_dungeon->getCellStatus(m_row, m_col+ 1) == ')' or my_dungeon->getCellStatus(m_row, m_col+1) == '?' or my_dungeon->getCellStatus(m_row, m_col+1) == '&') and (my_dungeon->getCellStatus(m_row , m_col+ 2) == '@' or  my_dungeon->getCellStatus(m_row, m_col+3) == '@' or my_dungeon->getCellStatus(m_row , m_col +4) == '@' or my_dungeon->getCellStatus(m_row, m_col+5) == '@')) // if it is an empty space and actor is within range  move up
        {
            my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
            my_dungeon->setCellStatus(m_row, m_col+1,'B') ;
            m_col = m_col+1;
        }
        
        else if(my_dungeon->getCellStatus(m_row, m_col +1) == '@')
        {
           // my_dungeon->monster_killer(m_row, m_col+1);
        }
       else
       {
           //do nothing
       }
    }
}
void Bogeymen::drop_weapon()
{
    
}
string Bogeymen::get_actor() const
{
    return "Bogeymen";
}

Bogeymen::~Bogeymen()
{
    delete weapon;
}
int Bogeymen::get_row() const
{
    return m_row;
}


int Bogeymen::get_col() const
{
    return m_col;
}
objects* Bogeymen::get_weapon() const
{
    return weapon;
}




Goblins::Goblins(dungeon* dung ,int row, int col): m_row(row), m_col(col), my_dungeon(dung),actors(dung,row,col)
{
    m_hitpoints = randInt(15,20);
    m_strength = GOBLINS_STRENGTH;
    m_dexterity = GOBLINS_DEXTERITY;
    m_sleep = 0;
    m_dead = false;
    m_armor = GOBLINS_ARMOR;
    weapon = new ShortSword(m_row,m_col);
    
}
int Goblins::get_strength() const
{
    return m_strength;
}
int Goblins::get_dexterity() const
{
    return m_dexterity;
}
int Goblins::get_armor() const
{
    return m_armor;
}
int Goblins::get_hitpoints() const
{
    return m_hitpoints;
}
int Goblins::get_sleep() const
{
    return m_sleep;
}
bool Goblins::get_dead() const
{
    if(m_hitpoints <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Goblins::set_strength(int strength)
{
    m_strength = m_strength + strength;
}
void Goblins::set_dexterity(int dexterity)
{
    m_dexterity += dexterity;
}
void Goblins::set_armor(int armor)
{
    m_armor += armor;
}
void Goblins::set_hitpoints(int hitpoints)
{
    m_hitpoints += hitpoints;
}
void Goblins::set_sleep(int sleep)
{
if (m_sleep > 0)
    {
        if(sleep > m_sleep)
        {
            m_sleep = sleep;
        }
        else
        {
            
        }
    
    }
else
    {
        m_sleep += sleep;
    }
}
void Goblins::move(int instructions)
{
    {
        {
         if((my_dungeon->getCellStatus(m_row - 1, m_col) == ' ' or my_dungeon->getCellStatus(m_row -1, m_col) == '>' or my_dungeon->getCellStatus(m_row -1, m_col) == ')' or my_dungeon->getCellStatus(m_row -1, m_col) == '?' or my_dungeon->getCellStatus(m_row -1, m_col) == '&') and (my_dungeon->getCellStatus(m_row - 2, m_col) == '@' or  my_dungeon->getCellStatus(m_row - 3, m_col) == '@' or my_dungeon->getCellStatus(m_row -4, m_col) == '@' or my_dungeon->getCellStatus(m_row - 5, m_col) == '@')) // if it is an empty space and actor is within range  move up
         {
             my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
             my_dungeon->setCellStatus(m_row-1, m_col,'G') ;
             m_row = m_row-1;
         }
         
         else if(my_dungeon->getCellStatus(m_row - 1, m_col) == '@')
         {
            // my_dungeon->monster_killer(m_row-1, m_col);
             
         }
        else
        {
            //do nothing
        }
        }
         
        {
            if((my_dungeon->getCellStatus(m_row +1, m_col) == ' ' or my_dungeon->getCellStatus(m_row +1, m_col) == '>' or my_dungeon->getCellStatus(m_row +1, m_col) == ')' or my_dungeon->getCellStatus(m_row +1, m_col) == '?' or my_dungeon->getCellStatus(m_row +1, m_col) == '&') and (my_dungeon->getCellStatus(m_row + 2, m_col) == '@' or  my_dungeon->getCellStatus(m_row + 3, m_col) == '@' or my_dungeon->getCellStatus(m_row +4, m_col) == '@' or my_dungeon->getCellStatus(m_row + 5, m_col) == '@')) // if it is an empty space and actor is within range  move up
             {
                 my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
                 my_dungeon->setCellStatus(m_row+1, m_col,'G') ;
                 m_row = m_row+1;
             }
             
             else if(my_dungeon->getCellStatus(m_row + 1, m_col) == '@')
             {
                 //my_dungeon->monster_killer(m_row+1, m_col);
             }
            else
            {
                //do nothing
            }
        }
        
        {
            if((my_dungeon->getCellStatus(m_row, m_col -1) == ' ' or my_dungeon->getCellStatus(m_row, m_col-1) == '>' or my_dungeon->getCellStatus(m_row, m_col- 1) == ')' or my_dungeon->getCellStatus(m_row, m_col-1) == '?' or my_dungeon->getCellStatus(m_row, m_col-1) == '&') and (my_dungeon->getCellStatus(m_row , m_col- 2) == '@' or  my_dungeon->getCellStatus(m_row, m_col-3) == '@' or my_dungeon->getCellStatus(m_row , m_col -4) == '@' or my_dungeon->getCellStatus(m_row, m_col-5) == '@')) // if it is an empty space and actor is within range  move up
             {
                 my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
                 my_dungeon->setCellStatus(m_row, m_col-1,'G') ;
                 m_col = m_col-1;
             }
             
             else if(my_dungeon->getCellStatus(m_row, m_col-1) == '@')
             {
                // my_dungeon->monster_killer(m_row, m_col-1);
                 
             }
            else
            {
                //do nothing
            }
        }
        
        {
           if((my_dungeon->getCellStatus(m_row, m_col +1) == ' ' or my_dungeon->getCellStatus(m_row, m_col+1) == '>' or my_dungeon->getCellStatus(m_row, m_col+ 1) == ')' or my_dungeon->getCellStatus(m_row, m_col+1) == '?' or my_dungeon->getCellStatus(m_row, m_col+1) == '&') and (my_dungeon->getCellStatus(m_row , m_col+ 2) == '@' or  my_dungeon->getCellStatus(m_row, m_col+3) == '@' or my_dungeon->getCellStatus(m_row , m_col +4) == '@' or my_dungeon->getCellStatus(m_row, m_col+5) == '@')) // if it is an empty space and actor is within range  move up
            {
                my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
                my_dungeon->setCellStatus(m_row, m_col+1,'G') ;
                m_col = m_col+1;
            }
            
            else if(my_dungeon->getCellStatus(m_row, m_col +1) == '@')
            {
                //my_dungeon->monster_killer(m_row, m_col+1);
                
            }
           else
           {
               //do nothing
           }
        }
    }
}
void Goblins::drop_weapon()
{
    
}
string Goblins::get_actor() const
{
    return "Goblins";
}
Goblins::~Goblins()
{
    delete weapon;
}
int Goblins::get_row() const
{
    return m_row;
}


int Goblins::get_col() const
{
    return m_col;
}
objects* Goblins::get_weapon() const
{
    return weapon;
}





Snakewomen::Snakewomen(dungeon* dung ,int row, int col): m_row(row), m_col(col), my_dungeon(dung), actors(dung,row,col)
{
    m_hitpoints = randInt(3,6);
    m_strength = SNAKEWOMEN_STRENGTH;
    m_dexterity = SNAKEWOMEN_DEXTERITY;
    m_sleep = 0;
    m_dead = false;
    m_armor = SNAKEWOMEN_ARMOR;
    weapon = new MagicFangsOfSleep(m_row,m_col);
    
}
int Snakewomen::get_strength() const
{
    return m_strength;
}
int Snakewomen::get_dexterity() const
{
    return m_dexterity;
}
int Snakewomen::get_armor() const
{
    return m_armor;
}
int Snakewomen::get_hitpoints() const
{
    return m_hitpoints;
}
int Snakewomen::get_sleep() const
{
    return m_sleep;
}
bool Snakewomen::get_dead() const
{
    if(m_hitpoints <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Snakewomen::set_strength(int strength)
{
    m_strength = m_strength + strength;
}
void Snakewomen::set_dexterity(int dexterity)
{
    m_dexterity = dexterity + m_dexterity;
}
void Snakewomen::set_armor(int armor)
{
    m_armor = m_armor + armor;
}
void Snakewomen::set_hitpoints(int hitpoints)
{
    m_hitpoints = m_hitpoints + hitpoints;
}
void Snakewomen::set_sleep(int sleep)
{
   if (m_sleep > 0)
   {
       if(sleep > m_sleep)
       {
           m_sleep = sleep;
       }
       else
       {
           
       }
   
   }
   else
   {
       m_sleep += sleep;
   }
}
void Snakewomen::move(int instructions)
{
    {
    {
     if((my_dungeon->getCellStatus(m_row - 1, m_col) == ' ' or my_dungeon->getCellStatus(m_row -1, m_col) == '>' or my_dungeon->getCellStatus(m_row -1, m_col) == ')' or my_dungeon->getCellStatus(m_row -1, m_col) == '?' or my_dungeon->getCellStatus(m_row -1, m_col) == '&') and (my_dungeon->getCellStatus(m_row - 2, m_col) == '@' or  my_dungeon->getCellStatus(m_row - 3, m_col) == '@' or my_dungeon->getCellStatus(m_row -4, m_col) == '@' or my_dungeon->getCellStatus(m_row - 5, m_col) == '@')) // if it is an empty space and actor is within range  move up
     {
         my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
         my_dungeon->setCellStatus(m_row-1, m_col,'S') ;
         m_row = m_row-1;
     }
     
     else if(my_dungeon->getCellStatus(m_row - 1, m_col) == '@')
     {
        // my_dungeon->monster_killer(m_row-1, m_col);
         
     }
    else
    {
        //do nothing
    }
    }
     
    {
        if((my_dungeon->getCellStatus(m_row +1, m_col) == ' ' or my_dungeon->getCellStatus(m_row +1, m_col) == '>' or my_dungeon->getCellStatus(m_row +1, m_col) == ')' or my_dungeon->getCellStatus(m_row +1, m_col) == '?' or my_dungeon->getCellStatus(m_row +1, m_col) == '&') and (my_dungeon->getCellStatus(m_row + 2, m_col) == '@' or  my_dungeon->getCellStatus(m_row + 3, m_col) == '@' or my_dungeon->getCellStatus(m_row +4, m_col) == '@' or my_dungeon->getCellStatus(m_row + 5, m_col) == '@')) // if it is an empty space and actor is within range  move up
         {
             my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
             my_dungeon->setCellStatus(m_row+1, m_col,'S') ;
             m_row = m_row+1;
         }
         
         else if(my_dungeon->getCellStatus(m_row + 1, m_col) == '@')
         {
          //   my_dungeon->monster_killer(m_row+1, m_col);
         }
        else
        {
            //do nothing
        }
    }
    
    {
        if((my_dungeon->getCellStatus(m_row, m_col -1) == ' ' or my_dungeon->getCellStatus(m_row, m_col-1) == '>' or my_dungeon->getCellStatus(m_row, m_col- 1) == ')' or my_dungeon->getCellStatus(m_row, m_col-1) == '?' or my_dungeon->getCellStatus(m_row, m_col-1) == '&') and (my_dungeon->getCellStatus(m_row , m_col- 2) == '@' or  my_dungeon->getCellStatus(m_row, m_col-3) == '@' or my_dungeon->getCellStatus(m_row , m_col -4) == '@' or my_dungeon->getCellStatus(m_row, m_col-5) == '@')) // if it is an empty space and actor is within range  move up
         {
             my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
             my_dungeon->setCellStatus(m_row, m_col-1,'S') ;
             m_col = m_col-1;
         }
         
         else if(my_dungeon->getCellStatus(m_row, m_col-1) == '@')
         {
           //  my_dungeon->monster_killer(m_row, m_col-1);
             
         }
        else
        {
            //do nothing
        }
    }
    
    {
       if((my_dungeon->getCellStatus(m_row, m_col +1) == ' ' or my_dungeon->getCellStatus(m_row, m_col+1) == '>' or my_dungeon->getCellStatus(m_row, m_col+ 1) == ')' or my_dungeon->getCellStatus(m_row, m_col+1) == '?' or my_dungeon->getCellStatus(m_row, m_col+1) == '&') and (my_dungeon->getCellStatus(m_row , m_col+ 2) == '@' or  my_dungeon->getCellStatus(m_row, m_col+3) == '@' or my_dungeon->getCellStatus(m_row , m_col +4) == '@' or my_dungeon->getCellStatus(m_row, m_col+5) == '@')) // if it is an empty space and actor is within range  move up
        {
            my_dungeon->setCellStatus(m_row, m_col, ' '); // make old space empty
            my_dungeon->setCellStatus(m_row, m_col+1,'S') ;
            m_col = m_col+1;
        }
        
        else if(my_dungeon->getCellStatus(m_row, m_col +1) == '@')
        {
           // my_dungeon->monster_killer(m_row, m_col+1);
            
        }
       else
       {
           //do nothing
       }
    }
}
}
void Snakewomen::drop_weapon()
{
    
}
string Snakewomen::get_actor() const
{
    return "Snakewomen";
}
Snakewomen::~Snakewomen()
{
    delete weapon;
}
int Snakewomen::get_row() const
{
    return m_row;
}


int Snakewomen::get_col() const
{
    return m_col;
}
objects* Snakewomen::get_weapon() const
{
    return weapon;
}




Dragons::Dragons(dungeon* dung ,int row, int col): m_row(row), m_col(col),my_dungeon(dung), actors(dung,row,col)
{
    m_hitpoints = randInt(20,25);
    m_strength = DRAGON_STRENGTH;
    m_dexterity = DRAGON_DEXTERITY;
    m_sleep = 0;
    m_dead = false;
    m_armor = DRAGON_ARMOR;
    weapon = new LongSword(m_row,m_col);
    
}
int Dragons::get_strength() const
{
    return m_strength;
}
int Dragons::get_dexterity() const
{
    return m_dexterity;
}
int Dragons::get_armor() const
{
    return m_armor;
}
int Dragons::get_hitpoints() const
{
    return m_hitpoints;
}
int Dragons::get_sleep() const
{
    return m_sleep;
}
bool Dragons::get_dead() const
{
    if(m_hitpoints <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Dragons::set_strength(int strength)
{
    m_strength = m_strength + strength;
}
void Dragons::set_dexterity(int dexterity)
{
    m_dexterity += dexterity;
}
void Dragons::set_armor(int armor)
{
    m_armor += armor;
}
void Dragons::set_hitpoints(int hitpoints)
{
    m_hitpoints += hitpoints;
}
void Dragons::set_sleep(int sleep)
{
       if (m_sleep > 0)
    {
        if(sleep > m_sleep)
        {
            m_sleep = sleep;
        }
        else
        {
            
        }
    
    }
    else
    {
        m_sleep += sleep;
    }
}
void Dragons::move(int instructions)
{
    if(my_dungeon->getCellStatus(m_row, m_col +1) == '@')
    {
        my_dungeon->monster_killer(m_row, m_col+1);
    }
    else if(my_dungeon->getCellStatus(m_row+1, m_col) == '@')
    {
        my_dungeon->monster_killer(m_row+ 1, m_col);
    }
    else if(my_dungeon->getCellStatus(m_row-1, m_col) == '@')
    {
        my_dungeon->monster_killer(m_row-1, m_col);
    }
    else if(my_dungeon->getCellStatus(m_row, m_col -1) == '@')
    {
        my_dungeon->monster_killer(m_row, m_col-1);
    }
    else
    {
        
    }
}
void Dragons::drop_weapon()
{
    
}
string Dragons::get_actor() const
{
    return "Dragons";
}
Dragons::~Dragons()
{
    delete weapon;
}
int Dragons::get_row() const
{
    return m_row;
}


int Dragons::get_col() const
{
    return m_col;
}
objects* Dragons::get_weapon() const
{
    return weapon;
}
