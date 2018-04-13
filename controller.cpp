#include"controller.h"
#include"global.h"
#include"point.h"
#include"shape.h"
#include"controller.h"
#include<vector>
#include<string>
#include<conio.h>
#include<iostream>
#include<algorithm>
#include<windows.h>

Controller::Controller():gameMap("俄罗斯方块")
{
    std::vector<bool> cols(MAP_BUFFER_HEIGHT,false);
    for(int i = 0; i != MAP_BUFFER_WIDTH; ++i)
        mapBuffer.emplace_back(cols);

    levelName.push_back("Level 1");
    levelName.push_back("Level 2");
    levelName.push_back("Level 3");
    levelName.push_back("Level 4");
    levelName.push_back("Level 5");
    levelName.push_back("Level 6");
    levelName.push_back("Level 7");

    score = 0;
    scoreRate = 10;
    level = 0;
}

void Controller::MapBufferReSet()
{
    for(std::vector<bool>::size_type i = 0; i != mapBuffer.size(); ++i)
        for(std::vector<bool>::size_type j = 0; j != mapBuffer[0].size(); ++j)
            mapBuffer[i][j] = false;
}

void Controller::MapBufferSet()
{
    for(std::vector<bool>::size_type i = 0; i != mapBuffer.size(); ++i)
        for(std::vector<bool>::size_type j = 0; j != mapBuffer[0].size(); ++j)
            mapBuffer[i][j] = true;
}

void Controller::BufferToMap()
{
    for(std::vector<bool>::size_type i = 0; i != mapBuffer.size(); ++i)
    {
        for(std::vector<bool>::size_type j = 0; j != mapBuffer[0].size(); ++j)
        {
            int x = gameMap.GetMapLeft()+ i + 1;
            int y = gameMap.GetMapBottom() - 1 - j;
            if( x > gameMap.GetMapLeft() && x < gameMap.GetMapRight() && y > gameMap.GetMapTop() && y < gameMap.GetMapBottom())
                if(mapBuffer[i][j])
                    Point(x,y).DrawSquare(3);
                else
                    Point(x,y).DrawErase();
            else
                ;
        }
    }

}

int GetKeyBoard()
{
    int command = 0;
    if(kbhit())
    {

        command = getch();
        if(command == 0xE0)
            command = getch();
    }
    return command;
}

void Controller::PlayGame()
{
    gameMap.InitGameWindow();
    while(1)
    {
        if(!Select())
            return;
        gameMap.ClearMap();
        gameMap.DrawMap(levelName[level]);
        Shape shape;
        int counter = 0;
        int num =5;
        int speed = 150;
        switch(level)
        {
        case 0:
            speed = 150;
            break;
        case 1:
            speed = 120;
            break;
        case 2:
            speed = 90;
            break;
        case 3:
            speed = 60;
            break;
        case 4:
            speed = 30;
            break;
        case 5:
            speed = 10;
            break;
        case 6:
            speed = 5;
            break;
        default:
            break;
        }
        while(!GameOver())
        {

            counter++;
            counter %= num;
            Shape tempShape(shape);
            int command = GetKeyBoard();//识别键盘动作
            switch(command)
            {
            case GAME_ESC:
                if(StopChose())
                    return;
                break;
            case GAME_DELETE:
                return;
            case GAME_LEFT:
                shape.Move(GAME_LEFT,mapBuffer);
                break;
            case GAME_RIGHT:
                shape.Move(GAME_RIGHT,mapBuffer);
                break;
            case GAME_UP:
                shape.Rotate(mapBuffer);
                break;
            case GAME_DOWN:
                break;
            default:
                break;
            }
            if(!counter || (command == GAME_DOWN))
            {
                if(shape.Down(mapBuffer))
                {
                    shape.ShapeToBuffer(mapBuffer);
                    int lineNumber = RemoveFullLine(shape);
                    if(lineNumber != 0);
                    {
                        score += lineNumber * scoreRate;
                    }
                    BufferToMap();
                    gameMap.UpdateScore(score);
                    shape.ReSet();
                }
                else
                {
                    BufferToMap();
                    shape.ShapeToMap(gameMap);
                }
            }
            else
            {
                if(shape != tempShape)
                    BufferToMap();
                shape.ShapeToMap(gameMap);
            }
            Sleep(speed);
        }
        Point point;
        point.SetPosition(4, 7);
        point.WriteText("          ",10);
        point.SetPosition(4, 7);
        point.WriteText("Game Over!",10);
        point.SetPosition(3, 9);
        point.WriteText("              ",10);
        point.SetPosition(3, 9);
        point.WriteText("按ESC重新开始",10);
        point.SetPosition(3, 11);
        point.WriteText("              ",10);
        point.SetPosition(3, 11);
        point.WriteText("按DEL退出游戏",10);
        while(1)
        {
            int command = GetKeyBoard();//识别键盘动作
            if(command == GAME_ESC)
                break;
            else if(command == GAME_DELETE)
                return;
            else;
        }
        InitController();

    }

}

