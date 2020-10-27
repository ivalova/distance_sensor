#include "LedControl.h"

class displayController 
{
public:
  displayController();
  void setNumber(int value);
  
private:
  LedControl lc_;
  
  static constexpr int dataPin{11};
  static constexpr int clkPin{13};
  static constexpr int csPin{10};
};
