#include <winsock.h> //注意顺序，要放在mysql.h前
#include <mysql.h> //控制台项目中要在mysql.h之前include<winsock.h>
#include"StartMENU.h"
#include"TeacherMENU.h"
#include"StudentMENU.h"
#include"AdministratorMENU.h"
#include"Struct.h"
#include <iostream>
#include<easyx.h>
#include"DBConnection.h"
using namespace std;

int main() {
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    StartMENU menu;
    TeacherMENU Teacher;
    StudentMENU Student;
    AdministratorMENU Admin;
      // Teacher.Teachermenu();  //调试教师
    //连接数据库
    DBConnection dbConnection("127.0.0.1", "root", "348169", "gdsmsystem");
 
    Point p = menu.start(dbConnection);
    switch (p.temp)  //p.N
    {
    case 1:
        Teacher.Teachermenu(p.UserName,  dbConnection);
        break;
    case 2:
        Student.Studentmenu(p.UserName);
        break;
    case 3:
        Admin.Administratormenu(p.UserName);
        break;
    }

    return 0;
}