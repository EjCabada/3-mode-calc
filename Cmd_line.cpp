#include "Cmd_line.h"
#include <vector>
#include "Line_parser.h"

using namespace std;

Cmd_line::Cmd_line() {}

int Cmd_line::start_calc(vector<string> arg_list) {
    Line_parser parser;

    for (int i = 1; i < arg_list.size(); i++) {
        line.push_back(arg_list[i]);
    }

    answer = parser.parse_and_calculate(line);

    if (answer == "error") {
        return 1;
    } else {
        cout << answer;
    }
    return 0;
}
