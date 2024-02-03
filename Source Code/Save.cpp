#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Person.cpp"
#include "Student.cpp"
#include "Teacher.cpp"
#include "FileNotFound.cpp"
using namespace std;
class Save{
private:
   
public:
    void saveVectorToFile(const string& filename, vector<Person*> users) {
        ofstream outputFile(filename);
        if (outputFile.is_open()) {
            for (Person* user : users) {
                if (user->getRole() == "Student"){
                    outputFile << user->getfirstName() << " " << user->getlastName() << " " << user->getID() << " " << user->getGender() << " " << user->getUsername();
                    outputFile << " " << user->getPassword() << " " << user->getRole() << " ";
                    outputFile << user->getKhmer() << " " << user->getMath() << " " << user->getEnglish() << " " << user->getTotal() << " " ;
                    outputFile << user->getAvg() << " " << user->getGrade() << endl;
                }else if (user->getRole() == "Teacher"){
                    outputFile << user->getfirstName() << " " << user->getlastName() << " " << user->getID() << " " << user->getGender() << " " ;
                    outputFile << user->getUsername() << " " << user->getPassword() << " " << user->getRole() << endl;
                }else{
                    cerr << "Error: Unable to save user " << user->getfirstName() << " " << user->getlastName() << endl;
                }
            }

            outputFile.close();
        } else {
          FileNotFound e(filename);
               cerr << e.what() << endl;
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
                float khmer;
                float math;
                float english;
                float total;
                float avg;
                string grade;
                ss >> firstname >> lastname >> id >>gender >> username >> password >> role >> khmer >> math >> english >> total >> avg >> grade;
                if (role == "Student") {
                    users.push_back(new Student(firstname,lastname, id, gender, username, password, role, khmer, math, english, total, avg, grade));
                } else if (role == "Teacher") {
                    users.push_back(new Teacher(firstname,lastname, id, gender, username, password, role));
                }
            }
            inputFile.close();
        } else {
           FileNotFound e(filename);
               cerr << e.what() << endl;
        }
    }

};


