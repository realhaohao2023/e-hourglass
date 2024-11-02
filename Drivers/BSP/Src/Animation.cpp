#include "Animation.hpp"
using namespace std;
#include <vector>

// #include <iostream>

using namespace std;

// ���캯������ʼ�� rows ����
LEDMatrix::LEDMatrix()
{
    clear();
}

// ������� LED
void LEDMatrix::clear()
{
    for (int i = 0; i < 8; i++)
    {
        rows1[i] = 0;
        rows2[i] = 0;
    }
}

// �����ض��� LED����Ӱ��ͬһ�е����� LED��
void LEDMatrix::setLED(int row0, int col)
{
    int row = 7 - row0; // ����������
    if (row >= 0 && row < 8 && col >= 0 && col < 16) // ȷ���з�Χ����������ʾ��
    {
        if (col < 8)
        {
            rows1[row] |= (1 << (7 - col)); // ���Ƶ�һ����ʾ���ϵ� LED
        }
        else
        {
            rows2[row] |= (1 << (15 - col)); // ���Ƶڶ�����ʾ���ϵ� LED����������
        }
    }
}

// �ر��ض��� LED����Ӱ��ͬһ�е����� LED��
void LEDMatrix::clearLED(int row0, int col)
{
    int row = 7 - row0; // ����������
    if (row >= 0 && row < 8 && col >= 0 && col < 16) // ȷ���з�Χ����������ʾ��
    {
        if (col < 8)
        {
            rows1[row] &= ~(1 << (7 - col)); // ���Ƶ�һ����ʾ���ϵ� LED
        }
        else
        {
            rows2[row] &= ~(1 << (15 - col)); // ���Ƶڶ�����ʾ���ϵ� LED����������
        }
    }
}

// ����ˢ����ʾ
void LEDMatrix::refresh()
{
    for (int i = 0; i < 8; i++)
    {
        GC7219_Write_Command_Dual(i + 1, rows1[i], i + 1, rows2[i]);
    }
}

bool LEDMatrix::isLEDOn(int row0, int col)
{
    int row = 7 - row0; // ����������
    if (row >= 0 && row < 8 && col >= 0 && col < 16) // ���������ʾ�����з�Χ
    {
        if (col < 8)
        {
            return rows1[row] & (1 << (7 - col)); // ����һ����ʾ��
        }
        else
        {
            return rows2[row] & (1 << (15 - col)); // ���ڶ�����ʾ��
        }
    }
    return false;
}
