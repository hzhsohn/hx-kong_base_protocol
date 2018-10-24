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
	char a[]={0x06,0xa6,0x03,0x01,0x1b};
	nGen=hxNetCreateFrame("J2",5,(unsigned char*)a,true,tmpGen);

	//处理缓冲区获取数据帧
	tmp=hxNetGetFrame(tmpGen,nGen,&g_ocCmd,&g_isGetCmdOk);
	//处理指令
	if(g_isGetCmdOk)
	{
		printf("get is ok\n");
	}

	return 0;
}

