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
#include <vector>
#include "Admin.h"
#include "Member.h"
#include "Motorbike.h"
#include "RentalService.h"
#include "Review.h"
#include "Database.h"
#include "Request.h"
#include "Guest.h"
using namespace std;

void menu(){
  
}

int main(int argc, char const *argv[])
{
    /* code */
    Motorbike bike1;
    Request request1;
    Member m1("John", "username", "password", 010, 010, "expiryDate", 123, 123, bike1, vector<Request*>{}, 2, request1);

    return 0;
}
