#pragma once
//本文件存储功能性函数
#include"Struct.h"
#include<easyx.h>
#include<conio.h>
class Function
{
public:
	//输入框_登录界面（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
	int CR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
	//输入框_不显示字符_登录界面（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
	int CHR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
};

