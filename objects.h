#ifndef objects_h
#define objects_h
#include <string>
#include "globals.h"
#include "utilities.h"
//#include "actors.h"

using namespace std;

class objects
{

public:
    objects(int rows, int col);
    
    virtual int getDamage() const;
    virtual int getDexterity() const ;
    virtual string getAction() const = 0 ;
    virtual int get_strength() const ;
    virtual int get_sleep() const ;
    virtual int get_armor() const;
    virtual int get_health() const;
    virtual ~objects();
    virtual string identifier() const = 0;
    int get_row() const ; // object start position always the same as its end
    int get_col() const ; // object start position always the same as its end
    
private:
    int m_rows;
    int m_cols;

};



class MagicAxe : public objects
{
public:
    MagicAxe(int rows, int col);
    virtual string getAction() const;
    virtual int getDamage() const;
    virtual int getDexterity() const;
  //  virtual int get_strength() const ;
 //   virtual int get_sleep() const ;
 //   virtual int get_armor() const ;
    virtual ~MagicAxe();
    virtual string identifier() const;

    
private:
    int m_damage;
    int m_dexterity;
    string m_action;
};



class ShortSword : public objects
{
    public:
        ShortSword(int rows, int col);
    virtual string getAction() const;
    virtual int getDamage() const ;
    virtual int getDexterity() const;
    virtual ~ShortSword();
    virtual string identifier() const ;
  //  virtual int get_strength() const ;
 //   virtual int get_sleep() const ;
  //  virtual int get_armor() const ;
        
    private:
        int m_damage;
        int m_dexterity;
        string m_action;
    
};



class Mace : public objects
{
 public:
     Mace(int rows, int col);
     virtual string getAction() const;
     virtual int getDamage() const;
     virtual int getDexterity() const;
    virtual ~Mace();
     virtual string identifier() const ;
 private:
     int m_damage;
     int m_dexterity;
     string m_action;
    
};

class LongSword : public objects
{
    public:
        LongSword(int rows, int col);
        virtual string getAction() const;
        virtual int getDamage() const;
        virtual int getDexterity() const;
        virtual ~LongSword();
        virtual string identifier() const;


        
    private:
        int m_damage;
        int m_dexterity;
        string m_action;
    
};

class MagicFangsOfSleep : public objects
{
    public:
        MagicFangsOfSleep(int rows, int col);
        virtual string getAction() const;
        virtual int getDamage() const;
        virtual int getDexterity() const;
        virtual int get_sleep() const;
        virtual ~MagicFangsOfSleep();
        virtual string identifier() const ;


        
    private:
        int m_damage;
        int m_dexterity;
        int m_sleepTime;
        string m_action;
};


class ScrollOfTeleportation : public objects
{
    public:
        ScrollOfTeleportation(int rows, int col);
        virtual ~ScrollOfTeleportation();
         virtual string getAction() const;
        virtual int getDamage() const ;
        virtual int getDexterity() const;
        virtual string identifier() const ;
        // Teleport through game class
      
private:
    int m_damage;
    int m_dexterity;
    string m_action;
};


class ScrollOfImproveArmor : public objects
{
public:
   
    ScrollOfImproveArmor(int rows, int col);
    virtual int get_armor() const;
    virtual string getAction() const;
    virtual int getDamage() const ;
    virtual int getDexterity() const;
    virtual ~ScrollOfImproveArmor();
    virtual string identifier() const;

private:
    int m_armor ;
    int m_damage;
    int m_dexterity;
    string m_action;
};


class ScrollOfRaiseStrength: public objects
{
public:
    
    ScrollOfRaiseStrength(int rows, int col);
    virtual int get_strength() const;
     virtual string getAction() const;
    virtual int getDamage() const ;
    virtual int getDexterity() const;
    virtual ~ScrollOfRaiseStrength();
    virtual string identifier() const ;
    
private:
        
    int m_strength;
    int m_damage;
    int m_dexterity;
    string m_action;
        
    
};


class ScrollOfEnhanceHealth : public objects
{
public:
    ScrollOfEnhanceHealth(int rows, int col);
    virtual int get_health() const;
    virtual string getAction() const;
    virtual int getDamage() const ;
    virtual int getDexterity() const;
    virtual ~ScrollOfEnhanceHealth();
    virtual string identifier() const ;
             
private:
    int m_health;
    int m_damage;
    int m_dexterity;
    string m_action;
    
};


class ScrollOfEnhanceDexterity : public objects
{
public:
    ScrollOfEnhanceDexterity(int rows, int col);
    virtual int getDexterity() const;
    virtual string getAction() const;
    virtual int getDamage() const ;
    virtual ~ScrollOfEnhanceDexterity();
    virtual string identifier() const ;
        
private:
        
    int m_dexterity;
    int m_damage;
    string m_action;
    
};





#endif /* objects_h */
