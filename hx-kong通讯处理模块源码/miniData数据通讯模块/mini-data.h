/*
  ��ģ�����MCU���ͨѶЭ��

//-----------------------------------------------
����:
//--����ÿ��ָ��������ջ��泤��
//ͨѶ��У��
//��̽ṹΪ4���ֽ�
//uchar head;  ��0xAF��ͷ
//ushort parameter_len; ���Ȳ�����65545���ֽ�
//uchar* parameter; ʵ�ʴ�������
//uchar end;   ��0xFA��β
  
uchar g_cache[255]={0};
unsigned short g_len=0;
TzhMiniData g_ocCmd;
uchar g_isGetCmdOk; 

//���ݽ���
#pragma vector=UART1_R_RXNE_vector
__interrupt void UART1_RX_RXNE(void)
{
    //�ȴ��ն�����
    //while(!UART1_SR_RXNE); 
    	
	if(g_len+1>254){ g_len=0; }
    g_cache[g_len]=UART1_DR;
    g_len++;
    
    if(0xFA==UART1_DR)
    {
        int tmp;
 //_nnc:
         //��ȡָ��
         tmp=miniDataGet(g_cache,g_len,&g_ocCmd,&g_isGetCmdOk);
         //����ָ��
         if(g_isGetCmdOk)
         {
            func(g_ocCmd.parameter_len,g_ocCmd.parameter);
         }
         //����������
         if(tmp>0)
         {
           int n;
           g_len-=tmp;
           for(n=0;n<g_len;n++)
           { g_cache[n]=g_cache[tmp+n]; }
//         goto _nnc;
         }
    }
}

*/

#ifndef _HXMCU_MINI_DATA_PROTOCOL_H__

#ifdef __cplusplus
extern "C"{
#endif
 
#define uchar   unsigned char
#define ushort   unsigned short

#ifndef NULL
#define NULL    0
#endif


//-------------------------------------------------

typedef struct _TzhMiniData
{
  uchar head;  //0xAF��ͷ
  ushort parameter_len;
  uchar* parameter;
  uchar end;   //0xFA��β
}TzhMiniData;
 
/*
 ����:����ָ��  
    ����ָ��ĳ���
*/
int miniDataCreate(ushort parm_len,
                  const uchar* parm,
                  uchar* dst_buf);

/*
����:��ȡhx-kong��Э��
   �ӻ�������ȡָ��,�����һ���ֽڲ���OCЭ���ͷ��ʶ,���ȡʧ��
   ���ؽ�ȡ����,���ָ����Ч�Ļ�,���ص����������ݵĳ���
*/
int miniDataGet(uchar* cache,int cache_len,TzhMiniData* pcmd,uchar* is_get_cmd_success);


#ifdef __cplusplus
}
#endif
#define _HXMCU_MINI_DATA_PROTOCOL_H__
#endif
