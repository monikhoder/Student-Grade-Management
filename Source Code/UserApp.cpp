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
#include "Modify.cpp"
#include "CheckFile.cpp"
using namespace std;

class UserApp{
private:
//Data members
    Menu menu;
    Save save;
    Functions fun;
    Validation VG;
    Student st;
    Modify md;
    int choice;
    string Userfilename = "user.dat";
    vector<Person *> users;
//Student App
    void Student(int index)
    {
        do
        {
            menu.studentMenu();
            choice = VG.getint();
            switch (choice)
            {
            case 1:
            cout << "=========View Information=========" << endl;
            users[index]->View();
                system("pause");
                break;
            case 2:
            cout << "=========View Record=========" << endl;
            users[index]->ViewRecord();
                system("pause");
                break;
            case 3:
            cout << "=========Modify Username=========" << endl;
            md.ChangeUsername(users, index);
                system("pause");
                break;
            case 4:
            cout << "=========Modify Password=========" << endl;
            md.ChangePassword(users, index);
                system("pause");
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
//Teacher App
    void Teacher(int index)
    {
        do
        {
            menu.teacherMenu();
            choice = VG.getint();
            int idx;
            switch (choice)
            {
            case 1:
            cout << "=========Add student record=========" << endl;
            idx = fun.Search(users);
            if (idx == -1 || users[idx]->getRole() != "Student"){
                cout << "Student not found" << endl;
            }else{
                fun.AddScore(idx, users);
                cout << "Student record has been added" << endl;
                
            }
                system("pause");
                break;
            case 2:
            cout << "=========Search student=========" << endl;
            idx = fun.Search(users);
            if (idx == -1 || users[idx]->getRole() != "Student"){
                cout << "Student not found" << endl;
            }else{
                users[idx]->View();
                users[idx]->ViewRecord();
            }
                system("pause");
                break;
            case 3:
            cout << "=========Update student record=========" << endl;
            int idx;
            idx = fun.Search(users);
            if (idx == -1 || users[idx]->getRole() != "Student"){
                cout << "Student not found" << endl;
            }else{
                fun.AddScore(idx, users);
            }
                system("pause");
                break;
            case 4:
            cout << "=========View student record=========" << endl;
            fun.ShowRecord(users);
                system("pause");
                break;
            case 5:
            cout << "=========Modify username=========" << endl;
            md.ChangeUsername(users, index);
                system("pause");
                break;
            case 6:
            cout << "=========Modify password=========" << endl;
            md.ChangePassword(users, index);
                system("pause");
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
        username = VG.getstring();
        cout << "Enter password: ";
        password = VG.getstring();
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i]->getUsername() == username && users[i]->getPassword() == password)
            {
                return i;
            }
        }

        return -1;
    }

public:
//constructor
    UserApp()
    {
        CheckFile check;
        if (check.checkFile() == true){
            save.loadVectorFromFile(Userfilename, users);
        }
        
    }
//login function
    void login()
    {
        int index = loginIndex();
        if (index == -1)
        {
            cout << "Invalid username or password" << endl;
            system("pause");
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
//destructor
    ~UserApp()
    {
        for (int i = 0; i < users.size(); i++)
        {
            delete users[i];
        }
    }
};