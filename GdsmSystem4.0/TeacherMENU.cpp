#include "TeacherMENU.h"

int TeacherMENU::Teachermenu(char* UserNameid, DBConnection& dbConnection)
//int TeacherMENU::Teachermenu()
{
	initgraph(1280, 720, NOCLOSE);	// 创建绘图窗口，大小为 1280x720 像素
	// 设置背景色为淡白色
	setbkcolor(RGB(255, 255, 253));
	setbkmode(TRANSPARENT);
	// 用背景色清空屏幕
	cleardevice();
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	settextstyle(&format);						// 设置字体样式
	Print Loading;
	Function TPimage;
	//Loading.TE_PrintLoading();//（加载页面）
	IMAGE BG;
	IMAGE port;
	loadimage(&port, _T(".\\IMAGES\\TEport.png"), 266, 125);
	loadimage(&BG, _T(".\\IMAGES\\MainMenu.png"), 1280, 720);
	putimage(0, 0, &BG);	// 显示背景
	setcolor(RGB(255, 102, 102));
	settextstyle(35, 0, "SimHei");
	std::string found1 = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_name");
	std::string outputStr = "你好" + found1 + "！";
	outtextxy(980, 30, outputStr.c_str());
	TPimage.transparentimage5(NULL, 507, -11, &port);
	Teachermenu_Mainmenu(UserNameid, dbConnection);
	return 0;
}

int TeacherMENU::Teachermenu_Mainmenu(char* UserNameid, DBConnection& dbConnection)
{
	// 清除个人信息指定区域
	setfillcolor(WHITE);
	solidrectangle(25, 113, 114, 146); //left , top , right , bottom ;
	// 清除成绩管理指定区域
	solidrectangle(25, 162, 114, 193);  //left , top , right , bottom ;
	// 清除打印成绩指定区域
	solidrectangle(25, 210, 114, 241);  //left , top , right , bottom ;
	// 清除侧边线指定区域
	solidrectangle(15, 117, 18, 680);  //left , top , right , bottom ;
	// 清除信息区域
	setfillcolor(RGB(245, 245, 245));
	solidrectangle(194, 122, 1280, 720);
	Function TPimage;
	IMAGE Personal;
	IMAGE Grade;
	IMAGE Print;
	IMAGE MULine;
	loadimage(&Personal, _T(".\\IMAGES\\Personal.png"), 99, 33);
	loadimage(&Grade, _T(".\\IMAGES\\Grade.png"), 99, 31);
	loadimage(&Print, _T(".\\IMAGES\\Print.png"), 99, 31);
	loadimage(&MULine, _T(".\\IMAGES\\line1.png"), 3, 563);
	TPimage.transparentimage5(NULL, 15, 113, &Personal);
	TPimage.transparentimage5(NULL, 15, 162, &Grade);
	TPimage.transparentimage5(NULL, 15, 210, &Print);
	TPimage.transparentimage5(NULL, 15, 117, &MULine);
	MENUchoose choose;
	int MENUchoice;
	MENUchoice = choose.Teachermenu_MENUchoose();
	while (true) {
		switch (MENUchoice) {
		case 1:
			Teachermenu_Personal(UserNameid, dbConnection);
			break;
		case 2:
			Teachermenu_Grade(UserNameid, dbConnection);
			break;
		case 3:
			Teachermenu_Print(UserNameid, dbConnection);
			break;
		}
	}
}


