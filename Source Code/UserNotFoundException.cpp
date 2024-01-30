#pragma once
#include <exception>
using namespace std;

class UserNotFoundException: public exception {
    const char* what() const throw() {
        return "User not found";
    }
};
   


