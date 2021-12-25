#ifndef actors_h
#define actors_h
#include "objects.h"
#include <vector>
#include "globals.h"
class dungeon;

class actors
{
public:
    actors(dungeon* dung ,int row, int col);
    
    virtual int get_row() const = 0;
    virtual int get_col() const = 0;
    virtual int get_strength() const = 0 ;
    virtual int get_dexterity() const = 0;
    virtual int get_armor() const = 0;
    virtual int get_hitpoints() const =0;
    virtual bool get_dead() const =0;
    virtual int get_sleep() const = 0;
    virtual string get_actor() const = 0;
    virtual objects* get_weapon() const = 0;

    virtual void set_strength(int strength)= 0 ;
    virtual void set_dexterity(int dexterity)= 0;
    virtual void set_armor(int armor)= 0 ;
    virtual void set_hitpoints(int hitpoints) =0;
    virtual void set_sleep(int sleep) = 0;
    virtual void move(int instructions) = 0;
    virtual void drop_weapon() = 0;
    virtual ~actors();

    
    

private:
    
    dungeon* m_dungeon;
    int m_row;
    int m_col;
    
    
};

class Player : public actors
{
public:
    Player(dungeon* dung ,int row, int col);
    virtual int get_strength() const ;
    virtual int get_dexterity() const;
    virtual int get_armor() const;
    virtual int get_sleep() const;
    virtual bool get_dead() const;
    virtual int get_hitpoints() const;
    virtual void move(int instructions);
    virtual void set_strength(int strength) ;
    virtual void set_dexterity(int dexterity);
    virtual void set_armor(int armor);
    virtual void set_hitpoints(int hitpoints);
    virtual void set_sleep(int sleep);
    virtual void drop_weapon();
    virtual string get_actor() const;
    virtual ~Player();
    virtual int get_row() const;
    virtual int get_col() const;
    virtual void set_row(int r) ;
    virtual void set_col(int c) ;
    virtual objects* get_weapon() const;
    bool add_to_inventory(objects* add);
    void equip_weapon(char location);
    void update_Max_hitpoints(int increase);
    void display_inventory();
private:
    int m_strength;
    int m_armor;
    int m_dexterity;
    int m_sleep;
    int m_hitpoints;
    int m_dead;
    dungeon* my_dungeon;
    int m_row;
    int m_col;
    int updated_Max_hitpoints;
    vector<objects*> inventory;
    objects* my_weapon;
    
    
};

class Bogeymen : public actors
{
    public:
        Bogeymen(dungeon* dung ,int row, int col);
        virtual int get_strength() const ;
        virtual int get_dexterity() const;
        virtual int get_armor() const;
        virtual bool get_dead() const;
        virtual void move(int instructions);
        virtual void drop_weapon();
        virtual int get_hitpoints() const;
        virtual int get_sleep() const;
    
        virtual void set_strength(int strength) ;
        virtual void set_dexterity(int dexterity);
        virtual void set_armor(int armor);
        virtual void set_hitpoints(int hitpoints);
        virtual void set_sleep(int sleep);
        virtual string get_actor() const;
        virtual ~Bogeymen();
        dungeon* my_dungeon;
        virtual int get_row() const;
        virtual int get_col() const;
        virtual objects* get_weapon() const;
     
        
    private:
        int m_strength;
        int m_armor;
        int m_dexterity;
        int m_sleep;
        int m_hitpoints;
        int m_dead;
        objects* weapon;
        int m_row;
        int m_col;
};

class Goblins : public actors
{
    public:
           Goblins(dungeon* dung ,int row, int col);
           virtual int get_strength() const ;
           virtual int get_dexterity() const;
           virtual int get_armor() const;
           virtual bool get_dead() const;
           virtual int get_sleep() const;
           virtual void move(int instructions);
           virtual void drop_weapon();
           virtual int get_hitpoints() const;
           virtual void set_strength(int strength) ;
           virtual void set_dexterity(int dexterity);
           virtual void set_armor(int armor);
           virtual void set_hitpoints(int hitpoints);
           virtual void set_sleep(int sleep);
           virtual string get_actor() const;
           virtual ~Goblins();
           virtual int get_row() const;
           virtual int get_col() const;
           virtual objects* get_weapon() const;
       private:
           int m_strength;
           int m_armor;
           int m_dexterity;
           int m_sleep;
           int m_hitpoints;
           int m_dead;
           objects* weapon;
            dungeon* my_dungeon;
            int m_row;
            int m_col;
    
};

class Snakewomen : public actors
{
    public:
           Snakewomen(dungeon* dung ,int row, int col);
           virtual int get_strength() const ;
           virtual int get_dexterity() const;
           virtual int get_armor() const;
           virtual bool get_dead() const;
           virtual int get_sleep() const;
           virtual void move(int instructions);
           virtual void drop_weapon();
           virtual int get_hitpoints() const;
           virtual void set_strength(int strength) ;
           virtual void set_dexterity(int dexterity);
           virtual void set_armor(int armor);
           virtual void set_hitpoints(int hitpoints);
           virtual void set_sleep(int sleep);
           virtual string get_actor() const;
           virtual ~Snakewomen();
           virtual int get_row() const;
           virtual int get_col() const;
           virtual objects* get_weapon() const;
       private:
           int m_strength;
           int m_armor;
           int m_dexterity;
           int m_sleep;
           int m_hitpoints;
           int m_dead;
           objects* weapon;
            dungeon* my_dungeon;
            int m_row;
            int m_col;
    
};

class Dragons: public actors
{
    public:
           Dragons(dungeon* dung ,int row, int col);
           virtual int get_strength() const ;
           virtual int get_dexterity() const;
           virtual int get_armor() const;
           virtual bool get_dead() const;
           virtual int get_sleep() const;
           virtual void move(int instructions);
           virtual void drop_weapon();
           virtual int get_hitpoints() const;
           virtual void set_strength(int strength) ;
           virtual void set_dexterity(int dexterity);
           virtual void set_armor(int armor);
           virtual void set_hitpoints(int hitpoints);
           virtual void set_sleep(int sleep);
           virtual string get_actor() const;
           virtual ~Dragons();
           virtual int get_row() const;
           virtual int get_col() const;
            virtual objects* get_weapon() const;
       private:
           int m_strength;
           int m_armor;
           int m_dexterity;
           int m_sleep;
           int m_hitpoints;
           int m_dead;
           objects* weapon;
            dungeon* my_dungeon;
            int m_row;
            int m_col;
    
};








#endif /* actors_h */