void TeacherMENU::Teachermenu_Personal(char* UserNameid, DBConnection& dbConnection)
{
	// 清除个人信息指定区域
	setfillcolor(WHITE);
	solidrectangle(25, 113, 114, 146); //left , top , right , bottom ;
	// 清除成绩管理指定区域
	solidrectangle(25, 162, 114, 193);  //left , top , right , bottom ;
	// 清除打印成绩指定区域
	solidrectangle(25, 210, 114, 241);  //left , top , right , bottom ;
	// 清除侧边线指定区域
	solidrectangle(15, 117, 18, 680);  //left , top , right , bottom ;
	// 清除信息区域
	setfillcolor(RGB(245, 245, 245));
	solidrectangle(194, 122, 1280, 720);

	Function TPimage;
	Function Change;
	IMAGE TEPersonal;
	IMAGE chPersonal;
	IMAGE Grade;
	IMAGE Print;
	IMAGE MULine;
	IMAGE revise;
	IMAGE CHrevise;	
	loadimage(&revise, _T(".\\IMAGES\\编辑色块.png"), 15, 15);
	loadimage(&CHrevise, _T(".\\IMAGES\\选中编辑色块.png"), 15, 15);
	loadimage(&MULine, _T(".\\IMAGES\\line1.png"), 3, 563);
	loadimage(&Grade, _T(".\\IMAGES\\Grade.png"), 99, 31);
	loadimage(&Print, _T(".\\IMAGES\\Print.png"), 99, 31);
	loadimage(&chPersonal, _T(".\\IMAGES\\chPersonal.png"), 99, 33);
	loadimage(&TEPersonal, _T(".\\IMAGES\\AdTePersonal.png"), 974, 561);
	TPimage.transparentimage5(NULL, 15, 117, &MULine);
	TPimage.transparentimage5(NULL, 15, 162, &Grade);
	TPimage.transparentimage5(NULL, 15, 210, &Print);
	TPimage.transparentimage5(NULL, 240, 142, &TEPersonal);
	TPimage.transparentimage5(NULL, 15, 113, &chPersonal);
	TPimage.transparentimage5(NULL, 934, 444, &revise);

	//昵称
	setcolor(RGB(0, 0, 0));
	settextstyle(43, 0, "SimHei");
	std::string name = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_name");
	setfillcolor(WHITE);
	solidrectangle(610, 210, 910, 270);  // 填充红色矩形
	setbkmode(TRANSPARENT);  // 设置文本背景为透明
	outtextxy(630, 223, name.c_str());
	//id
	setcolor(RGB(0, 0, 0));
	settextstyle(27, 0, "SimHei");
	std::string id = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_id");
	setbkmode(TRANSPARENT);  // 设置文本背景为透明
	outtextxy(725, 281, id.c_str());
	//role
	setcolor(RGB(0, 0, 0));
	settextstyle(27, 0, "SimHei");
	std::string role = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_role");
	setbkmode(TRANSPARENT);  // 设置文本背景为透明
	outtextxy(985, 281, role.c_str());
	//unit
	setcolor(RGB(0, 0, 0));
	settextstyle(27, 0, "SimHei");
	std::string unit = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_unit");
	setbkmode(TRANSPARENT);  // 设置文本背景为透明
	outtextxy(715, 376, unit.c_str());
	//pwd
	setcolor(RGB(0, 0, 0));
	settextstyle(27, 0, "SimHei");
	std::string pwd = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_pwd");
	setbkmode(TRANSPARENT);  // 设置文本背景为透明
	outtextxy(715, 441, pwd.c_str());//相隔65

	MENUchoose choose;
	int MENUchoice_Personal;
	MENUchoice_Personal = choose.Teachermenu_Personal_MENUchoose();
	while (true) {
		switch (MENUchoice_Personal) {
		case 1:
			Teachermenu_Mainmenu(UserNameid, dbConnection);
			break;
		case 2:
			Teachermenu_Grade(UserNameid, dbConnection);
			break;
		case 3:
			Teachermenu_Print(UserNameid, dbConnection);
			break;
		case 4:
			TPimage.transparentimage5(NULL, 934, 444, &CHrevise);
			Sleep(50); // 延时0.05秒
			std::string newpassword = Change.Change_password(UserNameid, dbConnection, 715, 441, 915, 475);
			if (dbConnection.updateData(UserNameid, "teacher_table", "tea_id", "tea_pwd", newpassword.c_str()))
			{
				HWND wnd = GetHWnd();
				MessageBox(wnd, "密码修改成功！", "提示", MB_OK | MB_ICONINFORMATION);
			}
			else
			{
				HWND wnd = GetHWnd();
				MessageBox(wnd, "密码修改失败！", "警告", MB_OK | MB_ICONWARNING);
			}
			// 清除修改指定区域
			setfillcolor(WHITE);
			solidrectangle(934, 444, 949, 459); //left , top , right , bottom ;
			solidrectangle(565, 500, 1000, 600); //left , top , right , bottom ;
			solidrectangle(715, 441, 930, 460); //left , top , right , bottom ;

			//newpwd
			setcolor(RGB(0, 0, 0));
			settextstyle(27, 0, "SimHei");
			std::string newpwd = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_pwd");
			setbkmode(TRANSPARENT);  // 设置文本背景为透明
			outtextxy(715, 441, newpwd.c_str());//相隔65
			TPimage.transparentimage5(NULL, 934, 444, &revise);
			MENUchoice_Personal = choose.Teachermenu_Personal_MENUchoose();
			break;
		}
	}
}

