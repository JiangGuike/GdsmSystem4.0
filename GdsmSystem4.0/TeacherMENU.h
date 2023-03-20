#pragma once
#include"Function.h"
#include<easyx.h>
#include"Print.h"
#include"DBConnection.h"
class TeacherMENU
{
public:
	int Teachermenu(char* UserNameid , DBConnection& dbConnection);
	//int Teachermenu();
	int Teachermenu_Mainmenu(char* UserNameid, DBConnection& dbConnection);
private:
	void Teachermenu_Personal(char* UserNameid, DBConnection& dbConnection);
	void Teachermenu_Grade(char* UserNameid, DBConnection& dbConnection);
	void Teachermenu_Print(char* UserNameid, DBConnection& dbConnection);
};

