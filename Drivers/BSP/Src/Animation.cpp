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

// ���캯��
Sand::Sand(int startX, int startY, LEDMatrix* ledMatrix) : x(startX), y(startY), matrix(ledMatrix) {
    matrix->setLED(startX, startY);
}

// �����ƶ�������ʵ��
void Sand::moveUp() {
    if (x > 0) {
        matrix->clearLED(x, y);
        x--;
        matrix->setLED(x, y);
    }
}

void Sand::moveDown() {
    if (x < 15) {
        matrix->clearLED(x, y);
        x++;
        matrix->setLED(x, y);
    }
}

void Sand::moveLeft() {
    if (y > 0) {
        matrix->clearLED(x, y);
        y--;
        matrix->setLED(x, y);
    }
}

void Sand::moveRight() {
    if (y < 15) {
        matrix->clearLED(x, y);
        y++;
        matrix->setLED(x, y);
    }
}

void Sand::moveUpLeft() {
    if (x > 0 && y > 0) {
        matrix->clearLED(x, y);
        x--;
        y--;
        matrix->setLED(x, y);
    }
}

void Sand::moveUpRight() {
    if (x > 0 && y < 15) {
        matrix->clearLED(x, y);
        x--;
        y++;
        matrix->setLED(x, y);
    }
}

void Sand::moveDownLeft() {
    if (x < 15 && y > 0) {
        matrix->clearLED(x, y);
        x++;
        y--;
        matrix->setLED(x, y);
    }
}

void Sand::moveDownRight() {
    if (x < 15 && y < 15) {
        matrix->clearLED(x, y);
        x++;
        y++;
        matrix->setLED(x, y);
    }
}

void Sand::updatePosition() {
    matrix->setLED(x, y);
}

int Sand::getX() const {
    return x;
}

int Sand::getY() const {
    return y;
}