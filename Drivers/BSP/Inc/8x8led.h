#ifndef __8X8LED_H
#define __8X8LED_H


#ifdef __cplusplus
extern "C"
{
#endif


#include <stdint.h>
#include "main.h"


void GC7219_Write_byte(uint8_t data); //���ֽ�д��
void GC7219_Write_Command(uint8_t addr,uint8_t data); //д����߰�λ��ַ���Ͱ�λ����
void GC7219_INIT(void); //��ʼ��
void GC7219_Write_Command_Dual(uint8_t addr1, uint8_t data1, uint8_t addr2, uint8_t data2);

#ifdef __cplusplus
}
#endif

  
#endif