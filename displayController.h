#ifndef DISPLAY_CONTROLLER_H_
#define DISPLAY_CONTROLLER_H_

#include "LedControl.h"

class displayController
{
  public:
    displayController();
    
    /*Displays a number on 3-digit display, limited to 999*/
    void setNumber(int value);
    
    /*Turns off whole display*/
    void clearDisplay(void);

  private:
    LedControl lc_;

    static constexpr int dataPin{11};
    static constexpr int clkPin{13};
    static constexpr int csPin{10};
};

#endif //DISPLAY_CONTROLLER_H_
