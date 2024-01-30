#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class CheckFile {
private:
    string idfile = "ID.dat";
    string userfile = "user.dat";
public:
CheckFile(){
}
bool checkFile(){
        ifstream IDFile(idfile);
        ifstream UserFile(userfile);
        bool result = IDFile.good() && UserFile.good();
        IDFile.close();
        UserFile.close();
        return result;
}
};

