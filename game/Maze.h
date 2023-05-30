#ifndef PROJECT_MAZE_H
#define PROJECT_MAZE_H
#include <string>
#include <random>
#include "../scriptManage/manager/ScriptManager.h"



class Maze {
private:
    int mazeSize;
    int* (*maze);
    int skillCnt;
    int playerX;
    int playerY;
public:
    Maze(int mazeSize);
    Maze();
    ~Maze();
    void visualize();
    void buildMaze();
    void gameStart(int difficulty);
    void initMaze(int mazeSize);
    void move(int position);
    void moveToSkill(int position);

    int getMazeSize() const;

    int getSkillCnt() const;

};


#endif //PROJECT_MAZE_H
