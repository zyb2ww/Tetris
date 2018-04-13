#include"gameMap.h"
#include"console.h"
#include"point.h"
#include"global.h"
#include<stdlib.h>
#include<iostream>

GameMap::GameMap(std::string title):title(title)
{
    //this->title = title;
    windowWidth = WINDOW_WIDTH;
    windowHeight = WINDOW_HEIGHT;

    mapTop = GAME_MAP_TOP;
    mapBottom = GAME_MAP_BOTTOM;
    mapLeft = GAME_MAP_LEFT;
    mapRight = GAME_MAP_RIGHT;

    gameMapWidth = mapRight - mapLeft + 1;
    gameMapHeight = mapBottom - mapTop + 1;
}

void GameMap::InitGameWindow()
{
    SetWindowTitle(title);
    SetWindowSize(windowWidth,windowHeight);
    SetCursorVisible(false);
}

void GameMap::DrawMap(std::string name)
{
    mapTop = GAME_MAP_TOP;
    mapBottom = GAME_MAP_BOTTOM;
    mapLeft = GAME_MAP_LEFT;
    mapRight = GAME_MAP_RIGHT;
    for(int i = mapLeft; i <= mapRight; ++i)
    {
        Point(i,mapTop).DrawSquare(7);
    }
    for(int i = mapTop+1; i <= mapBottom-1; ++i)
    {
        Point(mapLeft,i).DrawSquare(7);
        Point(mapRight,i).DrawSquare(7);
    }
     for(int i = mapLeft; i <= mapRight; ++i)
    {
        Point(i,mapBottom).DrawSquare(7);
    }

    //侧栏绘制
    Point point;
    point.SetPosition(14, 1);
    point.WriteText("Tetris",3);
    point.SetPosition(13, 2);
    point.WriteText("俄罗斯方块",3);
    point.SetPosition(12, 4);
    point.WriteText("难度",7);
    point.SetPosition(13, 5);
    point.WriteText(name,3);
    point.SetPosition(12, 7);
    point.WriteText("得分",7);
    point.SetPosition(13, 8);
    point.WriteText("     0",3);
    point.SetPosition(12, 10);
    point.WriteText(" 操作说明",7);
    point.SetPosition(13, 11);
    point.WriteText("↑旋转",3);
    point.SetPosition(13, 12);
    point.WriteText("↓加速",3);
    point.SetPosition(13, 13);
    point.WriteText("←左移",3);
    point.SetPosition(13, 14);
    point.WriteText("→右移",3);
    point.SetPosition(13, 15);
    point.WriteText("ESC暂停",3);
    point.SetPosition(13, 16);
    point.WriteText("DEL退出",3);
    point.SetPosition(12, 17);
    point.WriteText(" 状态",7);
    point.SetPosition(13, 18);
    point.WriteText(" 运行中",3);
}

void GameMap::ClearMap()
{
    system("cls");
}

void GameMap::UpdateScore(int score)
{
    SetCursorPosition(13, 8);
    SetColor(7);
    std::cout.width(6);
    std::cout <<score;
}
