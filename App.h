#ifndef _APP_H_
#define _APP_H_

#include <iostream>
#include <vector>

enum Mode {
    INTERACTIVE_MODE,
    COMMAND_MODE,
    FILE_MODE,
};

class App {
   private:
    std::vector<std::string> arg_list;
    int                      arg_num;
    std::string              iFileName;
    std::string              oFileName;
    Mode                     mode;
    int                      parse_mode();

   public:
    App(int argc, char* argv[]);
    int run();
};

#endif  // !_APP_H_
