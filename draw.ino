#include "U8glib.h"
#include "math.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
int random_pin=0;
int output[]={1};
int input[]={0};
int i=0;
int blockX[4];
int blockY=0;
int width[4];
int height=5;
int j=0;
void setup()
{
 Serial.begin(9600);
 for(int i=0;i<sizeof(output)/sizeof(output[0]);i++)
     pinMode(output[i],OUTPUT);
 for(int i=0;i<sizeof(input)/sizeof(input[0]);i++)
     pinMode(input[i],INPUT);
 randomSeed(analogRead(0));
}
void loop()
{ 
j=0;i=0;
get_block();
u8g.firstPage();
 do 
  {
    draw();
  } 
  while( u8g.nextPage() );

}
void get_block()
{ 
  blockX[0]=0;
  width[0]=random(10,20);
  for(int w=1;w<5;w++)
  {
    blockX[w]=random(blockX[w-1]+width[w-1],blockX[w-1]+width[w-1]+20);
    width[w]=random(10,20);
  }
}                                                  
void draw()
{
 i++;
 for(int w=0;w<4;w++) 
 {
  u8g.drawBox(blockX[w],blockY,width[w],height);
 }
 delay(100);
}

