#pragma once
#include <iostream>
#include <string>
#include "Menu.cpp"
#include "Student.cpp"
#include "UserManager.cpp"
#include "Validation.cpp"
using namespace std;
class Admin
{
private:
    string username = "admin";
    string password = "admin";
    Menu menu;
    UserManager usm;
    Validation VG;

    void run()
    {
        int choice;
        do
        {
            menu.adminMenu();

            choice = VG.getint();
            switch (choice)
            {
            case 1:
                cout << "*******Add Student account*******" << endl;
                usm.AddStudent();
                break;
            case 2:
                cout << "*******Add Teacher account*******" << endl;
                usm.AddTeacher();
                break;
            case 3:
                cout << "*******Search user*******" << endl;
                int index;
                index = usm.Search();
                usm.View(index);
                break;
            case 4:
                cout << "*******Sort user list*******" << endl;
                usm.Sort();
                break;
            case 5:
                cout << "*******View user list*******" << endl;
                usm.Show();
                break;
            case 6:
                cout << "*******Update user account*******" << endl;
                usm.Update();
                break;
            case 7:
                cout << "*******Remove user account*******" << endl;
                usm.Remove();
                break;
            case 8:
                cout << "*******Save*******" << endl;
                usm.Savefile();
                break;
            case 9:
                cout << "*******Load*******" << endl;
                usm.Load();
                break;
            case 0:

                break;
            }

        } while (choice != 0);
    }

public:
    void login()
    {
        string user;
        string pass;
        cout << "Enter Username : ";
        user = VG.getstringNoSpace();
        cout << "Enter Password : ";
        pass = VG.getstringNoSpace();
        if (user == username && pass == password)
        {
            cout << "Login success" << endl;
            run();
        }
        else
        {
            cout << "Invalid Username or Password" << endl;
        }
    }
};
