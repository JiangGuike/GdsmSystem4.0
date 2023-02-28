#pragma once
#include"StartMENU.h"
#include"TeacherMENU.h"
#include"StudentMENU.h"
#include"AdministratorMENU.h"

int main()
{
    StartMENU menu;
    TeacherMENU Teacher;
    StudentMENU Student;
    AdministratorMENU Admin;
    int Choice = menu.start();
    switch (Choice)
    {
    case 1:
        Teacher.Teachermenu();
        break;
    case 2:
        Student.Studentmenu();
        break;
    case 3:
        Admin.Administratormenu();
        break;
    }

    return 0;

}
