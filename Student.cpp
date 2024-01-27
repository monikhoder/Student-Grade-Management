#pragma once
#include <iostream>
#include <string>
#include "Person.cpp"
#include "Validation.cpp"
using namespace std;
class Student : public Person
{
private:
    int clas;
    float khmer;
    float math;
    float english;
    float total;
    float avg;
    string grade;
    Validation VG;

public:
    Student() : Person()
    {
        clas = 0;
        khmer = 0;
        math = 0;
        english = 0;
        total = 0;
        avg = 0;
        grade = "";
    }
    Student(string firstName, string lastName, int id, string gender, string username, string password, string role) : Person(firstName, lastName, id, gender, username, password, role)
    {
        role = "Student";
    }
    // setChoice
    void setUsername(string username)
    {
        this->username = username;
    }
    void setID(int id)
    {
        this->id = id;
    }
    void setPassword(string password)
    {
        this->password = password;
    }

    void Add()
    {
        int choice;
        cout << "Enter first name: ";
        firstName = VG.getstringNoSpace();
        cout << "Enter last name: ";
        lastName = VG.getstringNoSpace();
        do
        {
            cout << "Enter gender (1 =Male / 2 = Female) : ";
            choice = VG.getint();
            if (choice == 1)
            {
                gender = "Male";
            }
            else if (choice == 2)
            {
                gender = "Female";
            }

        } while (choice != 1 && choice != 2);
        role = "Student";
        id = ID++;
        username = "St" + to_string(id);
        password = "123";
    }
    void Update (){
        
    }
    void AddRecord()
    {
        cout << "Enter Khmer score: ";
        khmer = VG.getfloat();
        cout << "Enter Math score: ";
        math = VG.getfloat();
        cout << "Enter English score: ";
        english = VG.getfloat();
        total = khmer + math + english;
    }

    // getChoice
    void Show()
    {
        cout << id << "\t\t" + firstName + "\t" + lastName + "\t" + gender + "\t\t" + role << endl;
    }
    void View()
    {
        cout << "ID: " << id << endl;
        cout << "Full Name : " << firstName << " " << lastName << endl;
        cout << "Gender : " << gender << endl;
        cout << "Role : " << role << endl;
    }
    void ShowRecord()
    {
        cout << khmer << "\t" << math << "\t";
        cout << "\t" << english << "\t" << total << endl;
    }
    string getUsername()
    {
        return username;
    }
    string getPassword()
    {
        return password;
    }
    string getRole()
    {
        return role;
    }
    string getfirstName()
    {
        return firstName;
    }
    string getlastName()
    {
        return lastName;
    }
    int getID()
    {
        return id;
    }
    string getGender()
    {
        return gender;
    }
};