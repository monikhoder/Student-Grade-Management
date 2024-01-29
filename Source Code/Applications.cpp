#pragma once
#include <iostream>
#include "Menu.cpp"
#include "AdminApp.cpp"
#include "UserApp.cpp"
#include "Validation.cpp"
using namespace std;
class Applictions
{
private:
//Data members
    Menu menu;
    Admin admin;
    UserApp user;
    Validation VG;
    int choice;

public:
//Run App function
    void Run()
    {
        do
        {
            menu.Main_menu();
            choice = VG.getint();
            
            switch (choice)
            {
            case 1:
                user.login();
                break;
            case 2:
                admin.login();
                break;
            case 0:
                cout << "Thank you for using our system" << endl;
                return;
                break;
            default:
                cout << "Wrong option" << endl;
                break;
            }
        } while (choice != 0);
    }
};
