#ifndef RECTANGLE_H
#define RECTANGLE_H

#include"point.h"

class Rectangle{
public:
    Rectangle():top(0),left(0),bottom(0),right(0){}
    Rectangle(int top,int left,int bottom,int right):top(top),left(left),bottom(bottom),right(right){};
    Rectangle(Rectangle &rect);
    Rectangle(Point &point1, Point &point2);
    void Fill(std::string token,int colorID);
    void Clear();
    int GetTop() { return top; }
    int GetLeft() { return left; }
    int GetBottom() { return bottom; }
    int GetRight() { return right; }
private:
    int top;
    int left;
    int bottom;
    int right;
};

#endif // RECTANGLE_H
