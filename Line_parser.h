#ifndef _LINE_PARSER_H_
#define _LINE_PARSER_H_

#include <iostream>
#include <vector>
#include "Calculator.h"

class Line_parser {
   private:
    Op          op;
    float       a;
    float       b;
    std::string answer;  // decided to change from float to string because i need a way to indicate
                         // that there was an error;

    bool        is_float(std::string a);
    float       convert_to_float(std::string a);
    void        parse_line(std::vector<std::string>& parsed_line, std::string line);
    bool        find_op(std::vector<std::string> parsed_line);
    bool        check_if_op(std::string s);
    bool        verify_line_syntax(std::vector<std::string> parsed_line);
    std::string verify_and_calc(std::vector<std::string>& parsed_line);
    // void  send_to_calc(); //line left for reference, example of a bad idea, was about to make a
    // function that would send to caluculator imperative way instead of oop

   public:
    Line_parser();
    std::string parse_and_calculate(std::string line);
    std::string parse_and_calculate(std::vector<std::string> line);
};

#endif  // !_LINE_PARSER_H_
