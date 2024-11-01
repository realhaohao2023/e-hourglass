#include "main.h"
#include "8x8led.h"

// ������д��ģ���ڲ���λ�Ĵ���
void GC7219_Write_byte(uint8_t data) // ���ֽ�д��
{
	uint8_t i = 0;
	for (i = 8; i > 0; i--)
	{
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_RESET); // MAX7219_CLK=0;
		if ((data & 0x80) == 0)									   // ��λ����
		{
			HAL_GPIO_WritePin(DIN_GPIO_Port, DIN_Pin, GPIO_PIN_RESET);
		}
		else
		{
			HAL_GPIO_WritePin(DIN_GPIO_Port, DIN_Pin, GPIO_PIN_SET);
		}
		data = data << 1;
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_SET);
	}
}
// ����λ�Ĵ����ڵ�ֵд����ƼĴ���
void GC7219_Write_Command(uint8_t addr, uint8_t data) // д����߰�λ��ַ���Ͱ�λ����
{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
	GC7219_Write_byte(addr); // �Ĵ�����ַ
	GC7219_Write_byte(data); // Ҫд�������
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
}

// ͬʱд������MAX7219оƬ
void GC7219_Write_Command_Dual(uint8_t addr1, uint8_t data1, uint8_t addr2, uint8_t data2)
{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
	GC7219_Write_byte(addr1); // ��һ��MAX7219�ļĴ�����ַ
	GC7219_Write_byte(data1); // ��һ��MAX7219������
	GC7219_Write_byte(addr2); // �ڶ���MAX7219�ļĴ�����ַ
	GC7219_Write_byte(data2); // �ڶ���MAX7219������
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
}

/************�궨�巽���޸ĺ͹۲�*******************/
// ��ַ��Ϣ
#define DECODEMODE 0X09	 // ����ģʽ
#define INTENSITY 0X0A	 // ����
#define SCANLIMT 0x0B	 // ɨ��Ĵ�������
#define SHUTDOWN 0X0C	 // �رռĴ���
#define DISPLAYTEST 0X0F // ��ʾ����
/*************************************************/
void GC7219_INIT(void)
{
	/*����Ĵ�����1ʹ��BCD��   0��ʹ��BCD*/
	GC7219_Write_Command(DECODEMODE, 0X00);
	/*���ȿ��� 0x00~0x0F --> �~����*/
	GC7219_Write_Command(INTENSITY, 0X01);
	/*������������  ����ܵĶ�λ  0ʱ1�У�7��8��*/
	GC7219_Write_Command(SCANLIMT, 0X07);
	/*����ģʽ��0����ģʽ  1����ģʽ*/
	GC7219_Write_Command(SHUTDOWN, 0X01);
	/*��ʾ�Ĵ�����0��ͨģʽ 1����ģʽ*/
	GC7219_Write_Command(DISPLAYTEST, 0X00);
}