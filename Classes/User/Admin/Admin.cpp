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
#include "Admin.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



string Admin::getUsername() {
    return username;
}
string Admin::getPassword() {
    return password;
}
void Admin::setUsername(string username) {
    this->username = username;
}
void Admin::setPassword(string password) {
    this->password = password;
}
        


