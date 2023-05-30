#include "Maze.h"

Maze::Maze(int mazeSize) {
    //initialize
    this->mazeSize = mazeSize;
    this->skillCnt = 2;
    maze = new int*[mazeSize];
    for (int i = 0; i < mazeSize; ++i) {
        maze[i] = new int[mazeSize];
        for (int j = 0; j < mazeSize; ++j) {
            maze[i][j] = 0;
        }
    }

}

void Maze::initMaze(int mazeSize) {
    this->mazeSize = mazeSize;
    maze = new int*[mazeSize];
    for (int i = 0; i < mazeSize; ++i) {
        maze[i] = new int[mazeSize];
        for (int j = 0; j < mazeSize; ++j) {
            maze[i][j] = 0;
        }
    }

    this->skillCnt = 2;
    playerX = playerY = 0;
}

Maze::~Maze() {

}

Maze::Maze() {
}



void Maze::visualize() {
    for (int i = 0; i < mazeSize; ++i) {
        for (int j = 0; j < mazeSize; ++j) {
            cout << maze[i][j] << " ";
        }
        cout << "\n";
    }
}

int Maze::getMazeSize() const {
    return mazeSize;
}

void Maze::buildMaze() {
    random_device rd;
    mt19937 gen(rd());
    std::uniform_int_distribution<int> obstacle(0, mazeSize-1);
    std::uniform_int_distribution<int> randNum(mazeSize, (mazeSize*obstacle(gen)) + mazeSize );
    int len = randNum(gen);
    int x;
    int y;

    //initialize
    for (int i = 0; i < mazeSize; ++i) {
        for (int j = 0; j < mazeSize; ++j) {
            maze[i][j] = 0;
        }
    }

    for (int i = 0; i < len; ++i) {
        x = obstacle(gen);
        y = obstacle(gen);

        //obstacle
        maze[x][y] = 1;
    }

    //player
    maze[0][0] = 9;

    //end point
    maze[mazeSize-1][mazeSize/2] = 3;
}



void Maze::gameStart(int difficulty) {
    this->initMaze(difficulty * 10);
    this->buildMaze();

}

void Maze::move(int position) {
    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {-1, 1, 0, 0};
    int nx = dx[position];
    int ny = dy[position];
    int positionX = playerX + nx;
    int positionY = playerY + ny;

    if (positionX < 0 || positionX > mazeSize - 1) {
        return;
    }
    if (positionY < 0 || positionY > mazeSize - 1) {
        return;
    }

    if (maze[positionX][positionY] == 0) {
        maze[playerX][playerY] = 0;
        playerX = positionX;
        playerY = positionY;
        maze[playerX][playerY] = 9;
    }
}

void Maze::moveToSkill(int position) {
    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {-1, 1, 0, 0};
    int nx = dx[position];
    int ny = dy[position];
    int positionX = playerX + nx;
    int positionY = playerY + ny;

    if (positionX < 0 || positionX > mazeSize - 1) {
        return;
    }
    if (positionY < 0 || positionY > mazeSize - 1) {
        return;
    }

    if ( (maze[positionX][positionY] == 0 || maze[positionX][positionY] == 1 ) && skillCnt > 0) {
        maze[playerX][playerY] = 0;
        playerX = positionX;
        playerY = positionY;
        maze[playerX][playerY] = 9;
        skillCnt--;
    }
}

int Maze::getSkillCnt() const {
    return skillCnt;
}
