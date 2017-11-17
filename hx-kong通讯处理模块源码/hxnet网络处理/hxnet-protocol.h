/*
  ��ģ�����hxnetЭ��

/////////////////////////////////////////////////////////////////////////
ʹ������
  ���g_ocCmd->endΪ0xBA ����ʹ��CRC16У��,���Ϊ0xBB��ʹ��У��

  uchar g_cache[256];
  int g_len=0;
  TzhNetFrame_Cmd g_ocCmd;
  uchar g_isGetCmdOk;

  int tmp;
  int n;
  
  //�����յ������ݷŵ�������
  g_cache[g_len]=UART1_DR;
  g_len++;
  
  //����������ȡ����֡
  tmp=hxNetGetFrame(g_cache,g_len,&g_ocCmd,&g_isGetCmdOk);
  //����ָ��
  if(g_isGetCmdOk)
  {
    ����
    //func(g_ocCmd.flag,g_ocCmd.parameter,g_ocCmd.parameter_len);
  }
  //����������
  if(tmp>0)
  {
   g_len-=tmp;
   for(n=0;n<g_len;n++)
   {
      g_cache[n]=g_cache[tmp+n];
   }
  }
/////////////////////////////////////////////////////////////////////////
*/

#ifndef _HX_NET__PROTOCOL_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C"{
#endif
  
#define U8      unsigned char
#define U16     unsigned short
#define I32     int
#define uchar   unsigned char
#define uint   unsigned int

#ifndef NULL
#define NULL    0
#endif

//�Ƿ�ʹ�ø�������
#define _IS_MCU_        0
#if _IS_MCU_
 int memcmp(char* src,char* dst,int len);
 void memcpy(void* dest, void* src, int count);
 int strlen(const char *str);
 char *strcat(char *str1, char *str2);
 char* strcpy(char* dest, const char* src);
 int strcmp(const char *str1,const char *str2);
 char *itoa(int num, char *str, int radix);//radix�Ƕ��ٽ���һ��Ϊ10
#endif

//-------------------------------------------------
typedef struct _TzhNetFrame_Cmd
{
  uchar head;
  char*flag;
  uint parameter_len;
  uchar* parameter;
  uchar end;
  U16 checksum;
  //
  uchar*frame_head;
  uint frame_len;
}TzhNetFrame_Cmd;
 
/*
 ����:����ָ��  
    ����ָ��ĳ���
*/
int hxNetCreateFrame(const char* flag,
                  uint parm_len,
                  const uchar* parm,
				  uchar is_need_crc16,
                  uchar* dst_buf);

/*
����:��ȡhx-kong��Э��
   �ӻ�������ȡָ��,�����һ���ֽڲ���OCЭ���ͷ��ʶ,���ȡʧ��
   ���ؽ�ȡ����,���ָ����Ч�Ļ�,���ص����������ݵĳ���
*/
int hxNetGetFrame(uchar* cache,int cache_len,TzhNetFrame_Cmd* pcmd,uchar* is_get_cmd_success);

#ifdef __cplusplus
}
#endif
#define _HX_NET__PROTOCOL_H__
#endif
