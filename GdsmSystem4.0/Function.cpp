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

void Function::transparentimage1(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();

	// 使用 Windows GDI 函数实现透明位图
	TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentcolor);
}

void Function::transparentimage2(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor)
{
	// 变量初始化
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 修正透明色，显示缓冲区中的数据结构为 0xaarrggbb
	transparentcolor = 0xff000000 | BGR(transparentcolor);

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			if (src[ix] != transparentcolor)
				dst[ix] = src[ix];
		}
		dst += dst_width;
		src += src_width;
	}
}

void Function::transparentimage3(int x, int y, IMAGE* srcimg, IMAGE* maskimg)
{
	putimage(x, y, maskimg, SRCAND);
	putimage(x, y, srcimg, SRCPAINT);
}

void Function::transparentimage4(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();

	// 结构体的第三个成员表示额外的透明度，0 表示全透明，255 表示不透明。
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	// 使用 Windows GDI 函数实现半透明位图
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}

void Function::transparentimage5(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	// 变量初始化
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// 源值已经乘过了透明系数
			int sg = ((src[ix] & 0xff00) >> 8);		// 源值已经乘过了透明系数
			int sb = src[ix] & 0xff;				// 源值已经乘过了透明系数
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}

