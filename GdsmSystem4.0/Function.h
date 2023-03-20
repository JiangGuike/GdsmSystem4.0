#pragma once
//���ļ��洢�����Ժ���
#include"Struct.h"
#include<easyx.h>
#include<conio.h>
#include"DBConnection.h"
#pragma comment( lib, "MSIMG32.LIB")
class Function
{
public:
	//�����_��¼���棨�������ݣ��������ƣ���������λ�ã����������λ�ã�������ܳ��ȣ�����߶ȣ�Ĭ����ʾ�����ݣ�
	int CR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
	//�����_����ʾ�ַ�_��¼���棨�������ݣ��������ƣ���������λ�ã����������λ�ã�������ܳ��ȣ�����߶ȣ�Ĭ����ʾ�����ݣ�
	int CHR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
	// ͸����ͼ����
    // ������
	//		dstimg: Ŀ�� IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���
	//		x, y:	Ŀ����ͼλ��
	//		srcimg: Դ IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���
	//		transparentcolor: ͸��ɫ��srcimg �ĸ���ɫ�����Ḵ�Ƶ� dstimg �ϣ��Ӷ�ʵ��͸����ͼ
	void transparentimage1(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor);
	//���� Windows API ���� TransparentBlt


	void transparentimage2(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor);
	//����ֱ�Ӳ�����ʾ��������Ч�ʸ��ߵ�ָ��͸��ɫ��ͼ


	// ������
	//		x, y:	Ŀ����ͼλ��
	//		srcimg: Դ IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���
	//		maskimg������ IMAGE
	void transparentimage3(int x, int y, IMAGE* srcimg, IMAGE* maskimg);
	//ʹ����Ԫ��դ����ʵ��͸����ͼ,���������漰������Դͼ��Ŀ��ͼ�񡢵�ǰ�����ɫ��ע��͸����ͼ��ʹ�á���ǰ�����ɫ����


	// ������
	//		dstimg: Ŀ�� IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���
	//		x, y:	Ŀ����ͼλ��
	//		srcimg: Դ IMAGE ����ָ�롣NULL ��ʾĬ�ϴ���
	void transparentimage4(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
	//���� png �� alpha ��Ϣʵ�ְ�͸����ͼ������ Windows API ���� AlphaBlend��


	// ������
	//		dstimg��Ŀ�� IMAGE��NULL ��ʾĬ�ϴ��壩
	//		x, y:	Ŀ����ͼλ��
	//		srcimg: Դ IMAGE ����ָ��
	void transparentimage5(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
	//���� png �� alpha ��Ϣʵ�ְ�͸����ͼ������ֱ�Ӳ�����ʾ��������



	//	����																			˵��																ִ�� 1000 �κ�ʱ(��)
	//	1. ָ��͸��ɫ��ͼ������ Windows API ���� TransparentBlt��						����ָ��ĳ��ɫΪ͸��ɫ��ͬʱ֧�����š�ѡ��Դ����					0.01600
	//	2. ָ��͸��ɫ��ͼ������ֱ�Ӳ�����ʾ��������										����ָ��ĳ��ɫΪ͸��ɫ�����ɶȸߣ����Բ������ʵ�ָ��๦�ܡ�		0.01134
	//	3. ʹ����Ԫ��դ����ʵ��͸����ͼ													����ָ��ĳ��ɫΪ͸��ɫ��											0.05837
	//	4. ���� png �� alpha ��Ϣʵ�ְ�͸����ͼ������ Windows API ���� AlphaBlend��		����ʵ�� 256 ��͸���ȣ�ͬʱ֧�����š�ѡ��Դ����͸���ȼӳɡ�		0.04719
	//	5. ���� png �� alpha ��Ϣʵ�ְ�͸����ͼ������ֱ�Ӳ�����ʾ��������				����ʵ�� 256 ��͸���ȣ����ɶȸߣ����Բ������ʵ�ָ��๦�ܡ�			0.0311

	//���彲����룺https://codebus.cn/yangw/transparent-putimage
	std::string Change_password(char* UserNameid, DBConnection& dbConnection,int left, int top, int right, int bottom);
};

