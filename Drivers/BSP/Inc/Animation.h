#ifndef __ANIMATION_H
#define __ANIMATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "main.h"
#include "8x8led.h"
#include <stdarg.h>
#include "stdio.h"
//#include <vector>



using namespace std;



void testled();
//声明一个类
class LEDMatrix {
public:
    LEDMatrix();         // 构造函数
    void clear();        // 清空所有 LED
    void setLED(int row, int col);  // 点亮指定的 LED
    void clearLED(int row, int col); // 关闭指定的 LED
    void refresh();      // 刷新显示，将 LED 状态写入硬件
    bool isLEDOn(int row, int col);  // 检查特定 LED 是否点亮

private:
    uint8_t rows[8];  // 存储每一行的 LED 状态
};

// 声明单个沙粒类
class Sand {
public:
    Sand(int startX, int startY, LEDMatrix& matrix);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void moveUpLeft();
    void moveUpRight();
    void moveDownLeft();
    void moveDownRight();
    bool isOn();  // 检查当前位置的亮灭状态
    void updatePosition(); // 更新位置

private:
    int x, y;           // 当前 LED 位置
    LEDMatrix& matrix;  // 引用 LED 矩阵对象，控制显示
    
};


#ifdef __cplusplus
}
#endif

#endif // !__SHALOU_HPP
