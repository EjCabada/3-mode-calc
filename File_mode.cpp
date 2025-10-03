#include "File_mode.h"
#include <string>
#include "Line_parser.h"

using namespace std;

File_mode::File_mode(string iF, string oF) {
    inFile.open(iF);
    if (inFile.is_open()) {
        outFile.open(oF);
    }
}

int File_mode::start_calculations() {
    string      line;
    string      answer;
    int         line_no = 1;
    Line_parser parser;
    if (inFile.is_open() && outFile.is_open()) {
        while (getline(inFile, line)) {
            answer = parser.parse_and_calculate(line);
            if (answer != "error") {
                outFile << answer << endl;
            } else {
                cerr << "error parsing input file at line number: " << line_no << endl;
                cout << "line: " << line_no << " \"" << line << "\"" << endl;
            }
            line_no++;
        }
    } else {
        cerr << "ERROR: failed to open files\n";
        return 1;
    }
    return 0;
}
