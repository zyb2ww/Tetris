#include"shape.h"
#include"global.h"
#include<time.h>
#include<stdlib.h>

Shape::Shape():MyPosition(INIT_POSITION_X,INIT_POSITION_Y)
{
    allShape.clear();
    std::vector< std::vector<Point> > gesture;
    std::vector<Point> s;

    //反之型
     s.push_back(Point(0,2));
     s.push_back(Point(0,1));
     s.push_back(Point(1,1));
     s.push_back(Point(1,0));
     gesture.push_back(s);
     s.clear();
     s.push_back(Point(0,1));
     s.push_back(Point(1,1));
     s.push_back(Point(-1,0));
     s.push_back(Point(0,0));
     gesture.push_back(s);
     s.clear();
     allShape.push_back(gesture);
     gesture.clear();

    //之型
    s.push_back(Point(1,2));
    s.push_back(Point(0,1));
    s.push_back(Point(1,1));
    s.push_back(Point(0,0));
    gesture.push_back(s);
    s.clear();
    s.push_back(Point(-1,1));
    s.push_back(Point(0,1));
    s.push_back(Point(0,0));
    s.push_back(Point(1,0));
    gesture.push_back(s);
    s.clear();
    allShape.push_back(gesture);
    gesture.clear();

    //L型
    s.push_back(Point(0,2));
    s.push_back(Point(0,1));
    s.push_back(Point(0,0));
    s.push_back(Point(1,0));
    gesture.push_back(s);
    s.clear();
    s.push_back(Point(-1,1));
    s.push_back(Point(0,1));
    s.push_back(Point(1,1));
    s.push_back(Point(-1,0));
    gesture.push_back(s);
    s.clear();
    s.push_back(Point(0,2));
    s.push_back(Point(1,2));
    s.push_back(Point(1,1));
    s.push_back(Point(1,0));
    gesture.push_back(s);
    s.clear();
    s.push_back(Point(1,1));
    s.push_back(Point(-1,0));
    s.push_back(Point(0,0));
    s.push_back(Point(1,0));
    gesture.push_back(s);
    s.clear();
    allShape.push_back(gesture);
    gesture.clear();

    //反L型
    s.push_back(Point(1,2));
    s.push_back(Point(1,1));
    s.push_back(Point(0,0));
    s.push_back(Point(1,0));
    gesture.push_back(s);
    s.clear();
    s.push_back(Point(-1,1));
    s.push_back(Point(-1,0));
    s.push_back(Point(0,0));
    s.push_back(Point(1,0));
    gesture.push_back(s);
    s.clear();
    s.push_back(Point(0,2));
    s.push_back(Point(1,2));
    s.push_back(Point(0,1));
    s.push_back(Point(0,0));
    gesture.push_back(s);
    s.clear();
    s.push_back(Point(-1,1));
    s.push_back(Point(0,1));
    s.push_back(Point(1,1));
    s.push_back(Point(1,0));
    gesture.push_back(s);
    s.clear();
    allShape.push_back(gesture);
    gesture.clear();

    //土型
    s.push_back(Point(1,2));
    s.push_back(Point(0,1));
    s.push_back(Point(1,1));
    s.push_back(Point(1,0));
    gesture.push_back(s);
    s.clear();
    s.push_back(Point(0,1));
    s.push_back(Point(-1,0));
    s.push_back(Point(0,0));
    s.push_back(Point(1,0));
    gesture.push_back(s);
    s.clear();
    s.push_back(Point(0,2));
    s.push_back(Point(0,1));
    s.push_back(Point(1,1));
    s.push_back(Point(0,0));
    gesture.push_back(s);
    s.clear();
    s.push_back(Point(-1,1));
    s.push_back(Point(0,1));
    s.push_back(Point(1,1));
    s.push_back(Point(0,0));
    gesture.push_back(s);
    s.clear();
    allShape.push_back(gesture);
    gesture.clear();

    //一型
    s.push_back(Point(0,3));
    s.push_back(Point(0,2));
    s.push_back(Point(0,1));
    s.push_back(Point(0,0));
    gesture.push_back(s);
    s.clear();
    s.push_back(Point(-1,0));
    s.push_back(Point(0,0));
    s.push_back(Point(1,0));
    s.push_back(Point(2,0));
    gesture.push_back(s);
    s.clear();
    allShape.push_back(gesture);
    gesture.clear();

    //田型
    s.push_back(Point(0,1));
    s.push_back(Point(1,1));
    s.push_back(Point(0,0));
    s.push_back(Point(1,0));
    gesture.push_back(s);
    s.clear();
    allShape.push_back(gesture);
    gesture.clear();

    srand((static_cast<unsigned int>(time(NULL))));
    myShape = rand() % allShape.size();
    myState = rand() % allShape.at(myShape).size();
}
Shape::Shape(Shape &shape)
{
    allShape = shape.allShape;
    myShape = shape.myShape;
    myState = shape.myState;
    MyPosition.SetPosition(shape.MyPosition);
}

