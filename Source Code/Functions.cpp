#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.cpp"
#include "Validation.cpp"
#include <algorithm>
using namespace std;

class Functions{
private:
    Validation VG;

public:
    int Search(vector<Person *> users){
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
        cout << "No\t\tID\t\tFirstName/LastName\tGender\t\tRole" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            cout << i + 1 << "\t\t";
            users[i]->Show();
        }
    }
    void Update(int index, vector<Person *> &users)
    {
        int choice;
        string set;
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
                users[index]->setFirstName(set);
                break;
            case 2:
                cout << "Enter new Last Name :";
                set = VG.getstringNoSpace();
                users[index]->setLastName(set);
                break;
            case 3:
                int ch;
                do
                {
                    cout << "Enter new Gender (1= Male / 2= Female) :";
                    ch = VG.getint();
                    if (ch == 1)
                    {
                        set = "Male";
                    }
                    else if (ch == 2)
                    {
                        set = "Female";
                    }else{
                        cout << "Wrong option" << endl;
                    }

                } while (ch != 1 && ch != 2);
                users[index]->setGender(set);
                break;
            case 0:
                break;
            default:
                cout << "Invalid data" << endl;
                break;
            }

        } while (choice != 0 && choice > 3);
    }
    void AddScore(int index, vector <Person*> & users){
        float khmer;
        float math;
        float english;
        cout << "Enter Khmer score :";
        khmer = VG.getfloat();
        cout << "Enter Math score :";
        math = VG.getfloat();
        cout << "Enter English score :";
        english = VG.getfloat();
        users[index]->Setscore(khmer,math,english);
    }
    void ShowRecord(vector <Person*> users){
        cout << "No\tID\t\tFirstName/LastName\tKhmer\tMath\tEnglish\tTotal\tAvg\tGrade" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i]->getRole() == "Student")
            {
                cout << i + 1 << "\t";
                users[i]->ShowRecord();
            }
           
        }
    }
    
};