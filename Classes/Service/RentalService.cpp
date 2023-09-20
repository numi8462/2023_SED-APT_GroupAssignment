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

#include "RentalService.h"
#include <iostream>
#include <vector>
using namespace std;

// register guest to member
void RentalService::registerMember(){

}

// shows list of motorbikes which filters by city, points, and member's rating
void RentalService::showMotorbikeList(string city, int myPoints, double myRating){
    int listNumber = 1;
    int index = 0;
    for (int i = 0; i < motorbikes.size(); i++)
    {
    // filters
    if(motorbikes[i]->getCity() == city && motorbikes[i]->getPointsPerDay() <= myPoints && motorbikes[i]->getMinimumRenterScore() <= myRating){
        cout << listNumber << ". ";
        motorbikes[i]->showInfo();
        listNumber++;
    }
    }
    
}

// adds bike to system
void RentalService::addMotorbike(Motorbike &motorbike){
    motorbikes.push_back(&motorbike);
}

Motorbike& RentalService::getMotorbike(int index){
    return *motorbikes[index];
}

// main menu
void RentalService::menuMain(){
    cout << "\nEEET2482/COSC2082 ASSIGNMENT" << endl;
    cout << "MOTORBIKE RENTAL APPLICATION\n" << endl;
    cout << "Instructor: Dr. Ling Huo Chong" << endl;
    cout << "Group: Group No. 25" << endl;
    cout << "s3726115, Youngho Kim" << endl;
    cout << "s3790421, Kien Chau" << endl;
    cout << "s3979772, Tri Ngo\n" << endl;
    cout << "Use the app as 1.Guest   2.Member    3.Admin\n" << endl;
    cout << "Enter your choice: ";
}

// menu for guests
void RentalService::menuGuest(){

}

// menu for searching bike
void RentalService::menuSearchBike(Member& member){
    cout << "\nChoose a city to borrow:   1.Hanoi   2.Saigon\n" << endl;
    int choice;
    do {
        cout << "Enter your choice: ";  
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Avaiable bike for you are: (Credit less than " << member.getPoints() << ", Renter rating more than " << member.getRentScoreAverage() << ")" << endl;
            showMotorbikeList("Hanoi", member.getPoints(), member.getRentScoreAverage());
            break;
        case 2:
            cout << "Avaiable bike for you are: (Credit less than " << member.getPoints() << ", Renter rating more than " << member.getRentScoreAverage() << ")" << endl;
            showMotorbikeList("Saigon", member.getPoints(), member.getRentScoreAverage());
            break;
        default:
            cout << "Invalid Choice. Please try again." << endl;
            break;
        }
    } while (choice < 1 || choice > 2);
    
    
}

// menu for member
void RentalService::menuMember(Member &member){
    cout << "\nThis is your Member Menu\n" << endl;
    cout << "0. Exit" << endl;
    cout << "1. View my Information" << endl;
    cout << "2. View List of Bikes" << endl;
    cout << "3. Search Bike for rent" << endl;
    cout << "4. Add credit" << endl;
    cout << "\nEnter your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        menuSearchBike(member);
        break;

    default:
        cout << "Invalid Choice" << endl;
        break;
    }
}


// menu for admin
void RentalService::menuAdmin(){

}



