#pragma once
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Validation{
public:
    int getint()
    {
        int num;
        do
        {
            cin >> num;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Please enter a number : ";
                getint();
            }
        } while (cin.fail());
        return num;
    }

    string getstring()
    {
        string input;
        cin >> input;
        return input;
    }

    float getfloat()
    {
        float num;
        do{
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a number : " ;
            getfloat();
        }
        if (num > 100){
            cout << "Max score is 100 : " ;
        }
        }while (num > 100);
        return num;
    }

};