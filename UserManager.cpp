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

class UserManager
{
private:

    vector<Person*> users;
    Student st;
    Teacher tc;
    Menu menu;
    Validation VG;
    string filename = "user.dat";

public:
vector <Person*>& getUsers(){
    return users;
    }
    
    void AddStudent()
    {
        st.Add();
        users.push_back(new Student(st));
        
    }
    void AddTeacher()
    {
        tc.Add();
        users.push_back(new Teacher(tc));
        
    }
    int Search()
    {
        cout << "1. Search by ID" << endl;
        cout << "2. Search by Name" << endl;
        int choice;
        do {
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
    void Sort()
    {
        int choice;
        do {
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
            sort(users.begin(), users.end(), [](Person* a, Person* b) {return a->getID() < b->getID(); });
        }
        else if (choice == 2)
        {
            sort(users.begin(), users.end(), [](Person* a, Person* b) {return a->getfirstName() < b->getfirstName(); });
        }
    }
    void Update(){
        cout << "Search user to update" << endl;
        int index;
        index = Search();
        if (index != -1){
            users[index]->Add();
        }else{
            cout << "User not found" << endl;
        }

    }
    void View(int index)
    {
        
        if (index == -1)
        {
            cout << "User Not found" << endl;
        }
        else
        {
            cout << "No\t\tID\t\tName\t\t\tGender\t\tRole" << endl;
            cout << index + 1 << "\t\t";
            users[index]->Show();
        }
    }
    void Remove()
    {
        int index;
        index = Search();
        if (index != -1)
        {
            users.erase(users.begin() + index);
        }
        else
        {
            cout << "User not found" << endl;
        }
    }
    void Savefile(){
        Save sv;
        sv.saveVectorToFile(filename, users);

    }
    void Load(){
        Save sv;
        sv.loadVectorFromFile(filename, users);
    }
   

    void Show()
    {
        cout << "No\t\tID\t\tFirstName/LastName\t\tGender\t\tRole" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            cout << i + 1 << "\t\t";
           users[i]->Show();
           
        }
    }
    void ShowRecord(){
        int no = 0;
        cout << "ID\tName\t\tGender\tKhmer\tMath\tPhysic\tBiology\tChemistry\tGeography\tHistory\tEnglish\tTotal" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i]->getRole() == "Student")
            {
            cout << no++ << "\t";
            users[i]->Show();
            users[i]->ShowRecord();
            }
            
        }
    }
    
   
};