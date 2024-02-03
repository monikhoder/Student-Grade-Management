#pragma once
#include <iostream>
#include <string>
using namespace std;

class FileNotFound : public exception {
private:
    string filename;
public:
      FileNotFound(string filename) : filename(filename) {}
      const char* what() const throw() {
         return ("Error: Unable to open file " + filename).c_str();
      }
   };
