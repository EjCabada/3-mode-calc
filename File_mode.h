#ifndef _FILE_MODE_H_
#define _FILE_MODE_H_

#include <fstream>
#include <iostream>

class File_mode {
   private:
    std::ifstream inFile;
    std::ofstream outFile;

   public:
    File_mode(std::string iF, std::string oF);
    int start_calculations();
};
#endif  // !_FILE_MODE_H_
