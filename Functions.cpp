#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Menu.cpp"
#include "Student.cpp"
#include "Teacher.cpp"
#include "Person.cpp"
#include "Validation.cpp"
#include <algorithm>
#include <fstream>
#include "Save.cpp"
using namespace std;

class Functions
{
private:
    // vector<Person*> users;
    Student st;
    Teacher tc;
    Menu menu;
    Validation VG;
    string filename = "user.dat";

public:
    int Search(vector<Person *> users)
    {
        cout << "1. Search by ID" << endl;
        cout << "2. Search by Name" << endl;
        int choice;
        do
        {
            cout << "Please choose your option : ";
            choice = VG.getint();
            if (choice != 1 && choice != 2)
            {
                cout << "Wrong option" << endl;
            }
        } while (choice != 1 && choice != 2);
        if (users.size() == 0)
        {
            cout << "No user in list" << endl;
            return -1;
        }
        if (choice == 1)
        {
            int id;
            cout << "Enter ID : ";
            id = VG.getint();
            for (int i = 0; i < users.size(); i++)
            {
                if (users[i]->getID() == id)
                {
                    return i;
                }
            }
        }
        else if (choice == 2)
        {
            string name;
            cout << "Enter Name : ";
            name = VG.getstring();
            for (int i = 0; i < users.size(); i++)
            {
                if (users[i]->getlastName() == name)
                {
                    return i;
                }
            }
        }

        return -1;
    }
    void Sort(vector<Person *> &users)
    {
        int choice;
        do
        {
            cout << "1. Sort by ID" << endl;
            cout << "2. Sort by Name" << endl;
            cout << "Please choose your option : ";
            choice = VG.getint();
            if (choice != 1 && choice != 2)
            {
                cout << "Wrong option" << endl;
            }
        } while (choice != 1 && choice != 2);
        if (choice == 1)
        {
            sort(users.begin(), users.end(), [](Person *a, Person *b)
                 { return a->getID() < b->getID(); });
        }
        else if (choice == 2)
        {
            sort(users.begin(), users.end(), [](Person *a, Person *b)
                 { return a->getfirstName() < b->getfirstName(); });
        }
    }

    void Remove(vector<Person *> &users)
    {
        int index;
        index = Search(users);
        if (index != -1)
        {
            users.erase(users.begin() + index);
        }
        else
        {
            cout << "User not found" << endl;
        }
    }

    void Show(vector<Person *> users)
    {
        cout << "No\t\tID\t\tFirstName/LastName\t\tGender\t\tRole" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            cout << i + 1 << "\t\t";
            users[i]->Show();
        }
    }
    void View(int index, vector<Person *> users)
    {
        if (index != -1)
        {
            users[index]->View();
        }
        else
        {
            cout << "User not found" << endl;
        }
    }
    void Update(int index, vector<Person *> &users)
    {
        int choice;
        string set;
        string gender;
        do
        {
            cout << "1. Update First Name" << endl;
            cout << "2. Update Last Name" << endl;
            cout << "3. Update Gender" << endl;
            cout << "0. Back" << endl;
            cout << "which data you want to update?";
            choice = VG.getint();
            switch (choice)
            {
            case 1:
                cout << "Enter new First Name :";
                set = VG.getstringNoSpace();

                break;
            case 2:
                cout << "Enter new Last Name :";
                set = VG.getstringNoSpace();
                break;
            case 3:

                cout << "Enter new Gender (1= Male / 2= Female) :";
                do
                {
                    choice = VG.getint();
                    if (choice == 1)
                    {
                        gender == "Male";
                    }
                    else if (choice == 2)
                    {
                        gender = "Female";
                    }

                } while (choice != 1 || choice != 2);
                break;
            case 0:
                break;
            default:
                cout << "Invalid data" << endl;
                break;
            }

        } while (choice != 0 && choice > 3);
    }
};