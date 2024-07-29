void sona()
{
  while(1)
  {
    if (SW_A())
    {
    oled.text(0,1,"%d",analog(6));
    oled.show();
    delay(250);
    oled.clear();
    }
    if (SW_B())
    {
      break;
    }
  }
}