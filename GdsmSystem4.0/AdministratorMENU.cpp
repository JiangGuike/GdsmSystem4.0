#include "AdministratorMENU.h"

int AdministratorMENU::Administratormenu(string UserName)
{
	initgraph(1280, 720, NOCLOSE);	// ������ͼ���ڣ���СΪ 1280x720 ����
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
	loadimage(&BG, _T(".\\IMAGES\\MainMenu.png"), 1280, 720);
	putimage(0, 0, &BG);	// ��ʾ����
	int MENUchoice;
	MENUchoice = Administratormenu_Mainmenu();
	while (true)
	{
		switch (MENUchoice)
		{
		case 1:
			MENUchoice = Administratormenu_Mainmenu();
			Sleep(5000);
		}

	}
	return 0;
}

int AdministratorMENU::Administratormenu_Mainmenu()
{
    return 0;
}
