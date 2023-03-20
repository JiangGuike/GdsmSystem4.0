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
	//Loading.TE_PrintLoading();//������ҳ�棩
	IMAGE BG;
	IMAGE port;
	loadimage(&port, _T(".\\IMAGES\\TEport.png"), 266, 125);
	loadimage(&BG, _T(".\\IMAGES\\MainMenu.png"), 1280, 720);
	putimage(0, 0, &BG);	// ��ʾ����
	setcolor(RGB(255, 102, 102));
	settextstyle(35, 0, "SimHei");
	std::string found1 = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_name");
	std::string outputStr = "���" + found1 + "��";
	outtextxy(980, 30, outputStr.c_str());
	TPimage.transparentimage5(NULL, 507, -11, &port);
	Teachermenu_Mainmenu(UserNameid, dbConnection);
	return 0;
}

int TeacherMENU::Teachermenu_Mainmenu(char* UserNameid, DBConnection& dbConnection)
{
	// ���������Ϣָ������
	setfillcolor(WHITE);
	solidrectangle(25, 113, 114, 146); //left , top , right , bottom ;
	// ����ɼ�����ָ������
	solidrectangle(25, 162, 114, 193);  //left , top , right , bottom ;
	// �����ӡ�ɼ�ָ������
	solidrectangle(25, 210, 114, 241);  //left , top , right , bottom ;
	// ��������ָ������
	solidrectangle(15, 117, 18, 680);  //left , top , right , bottom ;
	// �����Ϣ����
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
	// ���������Ϣָ������
	setfillcolor(WHITE);
	solidrectangle(25, 113, 114, 146); //left , top , right , bottom ;
	// ����ɼ�����ָ������
	solidrectangle(25, 162, 114, 193);  //left , top , right , bottom ;
	// �����ӡ�ɼ�ָ������
	solidrectangle(25, 210, 114, 241);  //left , top , right , bottom ;
	// ��������ָ������
	solidrectangle(15, 117, 18, 680);  //left , top , right , bottom ;
	// �����Ϣ����
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
	loadimage(&revise, _T(".\\IMAGES\\�༭ɫ��.png"), 15, 15);
	loadimage(&CHrevise, _T(".\\IMAGES\\ѡ�б༭ɫ��.png"), 15, 15);
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

	//�ǳ�
	setcolor(RGB(0, 0, 0));
	settextstyle(43, 0, "SimHei");
	std::string name = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_name");
	setfillcolor(WHITE);
	solidrectangle(610, 210, 910, 270);  // ����ɫ����
	setbkmode(TRANSPARENT);  // �����ı�����Ϊ͸��
	outtextxy(630, 223, name.c_str());
	//id
	setcolor(RGB(0, 0, 0));
	settextstyle(27, 0, "SimHei");
	std::string id = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_id");
	setbkmode(TRANSPARENT);  // �����ı�����Ϊ͸��
	outtextxy(725, 281, id.c_str());
	//role
	setcolor(RGB(0, 0, 0));
	settextstyle(27, 0, "SimHei");
	std::string role = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_role");
	setbkmode(TRANSPARENT);  // �����ı�����Ϊ͸��
	outtextxy(985, 281, role.c_str());
	//unit
	setcolor(RGB(0, 0, 0));
	settextstyle(27, 0, "SimHei");
	std::string unit = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_unit");
	setbkmode(TRANSPARENT);  // �����ı�����Ϊ͸��
	outtextxy(715, 376, unit.c_str());
	//pwd
	setcolor(RGB(0, 0, 0));
	settextstyle(27, 0, "SimHei");
	std::string pwd = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_pwd");
	setbkmode(TRANSPARENT);  // �����ı�����Ϊ͸��
	outtextxy(715, 441, pwd.c_str());//���65

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
			Sleep(50); // ��ʱ0.05��
			std::string newpassword = Change.Change_password(UserNameid, dbConnection, 715, 441, 915, 475);
			if (dbConnection.updateData(UserNameid, "teacher_table", "tea_id", "tea_pwd", newpassword.c_str()))
			{
				HWND wnd = GetHWnd();
				MessageBox(wnd, "�����޸ĳɹ���", "��ʾ", MB_OK | MB_ICONINFORMATION);
			}
			else
			{
				HWND wnd = GetHWnd();
				MessageBox(wnd, "�����޸�ʧ�ܣ�", "����", MB_OK | MB_ICONWARNING);
			}
			// ����޸�ָ������
			setfillcolor(WHITE);
			solidrectangle(934, 444, 949, 459); //left , top , right , bottom ;
			solidrectangle(565, 500, 1000, 600); //left , top , right , bottom ;
			solidrectangle(715, 441, 930, 460); //left , top , right , bottom ;

			//newpwd
			setcolor(RGB(0, 0, 0));
			settextstyle(27, 0, "SimHei");
			std::string newpwd = dbConnection.findData(UserNameid, "teacher_table", "tea_id", "tea_pwd");
			setbkmode(TRANSPARENT);  // �����ı�����Ϊ͸��
			outtextxy(715, 441, newpwd.c_str());//���65
			TPimage.transparentimage5(NULL, 934, 444, &revise);
			MENUchoice_Personal = choose.Teachermenu_Personal_MENUchoose();
			break;
		}
	}
}

void TeacherMENU::Teachermenu_Grade(char* UserNameid, DBConnection& dbConnection)
{
	// ���������Ϣָ������
	setfillcolor(WHITE);
	solidrectangle(25, 113, 114, 146); //left , top , right , bottom ;
	// ����ɼ�����ָ������
	solidrectangle(25, 162, 114, 193);  //left , top , right , bottom ;
	// �����ӡ�ɼ�ָ������
	solidrectangle(25, 210, 114, 241);  //left , top , right , bottom ;
	// ��������ָ������
	solidrectangle(15, 117, 18, 680);  //left , top , right , bottom ;
	// �����Ϣ����
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
	// ���������Ϣָ������
	setfillcolor(WHITE);
	solidrectangle(25, 113, 114, 146); //left , top , right , bottom ;
	// ����ɼ�����ָ������
	solidrectangle(25, 162, 114, 193);  //left , top , right , bottom ;
	// �����ӡ�ɼ�ָ������
	solidrectangle(25, 210, 114, 241);  //left , top , right , bottom ;
	// ��������ָ������
	solidrectangle(15, 117, 18, 680);  //left , top , right , bottom ;
	// �����Ϣ����
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
