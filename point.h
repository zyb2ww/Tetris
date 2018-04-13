#ifndef POINT_H
#define POINT_H

#include<string>

class Point{
public:
    Point():x(0),y(0){}
    Point(const int x, const int y):x(x),y(y){}
    Point(const Point& point) { x = point.x; y = point.y; }
    void DrawSquare(int colorID) const;
    void DrawCircle(int colorID) const;
    void DrawStar(int colorID) const;
    void WriteText(std::string text,int colorID);
    void DrawErase() const;

    void SetPosition(const Point& point) { this->x = point.x; this->y = point.y; }
    void SetPosition(int x, int y) { this->x = x; this->y = y; };
    bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
    bool operator!= (const Point& point) { return !(*this == point); }
    int GetX() { return x; }
    int GetY() { return y; }
private:
    int x;
    int y;
};

#endif // POINT_H
