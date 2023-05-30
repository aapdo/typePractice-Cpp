#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "Maze.h"

class Game {
private:
    Maze maze;
    vector<string> words;
    random_device rd;
    ScriptManager scriptManager;
public:
    Game();
    ~Game();
    void readFile();
    void gameStart(int);
    vector<string> randomWord();


};


#endif //PROJECT_GAME_H
