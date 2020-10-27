#include "displayController.h"

displayController::displayController()
  : lc_{dataPin, clkPin, csPin}
{
  lc_.shutdown(0, false);
  /* Set the brightness to a medium value */
  lc_.setIntensity(0, 10);
  /* and clear the display */
  lc_.clearDisplay(0);
}

void displayController::setNumber(int value)
{
  if (value > 999)
  {
    value = 999;
  }

  lc_.setDigit(0, 1, value % 10, false);
  lc_.setDigit(0, 2, value / 10 % 10, false);
  lc_.setDigit(0, 3, value / 100, false);
}
