/*
该例程展示如何直接往LCD上写数据
硬件连接方式:
PIN_SCE         显示屏片选引脚
PIN_RESET     复位引脚
PIN_DC          数据和命令选择引脚
PIN_SDIN       数据引脚
PIN_SCLK       时钟引脚
*/

#include <Nokia5110.h>

Nokia5110 lcd(D3, D4, D5, D6, D7);

void setup(void)
{
	lcd.init(); // 初始化
}

void loop(void)
{
	lcd.clear(); // 清屏
	// 在0,2,4行显示
	for (int row = 0; row < 6; row++)
	{
		lcd.gotoXY(0, row);
		for (int index = 0; index < 84; index++)
		{
			if (row % 2 == 0)
			{
				lcd.write(LCD_DATA, 0xFF); //填充
			}
			else
			{
				lcd.write(LCD_DATA, 0x00); // 留下空格
			}
		}
	}
	delay(1000);

	lcd.clear();
	// 在1,3,5行显示
	for (int row = 0; row < 6; row++)
	{
		lcd.gotoXY(0, row);
		for (int index = 0; index < 84; index++)
		{
			if (row % 2 == 0)
			{
				lcd.write(LCD_DATA, 0x00);
			}
			else
			{
				lcd.write(LCD_DATA, 0xFF);
			}
		}
	}
	delay(1000);
}
