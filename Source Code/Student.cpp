#pragma once
#include <iostream>
#include <string>
#include "Person.cpp"
#include "Validation.cpp"
#include "static_ID.cpp"
using namespace std;
class Student : public Person
{
private:
    float khmer;
    float math;
    float english;
    float total;
    float avg;
    string grade;
    Validation VG;

public:
// Constructor
    Student() : Person()
    {

        khmer = 0;
        math = 0;
        english = 0;
        total = 0;
        avg = 0;
        grade = "";
    }
    Student(string firstName, string lastName, int id, string gender, string username, string password, string role, float khmer, float math, float english, float total, float avg, string grade) : Person(firstName, lastName, id, gender, username, password, role)
    {
        role = "Student";
        this->khmer = khmer;
        this->math = math;
        this->english = english;
        this->total = total;
        this->avg = avg;
        this->grade = grade;
    }

// setChoice
    void setUsername(string username)
    {
        this->username = username;
    }
    void setPassword(string password)
    {
        this->password = password;
    }
    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }
    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }
    void setGender(string gender)
    {
        this->gender = gender;
    }

    void Add()
    {
        int choice;
        static_ID ID;
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
        id = ID.getID();
        username = "St" + to_string(id);
        password = "123";
        khmer = 0;
        math = 0;
        english = 0;
        total = 0;
        avg = 0;
        grade = "N/A";
    }
    void Setscore(float khmer, float math, float english)
    {
        this->khmer = khmer;
        this->math = math;
        this->english = english;
        total = khmer + math + english;
        avg = total / 3;
        if (avg >= 90)
        {
            grade = "A";
        }
        else if (avg >= 80)
        {
            grade = "B";
        }
        else if (avg >= 70)
        {
            grade = "C";
        }
        else if (avg >= 60)
        {
            grade = "D";
        }
        else if (avg >= 50)
        {
            grade = "E";
        }
        else if(avg < 50)
        {
            grade = "F";
        }
        else if (avg < 0)
        {
            grade = "Invalid";
        }
    }
    

// getChoice
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
    float getKhmer()
    {
        return khmer;
    }
    float getMath()
    {
        return math;
    }
    float getEnglish()
    {
        return english;
    }
    float getTotal()
    {
        return total;
    }
    float getAvg()
    {
        return avg;
    }
    string getGrade()
    {
        return grade;
    }
//Ouput
     void Show()
    {
        cout << id << "\t\t" + firstName + "\t" + lastName + "\t\t" + gender + "\t\t" + role << endl;
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
       cout << id << "\t\t" + firstName + "\t" + lastName + "\t\t" << khmer << "\t" << math << "\t" << english << "\t" << total << "\t" << avg << "\t" << grade << endl;
    }
    void ViewRecord(){
        cout << "Khmer : " << khmer << endl;
        cout << "Math : " << math << endl;
        cout << "English : " << english << endl;
        cout << "Total : " << total << endl;
        cout << "Average : " << avg << endl;
        cout << "Grade : " << grade << endl;
    }
    
};