#include <iostream>
#include "dungeon.h"
#include "actors.h"


dungeon::dungeon(): m_cols(70) , m_rows(18),m_level(0) // CHANGE HBUNIKJOIJNJLJ THIS !!!
{
    
    build_dungeon();
    add_map_objects();
    add_player();
    add_stairs();
    add_monsters();
}

dungeon::~dungeon()
{
    delete m_player;
    for(int i = 0; i < m_monsters.size(); i++) //deletes monsters on the map
    {
        delete m_monsters[i];
    }
    for(int i = 0; i < 3; i++) // deletes objects on the map
    {
        delete map_objects[i];
    }
    m_monsters.clear(); //just in case
}





Player* dungeon::get_Player() const
{
    return m_player;
}
char dungeon::getCellStatus(int r, int c) const
{
    return m_grid[r][c];
}

void dungeon::setCellStatus(int r, int c, char status)
{
    if(r>=0 and r< 18 and c < 70 and c>= 0)
    {
    m_grid[r][c] = status;
    }
    else
    {
        
    }
}


void dungeon::display(string info) //const
{
    char CopyGrid[18][70];
    
    for(int r = 0; r < 18;r++)
    {
        for(int c = 0; c < 70;c++)
        {
            CopyGrid[r][c] = getCellStatus(r, c);
            if(getCellStatus(r, c) == ' ' and object_check(r, c) != ' ')
            {
              CopyGrid[r][c] = object_check(r, c); // if the space is empty and there is supposed to be an object there then place it ie. if an actor is currently on an object and moves update the spot
            }
            
                    
            else
            {
                
            }
        }
    }
    

    clearScreen();
    for(int i = 0; i<m_rows;i++)
    {
       for(int j = 0; j< m_cols; j++)
           cout << CopyGrid[i][j];
        cout << endl;
    }
    
    cout << endl;
    cout << "Dungeon Level: " << m_level << ", Hit points: " << m_player->get_hitpoints() << ", Armor: "<< m_player->get_armor() << ", Strength: ," << m_player->get_strength() << ", Dexterity: " << m_player->get_dexterity() << endl;
    
    if(info == "you are now wielding ")
    {
    cout << info <<  endl;
    }
    else if(info != "")
    {
        cout << info << endl;
    }
    
    
}

void dungeon::monster_killer(int r, int c)
{
  //  cout << m_monsters.size() << endl;
    for(int i=0; i < m_monsters.size();i++)
    {
        //cout << i << "." << getCellStatus(r, c) << endl;
        //cout << r <<  " "  << c << endl;
        //cout << m_monsters[i]->get_row() << " " <<  m_monsters[i]->get_col()  << endl;
        string outcome = "";
        string outcome2="";
        if(m_monsters[i]->get_row() == r and m_monsters[i]->get_col() == c)
        {
    
           // cout << i << "." << getCellStatus(r, c) << endl;
            int damagePoints = -randInt(0,m_player->get_strength()+(m_player->get_weapon()->getDamage()-1)); // make negative
            int damagePoints2 = -randInt(0,m_monsters[i]->get_strength()+(m_monsters[i]->get_weapon()->getDamage()-1));
            int attackerPoints = m_player->get_dexterity() + m_player->get_weapon()->getDexterity();
            int defenderPoints = m_monsters[i]->get_dexterity() + m_monsters[i]->get_weapon()->getDexterity();
              
            if (randInt(1, attackerPoints) >= randInt(1, defenderPoints))
            {
                m_monsters[i]->set_hitpoints(damagePoints);
                outcome = "and hits";
                outcome2 += m_monsters[i]->get_actor() + " " + m_monsters[i]->get_weapon()->getAction() + " and misses" ;
            }
            else
            {
                m_player->set_hitpoints(damagePoints2);
                outcome = " and misses";
                outcome2 += m_monsters[i]->get_actor() + " " + m_monsters[i]->get_weapon()->getAction() + " and hits" ;
            }
            
            string action = m_player->get_weapon()->getAction();
            string combine = m_player->get_actor();
            if(m_monsters[i]->get_dead() == true)
            {
                if(m_monsters[i]->get_actor() == "Dragons")
                {
                    setCellStatus(r, c, '?');
                    object_tracker(r, c, '?');
                    int x = randInt(1, 2);
                    if( x == 1)
                    {
                        map_objects.push_back(new ScrollOfTeleportation(r,c));
                    }
                    else
                    {
                        map_objects.push_back(new ScrollOfImproveArmor(r,c));
                    }
                }
                else
                {
                combine += action + " and delivers final blow";
                setCellStatus(r, c, ' ');
                m_monsters.erase(m_monsters.begin() + i);  // MEMORY LEAK MUST FIX
                }
            }
            else
            {
            combine += action + outcome;
            }
            //cout << combine << endl;
            display(combine);
            cout << outcome2;
        }
        else
        {
           // cout << "test" << endl;
        }
    }
}

