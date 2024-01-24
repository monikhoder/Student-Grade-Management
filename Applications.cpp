#pragma once
#include <iostream>
#include "Menu.cpp"
#include "AdminApp.cpp"
#include "Validation.cpp"
using namespace std;
class Applictions
{
private:
    Menu menu;
    Admin admin;
    
    Validation VG;
    int choice;
    

public:
    void Run()
    {
        do
        {
            menu.Main_menu();
            choice = VG.getint();
            
            switch (choice)
            {
            case 1:
                
                break;
            case 2:
                admin.login();
                break;
            case 0:
                exit(0);
            default:
                cout << "Wrong option" << endl;
                break;
            }
        } while (choice != 0);
    }
};