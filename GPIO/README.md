# GPIO LCD
## register map
![alt register map](https://github.com/chiweichiu/MCU/blob/main/GPIO/utils/register_map.JPG)
- 可以看到base address為0x4000_4000，其餘按照offset往下加即可
## gpio mode
![alt gpio_mode](https://github.com/chiweichiu/MCU/blob/main/GPIO/utils/gpio_mode.JPG)
- 可以設定input out 
## gpio dataout 
![alt gpio_dout](https://github.com/chiweichiu/MCU/blob/main/GPIO/utils/gpio_dout.JPG)
- 可以設定high low
## lcd線路圖
![alt LCD_sch](https://github.com/chiweichiu/MCU/blob/main/GPIO/utils/LCD_sch.JPG)
- 可以看到PC14接到RSC，PB14接到RWC，PB15接到Enable
## LCD pin function
![alt lcd_pin_func](https://github.com/chiweichiu/MCU/blob/main/GPIO/utils/lcd_pin_func.JPG)

## 8 bit 2-Line 範例
![alt LCD_control](https://github.com/chiweichiu/MCU/blob/main/GPIO/utils/LCD_control.JPG)
- 先將PC14 PB14 PB15 PA0-7 設定為output
- 再按照上圖流程設定PC14 PB14 PA0-7設定對應的data out
- PA7-0=0x48對應ascii code為'H' 
- 每設定完一個operation後透過Eneable pin(PB15 dout)拉High再拉low
  即可完成對LCD的顯示

## 轉換為C語言
## Reference
- en-us--TRM_M480_Series_EN_Rev3.05.pdf
- hd44780u.pdf
- M482_V2_SCH.pdf
