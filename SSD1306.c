#include "stm8s.h"

uint8_t lcd_buff[256];

const uint8_t manual[256] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xff, 0xff, 0x0e, 0x1c, 0x38, 0x70, 0xe0, 0xe0, 0x70, 0x38, 0x1c, 0x0e, 0xff, 0xff, 0x00,
  0x00, 0x00, 0x38, 0x1c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x9c, 0xf8, 0xe0, 0x00, 0x00,
  0x00, 0x00, 0xfc, 0xfc, 0x38, 0x1c, 0x0c, 0x0c, 0x0c, 0x0c, 0x1c, 0xf8, 0xf0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x38, 0x1c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x9c, 0xf8, 0xe0, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x00,
  0x00, 0x00, 0x3e, 0x7f, 0x73, 0x61, 0x61, 0x61, 0x61, 0x61, 0x61, 0x73, 0x3f, 0x7f, 0x60, 0x00,
  0x00, 0x00, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0x60, 0x00, 0x00,
  0x00, 0x00, 0x3f, 0x7f, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x3f, 0x7f, 0x60, 0x00, 0x00,
  0x00, 0x00, 0x3e, 0x7f, 0x73, 0x61, 0x61, 0x61, 0x61, 0x61, 0x61, 0x73, 0x3f, 0x7f, 0x60, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x40, 0x7f, 0x7f, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
const uint8_t automatic[256] = {
  
  0xf8, 0xfe, 0x1f, 0x07, 0x03, 0x03, 0x03, 0x03, 0x07, 0x1f, 0xfe, 0xf8, 0x00, 0x00,
  0x00, 0x00, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x30, 0x30, 0x30, 0xff, 0xff, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xf8, 0xfc, 0x1c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x1c, 0xfc, 0xf8, 0x00, 0x00,
  0x00, 0xfc, 0xfc, 0x18, 0x0c, 0x0c, 0x18, 0xf0, 0xf0, 0x18, 0x0c, 0x0c, 0x1c, 0xf8, 0xf0, 0x00,
  0x00, 0x00, 0x38, 0x1c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x9c, 0xf8, 0xe0, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0xff, 0xff, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xfb, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xf8, 0xfc, 0x1c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,

  0x00, 0x00, 0x7f, 0x7f, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x7f, 0x7f, 0x00, 0x00,
  0x00, 0x00, 0x3f, 0x7f, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x3f, 0x7f, 0x60, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0x60, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x3f, 0x7f, 0x70, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x70, 0x7f, 0x3f, 0x00, 0x00,
  0x00, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x00,
  0x00, 0x00, 0x3e, 0x7f, 0x73, 0x61, 0x61, 0x61, 0x61, 0x61, 0x61, 0x73, 0x3f, 0x7f, 0x60, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0x60, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x7f, 0x7f, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x3f, 0x7f, 0x70, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
};
const uint8_t time[256] = {
  0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0xff, 0xff, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xfb, 0xfb, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xfc, 0xfc, 0x18, 0x0c, 0x0c, 0x18, 0xf0, 0xf0, 0x18, 0x0c, 0x0c, 0x1c, 0xf8, 0xf0, 0x00,
  0x00, 0x00, 0xf8, 0xfc, 0x9c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x9c, 0xf8, 0xf0, 0x00, 0x00,
  0x00, 0x00, 0x70, 0x70, 0x70,

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0x60, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00,
  0x7f, 0x7f, 0x60, 0x00, 0x00, 0x00,
  0x00, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x00,
  0x00, 0x00, 0x3f, 0x7f, 0x73, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x71, 0x30, 0x00, 0x00,
  0x00, 0x00, 0x38, 0x38, 0x38,
};
const uint8_t welding[128] = {
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x3C, 0x40, 0x30, 0x40, 0x3C,
  0x38, 0x54, 0x54, 0x54, 0x18,
  0x00, 0x41, 0x7F, 0x40, 0x00,
  0x38, 0x44, 0x44, 0x48, 0x7F,
  0x00, 0x44, 0x7D, 0x40, 0x00,
  0x7C, 0x08, 0x04, 0x04, 0x78,
  0x0C, 0x52, 0x52, 0x52, 0x3E,
};