void dungeon::object_interactor(int r,int c) // when player wants to pick up object
{
    for(int i = 0; i < map_objects.size();i++) // we want to just create a new item in the inventory so we can delete the old one when we make a new level
    {
        if( map_objects[i]->get_col() == c and map_objects[i]->get_row() == r)
        {
            if(map_objects[i]->identifier() == "MagicFangsOfSleep")
            {
                m_player->add_to_inventory(new MagicFangsOfSleep(r,c));
            }
            else if(map_objects[i]->identifier() == "ScrollOfTeleportation")
            {
                m_player->add_to_inventory(new ScrollOfTeleportation(r,c));
            }
            else if(map_objects[i]->identifier() == "ScrollOfRaiseStrength")
            {
                m_player->add_to_inventory(new ScrollOfRaiseStrength(r,c));
            }
            else if(map_objects[i]->identifier() == "ScrollOfEnhanceHealth")
            {
                m_player->add_to_inventory(new ScrollOfEnhanceHealth(r,c));
            }
            else if(map_objects[i]->identifier() == "ScrollOfImproveArmor")
            {
                m_player->add_to_inventory(new ScrollOfImproveArmor(r,c));
            }
            else if(map_objects[i]->identifier() == "ScrollOfEnhanceDexterity")
            {
                m_player->add_to_inventory(new ScrollOfEnhanceDexterity(r,c));
            }
            else if(map_objects[i]->identifier() == "Mace")
            {
                m_player->add_to_inventory(new Mace(r,c));
            }
            else if(map_objects[i]->identifier() == "LongSword")
            {
                m_player->add_to_inventory(new LongSword(r,c));
            }
            else if(map_objects[i]->identifier() == "MagicAxe")
            {
                m_player->add_to_inventory(new MagicAxe(r,c));
            }
            else if(map_objects[i]->identifier() == "ShortSword")
            {
                m_player->add_to_inventory(new ShortSword(r,c));
            }
            
           // m_player->add_to_inventory(map_objects[i]);// maybe a mem leak
            object_tracker(r, c, ' '); // no need to delete objects vector dungeon takes care of that
            cout << "  " << map_objects[i]->identifier() << " has been added to your inventory" << endl;
        }
        else
        {
            
        }
    }
}

void dungeon::object_tracker(int r,int c, char status) // tracks objects already on the map
{
     if(r>=0 and r< 18 and c < 70 and c>= 0)
     {
         object_grid[r][c] = status;
     }
    else
    {
        
    }
}
char dungeon::object_check(int r, int c)
{
    return object_grid[r][c];
}

void dungeon::new_level(int level)
{
    m_level = level;
    clearScreen();
    for(int r = 0; r < m_rows ;r++)  // clears history
    {
        for(int c = 0; c < m_cols;c++)
        {
            setCellStatus(r, c, ' ');
            object_tracker(r, c, ' ');
        }
    }
    //m_player->set_col(0);
    //m_player->set_row(0);
    for(int i = 0; i < map_objects.size() ;i++)// clears history
    {
        delete map_objects[i];
    }
    map_objects.clear();
    for(int j = 0; j < m_monsters.size() ;j++) // clears history
    {
        delete m_monsters[j];
    }
    m_monsters.clear();
    for(;;) // adds Player
          {
              int r_player= randInt(0,17);
              int c_player =randInt(0,69);
              
            if (getCellStatus(r_player, c_player) == ' ')
            {
                m_player->set_col(r_player);
                m_player->set_col(c_player);
                setCellStatus(r_player, c_player, '@');
                break;
            }
            else
            {
                
            }
          }
    
build_dungeon();
add_map_objects();
    

    add_monsters();
    if(m_level != 4)      // add the stairs again
    {
        add_stairs();
    }
    else
    {
        for(;;) // adds the Golden idol
        {
            int r_g = randInt(0,17);
            int c_g =randInt(0,69);
            
          if (getCellStatus(r_g, c_g) == ' ')
          {
              setCellStatus(r_g, c_g, '&');
              object_tracker(r_g, c_g, '&');
              break;
          }
          else
          {
              
          }
        }
    }
    
   // display("");
   // display("");
  //  display("");
    
}

