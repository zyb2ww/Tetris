#ifndef GAMEMAP_H
#define GAMEMAP_H

#include"rectangle.h"
#include<string>

class GameMap{
public:
    //GameMap();{}//未定义
    GameMap(std::string title);
    void InitGameWindow();
    void DrawMap(std::string name);
    void ClearMap();
    void UpdateScore(int score);
    std::string GetTitle() { return title; }
    int GetWindowWidth() { return windowWidth; }
    int GetWindowHeight() { return windowHeight;}
    int GetGameMapWidth() { return gameMapWidth; }
    int GetGameMapHeight() { return gameMapHeight; }
    int GetMapTop() { return mapTop; }
    int GetMapBottom() { return mapBottom; };
    int GetMapLeft() { return mapLeft; };
    int GetMapRight() { return mapRight; };

private:
    std::string title;
    int windowWidth;
    int windowHeight;
    int gameMapWidth;
    int gameMapHeight;
    int mapTop;
    int mapBottom;
    int mapLeft;
    int mapRight;
};
#endif // GAMEMAP_H
