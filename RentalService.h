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
#include "Motorbike.h"
#include <vector>
using namespace std;

class RentalService
{
private:
    /* data */
    vector<Motorbike*> motorbikes;
public:
    RentalService(/* args */);
    ~RentalService();

    void registerMember(){

    }

    void showMotorbikeList(){
      for (int i = 0; i < motorbikes.size(); i++)
      {
        /* code */
        motorbikes[i]->showInfo();
      }
      
    }
};


