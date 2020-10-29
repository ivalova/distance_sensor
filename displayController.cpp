#include "displayController.h"

displayController::displayController()
  : lc_{dataPin, clkPin, csPin}
{
  lc_.shutdown(0, false);
  lc_.setIntensity(0, 15); /*Valid intensity: 0 - 15*/
  lc_.setScanLimit(0, 5);
  lc_.clearDisplay(0);
}

void displayController::setNumber(int value)
{
  // display has only 3 digits
  if (value > 999)
  {
    value = 999;
  }

  lc_.setDigit(0, 1, value % 10, false);


  if (value < 10)
  {
    //do not display leading zeroes
    lc_.setRow(0, 2, 0);
  }
  else
  {
    lc_.setDigit(0, 2, value / 10 % 10, false);
  }

  if (value < 100)
  {
    //do not display leading zeroes
    lc_.setRow(0, 3, 0);
  }
  else
  {
    lc_.setDigit(0, 3, value / 100, false);
  }

}

void displayController::clearDisplay(void)
{
  lc_.clearDisplay(0);

}
