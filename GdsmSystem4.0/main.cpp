#include <winsock.h> //ע��˳��Ҫ����mysql.hǰ
#include <mysql.h> //����̨��Ŀ��Ҫ��mysql.h֮ǰinclude<winsock.h>
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
      // Teacher.Teachermenu();  //���Խ�ʦ
    //�������ݿ�
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