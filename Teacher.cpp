#pragma once
#include <iostream>
#include <string>
#include "Person.cpp"
#include "Validation.cpp"
using namespace std;

class Teacher : public  Person{
private:
Validation VG;
public:
Teacher() : Person(){

}
Teacher (string firstName,string lastName, int id,string gender, string username, string password, string role) : Person (firstName,lastName, id,gender, username,  password, role){
       role = "Teacher";
    }
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
void Add(){
        int choice;
                cout << "Enter first name: ";
                firstName = VG.getstringNoSpace();
                cout << "Enter last name: ";
                lastName = VG.getstringNoSpace();
                do{
                cout << "Enter gender (1 =Male / 2 = Female) : ";
                cin >> choice;
                if (choice == 1){
                    gender = "Male";
                }else if(choice == 2){
                    gender = "Female";
                }

                }while (choice != 1 && choice != 2);
                role = "Teacher";
                id = ID++;
                username = "Tc" + to_string(id);
                password = "123";
            }
void Update (){
        
    }
void AddRecord(){}

void Show(){
    cout << id << "\t\t" + firstName + "\t" + lastName + "\t" + gender + "\t\t" + role << endl;
}
void View()
    {
        cout << "ID: " << id << endl;
        cout << "Full Name : " << firstName << " " << lastName << endl;
        cout << "Gender : " << gender << endl;
        cout << "Role : " << role << endl;
    }
void ShowRecord(){}
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
string getGender(){
    return gender;
}

};