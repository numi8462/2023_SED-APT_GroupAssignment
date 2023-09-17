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
#include "Database.h"
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
        string getUsername() {
            return username;
        }
        string getPassword() {
            return password;
        }
        void setUsername(string username) {
            this->username = username;
        }
        void setPassword(string password) {
            this->password = password;
        }
        
};