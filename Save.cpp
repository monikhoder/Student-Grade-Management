#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Person.cpp"
#include "Student.cpp"
#include "Teacher.cpp"
#include "FileNotFoundException.cpp"
using namespace std;
class Save{
private:
   
public:
    void saveVectorToFile(const string& filename, vector<Person*> users) {
        ofstream outputFile(filename);
        if (outputFile.is_open()) {
            for (Person* user : users) {
                outputFile <<user->getfirstName()<< " " << user->getlastName() << " "<< user->getID() << " " << user->getGender() << " "<< user->getUsername() << " " << user->getPassword() << " " << user->getRole() << endl;
                
            }

            outputFile.close();
        } else {
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }
    void loadVectorFromFile(const string& filename, vector<Person*>& users) {
        ifstream inputFile(filename);
        if (inputFile.is_open()) {
            string line;
            while (getline(inputFile, line)) {
                stringstream ss(line);
                string firstname;
                string lastname;
                int id;
                string gender;
                string username;
                string password;
                string role;
                ss >> firstname >> lastname >> id >>gender >> username >> password >> role;
                if (role == "Student") {
                    users.push_back(new Student(firstname,lastname, id, gender, username, password, role));
                } else if (role == "Teacher") {
                    users.push_back(new Teacher(firstname,lastname, id, gender, username, password, role));
                }
            }
            inputFile.close();
        } else {
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }

};


