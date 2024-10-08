#include <POP32.h>

int ag(int channel) //ฟังก์ชั่นเพื่อย่อ analog() ให้เหลือเพียง ag()
{
  return analog(channel);
}

void check()
{
  delay(200);
  oled.text(0,0,"A to get white value"); 
  oled.show();
  waitSW_A(); //รอจนกว่าจะกดปุ่ม A เพื่อรับค่าสีขาวเข้ามา
  int white[8] = {ag(0),ag(1),ag(2),ag(3),ag(4),ag(5),ag(6),ag(7)};
  oled.clear();
  for(int shw = 0; shw < 8; shw++) //แสดงผลค่าที่ได้รับเข้ามาเพื่อตรวจสอบความถูกต้อง
  {
    oled.text(shw,0,"%d",white[shw]);
  }
  oled.show();
  waitSW_B(); //รอให้กด B เพื่อล้าง oled
  oled.clear();

  delay(400);
  oled.text(0,0,"A to get black value");
  oled.show();
  waitSW_A();
  int black[8] = {ag(0),ag(1),ag(2),ag(3),ag(4),ag(5),ag(6),ag(7)};
  oled.clear();
  for(int shb = 0; shb <= 7; shb++) //แสดงผลค่าที่ได้รับเข้ามาเพื่อตรวจสอบความถูกต้อง
  {
    oled.text(shb,0,"%d",black[shb]);
  }
  oled.show();
  waitSW_B(); //รอให้กด B เพื่อล้าง oled
  oled.clear();

  int AVGValue[8]; //กำหนดตัวแปรเพื่อประมวลผลหาค่ากลาง
  for(int i = 0; i <= 7; i++) //คำนวณค่ากลาง
  {
    AVGValue[i] = (white[i] + black[i]) /2;
  }

  for(int ii = 0; ii <= 7; ii++) //แสดงผลค่ากลาง
  {
    oled.text(ii,0,"%d",AVGValue[ii]);
  }
  oled.show();
}

  void setup() 
{
  check();
}

void loop() 
{
  
}
