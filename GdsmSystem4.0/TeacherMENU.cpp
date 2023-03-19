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
	//Loading.TE_PrintLoading();（暂时注销调试）
	IMAGE BG;
	IMAGE port;
	IMAGE Personal;
	IMAGE Grade;
	IMAGE Print;
	loadimage(&port, _T(".\\IMAGES\\TEport.png"), 266, 125);
	loadimage(&BG, _T(".\\IMAGES\\MainMenu.png"), 1280, 720);
	loadimage(&Personal, _T(".\\IMAGES\\Personal.png"), 99, 33);
	loadimage(&Grade, _T(".\\IMAGES\\Grade.png"), 99, 31);
	loadimage(&Print, _T(".\\IMAGES\\Print.png"), 99, 31);
	putimage(0, 0, &BG);	// 显示背景
	setcolor(RGB(255, 102, 102));
	settextstyle(35, 0, "SimHei");

	std::string found1 = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_name");
	std::string outputStr = "你好" + found1 + "！";
	outtextxy(980, 30, outputStr.c_str());
	/*
	std::string outputStr = "你好吴瑞！";
	outtextxy(980, 30, outputStr.c_str());
	*/
	TPimage.transparentimage5(NULL, 507, -11, &port);
	TPimage.transparentimage5(NULL, 15, 113, &Personal);
	TPimage.transparentimage5(NULL, 15, 162, &Grade);
	TPimage.transparentimage5(NULL, 15, 210, &Print);
	MENUchoose choose;
	int MENUchoice;
	MENUchoice = choose.Teachermenu_MENUchoose();
	while (true) {
		switch (MENUchoice) {
		case 1:
			Teachermenu_Personal(UserNameid,dbConnection);
			break;
		case 2:
			Teachermenu_Grade();
			break;
		case 3:
			Teachermenu_Print();
			break;
		}
	}
}


void TeacherMENU::Teachermenu_Personal(char* UserNameid, DBConnection& dbConnection)
{
	// 清除个人信息指定区域
	setfillcolor(WHITE);
	solidrectangle(25, 113, 114, 146); //left , top , right , bottom ;
	// 清除信息区域
	setfillcolor(RGB(245, 245, 245));
	solidrectangle(194, 122, 1280, 720);

	Function TPimage;
	IMAGE TEPersonal;
	IMAGE chPersonal;
	loadimage(&chPersonal, _T(".\\IMAGES\\chPersonal.png"), 99, 33);
	loadimage(&TEPersonal, _T(".\\IMAGES\\AdTePersonal.png"), 974, 561);
	TPimage.transparentimage5(NULL, 240, 142, &TEPersonal);
	TPimage.transparentimage5(NULL, 15, 113, &chPersonal);
	//昵称
	setcolor(RGB(255, 102, 102));
	settextstyle(35, 0, "SimHei");
	std::string found2 = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_name");
	std::string outputStr =found2;
	outtextxy(980, 30, outputStr.c_str());
	Sleep(50000); // 暂时死循环（调试）
}

void TeacherMENU::Teachermenu_Grade()
{
	// 清除成绩管理指定区域
	solidrectangle(25, 162, 114, 193);  //left , top , right , bottom ;
	// 清除信息区域
	setfillcolor(RGB(245, 245, 245));
	solidrectangle(194, 122, 1280, 720);

	Function TPimage;
	IMAGE TEPersonal;
	IMAGE chGrade;
	loadimage(&chGrade, _T(".\\IMAGES\\chGrade.png"), 99, 33);
	loadimage(&TEPersonal, _T(".\\IMAGES\\AdTePersonal.png"), 974, 561);
	TPimage.transparentimage5(NULL, 240, 142, &TEPersonal);
	TPimage.transparentimage5(NULL, 15, 162, &chGrade);
	Sleep(50000); // 暂时死循环（调试）
}

void TeacherMENU::Teachermenu_Print()
{
	// 清除打印成绩指定区域
	solidrectangle(25, 210, 114, 241);  //left , top , right , bottom ;
	// 清除信息区域
	setfillcolor(RGB(245, 245, 245));
	solidrectangle(194, 122, 1280, 720);

	Function TPimage;
	IMAGE TEPersonal;
	IMAGE chPrint;
	loadimage(&chPrint, _T(".\\IMAGES\\chPrint.png"), 99, 33);
	loadimage(&TEPersonal, _T(".\\IMAGES\\AdTePersonal.png"), 974, 561);
	TPimage.transparentimage5(NULL, 240, 142, &TEPersonal);
	TPimage.transparentimage5(NULL, 15, 210, &chPrint);
	Sleep(50000); // 暂时死循环（调试）
}
