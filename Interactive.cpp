#include "Interactive.h"

using namespace std;

Interactive::Interactive() {}

int Interactive::start_loop() {
    cout << "Calculator started. Type 'help' for commands." << endl;
    while (true) {
        getline(cin, line);

        if (line == "quit") {
            break;
        } else if (line == "history") {
            history.print();
        } else if (line == "clear") {
            history.clear();
        } else if (line == "help") {
            cout << "Available operations: +, -, *, /, %, ^, sqrt, abs\n  Special commands: "
                    "history, clear, quit"
                 << endl;
        } else {
            Line_parser line_parser;
            answer = line_parser.parse_and_calculate(line);

            if (answer != "error") {
                history.add(line, answer);
                cout << "Result: " << answer << endl;
            }
        }
    }
    return 0;
}
