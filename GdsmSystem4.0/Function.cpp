#include "Function.h"

int Function::CR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default)
{
	clearrectangle(x, y, x + Lsize, y + Hsize + 2);
	fflush(stdin);//先清空输入缓存
	char c;
	int Length = 0;
	char InputBuf[100] = { '\0' };
	//MOUSEMSG m;
	settextstyle(28, 0, FONT2_EN);
	setlinecolor(BLACK);
	for (int i = x + 5; i < x + 155; i++)
	{
		line(i, y + 42, i + 98, y + 42);
		//Sleep(1);
	}
	settextcolor(RGB(220, 220, 220));
	outtextxy(x + 10, y + 4, Default);
	settextcolor(BLACK);
	FlushMouseMsgBuffer();
	while (true)
	{
		/*
		MOUSEMSG m;
		if (MouseHit())//如果鼠标被按下，则退出输入
		{
			m = GetMouseMsg();
			if (m.mkLButton || m.mkRButton)
			{
				strcpy_s(Input, sizeof(Input), InputBuf);
				//strcpy(Input, InputBuf);
				return Length;
			}
		}
		*/
		c = _getch();
		if (c != 13)//如果输入的不是回车
		{
			if (Length == 0)
			{
				clearrectangle(x, y, x + 160, y + 34);
			}
			if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
			{
				if (Length == Limit - 1)
				{
					;
				}
				else
				{
					InputBuf[Length] = c;
					InputBuf[Length + 1] = '\0';
					outtextxy(x + 10 + 14 * Length, y + 6, c);
					setlinecolor(RGB(0, 191, 255));
					line(x + 8 + Length * 14, y + 42, x + 22 + Length * 14, y + 42);
					Length++;
				}
			}
			if (c == 8)
			{
				if (Length != 0)
				{
					InputBuf[Length] = '\0';
					Length--;
					clearrectangle(x + 10 + 14 * Length, y, x + 24 + 14 * Length, y + 34);
					setlinecolor(BLACK);
					line(x + 8 + Length * 14, y + 42, x + 22 + Length * 14, y + 42);
				}
			}
		}
		else
		{
			strcpy_s(Input, 50, InputBuf);
			return Length; 
		}
	}
}

int Function::CHR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default)
{
	clearrectangle(x, y, x + Lsize, y + Hsize + 2);
	fflush(stdin);//先清空输入缓存
	char c;
	int Length = 0;
	char InputBuf[100] = { '\0' };
	//MOUSEMSG m;
	settextstyle(Hsize, 0, FONT);
	setlinecolor(BLACK);
	/*for (int i = x; i < x + Lsize; i++)
	{
		line(i, y + Hsize, i + 1, y + Hsize);
		//Sleep(1);
	}*/
	for (int i = x + 5; i < x + 155; i++)
	{
		line(i, y + 42, i + 98, y + 42);
		//Sleep(1);
	}
	settextcolor(RGB(220, 220, 220));
	outtextxy(x, y, Default);
	settextcolor(BLACK);
	FlushMouseMsgBuffer();
	while (true)
	{
		//while (MouseHit())//如果鼠标被按下，则退出输入
		//{
		//	m = GetMouseMsg();
		//	if (m.uMsg == WM_LBUTTONDOWN)
		//	{
		//		strcpy(Input, InputBuf);
		//		return Length;
		//	}
		//}
		c = _getch();
		if (c != 13)//如果输入的不是回车
		{
			if (Length == 0)
			{
				clearrectangle(x, y, x + Lsize, y + Hsize);
				settextcolor(RGB(220, 220, 220));
				outtextxy(x, y, Default);
				settextcolor(BLACK);
			}
			if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '.' || c == '\\' || c == '/' || c == '_' || c == ':' || c == '-')
			{
				if (Length == Limit)
				{
					;
				}
				else
				{
					if (Length == 0)//第一个字符
					{
						clearrectangle(x, y, x + Lsize, y + Hsize);
					}
					InputBuf[Length] = c;
					InputBuf[Length + 1] = '\0';
					outtextxy(x + (Hsize / 2) * Length+5, y+10, '*');
					setlinecolor(RGB(0, 191, 255));
					line(x + Length * (Hsize / 2)+7, y + Hsize+12, x + (Length + 1) * (Hsize / 2)+2, y + Hsize+12);
					Length++;
				}
			}
			if (c == 8)
			{
				if (Length != 0)
				{
					InputBuf[Length] = '\0';
					Length--;
					clearrectangle(x + Length * (Hsize / 2)+5, y, x + (Length + 1) * (Hsize / 2)+5, y + Hsize);
					setlinecolor(BLACK);
					line(x + 10 + Length * 14, y + 42, x + 24 + Length * 14, y + 42);
					line(x + Length * (Hsize / 2) + 7, y + Hsize + 12, x + (Length + 1) * (Hsize / 2) + 2, y + Hsize + 12);
				}
			}
		}
		else
		{
			strcpy_s(Input, 50, InputBuf);

			//strcpy(Input, InputBuf);
			return Length;
		}
	}
}
