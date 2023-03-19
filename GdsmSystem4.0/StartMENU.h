#pragma once
#ifndef StartMENU_H
#define StartMENU_H
#include"DBConnection.h"
#include <easyx.h>
#include<graphics.h>
#include"Struct.h"
#include "Function.h"
#include <windows.h>
#include <vector>
class StartMENU
{
public:
	Point start(DBConnection& dbConnection);
	Point teacher_start(DBConnection& dbConnection);
	Point student_start(DBConnection& dbConnection);
	Point administrator_start(DBConnection& dbConnection);
	//StartMENU();
	//~StartMENU();

private:

};


#endif // !StartMENU_H
