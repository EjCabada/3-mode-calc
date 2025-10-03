#include "Line_parser.h"

#include <sstream>
#include <string>
#include <vector>
#include "Calculator.h"

using namespace std;

Line_parser::Line_parser() {}

string Line_parser::parse_and_calculate(string line) {
    vector<string> parsed_line;

    parse_line(parsed_line, line);

    answer = verify_and_calc(parsed_line);

    return answer;
}

string Line_parser::parse_and_calculate(vector<string> line) {
    answer = verify_and_calc(line);
    return answer;
}

void Line_parser::parse_line(vector<string>& parsed_line, string line) {
    stringstream ss(line);
    string       word;
    while (ss >> word) {
        parsed_line.push_back(word);
    }
}

string Line_parser::verify_and_calc(vector<string>& parsed_line) {
    bool right_format;

    if (!find_op(parsed_line)) {
        return "error";
    }

    if (verify_line_syntax(parsed_line)) {
        Calculator calculator;

        if (op == ABS || op == SQRT) {
            a      = convert_to_float(parsed_line[1]);
            answer = calculator.calculate(op, a);
        } else if (op != ERR) {
            a      = convert_to_float(parsed_line[0]);
            b      = convert_to_float(parsed_line[2]);
            answer = calculator.calculate(op, a, b);
        } else {
            cerr << "ERROR: unable to perform calculation\n";
            return "error";
        }
    } else {
        return "error";
    }
    return answer;
}

bool Line_parser::find_op(vector<string> parsed_line) {
    int  size  = parsed_line.size();
    bool found = false;
    if (size == 2) {
        found = check_if_op(parsed_line[0]);
    } else if (size == 3) {
        found = check_if_op(parsed_line[1]);
    }
    return found;
}

bool Line_parser::check_if_op(string s) {
    if (s == "+") {
        op = ADD;
    } else if (s == "-") {
        op = SUB;
    } else if (s == "/") {
        op = DIV;
    } else if (s == "*") {
        op = MULT;
    } else if (s == "^") {
        op = EXP;
    } else if (s == "%") {
        op = MOD;
    } else if (s == "sqrt") {
        op = SQRT;
    } else if (s == "abs") {
        op = ABS;
    } else {
        cerr << "ERROR: could not locate op" << endl;
        return false;
    }
    return true;
}

bool Line_parser::is_float(string a) {
    try {
        stof(a);
        return true;
    } catch (...) {
        // no point of catching, because this function only serves to check if its a float
    }
    return false;
}

bool Line_parser::verify_line_syntax(vector<string> parsed_line) {
    // two cases:  {op , #} or {# , op , #} we must verify both cases
    if (op == SQRT || op == ABS) {
        // two conditions, only 2 args and parsed_line[1] must be float
        if (parsed_line.size() == 2 && is_float(parsed_line[1])) {
            return true;
        }
    } else if (op != ERR) {
        // second scenario: size = 3 && [0] & [2] must be floats
        if (parsed_line.size() == 3 && is_float(parsed_line[0]) && is_float(parsed_line[2])) {
            return true;
        }
    }
    cerr << "ERROR: wrong syntax, {op , #} or {# , op , #} " << endl;
    return false;
}

float Line_parser::convert_to_float(string a) {
    return stof(a);
}
