#include "Game.h"
#include "../lib/utils.h"


Game::Game() {

}

Game::~Game() {

}

void Game::gameStart(int difficulty) {
    maze.gameStart(difficulty);
    vector<string> word4;
    readFile();
    //player position
    int x = 0, y = 0;
    int goalX = maze.getMazeSize() - 1;
    int goalY = maze.getMazeSize()/2;
    string inputStr;
    cout << "If you want to use a skill that overcomes obstacles, please add '-' in front of the word.\n";
    cout << "The skill can be used up to two times.\n";
    cout << "9: player, 3: goal, 1: obstacle, 0: street\n";
    while (1) {
        fflush(stdin);
        cout << "\n";
        if (x == goalX && y == goalY) {
            cout << "도착!\n\n";
            break;
        }
        word4 = randomWord();
        maze.visualize();
        cout << "\n";
        cout << "남은 스킬 개수: " << maze.getSkillCnt() << "\n";
        cout << "위: " << word4[0];
        cout << " 아래: " << word4[1];
        cout << " 좌: " << word4[2];
        cout << " 우: " << word4[3];
        cout << "\n입력: ";
        cin >> inputStr;
        if (inputStr[0] == '-') {
            if (hardStringCompare(inputStr, "-"+word4[0])) {
                maze.moveToSkill(0);
            } else if (hardStringCompare(inputStr, "-"+word4[1])) {
                maze.moveToSkill(1);
            }else if (hardStringCompare(inputStr, "-"+word4[2])) {
                maze.moveToSkill(2);
            }else if (hardStringCompare(inputStr, "-"+word4[3])) {
                maze.moveToSkill(3);
            }
            continue;
        }
        if (hardStringCompare(inputStr, word4[0])) {
            maze.move(0);
        } else if (hardStringCompare(inputStr, word4[1])) {
            maze.move(1);
        }else if (hardStringCompare(inputStr, word4[2])) {
            maze.move(2);
        }else if (hardStringCompare(inputStr, word4[3])) {
            maze.move(3);
        }
    }
}

void Game::readFile() {
    scriptManager.fOpen("words.txt", ios_base::in);
    words = scriptManager.read();
    scriptManager.fClose();
}

vector<string> Game::randomWord() {
    vector<string> result;
    int wordsLen = words.size();
    int randNums[4] = {wordsLen, };
    int randNum;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, wordsLen-1);

    int i = 0;
    while(1){
        if (i == 4) {
            break;
        }
        randNum = dis(gen);
        for (int j = 0; j < i; ++j) {
            if (randNum == randNums[j]) {
                continue;
            }
        }
        result.push_back(words[dis(gen)]);
        i++;
    }

    return result;
}
