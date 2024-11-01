#include "Animation.h"
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
        rows[i] = 0;
    }
}

// 点亮特定的 LED（不影响同一行的其他 LED）
void LEDMatrix::setLED(int row, int col)
{
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
        return;              // 边界检查
    rows[row] |= (1 << col); // 按位或操作设置 LED
}

// 关闭特定的 LED（不影响同一行的其他 LED）
void LEDMatrix::clearLED(int row, int col)
{
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
        return;               // 边界检查
    rows[row] &= ~(1 << col); // 按位与操作清除 LED
}

// 逐行刷新显示
void LEDMatrix::refresh()
{
    for (int row = 0; row < 8; row++)
    {
        GC7219_Write_Command(row + 1, rows[row]); // 调用现有的驱动函数逐行写入
    }
}

bool LEDMatrix::isLEDOn(int row, int col)
{
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
        return false;
    return rows[row] & (1 << col); // 检查该位置是否为亮
}

