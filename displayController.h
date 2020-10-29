#ifndef DISPLAY_CONTROLLER_H_
#define DISPLAY_CONTROLLER_H_

#include "LedControl.h"

class displayController
{
  public:
    displayController();
    void setNumber(int value);
    void clearDisplay(void);

  private:
    LedControl lc_;

    static constexpr int dataPin{11};
    static constexpr int clkPin{13};
    static constexpr int csPin{10};
};

#endif //DISPLAY_CONTROLLER_H_
