// demo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "../../hxnet-protocol.h"

TzhNetFrame_Cmd g_ocCmd;
uchar g_isGetCmdOk;

unsigned char tmpGen[128];
int nGen;
int tmp;

int _tmain(int argc, _TCHAR* argv[])
{
	nGen=hxNetCreateFrame("abc",6,(unsigned char*)"123456",true,tmpGen);

	//����������ȡ����֡
	tmp=hxNetGetFrame(tmpGen,nGen,&g_ocCmd,&g_isGetCmdOk);
	//����ָ��
	if(g_isGetCmdOk)
	{
	}

	return 0;
}

