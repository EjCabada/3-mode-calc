#ifndef _INTERACTIVE_H_
#define _INTERACTIVE_H_

#include <iostream>
#include "History.h"
#include "Line_parser.h"

class Interactive {
   private:
    History     history;
    std::string answer;
    std::string line;
    float       a;
    float       b;

   public:
    Interactive();
    int start_loop();
};

#endif  // !_INTERACTIVE_H_
