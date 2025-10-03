#ifndef _HISTORY_H_
#define _HISTORY_H_

#include <iostream>
#include <queue>
#include <utility>

class History {
   private:
    std::queue<std::pair<std::string, std::string>> history_table;

   public:
    History();
    void clear();
    void add(std::string s, std::string answer);
    void print();
};

#endif  // !_HISTORY_H_
