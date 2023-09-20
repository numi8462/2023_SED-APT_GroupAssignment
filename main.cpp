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

#include "Database/Database.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main(int argc, char const *argv[])
{
  /* code */

  Motorbike 
  bike1("r1","m1","Suzuki SV650","","","","","",false,5,0,0,vector<Review*>{},"Hanoi",1,5),
  bike2("r2","John","Triumph Tiger","","","","","",false,2,0,0,vector<Review*>{},"Hanoi",2,7),
  bike3("r2","John","Honda Trail 125","","","","","",false,2,0,0,vector<Review*>{},"Hanoi",3,5),
  bike4("r2","John","Honda CRF 300L Rally ABS","","","","","",false,2,0,0,vector<Review*>{},"Hanoi",4,5),
  bike5("r2","John","Yamaha XT 250","","","","","",false,2,0,0,vector<Review*>{},"Hochiminh",1,7),
  bike6("r2","John","Kawasaki Ninja","","","","","",false,2,0,0,vector<Review*>{},"Hochiminh",2,5),
  bike7("r2","John","Honda CRF 110F","","","","","",false,2,0,0,vector<Review*>{},"Hochiminh",3,5),
  bike8("r2","John","Yamaha YZF R1","","","","","",false,2,0,0,vector<Review*>{},"Hochiminh",4,5);


  Request request1;
  Review r1(5,""),r2(6,"");
  Member m1("Alice", "username", "password",222,222, "expiryDate");



  // @test for renting bike and write review for bike
  m1.setMyRequest(request1);
  m1.getRequest()->setStatus(true);
  m1.rentBike(bike1);
  m1.getRentedBike()->showInfo();

  // if(m1.getRequest()->getStatus() == true){
  //   m1.writeReview();
  // }
  // bike1.showRentReviews();
  
  // m1.pushReview(&r1);
  // m1.pushReview(&r2);

  // m1.showMemberReviews();
  



  // @test for rent if request true
  // request1.setStatus(true);
  // m1.setMyRequest(request1);
  // m1.rentBike(bike1);

  // // @testing menu
  // rs.menuMain();
  // int choice;
  // cin >> choice;
  // switch (choice)
  // {
  //   case 1:
  //     break;
  //   case 2:
  //     rs.menuMember(o1);
  //     break;
  //   case 3:
  //     break;
  //   default:
  //     cout << "Invalid Choice" << endl;
  //     break;
  // }

  return 0;
}
