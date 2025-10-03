#ifndef _CMD_LINE_H_
#define _CMD_LINE_H_

#include <iostream>
#include <vector>

class Cmd_line {
   private:
    std::string              answer;
    std::vector<std::string> line;

   public:
    Cmd_line();
    int start_calc(std::vector<std::string> arg_list);
};

#endif  // !_CMD_LINE_H_
