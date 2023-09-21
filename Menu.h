#ifndef RENTALSERVICE_H
#define RENTALSERVICE_H
#include "../User/Member/Member.cpp"
#include <iostream>
#include <vector>
using namespace std;

class RentalService
{
private:
    /* data */
    vector<Motorbike*> motorbikes;
public:
    RentalService(vector<Motorbike*> motorbikes) : motorbikes(motorbikes){};

    // register guest to member
    void registerMember();

    // shows list of motorbikes which filters by city, points, and member's rating
    void showMotorbikeList(string city, int myPoints, double myRating);

    // adds bike to system
    void addMotorbike(Motorbike &motorbike);

    Motorbike &getMotorbike(int index);

    // main menu
    void menuMain();

    // menu for guests
    void menuGuest(){

    }

    // menu for searching bike
    void menuSearchBike(Member& member);
    

    // menu for member
    void menuMember(Member &member);
     void loginMemMenu();



    // menu for admin
    void menuAdmin();
    void adminLoginMenu();
};


#endif