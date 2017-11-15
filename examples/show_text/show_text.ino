/*
该例程展示如何显示字符串
硬件连接方式:
PIN_SCE         显示屏片选引脚
PIN_RESET     复位引脚
PIN_DC          数据和命令选择引脚
PIN_SDIN       数据引脚
PIN_SCLK       时钟引脚
*/

#include <Nokia5110.h>

Nokia5110 lcd(D3, D4, D5, D6, D7);

char* const hello[] = {"This is flash!"};

void setup(void)
{
    lcd.init(); // 初始化
}

void loop(void)
{
    lcd.clear();
    lcd.gotoXY(6, 2);
    lcd.string("Hello World!");
    delay(1000);

    lcd.clear();
    lcd.gotoXY(0, 2);
    lcd.string(hello[0]);
    delay(1000);
}
