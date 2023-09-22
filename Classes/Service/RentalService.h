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

    void viewAllBike(); // view all bikes
    void viewAllMember(); // view all members
    void rentBike(string id); // member rents bike
    void viewRentedBike(string renterID); // view rented bike
    void viewMyBike(string ownerID); // view my bike, if no bike add one
    void registerBike(string ownerID); // register bike

    void viewMyInfo(string ownerID);
    void writeReviewForRenter(string ownerID);
    void writeReviewForBike(string ownerID);

    void getAverageRatingForRenter(string renterID); // get average rating from reviews
    void getAverageRatingForBike(string ownerID);

    void viewBikeReviews(string id);
    void createRequest(string renterID, string ownerID); // create request to Owner
    void acceptRequest(string renterID, string ownderID);// owner can accept request
    void declineRequest(string renterID, string ownderID);// owner declines request
    void checkRequest(string renterID);// member can check the request status

    void loginMember(); // confirms login
    void loginAdmin();  // confirms admin
    void unlistBike(string ownerID); // removes all data related to motorbike
    void returnBike(string renterID, string ownerID); // returns bike to owner
    void addCredit(string ownerID);

    void getDataFromDatabase(); // reads data from database
    void saveDataToDatabase(); // saves data to database
    void registerMember();    // register guest to member

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
    void menuMemberLogin();

    // menu for admin
    void menuAdmin();
    void menuAdminLogin();

    //menu for renting bike
    void menuRentBike(Member& member,string bikeOwnerID);

    // menu for requests
    void menuRequest(Member& member);

    void menuWriteReview(Member& member);

};


#endif