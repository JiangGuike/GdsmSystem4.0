#include "StudentMENU.h"

int StudentMENU::Studentmenu()
{
	initgraph(1280, 720, EW_NOCLOSE);	// ������ͼ���ڣ���СΪ 1280x720 ����
	// ���ñ���ɫΪ����ɫ
	setbkcolor(RGB(255, 255, 253));
	setbkmode(TRANSPARENT);
	// �ñ���ɫ�����Ļ
	cleardevice();
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// ��������ΪFONT
	settextstyle(&format);						// ����������ʽ
	Print Loading;
	Loading.TE_PrintLoading();
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Te_MainMenu.png"), 1280, 720);
	putimage(0, 0, &BG);	// ��ʾ����
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
