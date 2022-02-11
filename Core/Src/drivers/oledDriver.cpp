#include <drivers/oledDriver.h>
#include "main.h"
#include "gpio.h"
#include <string.h>
#include <cmsis_os2.h>


#ifdef __cplusplus
extern "C"
{
#endif

#define INTERFACE_4WIRE_SPI 1
#define INTERFACE_3WIRE_SPI !(INTERFACE_4WIRE_SPI)

OledDriver::OledDriver(void)
{
  memset(_ColorBuffer, 0, sizeof(_ColorBuffer));
  memset(_FillColor, 0, sizeof(_FillColor));
}

uint8_t* OledDriver::GetFillColor()
{
  return _FillColor;
}

uint16_t OledDriver::ConvertToRgb565(Color rgb888)
{
  int baseColor = (int)rgb888;

  uint8_t red = (baseColor >> 16) & 0xFF;
  uint8_t green = (baseColor >> 8) & 0xFF;
  uint8_t blue = baseColor & 0xFF;

  return (((red >> 3) & 0x1F) << 11)
       | (((green >> 2) & 0x3F) << 5)
       | ((blue >> 3) & 0x1F);
}

void OledDriver::SetColor(Color rgb888)
{
  uint16_t rgb565 = ConvertToRgb565(rgb888);
  _ColorBuffer[0] = (rgb565 >> 8) & 0xFF;
  _ColorBuffer[1] = rgb565 & 0xFF;
}

void OledDriver::SetFillColor(Color rgb888)
{
  uint16_t rgb565 = ConvertToRgb565(rgb888);
  _FillColor[0] = (rgb565 >> 8) & 0xFF;
  _FillColor[1] = rgb565 & 0xFF;
}

void OledDriver::WriteCommand(uint8_t cmd)
{
  OLED_CS(GPIO_PIN_RESET);

  OLED_DC(GPIO_PIN_RESET);

  while (HAL_SPI_Transmit(&hspi1, &cmd, 0x01, 0x10) != HAL_OK);

  OLED_DC(GPIO_PIN_SET);

  OLED_CS(GPIO_PIN_SET);
}

void OledDriver::WriteData(uint8_t dat)
{
  OLED_CS(GPIO_PIN_RESET);


  OLED_DC(GPIO_PIN_SET);

  while (HAL_SPI_Transmit(&hspi1, &dat, 0x01, 0x10) != HAL_OK);

  OLED_DC(GPIO_PIN_RESET);

  OLED_CS(GPIO_PIN_SET);
}

void OledDriver::WriteData(uint8_t *dat_p, uint16_t length)
{
  OLED_CS(GPIO_PIN_RESET);
  OLED_DC(GPIO_PIN_SET);

  while (HAL_SPI_Transmit(&hspi1, dat_p, length, 0x10) != HAL_OK);

  OLED_DC(GPIO_PIN_RESET);
  OLED_CS(GPIO_PIN_SET);
}

void OledDriver::WriteMultipleData(uint16_t *data, uint16_t length)
{
	OLED_CS(GPIO_PIN_RESET);
	OLED_DC(GPIO_PIN_SET);

	uint8_t buffer[2];

	for (int i = 0; i < length; i++)
	{
	  buffer[1] = data[i] & 0xFF;
	  buffer[0] = (data[i] >> 8) & 0xFF;
	  while (HAL_SPI_Transmit(&hspi1, buffer, 2, 0x10) != HAL_OK);
	}

	OLED_DC(GPIO_PIN_RESET);
	OLED_CS(GPIO_PIN_SET);
}

void OledDriver::RAMAddress(void)
{
  WriteCommand(0x15);
  WriteData(0x00);
  WriteData(0x7f);

  WriteCommand(0x75);
  WriteData(0x00);
  WriteData(0x7f);
}

void OledDriver::ClearScreen(void)
{
  int i, j;

  uint8_t clear_byte[] = { 0x00, 0x00 };
  RAMAddress();
  WriteCommand(0x5C);
  for (i = 0; i < 128; i++)
  {
    for (j = 0; j < 128; j++)
    {
      WriteData(clear_byte, 2); //RAM data clear
    }
  }
}

void OledDriver::FillColor(Color rgb888)
{
  int i;
  int j;

  RAMAddress();
  WriteCommand(0x5C);
  SetColor(rgb888);
  for (i = 0; i < 128; i++)
  {
    for (j = 0; j < 128; j++)
    {
      WriteData(_ColorBuffer, 2);
    }
  }
}

void OledDriver::SetCoordinates(uint16_t x, uint16_t y)
{
  if ((x >= ScreenWidth) || (y >= ScreenHeight))
    return;
  //Set x and y coordinate
  WriteCommand(SSD1351_CMD_SETCOLUMN);
  WriteData(x);
  WriteData(ScreenWidth - 1);
  WriteCommand(SSD1351_CMD_SETROW);
  WriteData(y);
  WriteData(ScreenHeight - 1);
  WriteCommand(SSD1351_CMD_WRITERAM);
}

void OledDriver::SetAddrWindow(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h)
{
  WriteCommand(SSD1351_CMD_SETCOLUMN); // X range
  WriteData(x1);
  WriteData(x1 + w - 1);
  WriteCommand(SSD1351_CMD_SETROW); // Y range
  WriteData(y1);
  WriteData(y1 + h - 1);
  WriteCommand(SSD1351_CMD_WRITERAM); // Begin write
}

void OledDriver::SetAddress(uint8_t column, uint8_t row)
{
  WriteCommand(SSD1351_CMD_SETCOLUMN);
  WriteData(column);	//X start
  WriteData(column);	//X end
  WriteCommand(SSD1351_CMD_SETROW);
  WriteData(row);	//Y start
  WriteData(row + 7);	//Y end
  WriteCommand(SSD1351_CMD_WRITERAM);
}

void OledDriver::WriteText(uint8_t dat)
{
  uint8_t i;

  for (i = 0; i < 8; i++)
  {
    if (dat & 0x01)
    {
      WriteData(_ColorBuffer, 2);
    }
    else
    {
      WriteData(0x00);
      WriteData(0x00);
    }
    dat >>= 1;
  }
}

void OledDriver::Invert(bool v)
{
  if (v)
  {
    WriteCommand(SSD1351_CMD_INVERTDISPLAY);
  }
  else
  {
    WriteCommand(SSD1351_CMD_NORMALDISPLAY);
  }
}

void OledDriver::DrawPixel(int16_t x, int16_t y)
{
  SetAddress(x, y);

  // transfer data
  WriteData(_ColorBuffer, 2);
}

void OledDriver::DrawPixel(int x, int y, uint16_t color)
{
	SetAddress(x, y);
	// transfer data
	WriteData(reinterpret_cast<unsigned char *>(&color), 2);
}

void OledDriver::DeviceInit(void)
{
  OLED_RST(GPIO_PIN_RESET);
  osDelay(50);
  OLED_RST(GPIO_PIN_SET);
  osDelay(50);

  WriteCommand(SSD1351_CMD_COMMANDLOCK);
  WriteData(0x12);

  WriteCommand(SSD1351_CMD_COMMANDLOCK);
  WriteData(0xB1);

  WriteCommand(SSD1351_CMD_DISPLAYOFF);

  WriteCommand(SSD1351_CMD_SETCOLUMN);
  WriteData(0x00);     //column address start 00
  WriteData(0x7f);     //column address end 95

  WriteCommand(SSD1351_CMD_SETROW);
  WriteData(0x00);     //row address start 00
  WriteData(0x7f);     //row address end 63

  WriteCommand(SSD1351_CMD_CLOCKDIV);  // Internal oscillator frequency
  WriteData(0xF1);

  WriteCommand(SSD1351_CMD_MUXRATIO);
  WriteData(0x7F);

  WriteCommand(SSD1351_CMD_SETREMAP);  //set re-map & data format
  // madctl bits:
  // 6,7 Color depth (01 = 64K)
  // 5   Odd/even split COM (0: disable, 1: enable)
  // 4   Scan direction (0: top-down, 1: bottom-up)
  // 3   Reserved
  // 2   Color remap (0: A->B->C, 1: C->B->A)
  // 1   Column remap (0: 0-127, 1: 127-0)
  // 0   Address increment (0: horizontal, 1: vertical)
  WriteData(0b01100000 | 0b00000110);

  WriteCommand(SSD1351_CMD_STARTLINE);
  WriteData(0x00);     //start 00 line

  WriteCommand(SSD1351_CMD_DISPLAYOFFSET);
  WriteData(0x00);

  WriteCommand(SSD1351_CMD_FUNCTIONSELECT);
  WriteData(0x01);

  WriteCommand(SSD1351_CMD_SETVSL);
  WriteData(0xA0);
  WriteData(0xB5);
  WriteData(0x55);

  WriteCommand(SSD1351_CMD_CONTRASTABC);
  WriteData(0xC8);
  WriteData(0x80);
  WriteData(0xC8);

  // Full contrast
  WriteCommand(SSD1351_CMD_CONTRASTMASTER);
  WriteData(0x0F);

  WriteCommand(SSD1351_CMD_PRECHARGE);
  WriteData(0x32);

  WriteCommand(SSD1351_CMD_DISPLAYENHANCE);
  WriteData(0xA4);
  WriteData(0x00);
  WriteData(0x00);

  WriteCommand(SSD1351_CMD_PRECHARGE2);
  WriteData(0x01);

  WriteCommand(SSD1351_CMD_VCOMH);
  WriteData(0x05);

  WriteCommand(SSD1351_CMD_INVERTDISPLAY);

  ClearScreen();
  WriteCommand(SSD1351_CMD_DISPLAYON);
}


// Draw a horizontal line ignoring any screen rotation.
void OledDriver::DrawFastHLine(int16_t x, int16_t y, int16_t length)
{
  // Bounds check
  if ((x >= ScreenWidth) || (y >= ScreenHeight))
  {
    return;
  }

  // X bounds check
  if (x + length > ScreenWidth)
  {
    length = ScreenWidth - x - 1;
  }

  if (length < 0)
  {
    return;
  }

  // set location
  WriteCommand(SSD1351_CMD_SETCOLUMN);
  WriteData(x);
  WriteData(x + length - 1);
  WriteCommand(SSD1351_CMD_SETROW);
  WriteData(y);
  WriteData(y);
  // fill!
  WriteCommand(SSD1351_CMD_WRITERAM);

  for (uint16_t i = 0; i < length; i++)
  {
    WriteData(_ColorBuffer, 2);
  }
}

// Draw a vertical line ignoring any screen rotation.
void OledDriver::DrawFastVLine(int16_t x, int16_t y, int16_t length)
{
  // Bounds check
  if ((x >= ScreenWidth) || (y >= ScreenHeight))
  {
    return;
  }
  // X bounds check
  if (y + length > ScreenHeight)
  {
    length = ScreenHeight - y - 1;
  }
  if (length < 0)
  {
    return;
  }

  // set location
  WriteCommand(SSD1351_CMD_SETCOLUMN);
  WriteData(x);
  WriteData(x);
  WriteCommand(SSD1351_CMD_SETROW);
  WriteData(y);
  WriteData(y + length - 1);
  // fill!
  WriteCommand(SSD1351_CMD_WRITERAM);

  for (uint16_t i = 0; i < length; i++)
  {
    WriteData(_ColorBuffer, 2);
  }
}

#ifdef __cplusplus
}
#endif

