#pragma once
#ifndef STRUCT_H
#define STRUCT_H
//#include <winsock.h> //注意顺序，要放在mysql.h前
//#include <mysql.h> //控制台项目中要在mysql.h之前include<winsock.h>
//在本文件中存储结构体定义和宏定义
//本文件被所有的其余文件包含
//全局字体格式
#define FONT "黑体"
#define FONT2_ZH "宋体"
#define FONT2_EN "Consolas"
//#include <winsock.h> //注意顺序，要放在mysql.h前
#include <mysql.h> //控制台项目中要在mysql.h之前include<winsock.h>
#include"MENUchoose.h"
#include<easyx.h>
#include<stdlib.h>
#include <string>



struct Point {
    int temp;
    //std::string UserName;
    char*  UserName;
};
//#include <iostream>
#endif // !STRUCT_H