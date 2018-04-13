#include"point.h"
#include"console.h"
#include<windows.h>
#include<iostream>

void Point::DrawSquare(int colorID) const
{
    SetColor(colorID);
    SetCursorPosition(x, y);
    std::cout << "■" ;
}

void Point::DrawCircle(int colorID) const
{
    SetColor(colorID);
    SetCursorPosition(x, y);
    std::cout << "●" ;
}

void Point::DrawStar(int colorID) const
{
    SetColor(colorID);
    SetCursorPosition(x, y);
    std::cout << "★" ;
}

void Point::WriteText(std::string text,int colorID)
{
    SetColor(colorID);
    SetCursorPosition(x, y);
    std::cout << text;
}

void Point::DrawErase() const
{
    SetCursorPosition(x, y);
    std::cout << "  " ;
}
