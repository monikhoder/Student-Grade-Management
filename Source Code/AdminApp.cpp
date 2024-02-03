#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Menu.cpp"
#include "Person.cpp"
#include "Student.cpp"
#include "Teacher.cpp"
#include "Functions.cpp"
#include "Validation.cpp"
#include "InvalidUser.cpp"
#include "Functions.cpp"
#include "Save.cpp"
#include "CheckFile.cpp"
using namespace std;
class Admin{
private:
//Data members
    string username = "admin";
    string password = "admin";
    Menu menu;
    Functions fun;
    Validation VG;
    invalidUser invalid;
    vector<Person*> users;
    Student st;
    Teacher tc;
    Save save;
    string filename = "user.dat";
//Admin App
    void run(){
        int choice;
        do
        {
            menu.adminMenu();
            int idx;
            choice = VG.getint();
            switch (choice)
            {
            case 1:
                cout << "*******Add Student account*******" << endl;
                st.Add();
                users.push_back(new Student(st));
                cout << "Student account has been added by :" << endl;
                cout << "Username: " << st.getUsername() << endl;
                cout << "Password: " << st.getPassword() << endl;
                system("pause");
                break;
            case 2:
                cout << "*******Add Teacher account*******" << endl;
                tc.Add();
                users.push_back(new Teacher(tc));
                cout << "Teacher account has been added by :" << endl;
                cout << "Username: " << tc.getUsername() << endl;
                cout << "Password: " << tc.getPassword() << endl;
                system("pause");
                break;
            case 3:
                cout << "*******Search user*******" << endl;
                idx = fun.Search(users);
                if (idx != -1){
                    cout << "User found" << endl;
                    users[idx]->View();
                }else {
                    cout << "User not found" << endl;
                }
                system("pause");
                break;
            case 4:
                cout << "*******Sort user list*******" << endl;
                fun.Sort(users);
                cout << "User list has been sorted" << endl;
                system("pause");
                break;
            case 5:
                cout << "*******View user list*******" << endl;
                fun.Show(users);
                system("pause");
                break;
            case 6:
                cout << "*******Update user account*******" << endl;
                idx = fun.Search(users);
                fun.Update(idx, users);
                cout << "User account has been updated" << endl;
                system("pause");
                break;
            case 7:
                cout << "*******Remove user account*******" << endl;
                fun.Remove(users);
                cout << "User account has been removed" << endl;
                system("pause");
                break;
            case 8:
                cout << "*******Save*******" << endl;
                save.saveVectorToFile(filename, users);
                cout << "User list has been saved" << endl;
                system("pause");
                break;
            case 9:
                cout << "*******Load*******" << endl;
                save.loadVectorFromFile(filename, users);
                cout << "User list has been loaded" << endl;
                system("pause");
                break;
            case 0:
                cout << "*******Exit*******" << endl;
                save.saveVectorToFile(filename, users);
                break;
            }

        } while (choice != 0);
    }

public:
//Constructor
    Admin()
    { CheckFile check;
       if (check.checkFile() == true){
           save.loadVectorFromFile(filename, users);
    }
    }
   
//Login function
    void login()
    {
        bool check = false;
        check = invalid.AdminLogin(username, password);
        if (check == true)
        {
            run();
        }
        else
        {
            cout << "Wrong username or password" << endl;
            system("pause");
        }
        
       
    }
//Destructor
    ~Admin()
    {
        for (int i = 0; i < users.size(); i++)
        {
            delete users[i];
        }
    }
};
