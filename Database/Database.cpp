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



void Database::displayData(){
    for(int i = 0; i < members.size(); i++){
        members[i]->showInfo();
    }
    for(int i = 0; i < motorbikes.size(); i++){
        motorbikes[i]->showInfo();
    }
};

