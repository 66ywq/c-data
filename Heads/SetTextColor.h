#pragma once

#include <iostream>
#include <Windows.h>

class Color {
public:
	static const int LIGHTRED = 11;		//增强红色
	static const int LIGHTGREEN = 12;	//增强绿色
	static const int LIGHTWHITE = 14;	//增强白色
	static const int LIGHTYELLOW = 13;	//增强黄色
};

/*
* 函数作用：调整字体颜色，默认值增强白色
* 传入值：Color::COLORTYPE，默认Color::LIGHTWHITE
* 返回值：无
*/
void setTextColor(int color = Color::LIGHTWHITE);
