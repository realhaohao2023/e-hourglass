#include "Animation.h"
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
        rows[i] = 0;
    }
}

// �����ض��� LED����Ӱ��ͬһ�е����� LED��
void LEDMatrix::setLED(int row, int col)
{
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
        return;              // �߽���
    rows[row] |= (1 << col); // ��λ��������� LED
}

// �ر��ض��� LED����Ӱ��ͬһ�е����� LED��
void LEDMatrix::clearLED(int row, int col)
{
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
        return;               // �߽���
    rows[row] &= ~(1 << col); // ��λ�������� LED
}

// ����ˢ����ʾ
void LEDMatrix::refresh()
{
    for (int row = 0; row < 8; row++)
    {
        GC7219_Write_Command(row + 1, rows[row]); // �������е�������������д��
    }
}

bool LEDMatrix::isLEDOn(int row, int col)
{
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
        return false;
    return rows[row] & (1 << col); // ����λ���Ƿ�Ϊ��
}

