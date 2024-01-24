#pragma once
#include <iostream>
using namespace std;

class FileNotFoundException: public exception{
    public:
        const char* what() const throw(){
            return "file was not found";
        }
};

//cerr << "Error: Unable to open file " << filename << std::endl;