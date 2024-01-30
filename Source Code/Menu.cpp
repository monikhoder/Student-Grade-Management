#pragma once
#include <iostream>
using namespace std;
class Menu
{
public:
    void Main_menu()
    {
        system("cls");
        cout << "================================================" << endl;
        cout << "*******Welcom to Student Mangement System*******" << endl;
        cout << "================================================" << endl;
        cout << "1. Login" << endl;
        cout << "2. Login as admin" << endl;
        cout << "0. Exit" << endl;
        cout << "Please choose your option : ";
    }
    void studentMenu()
    {
        system("cls");
        cout << "Student Menu :" << endl;
        cout << "1. View info" << endl;
        cout << "2. View record" << endl;
        cout << "3. Change username " << endl;
        cout << "4. Modify password " << endl;
        cout << "0. Back" << endl;
        cout << "Please choose your option : ";
    }
    void teacherMenu()
    {
        system("cls");
        cout << "Teacher Menu :" << endl;
        cout << "1. Add student record " << endl;
        cout << "2. Search student" << endl;
        cout << "3. Update student record" << endl;
        cout << "4. View student Record" << endl;
        cout << "5. Change username" << endl;
        cout << "6. Modify password" << endl;
        cout << "0. Back" << endl;
        cout << "Please choose your option : ";
    }
    void adminMenu()
    {
        system("cls");
        cout << "Admin Menu :" << endl;
        cout << "1. Add Student account " << endl;
        cout << "2. Add Teacher account " << endl;
        cout << "3. Search user" << endl;
        cout << "4. Sort user list" << endl;
        cout << "5. View user list " << endl;
        cout << "6. Update user account" << endl;
        cout << "7. Remove user account" << endl;
        cout << "8. Save" << endl;
        cout << "9. Load" << endl;
        cout << "0. Back" << endl;
        cout << "Please choose your option : ";
    }
};