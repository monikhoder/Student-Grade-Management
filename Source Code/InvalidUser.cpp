#pragma once
#include <iostream>
#include <string>
#include "Validation.cpp"
#include "Person.cpp"
#include <vector>
using namespace std;

class invalidUser{
private:
    Menu menu;
    int choice;
    Validation VG;
public:
    bool AdminLogin(string username, string password){
        string user;
        string pass;
        cout << "Enter username: ";
        user = VG.getstring();
        cout << "Enter password: ";
        pass = VG.getstring();
        if (user == username && pass == password)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int userLogin(vector <Person*> users){
        string user;
        string pass;
        cout << "Enter username: ";
        user = VG.getstring();
        cout << "Enter password: ";
        pass = VG.getstring();
        for (int i = 0; i < users.size(); i++)
        {
            if (user == users[i]->getUsername() && pass == users[i]->getPassword())
            {
                return i;
            }
        }
        return -1;
    }
        
};