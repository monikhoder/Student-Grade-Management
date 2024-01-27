#pragma once
#include <iostream>
#include <string>
#include "Menu.cpp"
#include "Save.cpp"
#include "UserManager.cpp"
#include "Validation.cpp"
#include "Person.cpp"
#include "Student.cpp"
#include "Teacher.cpp"
using namespace std;

class UserApp {
private:
    Menu menu;
    Save save;
    UserManager userManager;
    Validation VG;
    int choice;
    string filename = "user.dat";
    vector<Person*> users;
void Student(int index){
    do {
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
        return;
            break;
        default:
            cout << "Wrong option" << endl;
            break;
        }
    } while (choice != 0);
}
void Teacher(int index){
    do {
        menu.teacherMenu();
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
        return;
            break;  
        default:
            cout << "Wrong option" << endl;
            break;
        }
    } while (choice != 0);

}
public :
    void login(){
        save.loadVectorFromFile(filename, users);
        string username;
        string password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        for (int i = 0; i < users.size(); i++){
            if (users[i]->getUsername() == username && users[i]->getPassword() == password){
                cout << "Login successfully" << endl;
                if (users[i]->getRole() == "Student"){
                    Student(i);
                }
                else if (users[i]->getRole() == "Teacher"){
                    Teacher(i);
                }
            } 
        }
        cout << "Login failed" << endl;
    }
    
};