#pragma once
#include <iostream>
#include <string>
#include "Menu.cpp"
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
        user = VG.getstringNoSpace();
        cout << "Enter password: ";
        pass = VG.getstringNoSpace();
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
        user = VG.getstringNoSpace();
        cout << "Enter password: ";
        pass = VG.getstringNoSpace();
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