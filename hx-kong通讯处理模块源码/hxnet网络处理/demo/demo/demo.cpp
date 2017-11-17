// demo.cpp : 定义控制台应用程序的入口点。
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

	//处理缓冲区获取数据帧
	tmp=hxNetGetFrame(tmpGen,nGen,&g_ocCmd,&g_isGetCmdOk);
	//处理指令
	if(g_isGetCmdOk)
	{
	}

	return 0;
}

