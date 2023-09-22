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
#ifndef DATABASE_H
#define DATABASE_H
#include "../Classes/User/Admin/Admin.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Database
{
private:
    vector<Member> members;
    vector<Motorbike> motorbikes;
    vector<Review> reviews;
    vector<Request> requests;

public:
    Database(){
      this->members = members;
      this->motorbikes = motorbikes;
      this->reviews = reviews;
      this->requests = requests;
    };

    vector<Member> getMembers();
    void displayData();

    Member readMemberData(string memberID);
    Motorbike readBikeData(string ownerID);

    void getAllMembers();
    void getAllMotorbikes();
    void getAllReviews();
    void getAllRequests();

    void writeMemberData(Member &member);
    void writeMotorbikeData(Motorbike &motorbike);
    void writeReviewData(Review &review);
    void writeRequestData(Request &request);

    void replaceMemberData(string currID, Member &member);

};


#endif // DATABASE_H