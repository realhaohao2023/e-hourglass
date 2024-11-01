#include "Animation.hpp"
using namespace std;
#include <vector>

// #include <iostream>

using namespace std;

// 构造函数，初始化 rows 数组
LEDMatrix::LEDMatrix()
{
    clear();
}

// 清空所有 LED
void LEDMatrix::clear()
{
    for (int i = 0; i < 8; i++)
    {
        rows1[i] = 0;
        rows2[i] = 0;
    }
}

// 点亮特定的 LED（不影响同一行的其他 LED）
void LEDMatrix::setLED(int row0, int col)
{
    int row = 7 - row0; // 行索引调整
    if (row >= 0 && row < 8 && col >= 0 && col < 16) // 确保列范围覆盖两个显示屏
    {
        if (col < 8)
        {
            rows1[row] |= (1 << (7 - col)); // 控制第一个显示屏上的 LED
        }
        else
        {
            rows2[row] |= (1 << (15 - col)); // 控制第二个显示屏上的 LED，索引调整
        }
    }
}

// 关闭特定的 LED（不影响同一行的其他 LED）
void LEDMatrix::clearLED(int row0, int col)
{
    int row = 7 - row0; // 行索引调整
    if (row >= 0 && row < 8 && col >= 0 && col < 16) // 确保列范围覆盖两个显示屏
    {
        if (col < 8)
        {
            rows1[row] &= ~(1 << (7 - col)); // 控制第一个显示屏上的 LED
        }
        else
        {
            rows2[row] &= ~(1 << (15 - col)); // 控制第二个显示屏上的 LED，索引调整
        }
    }
}

// 逐行刷新显示
void LEDMatrix::refresh()
{
    for (int i = 0; i < 8; i++)
    {
        GC7219_Write_Command_Dual(i + 1, rows1[i], i + 1, rows2[i]);
    }
}

bool LEDMatrix::isLEDOn(int row0, int col)
{
    int row = 7 - row0; // 行索引调整
    if (row >= 0 && row < 8 && col >= 0 && col < 16) // 检查两个显示屏的列范围
    {
        if (col < 8)
        {
            return rows1[row] & (1 << (7 - col)); // 检查第一个显示屏
        }
        else
        {
            return rows2[row] & (1 << (15 - col)); // 检查第二个显示屏
        }
    }
    return false;
}
