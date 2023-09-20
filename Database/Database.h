/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2023-2
  Group Assignment
  Group: 25
  Compiler used: Compiler version g++ 9.2.0
  Created  date: 14/09/2023
  Acknowledgement: 
*/
#ifndef DATABASE_H
#define DATABASE_H
#include "../Classes/User/Admin/Admin.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Database
{
private:
    string fileName;
    vector<Member*> members;
    vector<Motorbike*> motorbikes;

public:
    Database();
    Database(string fileName);
    ~Database();

    void displayData();
};

#endif // DATABASE_H