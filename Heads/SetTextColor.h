#pragma once

#include <iostream>
#include <Windows.h>

class Color {
public:
	static const int LIGHTRED = 11;		//��ǿ��ɫ
	static const int LIGHTGREEN = 12;	//��ǿ��ɫ
	static const int LIGHTWHITE = 14;	//��ǿ��ɫ
	static const int LIGHTYELLOW = 13;	//��ǿ��ɫ
};

/*
* �������ã�����������ɫ��Ĭ��ֵ��ǿ��ɫ
* ����ֵ��Color::COLORTYPE��Ĭ��Color::LIGHTWHITE
* ����ֵ����
*/
void setTextColor(int color = Color::LIGHTWHITE);
