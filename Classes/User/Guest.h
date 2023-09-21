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
#include <iostream>
#include <string>

using namespace std;

class Guest {
      private:
          string name;
          int phoneNumber;
      public:
          // Getter method for name
          string getName() {
              return name;
          }
          
          // Setter method for name
          void setName(const string& newName) {
              this->name = newName;
          }
          
          // Getter method for phoneNumber
          int getPhoneNumber() {
              return phoneNumber;
          }
          
          // Setter method for phoneNumber
          void setPhoneNumber(int newPhoneNumber) {
              this->phoneNumber = newPhoneNumber;
          }
};
