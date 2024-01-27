#pragma once
#include <iostream>
#include <string>

using namespace std;

class Validation
{
public:
    int getint()
    {
        int num;
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a number : " ;
            getint();
        }
        return num;
    }

    string getstring()
    {
        string enter;
        cin.ignore();
        getline(cin, enter);
        return enter;
    }

    float getfloat()
    {
        float num;
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a number" << endl;
            getfloat();
        }
        return num;
    }

    string getstringNoSpace()
    {
        string enter;
        cin >> enter;
        return enter;
    }
    



    




};