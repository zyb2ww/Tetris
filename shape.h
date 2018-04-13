#ifndef SHAPE_H
#define SHAPE_H

#include"point.h"
#include"gameMap.h"
#include<vector>

class Shape{
public:
    Shape();
    Shape(Shape &shape);
    bool operator==(Shape &shape);
    bool operator!=(Shape &shape);
    bool Move(int command, std::vector< std:: vector<bool> > &mapBuffer);
    bool Down(std::vector< std:: vector<bool> > &mapBuffer);
    bool Rotate(std::vector< std:: vector<bool> > &mapBuffer);
    bool EdgeCheck(std::vector< std::vector<bool> > & mapBuffer);
    bool StopCheck(std::vector< std::vector<bool> > & mapBuffer);
    void ReSet();
    void ShapeToBuffer(std::vector< std:: vector<bool> > &mapBuffer);
    void ShapeToMap(GameMap &gameMap);
    int GetMyShape() { return myShape; }
    int GetMyState() { return myState; }
    Point GetPosition() { return MyPosition; }
private:
    int myShape;//形状类别
    int myState;//形状姿态
    Point MyPosition;//形状姿态
    std::vector< std::vector< std::vector<Point> > > allShape;
};

#endif // SHAPE_H

