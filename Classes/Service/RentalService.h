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


    // menu for admin
    void menuAdmin();
};


#endif