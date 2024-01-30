#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "CheckFile.cpp"
using namespace std;

class static_ID{
private:
    int ID = 999;
public:
static_ID(){
    CheckFile check;
    if (check.checkFile() == true){
        loadID();
    }
}
int getID(){
    ID++;
    return ID;
}
void saveID(){
    ofstream outputFile("ID.dat");
    if (outputFile.is_open()) {
        outputFile << ID;
        outputFile.close();
    }
}
void loadID(){
    ifstream inputFile("ID.dat");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            stringstream ss(line);
            ss >> ID;
        }
        inputFile.close();
    } 
}
~static_ID(){
    saveID();
}
};