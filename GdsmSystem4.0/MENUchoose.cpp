#include"MENUchoose.h"

int MENUchoose::StartMENU_MENUchoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 223 && m.y < 274 && m.x>361 && m.x < 662)//��갴����ʦ��¼����
				return 1;
			if (m.y > 301 && m.y < 352 && m.x>361 && m.x < 662)//��갴��ѧ����¼����
				return 2;
			if (m.y > 378 && m.y < 429 && m.x>361 && m.x < 662)//��갴�ڹ���Ա��¼����
				return 3;
		}
	}
}

int MENUchoose::StartMENU_Login_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 223 && m.y < 274 && m.x>361 && m.x < 662)//��갴�������˺�����
				return 1;
			if (m.y > 301 && m.y < 352 && m.x>361 && m.x < 662)//��갴��������������
				return 2;
			if (m.y > 378 && m.y < 429 && m.x>361 && m.x < 662)//��갴�ڵ�¼����
				return 3;
			if (m.y > 452 && m.y < 468 && m.x>495 && m.x < 528)//��갴��ȡ������
				return 4;
		}
	}
}