bool Controller::GameOver()
{
    bool flag = false;
    std::vector<bool>::size_type len = mapBuffer[0].size();
    for(std::vector< std::vector<bool> >::size_type i = 0; i != mapBuffer.size(); ++i)
        if(mapBuffer[i][len-1])
        {
            flag = true;
            break;
        }
    return flag;
}

int Controller::RemoveFullLine(Shape &shape)
{
    int width = mapBuffer.size();
    int height = mapBuffer[0].size();
    int initHeight = shape.GetPosition().GetY();
    bool removeFlag;
    int lineNumber = 0;
    std::vector<bool> removeFlagArray(height,false);
    for(int i = initHeight; i < std::min(height,initHeight + 4); ++i)//找出满行
    {
        removeFlag = true;
        for(int j = 0; j < width; ++j)
        {
            if(!mapBuffer[j][i])
                removeFlag = false;
        }
        removeFlagArray[i] = removeFlag;
        if(removeFlag)
            lineNumber++;
    }

    for(int i = 0, j = 0; i < height; ++i,++j)
    {
        while(removeFlagArray[j])
            j++;
        if(i < j && j<height)
        {
            for(int k = 0; k < width; ++k)
                mapBuffer[k][i] = mapBuffer[k][j];
        }
        if(i<j && j >= height)
        {
            for(int k = 0; k < width; ++k)
                mapBuffer[k][i] = false;
        }
    }
    return lineNumber;
}

void Controller::InitController()
{
    score = 0;
    level = 0;
    MapBufferReSet();
    gameMap.ClearMap();
}

bool Controller::Select()
{
    int levelNumber = 7;
    bool flag = false;
    Point point;
    point.SetPosition(6, 1);
    point.WriteText("俄罗斯方块",3);
    point.SetPosition(2, 3);
    point.WriteText("难度等级(等级越高难度越大)",5);
    point.SetPosition(7, 5);
    point.WriteText(levelName[0],120);
    point.SetPosition(7, 6);
    point.WriteText(levelName[1],7);
    point.SetPosition(7, 7);
    point.WriteText(levelName[2],7);
    point.SetPosition(7, 8);
    point.WriteText(levelName[3],7);
    point.SetPosition(7, 9);
    point.WriteText(levelName[4],7);
    point.SetPosition(7, 10);
    point.WriteText(levelName[5],7);
    point.SetPosition(7, 11);
    point.WriteText(levelName[6],7);

    point.SetPosition(6, 13);
    point.WriteText("↑和↓选择难度",10);
    point.SetPosition(6, 15);
    point.WriteText("ENTER确认",10);
    point.SetPosition(6, 17);
    point.WriteText("ESC退出游戏",10);


    while(1)
    {
        int command = GetKeyBoard();//识别键盘动作
        switch(command)
        {
        case GAME_UP:
            point.SetPosition(7, 5+level);
            point.WriteText(levelName[level],7);
            level--;
            level = (level + levelNumber) % levelNumber;
            point.SetPosition(7, 5+level);
            point.WriteText(levelName[level],120);
            break;
        case GAME_DOWN:
            point.SetPosition(7, 5+level);
            point.WriteText(levelName[level],7);
            level++;
            level = (level + levelNumber) % levelNumber;
            point.SetPosition(7, 5+level);
            point.WriteText(levelName[level],120);
            break;
        case GAME_ENTER:
            point.SetPosition(0, 0);
            point.WriteText(" ",7);
            return true;
        case GAME_ESC:
            return false;
        default:
            break;
        }
    }
    return true;
}

bool Controller::StopChose()
{
    int state = 0;
    int key = 0;
    std::vector<std::string> stateStr;
    stateStr.push_back(" 继续游戏");
    stateStr.push_back(" 退出游戏");
    Point point;
    point.SetPosition(13, 18);
    point.WriteText(" 暂停中",3);
    point.SetPosition(13, 19);
    point.WriteText(stateStr[0],120);
    point.SetPosition(13, 20);
    point.WriteText(stateStr[1],7);
    while(1)
    {
        int command = GetKeyBoard();
        switch(command)
        {
        case GAME_UP:
            point.SetPosition(13, 19 + key);
            point.WriteText(stateStr[key],120);
            key--;
            key = (key + 2) % 2;
            point.SetPosition(13, 19 + key);
            point.WriteText(stateStr[key],7);
            break;
        case GAME_DOWN:
            point.WriteText(stateStr[key],120);
            key++;
            key = (key + 2) % 2;
            point.SetPosition(13, 19 + key);
            point.WriteText(stateStr[key],7);
            break;
        case GAME_ENTER:
            point.SetPosition(13, 19);
            point.WriteText("         ",7);
            point.SetPosition(13, 20);
            point.WriteText("         ",7);
            return (key == 1) ? true : false;
        default:
            break;
        }
    }
    return false;
}
