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
    Member member;
    Admin admin;
    
    string fileName;
    vector<Member*> members;
    vector<Motorbike*> motorbikes;
    vector<Review*> reviews;
    vector<Request*> requests;

public:
    Database(){

    };

    void displayData();

    Member readMemberData(string memberID);
    void readMotorbikeData(Motorbike &motorbike);

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