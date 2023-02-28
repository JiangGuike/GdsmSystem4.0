#include "StudentMENU.h"

int StudentMENU::Studentmenu()
{
	initgraph(1280, 720, EW_NOCLOSE);	// 创建绘图窗口，大小为 1280x720 像素
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
	Loading.TE_PrintLoading();
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Te_MainMenu.png"), 1280, 720);
	putimage(0, 0, &BG);	// 显示背景
	int MENUchoice;
	MENUchoice = Studentmenu_Mainmenu();
	while (true)
	{
		switch (MENUchoice)
		{
		case 1:
			MENUchoice = Studentmenu_Mainmenu();
			Sleep(5000);
		}

	}
	return 0;
}

int StudentMENU::Studentmenu_Mainmenu()
{
    return 1;
}
