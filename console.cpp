#include"console.h"
#include<windows.h>
#include<stdio.h>
#include<string>

void SetUTF_8Style(void)//设置控制输出UTF-8格式编码
{
    system("chcp 65001");
}

void SetWindowTitle(std::string title)//设置窗口标题
{
    system(("title "+title).c_str());
}

void SetWindowSize(int cols, int lines)//设置窗口大小
{
    char cmd[30];
    sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
    system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
}

void SetCursorPosition(const int x, const int y)//设置光标位置
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(unsigned int colorID)//设置文本颜色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetCursorVisible(bool visible)//设置光标是否可见
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 25; //默认值
    cursor.bVisible = visible ? TRUE : FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor);
}
