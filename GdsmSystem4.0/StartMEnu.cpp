#pragma once
#include"StartMENU.h"


Point StartMENU::start(DBConnection& dbConnection)
{
	initgraph(1024, 576);    // 创建绘图窗口，大小为 1280x720 像素
	cleardevice();
	setbkcolor(RGB(244, 244, 244));
	// 设置背景色为淡白色
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 30;						// 设置字体高度为30
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT2_EN));	// 设置字体为FONT2_EN
	settextstyle(&format);
	Point p;
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\StartMenu.png"), 1024, 576);
	putimage(0, 0, &BG);


	//数据库检查
	if (dbConnection.connect())
	{
		HWND wnd = GetHWnd();
		MessageBox(wnd, "数据库连接成功！", "提示", MB_OK | MB_ICONINFORMATION);
		// 连接成功，可以使用dbConnection.getMySQL()获取MYSQL*类型的数据库连接对象进行操作
	}
	else
	{
		HWND wnd = GetHWnd();
		MessageBox(wnd, "数据库连接失败！", "警告", MB_OK | MB_ICONWARNING);
		exit(0);
		// 连接失败，处理错误
	}

	//DBConnection::~DBConnection()
	//以上都是常规代码
	p=startmenu(dbConnection);
	return p;
	closegraph();			// 关闭绘图窗口

 }

Point StartMENU::startmenu(DBConnection& dbConnection)
{
	IMAGE BG;
	Point p;
	IMAGE TeacherBox;
	IMAGE StudentBox;
	IMAGE AdministratorBox;
	loadimage(&BG, _T(".\\IMAGES\\StartMenu.png"), 1024, 576);
	loadimage(&TeacherBox, _T(".\\IMAGES\\TeacherBox.png"), 301, 51);
	loadimage(&StudentBox, _T(".\\IMAGES\\StudentBox.png"), 301, 51);
	loadimage(&AdministratorBox, _T(".\\IMAGES\\AdministratorBox.png"), 301, 51);
	putimage(0, 0, &BG);
	MENUchoose choose;
	int MENUchoice;
	MENUchoice = choose.StartMENU_MENUchoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 1:
		{
			putimage(361, 223, &TeacherBox);
			Sleep(50); // 延时0.05秒
			p = teacher_start(dbConnection);
			return p;
			break;
		}
		case 2:
		{
			putimage(361, 301, &StudentBox);
			Sleep(50); // 延时0.05秒
			p = student_start(dbConnection);
			return p;
			break;
		}
		case 3:
		{
			putimage(361, 378, &AdministratorBox);
			Sleep(50); // 延时0.05秒
			p = administrator_start(dbConnection);
			return p;
			break;
		}
		}
	}
}

Point StartMENU::teacher_start(DBConnection& dbConnection)
{
	Point p;
	//cleardevice();
	IMAGE TeacherMENU;
	IMAGE UserNameBox;
	IMAGE PassWordBox;
	IMAGE UserNameWrong;
	IMAGE PassWordWrong;
	IMAGE CancelBox;
	loadimage(&CancelBox,_T(".\\IMAGES\\CancelBox.png"), 33, 16);
	loadimage(&UserNameBox, _T(".\\IMAGES\\UserNameBox.png"), 301, 51);
	loadimage(&PassWordBox, _T(".\\IMAGES\\PasswordBox.png"), 301, 51);
	loadimage(&UserNameWrong, _T(".\\IMAGES\\UserNameWrong.png"), 301, 51);
	loadimage(&PassWordWrong, _T(".\\IMAGES\\PasswordWrong.png"), 301, 51);
	loadimage(&TeacherMENU, _T(".\\IMAGES\\Teacher_login.png"), 1024, 576);
	putimage(0, 0, &TeacherMENU);
	char UserNameID[50] = {'1', '2','3'};
	char PassWord[50] = {'1','2','3'};
	Function input;
	MENUchoose choose;
	int MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
	while (true)
	{
		switch (MENUchoice_Login)
		{
		case 1:
			{
			cleardevice(); // 清空屏幕
			putimage(0, 0, &TeacherMENU);
			putimage(361, 223, &UserNameBox);
			input.CR_InputBox(UserNameID, 11, 405, 229, 252, 40, "");

			setlinecolor(BLACK);
			line(409, 271, 657, 271);
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
			break;
			}
		case 2:                                                                                                                   
			{
			putimage(361,301, &PassWordBox);
			input.CHR_InputBox(PassWord, 16, 405, 307, 252, 30, "");
			setlinecolor(BLACK);
			line(409, 349, 657, 349);
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
			break;
			}
		case 3:
			{
			std::string found = dbConnection.findData(UserNameID, "teacher_table", "tea_id", "tea_pwd");
			if (found.empty()) {
				putimage(361, 223, &UserNameWrong);
				putimage(361, 301, &PassWordWrong);
				MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
				break;
			}
			else
			if (strcmp(found.c_str(), PassWord) == 0)
			{
				p.temp = 1;
				p.UserName = new char[strlen(UserNameID) + 1];
				strcpy_s(p.UserName, strlen(UserNameID) + 1, UserNameID);
				return p;
				}
			else {
				putimage(361, 301, &PassWordWrong);
				MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
				break;
				}
			}
		case 4:
			{
			fflush(stdin);//先清空输入缓存
			putimage(495, 452, &CancelBox);
			Sleep(50); // 延时0.05秒
			startmenu(dbConnection);
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
			break;
			}
		}
	}
}



