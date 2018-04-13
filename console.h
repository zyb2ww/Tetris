#ifndef CONSOLE_H
#define CONSOLE_H

#include<string>

//colorID 值定义在wincon.h中，如下
//#define FOREGROUND_BLUE	1
//#define FOREGROUND_GREEN	2
//#define FOREGROUND_RED	4
//#define FOREGROUND_INTENSITY	8
//#define BACKGROUND_BLUE	16
//#define BACKGROUND_GREEN	32
//#define BACKGROUND_RED	64
//#define BACKGROUND_INTENSITY	128

void SetUTF_8Style(void);
void SetWindowTitle(std::string title);
void SetWindowSize(int cols, int rows);
void SetCursorPosition(const int x, const int y);
void SetColor(unsigned int colorID);
void SetCursorVisible(bool visible);

#endif // CONSOLE_H

