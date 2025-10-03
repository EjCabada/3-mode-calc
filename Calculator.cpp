#include "Calculator.h"

#include <cmath>
#include <string>

using namespace std;

Calculator::Calculator() {}

string Calculator::calculate(Op op, float a) {
    if (op == SQRT) {
        int n = sqrt(a);
        if (is_whole_number(n)) {
            return to_string(int(n));
        }
        return to_string(answer);
    } else if (op == ABS) {
        int n = abs(a);
        if (is_whole_number(n)) {
            return to_string(int(n));
        }
        return to_string(answer);
    }
    cerr << "ERROR: Calculator unable to find Op" << endl;
    return "error";
}

string Calculator::calculate(Op op, float a, float b) {
    switch (op) {
        case ADD:
            answer = a + b;
            break;
        case SUB:
            answer = a - b;
            break;
        case MULT:
            answer = a * b;
            break;
        case DIV:
            if (b == 0) {
                cerr << "ERROR: Atempt to divide by zero" << endl;
                return "error";
            }
            answer = a / b;
            break;
        case MOD:
            answer = int(a) % int(b);
            break;
        case EXP: {
            answer = pow(double(a), double(b));
            break;
        }
        default:
            cerr << "ERROR: Calculator could not find Op" << endl;
            return "error";
    }
    if (is_whole_number(answer)) {
        return to_string(int(answer));
    }
    return to_string(answer);
}

bool Calculator::is_whole_number(float f) {
    return fmod(abs(f), 1.0f) < 0.00001f;
}