bool Shape::operator==(Shape &shape)
{
    if((myShape == shape.myShape) && (myState == shape.myState) && (MyPosition == shape.MyPosition))
        return true;
    return false;
}

bool Shape::operator!=(Shape &shape)
{
    return !(*this == shape);
}

bool Shape::Move(int command, std::vector< std:: vector<bool> > &mapBuffer)
{
    Point tempPosition(MyPosition);
    int x = MyPosition.GetX();
    int y = MyPosition.GetY();
    switch(command)
    {
    case GAME_LEFT://LEFT
        x = MyPosition.GetX();
        y = MyPosition.GetY();
        MyPosition.SetPosition(x - 1,y);
        if(EdgeCheck(mapBuffer) || StopCheck(mapBuffer))
        {
            MyPosition.SetPosition(x,y);
            return true;
        }
        break;
    case GAME_RIGHT://RIGHT
        x = MyPosition.GetX();
        y = MyPosition.GetY();
        MyPosition.SetPosition(x + 1,y);
        if(EdgeCheck(mapBuffer) || StopCheck(mapBuffer))
        {
            MyPosition.SetPosition(x,y);
            return true;
        }
        break;
    default:
        break;
    }
    return false;
}

bool Shape::Down(std::vector< std:: vector<bool> > &mapBuffer)
{
    Point tempPosition(MyPosition);
    int x = MyPosition.GetX();
    int y = MyPosition.GetY();

    x = MyPosition.GetX();
    y = MyPosition.GetY();
    MyPosition.SetPosition(x,y - 1);
    if(StopCheck(mapBuffer))
    {
        MyPosition.SetPosition(x,y);
        return true;
    }
    return false;
}
bool Shape::Rotate(std::vector< std:: vector<bool> > &mapBuffer)
{
    int tempState = myState;
    myState = (myState + 1) % allShape.at(myShape).size();
    if(EdgeCheck(mapBuffer) || StopCheck(mapBuffer))
    {
        myState = tempState;
        return true;
    }
    return false;
}

bool Shape::EdgeCheck(std::vector< std::vector<bool> > & mapBuffer)
{
    int width = mapBuffer.size();
    int height = mapBuffer[0].size();
    bool flag = false;
    for(std::vector<Point>::size_type i = 0; i != allShape[myShape][myState].size(); ++i)//方块当前的各个位置是否和已堆叠的区域接触
    {
        int tempX = allShape[myShape][myState][i].GetX() + MyPosition.GetX();
        int tempY = allShape[myShape][myState][i].GetY() + MyPosition.GetY();
        if(tempX < 0 || tempX >= width)
            flag = true;
        if(tempX >=0 && tempX < width && tempY >= 0 && tempY < height && mapBuffer[tempX][tempY])
            flag = true;
    }
    return flag;
}

bool Shape::StopCheck(std::vector< std::vector<bool> > & mapBuffer)
{
    int width = mapBuffer.size();
    int height = mapBuffer[0].size();
    bool flag = false;
    for(std::vector<Point>::size_type i = 0; i != allShape[myShape][myState].size(); ++i)//方块当前的各个位置是否和已堆叠的区域接触
    {
        int tempX = allShape[myShape][myState][i].GetX() + MyPosition.GetX();
        int tempY = allShape[myShape][myState][i].GetY() + MyPosition.GetY();
        if((tempY < 0 )|| (tempY < height && tempX >= 0 && tempX < width && mapBuffer[tempX][tempY]))
            flag = true;
    }
    return flag;
}

void Shape::ReSet()
{
    myShape = rand() % allShape.size();
    myState = rand() % allShape.at(myShape).size();
    MyPosition.SetPosition(INIT_POSITION_X,INIT_POSITION_Y-1);
}

void Shape::ShapeToBuffer(std::vector< std:: vector<bool> > &mapBuffer)
{
    for(std::vector<Point>::size_type i = 0; i != allShape[myShape][myState].size(); ++i)
    {
        int x = allShape[myShape][myState][i].GetX() + MyPosition.GetX();
        int y = allShape[myShape][myState][i].GetY() + MyPosition.GetY();
        if(x >= 0 && x < MAP_BUFFER_WIDTH && y >= 0 && y < MAP_BUFFER_HEIGHT)
            mapBuffer[x][y] = true;
    }
}

void Shape::ShapeToMap(GameMap &gameMap)
{
    for(std::vector<Point>::size_type i = 0; i != allShape[myShape][myState].size(); ++i)
    {
        int bufferX = allShape[myShape][myState][i].GetX() + MyPosition.GetX();
        int bufferY = allShape[myShape][myState][i].GetY() + MyPosition.GetY();
        int x = gameMap.GetMapLeft()+ bufferX + 1;
        int y = gameMap.GetMapBottom() - 1 - bufferY;
        if( x > gameMap.GetMapLeft() && x < gameMap.GetMapRight() && y > gameMap.GetMapTop() && y < gameMap.GetMapBottom())
            Point(x,y).DrawSquare(3);
    }
}