const uint8_t numbers[20][8] = {
  {0xfc, 0xfe, 0x07, 0x03, 0x03, 0x07, 0xfe, 0xfc},  //0 up
  {0x3f, 0x7f, 0xe0, 0xc0, 0xc0, 0xe0, 0x7f, 0x3f},  //0 down
  {0x00, 0x08, 0x0c, 0x0e, 0xff, 0xff, 0x00, 0x00},  //1 up
  {0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00},  //1 down
  {0x03, 0x03, 0x03, 0x03, 0x83, 0xc7, 0xfe, 0x7c},  //2 up
  {0xf8, 0xfe, 0xce, 0xc7, 0xc3, 0xc1, 0xc0, 0xc0},  //2 down
  {0x03, 0x83, 0x83, 0x83, 0x83, 0xc7, 0xfe, 0x3c},  //3 up
  {0xc0, 0xc1, 0xc1, 0xc1, 0xc1, 0xe3, 0x7f, 0x3c},  //3 down
  {0xff, 0xff, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x00},  //4 up
  {0x07, 0x07, 0x06, 0x06, 0x06, 0xff, 0xff, 0x06},  //4 down
  {0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x03, 0x03},  //5 up
  {0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xe3, 0x7f, 0x3e},  //5 down
  {0xfc, 0xfe, 0x87, 0x83, 0x83, 0x83, 0x03, 0x03},  //6 up
  {0x3f, 0x7f, 0xe3, 0xc1, 0xc1, 0xe3, 0x7f, 0x3e},  //6 down
  {0x03, 0x03, 0x03, 0x83, 0xe3, 0x7b, 0x1f, 0x0f},  //7 up
  {0xe0, 0xf8, 0x1e, 0x07, 0x01, 0x00, 0x00, 0x00},  //7 down
  {0x3c, 0x7e, 0xc7, 0x83, 0x83, 0xc7, 0x7e, 0x3c},  //8 up
  {0x3c, 0x7e, 0xe3, 0xc1, 0xc1, 0xe3, 0x7e, 0x3c},  //8 down
  {0x7c, 0xfe, 0xc7, 0x83, 0x83, 0xc7, 0xfe, 0xfc},  //9 up
  {0xc0, 0xc0, 0xc1, 0xc1, 0xc1, 0xe1, 0x7f, 0x3f},  //9 down
};

void LCD_Init(void)
{
  uint8_t ix=0;
  uint8_t comm[]={
    0xAE, //display off
    0xD5, //clock division
    0xF0,
    0xA8, //set multiplex
    0x3F,
    0xD3, //set display offset
    0x00,
    0x40, //set startline
    0x8D,
    0x14, //charge pump on
    0xA1,
    0xC8, //com scan dec
    0x20,
    0x00,
    0xDA, //set com pins
    0x12,
    0xD9, // set precharge
    0xE1,
    0xDB, // set vcom detect
    0x40,
    0xA4, //display on resume
    0xA6, //normal display
    0xAF,
    0xFF
  };
  
  I2C_DeInit();
  I2C_Init(I2C_MAX_FAST_FREQ, 0x52, I2C_DUTYCYCLE_2, I2C_ACK_CURR,
    I2C_ADDMODE_7BIT, 16 );
  
  I2C_GenerateSTART(ENABLE);
  while (!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
  I2C_Send7bitAddress(0x78, I2C_DIRECTION_TX);
  while (!I2C_CheckEvent(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
  I2C_SendData(0x00);
  while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTING));
  while(comm[ix]!=0xFF)
  {
     I2C_SendData(comm[ix]);
     while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTING));
     ix++;
  }
  I2C_GenerateSTOP(ENABLE);
}

void LCD_Update(void)
{
  int ix;
  I2C_GenerateSTART(ENABLE);
  while (!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
  I2C_Send7bitAddress(0x78, I2C_DIRECTION_TX);
  while (!I2C_CheckEvent(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
  I2C_SendData(0x40);
  while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTING));
  for(ix=0;ix<256;ix++)
  {
     I2C_SendData(manual[ix]);
     while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTING));
  }
  for(ix=0;ix<256;ix++)
  {
     I2C_SendData(automatic[ix]);
     while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTING));
  }
  for(ix=0;ix<128;ix++)
  {
     I2C_SendData(welding[ix]);
     while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTING));
  }
  for(ix=0;ix<128;ix++)
  {
     I2C_SendData(0x00);
     while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTING));
  }
  for(ix=0;ix<256;ix++)
  {
     I2C_SendData(lcd_buff[ix]);
     while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTING));
  }
  I2C_GenerateSTOP(ENABLE);
}

void LCD_Time_Init(void)
{
  int ix;
  for(ix=0;ix<256;ix++)
  {
    lcd_buff[ix]=time[ix];
  }
}

void LCD_Set_Time(uint8_t welding_time)
{
  int ix;
  int digit1 = 0;
  int digit2 = 1;

  if (welding_time >= 10)
  {
    digit2 = welding_time%10;
    digit1 = (welding_time/10)%10;
  } else {
    digit1 = 0;
    digit2 = welding_time%10;
  }

  for(ix=0;ix<8;ix++)
  {
    lcd_buff[ix+74]=numbers[digit1*2][ix];
    lcd_buff[ix+86]=numbers[digit2*2][ix];
    lcd_buff[ix+202]=numbers[digit1*2+1][ix];
    lcd_buff[ix+214]=numbers[digit2*2+1][ix];
  }
}