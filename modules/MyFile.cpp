#include "MyFile.h"
#include "MyVector.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace MyFile
{
    void LoadDataFromFileToVector(string FileName, vector<string>& vFileContent)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                vFileContent.push_back(Line);
            }
            MyFile.close();
        }
    }

    void SaveVectorToFile(string FileName, vector<string>& vFileContent)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out);
        if (MyFile.is_open())
        {
            for (string &Line : vFileContent)
            {
                if (Line != "")
                {
                    MyFile << Line << endl;
                }
            }
            MyFile.close();
        }
    }

    void PrintFile(string FileName, string prompt)
    {
        cout << prompt << endl;
        fstream MyFile;
        MyFile.open(FileName, ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                cout << Line << endl;
            }
        }
        MyFile.close();
    }

    void CreatFile(string FileName)
    {
        vector<string> vFileContent;
        MyVector::readVector(vFileContent);
        SaveVectorToFile(FileName, vFileContent);
    }

    void appendOneLine(string FileName, string Line)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << Line << endl;
        }
        MyFile.close();
    }

    void AppendMultLine(string FileName)
    {
        cout << "Do you want to add text to " << FileName << " file? ";
        char d;
        cin >> d;
        do
        {
            vector<string> vappendContent;
            MyVector::readVector(vappendContent);
            for (string &Line : vappendContent) {
                appendOneLine(FileName, Line);
            }
            d = 'n';
        }
        while (d == 'Y' || d == 'y');
    }

    void UpdateRecord(string FileName, string Record, string newtext)
    {
        vector<string> vFileContent;
        LoadDataFromFileToVector(FileName, vFileContent);
        for (string &Line : vFileContent) {
            if (Line == Record)
            {
                Line = newtext;
            }
        }
        SaveVectorToFile(FileName, vFileContent);
    }

    void AddDataLineToFile(string stDataLine, string UsersFileName)
    {
        fstream MyFile;
        MyFile.open(UsersFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }
}
