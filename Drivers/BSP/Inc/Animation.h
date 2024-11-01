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
//����һ����
class LEDMatrix {
public:
    LEDMatrix();         // ���캯��
    void clear();        // ������� LED
    void setLED(int row, int col);  // ����ָ���� LED
    void clearLED(int row, int col); // �ر�ָ���� LED
    void refresh();      // ˢ����ʾ���� LED ״̬д��Ӳ��
    bool isLEDOn(int row, int col);  // ����ض� LED �Ƿ����

private:
    uint8_t rows[8];  // �洢ÿһ�е� LED ״̬
};

// ��������ɳ����
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
    bool isOn();  // ��鵱ǰλ�õ�����״̬
    void updatePosition(); // ����λ��

private:
    int x, y;           // ��ǰ LED λ��
    LEDMatrix& matrix;  // ���� LED ������󣬿�����ʾ
    
};


#ifdef __cplusplus
}
#endif

#endif // !__SHALOU_HPP
