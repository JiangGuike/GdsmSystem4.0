#pragma once
#include"StartMENU.h"


int StartMENU::start()
{
	initgraph(1024, 576);    // ������ͼ���ڣ���СΪ 1280x720 ����
	cleardevice();
	setbkcolor(RGB(244, 244, 244));
	// ���ñ���ɫΪ����ɫ
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 30;						// ��������߶�Ϊ30
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT2_EN));	// ��������ΪFONT2_EN
	settextstyle(&format);
	IMAGE BG;
	IMAGE TeacherBox;
	IMAGE StudentBox;
	IMAGE AdministratorBox;
	loadimage(&BG, _T(".\\IMAGES\\StartMenu.png"), 1024, 576);
	loadimage(&TeacherBox, _T(".\\IMAGES\\TeacherBox.png"), 301, 51);
	loadimage(&StudentBox, _T(".\\IMAGES\\StudentBox.png"), 301, 51);
	loadimage(&AdministratorBox, _T(".\\IMAGES\\AdministratorBox.png"), 301, 51);
	putimage(0, 0, &BG);
	//���϶��ǳ������
	int temp;
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
			Sleep(50); // ��ʱ0.05��
			temp = teacher_start();
			return temp;
			}
		case 2:
			{
			putimage(361, 301, &StudentBox);
			Sleep(50); // ��ʱ0.05��
			temp = student_start();
			return temp;
			}
		case 3:
			{
			putimage(361, 378, &AdministratorBox);
			Sleep(50); // ��ʱ0.05��
			temp = administrator_start();
			return temp;
			}	
		}
	}
	return 1;

 }

int StartMENU::teacher_start()
{
	cleardevice();
	IMAGE TeacherMENU;
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
	loadimage(&TeacherMENU, _T(".\\IMAGES\\Teacher_login.png"), 1024, 576);
	putimage(0, 0, &TeacherMENU);
	char UserName[50] = "\0";
	char PassWord[50] = "\0";
	Function input;
	MENUchoose choose;
	int MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
	while (true)
	{
		switch (MENUchoice_Login)
		{
		case 1:
			{
			putimage(361, 223, &UserNameBox);
			input.CR_InputBox(UserName, 11, 405, 229, 252, 40, "");
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
			int temp;
			temp = 1;
			return temp;
			//��¼��֤ģ��
			char text[] = "	���Ե�¼��ť�ɹ���3���ɹرգ�";
			outtextxy(100, 100, text);
			Sleep(3000); // ��ʱ3��
			//MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
			}
		case 4:
			{
			putimage(495, 452, &CancelBox);
			Sleep(50); // ��ʱ0.05��
			start();
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
			break;
			}
		}
	}
}

int StartMENU::student_start()
{
	cleardevice();
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
	char UserName[50] = "\0";
	char PassWord[50] = "\0";
	Function input;
	MENUchoose choose;
	int MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
	while (true)
	{
		switch (MENUchoice_Login)
		{
		case 1:
		{
			putimage(361, 223, &UserNameBox);
			input.CR_InputBox(UserName, 11, 405, 229, 252, 40, "");
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
			int temp;
			temp = 2;
			return temp;
			//��¼��֤ģ��
			char text[] = "	���Ե�¼��ť�ɹ���3���ɹرգ�";
			outtextxy(100, 100, text);
			Sleep(3000); // ��ʱ3��
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
		}
		case 4:
		{
			putimage(495, 452, &CancelBox);
			Sleep(50); // ��ʱ0.05��
			start();
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
			break;
		}
		}
	}
}

int StartMENU::administrator_start()
{
	cleardevice();
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
	char UserName[50] = "\0";
	char PassWord[50] = "\0";
	Function input;
	MENUchoose choose;
	int MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
	while (true)
	{
		switch (MENUchoice_Login)
		{
		case 1:
		{
			putimage(361, 223, &UserNameBox);
			input.CR_InputBox(UserName, 11, 405, 229, 252, 40, "");
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
			int temp;
			temp = 3;
			return temp;
			//��¼��֤ģ��
			char text[] = "	���Ե�¼��ť�ɹ���3���ɹرգ�";
			outtextxy(100, 100, text);
			Sleep(3000); // ��ʱ3��
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
		}
		case 4:
		{
			putimage(495, 452, &CancelBox);
			Sleep(50); // ��ʱ0.05��
			start();
			MENUchoice_Login = choose.StartMENU_Login_MENUChoose();
			break;
		}
		}
	}
}



