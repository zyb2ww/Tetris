#include"rectangle.h"
#include"console.h"
#include<algorithm>
#include<iostream>

Rectangle::Rectangle(Rectangle &rect)
{
    top = rect.top;
    left = rect.left;
    bottom = rect.bottom;
    right = rect.right;
}

Rectangle::Rectangle(Point &point1, Point &point2)
{
    int x1,x2,y1,y2;
    x1 = point1.GetX();
    y1 = point1.GetY();
    x2 = point2.GetX();
    y2 = point2.GetY();
    top = std::min(y1,y2);
    left = std::min(x1,x2);
    bottom = std::max(y1,y2);
    right = std::max(x1,x2);
}

void Rectangle::Fill(std::string token,int colorID)
{
    SetColor(colorID);
    for(int i = top; i <= bottom; ++i)
    {
        for(int j = left; j <= right; ++j)
        {
            SetCursorPosition(j, i);
            std::cout << token;
        }
    }

}

void Rectangle::Clear()
{
    Fill("  ",7);
}
