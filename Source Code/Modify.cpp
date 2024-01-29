#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.cpp"
#include "Validation.cpp"
using namespace std;

class Modify {
private:
    string username;
    string password;
    Validation VG;
public:
 void ChangeUsername(vector <Person*>& users, int index){
     cout << "Enter new username : ";
     username = VG.getstringNoSpace();
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->getUsername() == username)
        {
            cout << "Username already exist" << endl;
            return;
        }
    }
    users[index]->setUsername(username);
    }
    void ChangePassword(vector <Person*>& users, int index){
            cout << "Enter old password : ";
            password = VG.getstringNoSpace();
            for (int i = 0; i < users.size(); i++)
            {
                if (users[i]->getPassword() == password)
                {
                    cout << "Enter new password : ";
                    password = VG.getstringNoSpace();
                    users[index]->setPassword(password);
                    return;
                }
            }
            cout << "Wrong password" << endl;    
    }
    };