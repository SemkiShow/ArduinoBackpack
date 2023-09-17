#define COLOR_DEBTH 3
#include <microLED.h>
#define NUM_LEDS 6*6
#define WIDTH 6
#define HEIGHT 7
#define DATA_PIN 11
microLED<NUM_LEDS, DATA_PIN, -1, LED_WS2812, ORDER_GRB> matrix(WIDTH, HEIGHT, ZIGZAG, LEFT_TOP, DIR_DOWN);

void setup()
{
  Snow();
}

void loop()
{
  /*CheckLEDs(mHEX(0xFF0000));
  CheckLEDs(mHEX(0x00FF00));
  CheckLEDs(mHEX(0x0000FF));

  CheckLEDs(mHEX(0xFFFF00));
  CheckLEDs(mHEX(0xFF00FF));
  CheckLEDs(mHEX(0x00FFFF));

  CheckLEDs(mHEX(0xFFFFFF));*/
}

void Clear()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    matrix.leds[i] = mHEX(0x000000);
  }
  matrix.show();
}

void CheckLEDs(mData color)
{
  for (int j = 0; j < NUM_LEDS; j++)
  {
    for (int i = 0; i <= j; i++)
    {
      matrix.leds[i] = color;
    }
    matrix.show();
    delay(100);
  }
  Clear();
}

void Snow()
{
  Clear();
  for (int i = 0; i < HEIGHT * 2; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      for (int k = 0; k < HEIGHT - 1; k++)
      {
        matrix.set(j, k, matrix.get(j, k + 1));
      }
    }

    for (int j = 0; j < WIDTH; j++)
    {
      matrix.set(j, HEIGHT - 1, mBlack);
    }

    for (int j = 0; j < random(4); j++)
    {
      matrix.set(random(WIDTH), HEIGHT - 1, mWhite);
    }

    delay(100);
  }
}
