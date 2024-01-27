#pragma once
#include <iostream>
#include <string>
#include "Menu.cpp"
#include "Save.cpp"
#include "Functions.cpp"
#include "Validation.cpp"
#include "Person.cpp"
#include "Student.cpp"
#include "Teacher.cpp"
#include "UserNotFoundException.cpp"
using namespace std;

class UserApp
{
private:
    Menu menu;
    Save save;
    Functions fun;
    Validation VG;
    Student st;
    int choice;
    string Userfilename = "user.dat";
    vector<Person *> users;
    void Student(int index)
    {
        do
        {
            menu.studentMenu();
            choice = VG.getint();
            switch (choice)
            {
            case 1:
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 0:
            save.saveVectorToFile(Userfilename, users);
                return;
                break;
            default:
                cout << "Wrong option" << endl;
                break;
            }
        } while (choice != 0);
    }
    void Teacher(int index)
    {
        do
        {
            menu.teacherMenu();
            choice = VG.getint();
            switch (choice)
            {
            case 1:
            cout << "=========Add student record=========" << endl;
            int idx;
            idx = fun.Search(users);
            if (idx == -1 && users[idx]->getRole() != "Student"){
                throw UserNotFoundException();
            }else{
                fun.AddScore(idx, users);
            }
            
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
            cout << "=========View student record=========" << endl;
            fun.ShowRecord(users);
                break;
            case 5:

                break;
            case 6:

                break;
            case 0:
            save.saveVectorToFile(Userfilename, users);
                return;
                break;
            default:
                cout << "Wrong option" << endl;
                break;
            }
        } while (choice != 0);
    }
    int loginIndex()
    {
        string username;
        string password;
        cout << "Enter username: ";
        username = VG.getstringNoSpace();
        cout << "Enter password: ";
        password = VG.getstringNoSpace();
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i]->getUsername() == username && users[i]->getPassword() == password)
            {
                cout << "Login successfully" << endl;
                return i;
            }
        }

        return -1;
    }

public:
    UserApp()
    {
        save.loadVectorFromFile(Userfilename, users);
    }
    void login()
    {
        int index = loginIndex();
        if (index == -1)
        {
            cout << "Invalid username or password" << endl;
            return;
        }
        if (users[index]->getRole() == "Student")
        {
            Student(index);
        }
        else if (users[index]->getRole() == "Teacher")
        {
            Teacher(index);
        }
    }
    ~UserApp()
    {
        for (int i = 0; i < users.size(); i++)
        {
            delete users[i];
        }
    }
};