

#ifndef ARENA_H
#define ARENA_H

#include <stdio.h>
#include <string>
#include "Robot.h"
#include "globals.h"
#include "Before.h"
//#include "Player.h"
class Player;


using std::string; 

class Arena
{
public:
    // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();
    
    // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     robotCount() const;
    int     nRobotsAt(int r, int c) const;
    void    display(string msg) const;
    
    // Mutators
    bool   addRobot(int r, int c);
    bool   addPlayer(int r, int c);
    void   damageRobotAt(int r, int c);
    bool   moveRobots();
    
    // Before
    Before& whatWasBefore();
    
private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Robot*  m_robots[MAXROBOTS];
    int     m_nRobots;
    Before m_history;
};

#endif
