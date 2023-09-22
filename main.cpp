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

#include "Classes/Service/RentalService.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */

    // Motorbike b1("MEM1","yamada","red","enginesize","mode","yearmade","description",false,10,"Hanoi",5,8);3
    // Motorbike b2("MEM2","Honda","blue","enginesize","mode","yearmade","description",false,9,"Hanoi",6,5);

    // Review r1("renter","MEM1",5,"comment");
    // Review r2("bike","MEM2",5,"comment");

    // Request req1("MEM1","MEM2",10,false,false);
    // Request req2("MEM2","MEM1",8,false,false);

    // database.writeRequestData(req1);
    // database.writeRequestData(req2);
    // database.writeMemberData(m2);


    // database.readMemberData("MEM2").showInfo();

    // database.replaceMemberData("MEM2",m2);

    // database.getAllMembers();
    // database.writeMotorbikeData(b1);
    // database.writeMotorbikeData(b2);

    // database.readBikeData("MEM2").showDetailedInfo();
    // database.getAllMotorbikes();

    // database.writeReviewData(r1);
    // database.writeReviewData(r2);
    // database.getAllReviews();
    // database.getRenterReviewsVector()[0].showReview();
    // database.getBikeReviewsVector()[0].showReview();

    Database database;
    RentalService service;
    Member currMember;
    service.getDataFromDatabase();
    for(auto m  : service.getMembers()){
      if(m.getMemberID() == "MEM1"){
        currMember = m;
      }
    }
    
    
    service.menuMember(currMember);

    return 0;
}