void TeacherMENU::Teachermenu_Grade(char* UserNameid, DBConnection& dbConnection)
{
	// 清除个人信息指定区域
	setfillcolor(WHITE);
	solidrectangle(25, 113, 114, 146); //left , top , right , bottom ;
	// 清除成绩管理指定区域
	solidrectangle(25, 162, 114, 193);  //left , top , right , bottom ;
	// 清除打印成绩指定区域
	solidrectangle(25, 210, 114, 241);  //left , top , right , bottom ;
	// 清除侧边线指定区域
	solidrectangle(15, 117, 18, 680);  //left , top , right , bottom ;
	// 清除信息区域
	setfillcolor(RGB(245, 245, 245));
	solidrectangle(194, 122, 1280, 720);

	Function TPimage;
	IMAGE TEPersonal;
	IMAGE chGrade;
	IMAGE Personal;
	IMAGE Print;
	IMAGE MULine;
	loadimage(&MULine, _T(".\\IMAGES\\line1.png"), 3, 563);
	loadimage(&Personal, _T(".\\IMAGES\\Personal.png"), 99, 33);
	loadimage(&Print, _T(".\\IMAGES\\Print.png"), 99, 31);
	loadimage(&chGrade, _T(".\\IMAGES\\chGrade.png"), 99, 33);
	loadimage(&TEPersonal, _T(".\\IMAGES\\AdTePersonal.png"), 974, 561);
	TPimage.transparentimage5(NULL, 15, 117, &MULine);
	TPimage.transparentimage5(NULL, 15, 113, &Personal);
	TPimage.transparentimage5(NULL, 15, 210, &Print);
	TPimage.transparentimage5(NULL, 240, 142, &TEPersonal);
	TPimage.transparentimage5(NULL, 15, 162, &chGrade);

	MENUchoose choose;
	int MENUchoice;
	MENUchoice = choose.Teachermenu_Grade_MENUchoose();
	while (true) {
		switch (MENUchoice) {
		case 1:
			Teachermenu_Personal(UserNameid, dbConnection);
			break;
		case 2:
			Teachermenu_Mainmenu(UserNameid, dbConnection);
			break;
		case 3:
			Teachermenu_Print(UserNameid, dbConnection);
			break;
		}
	}
}

void TeacherMENU::Teachermenu_Print(char* UserNameid, DBConnection& dbConnection)
{
	// 清除个人信息指定区域
	setfillcolor(WHITE);
	solidrectangle(25, 113, 114, 146); //left , top , right , bottom ;
	// 清除成绩管理指定区域
	solidrectangle(25, 162, 114, 193);  //left , top , right , bottom ;
	// 清除打印成绩指定区域
	solidrectangle(25, 210, 114, 241);  //left , top , right , bottom ;
	// 清除侧边线指定区域
	solidrectangle(15, 117, 18, 680);  //left , top , right , bottom ;
	// 清除信息区域
	setfillcolor(RGB(245, 245, 245));
	solidrectangle(194, 122, 1280, 720);

	Function TPimage;
	IMAGE TEPersonal;
	IMAGE chPrint;
	IMAGE Personal;
	IMAGE Grade;
	IMAGE MULine;
	loadimage(&MULine, _T(".\\IMAGES\\line1.png"), 3, 563);
	loadimage(&Personal, _T(".\\IMAGES\\Personal.png"), 99, 33);
	loadimage(&Grade, _T(".\\IMAGES\\Grade.png"), 99, 31);
	loadimage(&chPrint, _T(".\\IMAGES\\chPrint.png"), 99, 33);
	loadimage(&TEPersonal, _T(".\\IMAGES\\AdTePersonal.png"), 974, 561);
	TPimage.transparentimage5(NULL, 15, 117, &MULine);
	TPimage.transparentimage5(NULL, 15, 113, &Personal);
	TPimage.transparentimage5(NULL, 15, 162, &Grade);
	TPimage.transparentimage5(NULL, 240, 142, &TEPersonal);
	TPimage.transparentimage5(NULL, 15, 210, &chPrint);

	MENUchoose choose;
	int MENUchoice;
	MENUchoice = choose.Teachermenu_Print_MENUchoose();
	while (true) {
		switch (MENUchoice) {
		case 1:
			Teachermenu_Personal(UserNameid, dbConnection);
			break;
		case 2:
			Teachermenu_Grade(UserNameid, dbConnection);
			break;
		case 3:
			Teachermenu_Mainmenu(UserNameid, dbConnection);
			break;
		}
	}
}
