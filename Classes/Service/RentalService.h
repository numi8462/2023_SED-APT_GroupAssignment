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
#ifndef RENTALSERVICE_H
#define MRENTALSERVICE_H
#include "../User/Member/Member.cpp"
#include "../User/Admin/Admin.cpp"
#include "../../Database/Database.cpp"
#include <iostream>
#include <vector>
using namespace std;

class RentalService
{
private:
    /* data */
    vector<Member> members;
    vector<Motorbike> motorbikes;
    vector<Review> renterReviews;
    vector<Review> bikeReviews;
    vector<Request> requests;
public:
    RentalService(){};
    // getters
    vector<Member> getMembers();
    vector<Motorbike> getMotorbikes();
    vector<Review> getRenterReviews();
    vector<Review> getBikeReviews();
    vector<Request> getRequests();

    void rentBike(string id);
    void viewRentedBike(string renterID);
    void viewMyBike(string ownerID);
    void writeReviewForRenter(string renterID);
    void writeReviewForBike(string ownerID);
    void getAverageRatingForRenter(string renterID);
    void getAverageRatingForBike(string ownerID);
    void viewBikeReviews(string id);
    void createRequest(string renterID, string ownerID);
    void acceptRequest(string renterID, string ownderID);
    void declineRequest(string renterID, string ownderID);
    void checkRequest(string renterID);

    void getDataFromDatabase();
    void saveDataToDatabase();
    // register guest to member
    void registerMember();

    // shows list of motorbikes which filters by city, points, and member's rating
    void showMotorbikeList(string city, int myPoints, double myRating);


    // main menu
    void menuMain();

    // menu for guests
    void menuGuest();

    // menu for searching bike
    void menuSearchBike(Member& member);

    // menu for member
    void menuMember(Member &member);


    // menu for admin
    void menuAdmin();

    //menu for renting bike
    void menuRentBike(Member& member,string bikeOwnerID);

    // menu for requests
    void menuRequest(Member& member);

};


#endif