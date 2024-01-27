#pragma once
#include <iostream>
#include <string>
#include "Menu.cpp"
using namespace std;
static int ID = 1000;
class Person
{
private:
    int choice;
protected:
    string firstName;
    string lastName;
    string username;
    string password;
    string gender;
    string role;
    int id;

public:
    Person()
    {
        firstName = "-";
        lastName = "-";
        username = "-";
        password = "-";
        gender = "-";
        role = "-";
        id = 0;
    }
    Person(string firstName,string lastName, int id, string gender, string username, string password, string role)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->id = id;
        this->gender = gender;
        this->username = username;
        this->password = password;
        this->role = role;
       
    }

    // setChoice
    virtual void setUsername(string username) = 0;
    virtual void setID(int id) = 0;
    virtual void setPassword(string password) = 0;
    virtual void setFirstName(string firstName) = 0;
    virtual void setLastName(string lastName) = 0;
    virtual void setGender(string gender) = 0;
    virtual void Add() = 0;
    virtual void Update() = 0;
    virtual void AddRecord() = 0;
    // getChoice
    virtual string getUsername() = 0;
    virtual string getPassword() = 0;
    virtual string getRole() = 0;
    virtual string getfirstName() = 0;
    virtual string getlastName() = 0;
    virtual int getID() = 0;
    virtual string getGender() = 0;
    //Output
    virtual void Show () = 0;
    virtual void View () = 0;
    virtual void ShowRecord() = 0;
   
};