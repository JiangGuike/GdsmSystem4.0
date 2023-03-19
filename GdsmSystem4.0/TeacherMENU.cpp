#include "TeacherMENU.h"

int TeacherMENU::Teachermenu(char* UserNameid, DBConnection& dbConnection)
//int TeacherMENU::Teachermenu()
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
	Function TPimage;
	//Loading.TE_PrintLoading();����ʱע�����ԣ�
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
	putimage(0, 0, &BG);	// ��ʾ����
	setcolor(RGB(255, 102, 102));
	settextstyle(35, 0, "SimHei");

	std::string found1 = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_name");
	std::string outputStr = "���" + found1 + "��";
	outtextxy(980, 30, outputStr.c_str());
	/*
	std::string outputStr = "�������";
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
	// ���������Ϣָ������
	setfillcolor(WHITE);
	solidrectangle(25, 113, 114, 146); //left , top , right , bottom ;
	// �����Ϣ����
	setfillcolor(RGB(245, 245, 245));
	solidrectangle(194, 122, 1280, 720);

	Function TPimage;
	IMAGE TEPersonal;
	IMAGE chPersonal;
	loadimage(&chPersonal, _T(".\\IMAGES\\chPersonal.png"), 99, 33);
	loadimage(&TEPersonal, _T(".\\IMAGES\\AdTePersonal.png"), 974, 561);
	TPimage.transparentimage5(NULL, 240, 142, &TEPersonal);
	TPimage.transparentimage5(NULL, 15, 113, &chPersonal);
	//�ǳ�
	setcolor(RGB(255, 102, 102));
	settextstyle(35, 0, "SimHei");
	std::string found2 = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_name");
	std::string outputStr =found2;
	outtextxy(980, 30, outputStr.c_str());
	Sleep(50000); // ��ʱ��ѭ�������ԣ�
}

void TeacherMENU::Teachermenu_Grade()
{
	// ����ɼ�����ָ������
	solidrectangle(25, 162, 114, 193);  //left , top , right , bottom ;
	// �����Ϣ����
	setfillcolor(RGB(245, 245, 245));
	solidrectangle(194, 122, 1280, 720);

	Function TPimage;
	IMAGE TEPersonal;
	IMAGE chGrade;
	loadimage(&chGrade, _T(".\\IMAGES\\chGrade.png"), 99, 33);
	loadimage(&TEPersonal, _T(".\\IMAGES\\AdTePersonal.png"), 974, 561);
	TPimage.transparentimage5(NULL, 240, 142, &TEPersonal);
	TPimage.transparentimage5(NULL, 15, 162, &chGrade);
	Sleep(50000); // ��ʱ��ѭ�������ԣ�
}

void TeacherMENU::Teachermenu_Print()
{
	// �����ӡ�ɼ�ָ������
	solidrectangle(25, 210, 114, 241);  //left , top , right , bottom ;
	// �����Ϣ����
	setfillcolor(RGB(245, 245, 245));
	solidrectangle(194, 122, 1280, 720);

	Function TPimage;
	IMAGE TEPersonal;
	IMAGE chPrint;
	loadimage(&chPrint, _T(".\\IMAGES\\chPrint.png"), 99, 33);
	loadimage(&TEPersonal, _T(".\\IMAGES\\AdTePersonal.png"), 974, 561);
	TPimage.transparentimage5(NULL, 240, 142, &TEPersonal);
	TPimage.transparentimage5(NULL, 15, 210, &chPrint);
	Sleep(50000); // ��ʱ��ѭ�������ԣ�
}
