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
    vector<Review> renterReviews;
    vector<Review> bikeReviews;
    vector<Request> requests;

public:
    Database(){
      this->members = members;
      this->motorbikes = motorbikes;
      this->renterReviews = renterReviews;
      this->bikeReviews = bikeReviews;
      this->requests = requests;
    };

    vector<Member> getMembersVector();
    vector<Motorbike> getMotorbikesVector();
    vector<Review> getRenterReviewsVector();
    vector<Review> getBikeReviewsVector();
    vector<Request> getRequestsVector();

    void deleteDatabase();
    void displayData();

    Member readMemberData(string memberID);
    Motorbike readBikeData(string ownerID);
    Review readRenterReviewData(string memberID);
    Review readBikeReviewData(string memberID);

    void getAllMembers();
    void getAllMotorbikes();
    void getAllReviews();
    void getAllRequests();

    void writeMemberData(Member &member);
    void writeMotorbikeData(Motorbike &motorbike);
    void writeReviewData(Review &review);
    void writeRequestData(Request &request);

    void replaceMemberData(string currID, Member &member);
    // void replaceMotorbikeData();

};

#endif // DATABASE_H