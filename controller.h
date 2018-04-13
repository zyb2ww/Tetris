#ifndef CONTROLLER_H
#define CONTROLLER_H

#include"gameMap.h"
#include"shape.h"
#include<vector>

class Controller{
public:
    Controller();
    void MapBufferReSet();
    void MapBufferSet();
    void BufferToMap();
    void ShapeToMap();
    void PlayGame();
    bool GameOver();
    int RemoveFullLine(Shape &shape);
    void InitController();
    bool Select();
    bool StopChose();
private:
    std::vector< std::vector<bool> > mapBuffer;   //图像缓存区
    std::vector<std::string> levelName;
    GameMap gameMap;
    int score;
    int level;
    int scoreRate;

};

#endif // CONTROLLER_H
