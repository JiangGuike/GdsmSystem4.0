#pragma once
//本文件存储功能性函数
#include"Struct.h"
#include<easyx.h>
#include<conio.h>
#include"DBConnection.h"
#pragma comment( lib, "MSIMG32.LIB")
class Function
{
public:
	//输入框_登录界面（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
	int CR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
	//输入框_不显示字符_登录界面（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
	int CHR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
	// 透明贴图函数
    // 参数：
	//		dstimg: 目标 IMAGE 对象指针。NULL 表示默认窗体
	//		x, y:	目标贴图位置
	//		srcimg: 源 IMAGE 对象指针。NULL 表示默认窗体
	//		transparentcolor: 透明色。srcimg 的该颜色并不会复制到 dstimg 上，从而实现透明贴图
	void transparentimage1(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor);
	//基于 Windows API 函数 TransparentBlt


	void transparentimage2(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor);
	//基于直接操作显示缓冲区，效率更高的指定透明色贴图


	// 参数：
	//		x, y:	目标贴图位置
	//		srcimg: 源 IMAGE 对象指针。NULL 表示默认窗体
	//		maskimg：掩码 IMAGE
	void transparentimage3(int x, int y, IMAGE* srcimg, IMAGE* maskimg);
	//使用三元光栅操作实现透明贴图,操作对象涉及三个：源图像、目标图像、当前填充颜色（注：透明贴图不使用“当前填充颜色”）


	// 参数：
	//		dstimg: 目标 IMAGE 对象指针。NULL 表示默认窗体
	//		x, y:	目标贴图位置
	//		srcimg: 源 IMAGE 对象指针。NULL 表示默认窗体
	void transparentimage4(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
	//根据 png 的 alpha 信息实现半透明贴图（基于 Windows API 函数 AlphaBlend）


	// 参数：
	//		dstimg：目标 IMAGE（NULL 表示默认窗体）
	//		x, y:	目标贴图位置
	//		srcimg: 源 IMAGE 对象指针
	void transparentimage5(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
	//根据 png 的 alpha 信息实现半透明贴图（基于直接操作显示缓冲区）



	//	方法																			说明																执行 1000 次耗时(秒)
	//	1. 指定透明色贴图（基于 Windows API 函数 TransparentBlt）						可以指定某颜色为透明色。同时支持缩放、选择源区域。					0.01600
	//	2. 指定透明色贴图（基于直接操作显示缓冲区）										可以指定某颜色为透明色。自由度高，可以补充代码实现更多功能。		0.01134
	//	3. 使用三元光栅操作实现透明贴图													可以指定某颜色为透明色。											0.05837
	//	4. 根据 png 的 alpha 信息实现半透明贴图（基于 Windows API 函数 AlphaBlend）		可以实现 256 级透明度，同时支持缩放、选择源区域、透明度加成。		0.04719
	//	5. 根据 png 的 alpha 信息实现半透明贴图（基于直接操作显示缓冲区）				可以实现 256 级透明度，自由度高，可以补充代码实现更多功能。			0.0311

	//具体讲解代码：https://codebus.cn/yangw/transparent-putimage
	std::string Change_password(char* UserNameid, DBConnection& dbConnection,int left, int top, int right, int bottom);
};

