#pragma once
//���ļ��洢�����Ժ���
#include"Struct.h"
#include<easyx.h>
#include<conio.h>
class Function
{
public:
	//�����_��¼���棨�������ݣ��������ƣ���������λ�ã����������λ�ã�������ܳ��ȣ�����߶ȣ�Ĭ����ʾ�����ݣ�
	int CR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
	//�����_����ʾ�ַ�_��¼���棨�������ݣ��������ƣ���������λ�ã����������λ�ã�������ܳ��ȣ�����߶ȣ�Ĭ����ʾ�����ݣ�
	int CHR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
};

