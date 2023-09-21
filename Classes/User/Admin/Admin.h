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
#ifndef ADMIN_H
#define ADMIN_H
#include "../../Service/RentalService.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Admin {
    private:
        string username;
        string password;
    public:
        Admin(string username, string password) : username(username), password(password){}
        string getUsername();
        string getPassword();
        void setUsername(string username);
        void setPassword(string password);
};

#endif