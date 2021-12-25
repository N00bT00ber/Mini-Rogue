
#ifndef dungeon_h
#define dungeon_h
#include "actors.h"


class dungeon
{
public:
    dungeon();
    ~dungeon();

    
    void display(string info);
    Player* get_Player() const;
    char getCellStatus(int r, int c) const;
    void setCellStatus(int r, int c, char status);
    void monster_killer(int r, int c);
    void Player_attacker();
    void object_tracker(int r, int c, char status) ; // second set cell status for objects incase players run over them
    char object_check(int r, int c); // get cell status for object grid
    void object_interactor(int r,int c);
    //void add_objects(int r, int c,char type);
    void new_level(int level);
    void add_player();
    void add_monsters();
    void add_stairs();
    void add_map_objects();
    void build_dungeon();
    void attack_player();
    //void player_location();
   // void set_level(int level);
   // int get_level() const;
    
   
    // actor player
    // actor
private:
    
    int m_rows;
    int m_cols;
    int m_level;
    char m_grid[18][70];
    char object_grid[18][70];
    int monster_count;
    Player* m_player;
    vector<actors*> m_monsters ;
    vector<objects*> map_objects;
    
    
};


#endif /* dungeon_h */
