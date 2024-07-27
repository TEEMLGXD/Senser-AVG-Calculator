#include <POP32.h>

int ag(int channel)
{
  return analog(channel);
}

void check()
{
  delay(200);
  oled.text(0,0,"A to get white value");
  oled.show();
  waitSW_A();
  int white[8] = {ag(0),ag(1),ag(2),ag(3),ag(4),ag(5),ag(6),ag(7)};
  oled.clear();
  
  oled.text(0,0,"A to get black value");
  oled.show();
  int black[8] = {ag(0),ag(1),ag(2),ag(3),ag(4),ag(5),ag(6),ag(7)};
  oled.clear();

  int AVGValue[8];
  for(int i; i <= 7; i++)
  {
    AVGValue[i] = (white[i] + black[i]) /2;
  }
  
  for(int ii; ii <= 7; ii++)
  {
    if(ii <= 4)
    {
      oled.text(ii,0,"%d",AVGValue[ii]);
    }
    if(ii > 4)
    {
      oled.text(ii,7,"%d",AVGValue[ii]);
    }
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
