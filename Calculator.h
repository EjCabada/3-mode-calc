#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <iostream>

enum Op {
    ADD,
    SUB,
    MULT,
    DIV,
    EXP,
    SQRT,
    MOD,
    ABS,
    ERR,
};

class Calculator {
   private:
    float answer;
    bool  is_whole_number(float f);

   public:
    Calculator();
    std::string calculate(Op op, float a);
    std::string calculate(Op, float a, float b);
};

#endif  // !_CALCULATOR_H_
