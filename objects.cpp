#include <iostream>
#include "objects.h"

using namespace std;

objects::objects(int rows, int col): m_rows(rows) , m_cols(col)
{
    
}
int objects::getDexterity() const
{
    return 0;
}
int objects::get_armor() const
{
    return 0;
}
int objects::getDamage() const
{
    return 0;
}
int objects::get_sleep() const
{
    return 0;
}
int objects::get_strength() const
{
    return 0;
}
int objects::get_health() const
{
    return 0;
}
int objects::get_row() const
{
    return m_rows;
}
int objects::get_col() const
{
    return m_cols;
}
objects::~objects()
{
    
}

MagicAxe::MagicAxe(int rows, int col):m_damage(MAGICAXE_STRENGTH_BONUS), m_dexterity(MAGICAXE_DEXTERITY_BONUS),objects(rows, col)
{
    m_action = " swings Magic Axe " ;
}
int MagicAxe::getDamage() const
{
    return m_damage;
}
int MagicAxe::getDexterity() const
{
    return m_dexterity;
}
string MagicAxe::getAction() const
{
    return m_action;
}
MagicAxe::~MagicAxe()
{
    
}
string MagicAxe::identifier() const
{
    return "MagicAxe";
}



ShortSword::ShortSword(int rows, int col): m_damage(SHORTSWORD_STRENGTH_BONUS), m_dexterity(SHORTSWORD_DEXTERITY_BONUS),objects(rows, col)
{
    m_action = " slashes Short Sword ";
}
int ShortSword::getDamage() const
{
    return m_damage;
}
int ShortSword::getDexterity() const
{
    return m_dexterity;
}
string ShortSword::getAction() const
{
    return m_action;
}
ShortSword::~ShortSword()
{
    
}
string ShortSword::identifier() const
{
    return "ShortSword";
}



LongSword::LongSword(int rows, int col):m_damage(LONGSWORD_STRENGTH_BONUS), m_dexterity(LONGSWORD_DEXTERITY_BONUS),objects(rows, col)
{
    m_action = " swings Long Sword ";
}
int LongSword::getDamage() const
{
    return m_damage;
}
int LongSword::getDexterity() const
{
    return m_dexterity;
}
string LongSword::getAction() const
{
    return m_action;
}
LongSword::~LongSword()
{
    
}
string LongSword::identifier() const
{
    return "LongSword";
}




Mace::Mace(int rows, int col):m_damage(MACE_STRENGTH_BONUS), m_dexterity(MAGICAXE_DEXTERITY_BONUS),objects(rows, col)
{
    m_action = " swings Mace ";
}
int Mace::getDamage() const
{
    return m_damage;
}
int Mace::getDexterity() const
{
    return m_dexterity;
}
string Mace::getAction() const
{
    return m_action;
}
Mace::~Mace()
{
    
}
string Mace::identifier() const
{
    return "Mace";
}




MagicFangsOfSleep::MagicFangsOfSleep(int rows, int col): m_damage(MAGICFANGS_OF_SLEEP_STRENGTH_BONUS) , objects(rows,col), m_dexterity(MAGICFANGS_OF_SLEEP_DEXTERITY_BONUS)
{
    m_action = " uses Magic Fangs of Sleep ";
    m_sleepTime = randInt(2, 6);
}
int MagicFangsOfSleep::getDamage() const
{
    return m_damage;
}
int MagicFangsOfSleep::getDexterity() const
{
    return m_dexterity;
}
string MagicFangsOfSleep::getAction() const
{
    return m_action;
}
int MagicFangsOfSleep::get_sleep() const
{
    return m_sleepTime;
}
MagicFangsOfSleep::~MagicFangsOfSleep()
{
    
}
string MagicFangsOfSleep::identifier() const
{
    return "MagicFangsOfSleep";
}




ScrollOfEnhanceDexterity::ScrollOfEnhanceDexterity(int rows, int col) : m_dexterity(1) , m_damage(0), m_action("You read a scroll of enhance dexterity. Your senses have heightened.") , objects(rows, col)
{
    
}
int ScrollOfEnhanceDexterity::getDexterity() const
{
    return m_dexterity;
}
ScrollOfEnhanceDexterity::~ScrollOfEnhanceDexterity()
{
    
}
string ScrollOfEnhanceDexterity::getAction() const
{
    return m_action;
}
int ScrollOfEnhanceDexterity::getDamage() const
{
    return m_damage;
}
string ScrollOfEnhanceDexterity::identifier() const
{
    return "ScrollOfEnhanceDexterity";
}






ScrollOfImproveArmor::ScrollOfImproveArmor(int rows, int col): m_damage(0),m_action("You read a scroll of enhance armor. Your armor glows blue."),m_dexterity(0) ,objects(rows, col)
{
    m_armor = randInt(1, 3);
}
int ScrollOfImproveArmor::get_armor() const
{
    return m_armor;
}
ScrollOfImproveArmor::~ScrollOfImproveArmor()
{
    
}
int ScrollOfImproveArmor::getDamage() const
{
    return m_damage;
}
string ScrollOfImproveArmor::getAction() const
{
    return m_action;
}
int ScrollOfImproveArmor::getDexterity() const
{
    return m_dexterity;
}
string ScrollOfImproveArmor::identifier() const
{
    return "ScrollOfImproveArmor";
}






ScrollOfEnhanceHealth::ScrollOfEnhanceHealth(int rows, int col): m_action("You read a scroll of enhance health. New blood courses through your veins."),m_dexterity(0),m_damage(0) ,objects(rows, col)
{
    m_health = randInt(2, 8);
}
int ScrollOfEnhanceHealth::get_health() const
{
    return m_health;
}
ScrollOfEnhanceHealth::~ScrollOfEnhanceHealth()
{
    
}
string ScrollOfEnhanceHealth::getAction() const
{
    return m_action;
}
int ScrollOfEnhanceHealth::getDexterity() const
{
    return m_dexterity;
}
int ScrollOfEnhanceHealth::getDamage() const
{
    return m_damage;
}
string ScrollOfEnhanceHealth::identifier() const
{
    return "ScrollOfEnhanceHealth";
}






ScrollOfRaiseStrength::ScrollOfRaiseStrength(int rows, int col): m_dexterity(0),m_action("You read a scroll of enhance strength. Your body grows stronger."),m_damage(0) ,objects(rows, col)
{
    m_strength = randInt(1, 3);
}
int ScrollOfRaiseStrength::get_strength() const
{
    return m_strength;
}
ScrollOfRaiseStrength::~ScrollOfRaiseStrength()
{
    
}
string ScrollOfRaiseStrength::getAction() const
{
    return m_action;
}
int ScrollOfRaiseStrength::getDexterity() const
{
    return m_dexterity;
}
int ScrollOfRaiseStrength::getDamage() const
{
    return m_damage;
}
string ScrollOfRaiseStrength::identifier() const
{
    return "ScrollOfRaiseStrength";
}




ScrollOfTeleportation::ScrollOfTeleportation(int rows, int col):m_damage(0),m_action("You read a scroll of teleportation. do not fear this strange place."),m_dexterity(0) ,objects(rows, col)
{
    
}
ScrollOfTeleportation::~ScrollOfTeleportation()
{
    
}
string ScrollOfTeleportation::getAction() const
{
    return m_action;
}
int ScrollOfTeleportation::getDexterity() const
{
    return m_dexterity;
}
int ScrollOfTeleportation::getDamage() const
{
    return m_damage;
}
string ScrollOfTeleportation::identifier() const
{
    return "ScrollOfTeleportation";
}