Point StartMENU::student_start(DBConnection& dbConnection)
{
	Point p;
	//cleardevice();
	IMAGE StudentMENU;
	IMAGE UserNameBox;
	IMAGE PassWordBox;
	IMAGE UserNameWrong;
	IMAGE PassWordWrong;
	IMAGE CancelBox;
	loadimage(&CancelBox, _T(".\\IMAGES\\CancelBox.png"), 33, 16);
	loadimage(&UserNameBox, _T(".\\IMAGES\\UserNameBox.png"), 301, 51);
	loadimage(&PassWordBox, _T(".\\IMAGES\\PasswordBox.png"), 301, 51);
	loadimage(&UserNameWrong, _T(".\\IMAGES\\UserNameWrong.png"), 301, 51);
	loadimage(&PassWordWrong, _T(".\\IMAGES\\PasswordWrong.png"), 301, 51);
	loadimage(&StudentMENU, _T(".\\IMAGES\\Student_login.png"), 1024, 576);
	putimage(0, 0, &StudentMENU);
	char UserNameID[50] = { '1', '2','3' };
	char PassWord[50] = { '1','2','3' };
	Function input;
	MENUchoose choose;
	int MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
	while (true)
	{
		switch (MENUchoice_Login)
		{
		case 1:
		{
			cleardevice(); // 清空屏幕
			putimage(0, 0, &StudentMENU);
			putimage(361, 223, &UserNameBox);
			input.CR_InputBox(UserNameID, 11, 405, 229, 252, 40, "");
			setlinecolor(BLACK);
			line(409, 271, 657, 271);
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
			break;
		}
		case 2:
		{
			putimage(361, 301, &PassWordBox);
			input.CHR_InputBox(PassWord, 16, 405, 307, 252, 30, "");
			setlinecolor(BLACK);
			line(409, 349, 657, 349);
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
			break;
		}
		case 3:
		{
			cout << UserNameID;
			std::string found = dbConnection.findData(UserNameID, "student_table", "stu_id", "stu_pwd");
			if (found.empty()) {
				putimage(361, 223, &UserNameWrong);
				putimage(361, 301, &PassWordWrong);
				MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
				break;
			}
			else
				if (strcmp(found.c_str(), PassWord) == 0)
				{
					p.temp = 2;
					p.UserName = new char[strlen(UserNameID) + 1];
					strcpy_s(p.UserName, strlen(UserNameID) + 1, UserNameID);
					return p;
				}
				else {
					putimage(361, 301, &PassWordWrong);
					MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
					break;
				}
		}
		case 4:
		{
			fflush(stdin);//先清空输入缓存
			putimage(495, 452, &CancelBox);
			Sleep(50); // 延时0.05秒
			startmenu(dbConnection);
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
			break;
		}
		}
	}
}

Point StartMENU::administrator_start(DBConnection& dbConnection)
{
	Point p;
	//cleardevice();
	IMAGE AdministratorMENU;
	IMAGE UserNameBox;
	IMAGE PassWordBox;
	IMAGE UserNameWrong;
	IMAGE PassWordWrong;
	IMAGE CancelBox;
	loadimage(&CancelBox, _T(".\\IMAGES\\CancelBox.png"), 33, 16);
	loadimage(&UserNameBox, _T(".\\IMAGES\\UserNameBox.png"), 301, 51);
	loadimage(&PassWordBox, _T(".\\IMAGES\\PasswordBox.png"), 301, 51);
	loadimage(&UserNameWrong, _T(".\\IMAGES\\UserNameWrong.png"), 301, 51);
	loadimage(&PassWordWrong, _T(".\\IMAGES\\PasswordWrong.png"), 301, 51);
	loadimage(&AdministratorMENU, _T(".\\IMAGES\\Administrator_login.png"), 1024, 576);
	putimage(0, 0, &AdministratorMENU);
	char UserNameID[50] = { '1', '2','3' };
	char PassWord[50] = { '1','2','3' };
	Function input;
	MENUchoose choose;
	int MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
	while (true)
	{
		switch (MENUchoice_Login)
		{
		case 1:
		{
			cleardevice(); // 清空屏幕
			putimage(0, 0, &AdministratorMENU);
			putimage(361, 223, &UserNameBox);
			input.CR_InputBox(UserNameID, 11, 405, 229, 252, 40, "");
			setlinecolor(BLACK);
			line(409, 271, 657, 271);
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
			break;
		}
		case 2:
		{
			putimage(361, 301, &PassWordBox);
			input.CHR_InputBox(PassWord, 16, 405, 307, 252, 30, "");
			setlinecolor(BLACK);
			line(409, 349, 657, 349);
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
			break;
		}
		case 3:
		{
			cout << UserNameID;
			std::string found = dbConnection.findData(UserNameID, "admin_table", "admin_id", "admin_pwd");
			if (found.empty()) {
				putimage(361, 223, &UserNameWrong);
				putimage(361, 301, &PassWordWrong);
				MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
				break;
			}
			else
				if (strcmp(found.c_str(), PassWord) == 0)
				{
					p.temp = 3;
					p.UserName = new char[strlen(UserNameID) + 1];
					strcpy_s(p.UserName, strlen(UserNameID) + 1, UserNameID);
					return p;
				}
				else {
					putimage(361, 301, &PassWordWrong);
					MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
					break;
				}
		}
		case 4:
			{
				fflush(stdin);//先清空输入缓存
				putimage(495, 452, &CancelBox);
				Sleep(50); // 延时0.05秒
				startmenu(dbConnection);
				MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
				break;
			}
		}
	}
}



