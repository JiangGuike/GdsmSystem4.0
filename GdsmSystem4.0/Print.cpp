#include "Print.h"

void Print::TE_PrintLoading()
{
	cleardevice();
	settextstyle(25, 0, FONT2_ZH);
	setbkcolor(RGB(255, 255, 255));
	// 逐一加载图片并绘制
	for (int i = 0; i <= 156; i++)
	{
		std::string file_name = "IMAGES\\Loading\\loading";
		if (i < 10) file_name += "00";
		else if (i < 100) file_name += "0";
		file_name += std::to_string(i) + ".png";

		IMAGE img;
		loadimage(&img, file_name.c_str());
		putimage(240, 60, &img);
		if (i < 60)
			outtextxy(610, 550, "你好！");
		else
			outtextxy(480, 550, "欢迎访问毕业答辩成绩管理系统");
		Sleep(8);  // 延时50毫秒
	}
	cleardevice();
	for (int i = 0; i <= 156; i++)
	{
		std::string file_name = "IMAGES\\Loading\\loading";
		if (i < 10) file_name += "00";
		else if (i < 100) file_name += "0";
		file_name += std::to_string(i) + ".png";

		IMAGE img;
		loadimage(&img, file_name.c_str());
		putimage(240, 60, &img);
		outtextxy(460, 550, "版权所有");
		outtextxy(570, 550, "CopyRight 2023 JiangGuike");
		Sleep(8);  // 延时50毫秒
	}
	cleardevice();
	for (int i = 0; i <= 156; i++)
	{
		std::string file_name = "IMAGES\\Loading\\loading";
		if (i < 10) file_name += "00";
		else if (i < 100) file_name += "0";
		file_name += std::to_string(i) + ".png";

		IMAGE img;
		loadimage(&img, file_name.c_str());
		putimage(240, 60, &img);
		if ((i / 20) % 5 == 0)
			outtextxy(470, 550, "正在加载系统及数据，请稍候");
		if ((i / 20) % 5 == 1)
			outtextxy(468, 550, "正在加载系统及数据，请稍候.");
		if ((i / 20) % 5 == 2)
			outtextxy(466, 550, "正在加载系统及数据，请稍候..");
		if ((i / 20) % 5 == 3)
			outtextxy(464, 550, "正在加载系统及数据，请稍候...");
		if ((i / 20) % 5 == 4)
			outtextxy(462, 550, "正在加载系统及数据，请稍候....");
		Sleep(8);  // 延时50毫秒
	}
	settextstyle(25, 0, FONT);
	/*
	{
		IMAGE Loading;
		char Location[50];
		char IntChange[4];
		cleardevice();
		settextstyle(25, 0, FONT2_ZH);
		setbkcolor(RGB(255, 255, 255));
		for (int i = 0; i < 156; i++)
		{
			strcpy_s(Location, MAX_PATH, ".\\IMAGES\\Loading\\loading");
			_snprintf_s(IntChange, sizeof(IntChange), _TRUNCATE, "%03d", i);
			strcat_s(Location, MAX_PATH, IntChange);
			strcat_s(Location, MAX_PATH, ".png");
			loadimage(&Loading, Location, 800, 600);
			putimage(240, 60, &Loading);
			if (i < 60)
				outtextxy(610, 550, "你好！");
			else
				outtextxy(480, 550, "欢迎访问老师后台管理系统");
			//outtextxy(0, 0, "欢迎访问老师后台管理系统");
			Sleep(8);
		}
		cleardevice();
		for (int i = 0; i < 156; i++)
		{
			strcpy_s(Location, MAX_PATH, ".\\IMAGES\\Loading\\loading");
			_snprintf_s(IntChange, sizeof(IntChange), _TRUNCATE, "%03d", i);
			strcat_s(Location, MAX_PATH, IntChange);
			strcat_s(Location, MAX_PATH, ".png");
			loadimage(&Loading, Location, 800, 600);
			putimage(240, 60, &Loading);
			outtextxy(460, 550, "版权所有");
			outtextxy(570, 550, "CopyRight 2023 JiangGuike");
			Sleep(8);
		}
		cleardevice();
		for (int i = 0; i < 156; i++)
		{
			strcpy_s(Location, MAX_PATH, ".\\IMAGES\\Loading\\loading");
			_snprintf_s(IntChange, sizeof(IntChange), _TRUNCATE, "%03d", i);
			strcat_s(Location, MAX_PATH, IntChange);
			strcat_s(Location, MAX_PATH, ".png");
			loadimage(&Loading, Location, 800, 600);
			putimage(240, 60, &Loading);
			if ((i / 20) % 5 == 0)
				outtextxy(470, 550, "正在加载系统及数据，请稍候");
			if ((i / 20) % 5 == 1)
				outtextxy(468, 550, "正在加载系统及数据，请稍候.");
			if ((i / 20) % 5 == 2)
				outtextxy(466, 550, "正在加载系统及数据，请稍候..");
			if ((i / 20) % 5 == 3)
				outtextxy(464, 550, "正在加载系统及数据，请稍候...");
			if ((i / 20) % 5 == 4)
				outtextxy(462, 550, "正在加载系统及数据，请稍候....");
			Sleep(8);
		}
		settextstyle(25, 0, FONT);
	}
	*/
}