void dungeon::Player_attacker()
{
    
}

void dungeon::add_player()
{
    for(;;) // adds Player
    {
        int r_player= randInt(0,17);
        int c_player =randInt(0,69);
        
      if (getCellStatus(r_player, c_player) == ' ')
      {
          m_player = new Player(this,r_player,c_player);
          setCellStatus(r_player, c_player, '@');
          break;
      }
      else
      {
          
      }
    }
    
}
void dungeon::add_monsters()
{
    int monsterCount = randInt(2, 5*(m_level +1)+1); // ADDS the monsters in random order to the monster vector
    //   cout << monsterCount << endl;
       while(monsterCount != 0)
       {
           int r = randInt(0,17);
           int c = randInt(0,69);
       if(getCellStatus(r, c) == ' ')
       {
           monsterCount--;
       if(m_level < 2)
       {
           int choose_monster = randInt(1, 2);
           if(choose_monster == 1)
           {
               m_monsters.push_back(new Goblins(this,r,c)) ;
               setCellStatus(r, c, 'G');
               //monster_count++;
           }
           else
           {
               m_monsters.push_back(new Snakewomen(this,r,c)) ;
               setCellStatus(r, c, 'S');
               //monster_count++;
           }
       }
        else if(m_level < 3)
         {
             int choose_monster = randInt(1, 3);
             if(choose_monster == 1)
             {
                 m_monsters.push_back(new Goblins(this,r,c)) ;
                 setCellStatus(r, c, 'G');
                 //monster_count++;
             }
             else if(choose_monster == 2)
             {
                 m_monsters.push_back(new Bogeymen(this,r,c)) ;
                 setCellStatus(r, c, 'B');
                 //monster_count++;
             }
             else
             {
                 m_monsters.push_back(new Snakewomen(this,r,c)) ;
                 setCellStatus(r, c, 'S');
                 //monster_count++;
             }
             
         }
         else if(m_level >=3)
         {
           int choose_monster = randInt(1, 4);
           
           if(choose_monster == 1)
           {
               m_monsters.push_back(new Goblins(this,r,c)) ;
               setCellStatus(r, c, 'G');
               //monster_count++;
           }
           else if(choose_monster == 2)
           {
               m_monsters.push_back(new Bogeymen(this,r,c)) ;
               setCellStatus(r, c, 'B');
               //monster_count++;
           }
           else if(choose_monster == 3)
           {
               m_monsters.push_back(new Dragons(this,r,c)) ;
               setCellStatus(r, c, 'D');
               //monster_count++;
           }
           else
           {
               m_monsters.push_back(new Snakewomen(this,r,c)) ;
               setCellStatus(r, c, 'S');
               //monster_count++;
           }
           
         }
       }
       else
       {
           
       }
       }
        
}
void dungeon::add_stairs()
{
    for(;;) // adds the stairs
    {
        int r_stairs = randInt(0,17);
        int c_stairs =randInt(0,69);
        
      if (getCellStatus(r_stairs, c_stairs) == ' ')
      {
          setCellStatus(r_stairs, c_stairs, '>');
          object_tracker(r_stairs, c_stairs, '>');
          break;
      }
      else
      {
          
      }
    }
}
void dungeon::add_map_objects()
{
        int i = 0;
        while(i < 3) // randomizer filling in the first 3 items in the array with random objects to put in the map
        {
            int object_type = randInt(1, 2);
            int r_object = randInt(0,17);
            int c_object =randInt(0,69);
    if(getCellStatus(r_object, c_object) == ' ')
        {
            i++;
            if(object_type == 1) // weapons
            {
                int weapon_type = randInt(1, 3);
                
                if(weapon_type == 1)
                {
                    map_objects.push_back(new LongSword(r_object,c_object));
                }
                else if(weapon_type == 2)
                {
                    map_objects.push_back(new ShortSword(r_object,c_object));
                }
                else
                {
                   map_objects.push_back(new Mace(r_object,c_object));
                    
                }
                setCellStatus(r_object, c_object, ')');
                object_tracker(r_object, c_object, ')');
                
            }
            else // scrolls
            {
                int scroll_type = randInt(1, 4);
                if(scroll_type == 1)
                {
                    map_objects.push_back(new ScrollOfEnhanceHealth(r_object,c_object));
                }
                else if(scroll_type == 2)
                {
                    map_objects.push_back(new ScrollOfImproveArmor(r_object,c_object));
                }
                else if(scroll_type == 3)
                {
                    map_objects.push_back(new ScrollOfEnhanceDexterity(r_object,c_object));
                }
                else
                {
                    map_objects.push_back(new ScrollOfRaiseStrength(r_object,c_object));
                }
             setCellStatus(r_object, c_object, '?');
             object_tracker(r_object, c_object, '?');
            }
        }
            else
            {
                
            }
    }
}
void dungeon::build_dungeon()
{
    int room_dimension_I_one = randInt(1, 3);
    int room_dimension_J_one = randInt(7,20);

    int room_dimension_I_two = randInt(8,11);
        
    int room_dimension_J_three = randInt(40, 55);
    int room_dimension_I_three = randInt(15, 18);

    for(int i = 0; i < m_rows; i++) // this creates a new dungeon setting, works by creating 3 rooms of seperate sizes with a corridor 1-3 items wide (usually two), the three rooms are in the same general area but will be different sizes each new level
    {

        for(int j = 0; j < m_cols; j++)
        {
            if(i == 0 or j == 0 or i == 17 or j == 69) // surrounds array with walls
            {
              //  m_grid[i][j] = '#';
               setCellStatus(i, j, '#');
               object_tracker(i, j, '#');
            }
           else if(i > room_dimension_I_one and j > 1 and i < room_dimension_I_two and  j < room_dimension_J_one) //creates a room
            {
               // m_grid[i][j] = ' ';
                setCellStatus(i, j, ' ');
                object_tracker(i, j, ' ');
            }
            else if(i > room_dimension_I_one and i < room_dimension_I_two and j > 20 and j < room_dimension_J_three) //creates a room
            {
               // m_grid[i][j] = ' ';
                setCellStatus(i, j, ' ');
                object_tracker(i, j, ' ');
            }
            else if(i > room_dimension_I_two and i < room_dimension_I_three and j > 30 and j < room_dimension_J_three) // creates a room
            {
               // m_grid[i][j] = ' ';
                setCellStatus(i, j, ' ');
                object_tracker(i, j,' ');
            }
            else if(i> room_dimension_I_one and i < room_dimension_I_two and j < 69 and j > (room_dimension_J_three +1)) // creates a room
            {
               // m_grid[i][j] = ' ';
                setCellStatus(i, j, ' ');
                object_tracker(i, j, ' ');
            }
            else if( i > (room_dimension_I_one + 1) and i < (room_dimension_I_one + 3) and j>= room_dimension_J_one and j <= 20) // connects room
            {
                //m_grid[i][j] = ' ' ;
                setCellStatus(i, j, ' ');
                object_tracker(i, j, ' ');
            }
            else if( i == room_dimension_I_two  and j > randInt(32,33) and j <= randInt(34,35)) // connects room
            {
                //m_grid[i][j]= ' ';
                setCellStatus(i, j, ' ');
                object_tracker(i, j, ' ');
            }
            else if( i < (room_dimension_I_two - 1) and i > (room_dimension_I_two - 3) and j >= room_dimension_J_three and j <= room_dimension_J_three +1 )// connects room
            {
                //m_grid[i][j]= ' ';
                setCellStatus(i, j, ' ');
                object_tracker(i, j, ' ');
            }
            else
            {
               // m_grid[i][j] = '#';
                setCellStatus(i, j, '#');
                object_tracker(i, j, '#');
            }

        }

    }

}

void dungeon::attack_player()
{
    for(int i =0 ; i < m_monsters.size();i++)
    {
        m_monsters[i] -> move(0);
    }
}
