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
#include <string>
#include <vector>

using namespace std;



int main(int argc, char const *argv[])
{
  /* code */
  RentalService rs(vector<Motorbike*>{});

  Motorbike 
  bike1("John","Suzuki SV650","","","","","",false,5,0,0,vector<Review*>{},"Hanoi",1,5),
  bike2("John","Triumph Tiger","","","","","",false,2,0,0,vector<Review*>{},"Hanoi",2,7),
  bike3("John","Honda Trail 125","","","","","",false,2,0,0,vector<Review*>{},"Hanoi",3,5),
  bike4("John","Honda CRF 300L Rally ABS","","","","","",false,2,0,0,vector<Review*>{},"Hanoi",4,5),
  bike5("John","Yamaha XT 250","","","","","",false,2,0,0,vector<Review*>{},"Hochiminh",1,7),
  bike6("John","Kawasaki Ninja","","","","","",false,2,0,0,vector<Review*>{},"Hochiminh",2,5),
  bike7("John","Honda CRF 110F","","","","","",false,2,0,0,vector<Review*>{},"Hochiminh",3,5),
  bike8("John","Yamaha YZF R1","","","","","",false,2,0,0,vector<Review*>{},"Hochiminh",4,5);

  rs.addMotorbike(bike1);
  rs.addMotorbike(bike2);
  rs.addMotorbike(bike3);
  rs.addMotorbike(bike4);
  rs.addMotorbike(bike5);
  rs.addMotorbike(bike6);
  rs.addMotorbike(bike7);
  rs.addMotorbike(bike8);

  Request request1;
  Owner o1("John", "username", "password", 010, 010, "expiryDate", 3, 6, &bike1, request1,vector<Review*>{},vector<Request*>{},&bike1);
  // request1.setStatus(true);
  // m1.setMyRequest(request1);
  // m1.rentBike(bike1);

  rs.menuMain();
  int choice;
  cin >> choice;
  switch (choice)
  {
    case 1:
      break;
    case 2:
      rs.menuMember(o1);
      break;
    case 3:
      break;
    default:
      cout << "Invalid Choice" << endl;
      break;
  }

  return 0;
}
