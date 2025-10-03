#include "App.h"
#include "Cmd_line.h"
#include "File_mode.h"
#include "Interactive.h"

using namespace std;

// instantiate an app obj && add all data to a vector
App::App(int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        arg_list.push_back(argv[i]);
    }
    arg_num = argc;

    parse_mode();
}

int App::run() {
    if (mode == INTERACTIVE_MODE) {
        Interactive interactive;
        return interactive.start_loop();
    } else if (mode == COMMAND_MODE) {
        Cmd_line cmd_line;
        return cmd_line.start_calc(arg_list);
    } else if (mode == FILE_MODE) {
        File_mode filemode(arg_list[2], arg_list[4]);
        filemode.start_calculations();
    }
    return 0;
}

// the actual parsing of the data to get the Mode
int App::parse_mode() {
    if (arg_num == 1) {
        mode = INTERACTIVE_MODE;
    } else if (arg_num == 3 || arg_num == 4) {
        mode = COMMAND_MODE;
    } else if (arg_num == 5 && arg_list[1] == "-f" && arg_list[3] == "-o") {
        mode = FILE_MODE;
    } else {
        cerr << "ERROR: unable to parse file commands" << endl;
        return 1;
    }
    return 0;
}
