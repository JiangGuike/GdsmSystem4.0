#include"MENUchoose.h"

int MENUchoose::StartMENU_MENUchoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 223 && m.y < 274 && m.x>361 && m.x < 662)//鼠标按在老师登录区域
				return 1;
			if (m.y > 301 && m.y < 352 && m.x>361 && m.x < 662)//鼠标按在学生登录区域
				return 2;
			if (m.y > 378 && m.y < 429 && m.x>361 && m.x < 662)//鼠标按在管理员登录区域
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
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 223 && m.y < 274 && m.x>361 && m.x < 662)//鼠标按在输入账号区域
				return 1;
			if (m.y > 301 && m.y < 352 && m.x>361 && m.x < 662)//鼠标按在输入密码区域
				return 2;
			if (m.y > 378 && m.y < 429 && m.x>361 && m.x < 662)//鼠标按在登录区域
				return 3;
			if (m.y > 452 && m.y < 468 && m.x>495 && m.x < 528)//鼠标按在取消区域
				return 4;
		}
	}
}




int MENUchoose::Teachermenu_MENUchoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 113 && m.y < 146 && m.x>15 && m.x < 114)//鼠标按在个人信息区域
				return 1;
			if (m.y > 162 && m.y < 193 && m.x>15 && m.x < 114)//鼠标按在成绩管理区域
				return 2;
			if (m.y > 210 && m.y < 241 && m.x>15 && m.x < 114)//鼠标按在打印区域
				return 3;
			if (m.y > 14 && m.y < 87 && m.x>1187 && m.x < 1259)//鼠标按在退出区域
				return 0;
		}
	}
}

int MENUchoose::Teachermenu_Personal_MENUchoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 113 && m.y < 146 && m.x>15 && m.x < 114)//鼠标按在个人信息区域
				return 1;
			if (m.y > 162 && m.y < 193 && m.x>15 && m.x < 114)//鼠标按在成绩管理区域
				return 2;
			if (m.y > 210 && m.y < 241 && m.x>15 && m.x < 114)//鼠标按在打印区域
				return 3;
			if (m.y > 444 && m.y < 455 && m.x>934 && m.x < 960)//鼠标按在修改密码区域
				return 4;
			if (m.y > 14 && m.y < 87 && m.x>1187 && m.x < 1259)//鼠标按在退出区域
				return 0;
		}
	}
}

int MENUchoose::Teachermenu_Grade_MENUchoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 113 && m.y < 146 && m.x>15 && m.x < 114)//鼠标按在个人信息区域
				return 1;
			if (m.y > 162 && m.y < 193 && m.x>15 && m.x < 114)//鼠标按在成绩管理区域
				return 2;
			if (m.y > 210 && m.y < 241 && m.x>15 && m.x < 114)//鼠标按在打印区域
				return 3;
			if (m.y > 14 && m.y < 87 && m.x>1187 && m.x < 1259)//鼠标按在退出区域
				return 0;
		}
	}
}

int MENUchoose::Teachermenu_Print_MENUchoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 113 && m.y < 146 && m.x>15 && m.x < 114)//鼠标按在个人信息区域
				return 1;
			if (m.y > 162 && m.y < 193 && m.x>15 && m.x < 114)//鼠标按在成绩管理区域
				return 2;
			if (m.y > 210 && m.y < 241 && m.x>15 && m.x < 114)//鼠标按在打印区域
				return 3;
			if (m.y > 14 && m.y < 87 && m.x>1187 && m.x < 1259)//鼠标按在退出区域
				return 0;
		}
	}
}


