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

#include "Motorbike.h"
#include "Request.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Member.h
class Member {
    private:
        string fullName;
        string username;
        string password;
        int phoneNumber;
        string idType;
        int idNumber;
        int licenceNumber;
        string expiryDate;
        int points;
        double rentScoreAverage;
        Motorbike rentedBike;
        vector<Request*> requests;
        double minimumRenterScore;
        Request myRequest;
    public:
        Member( string fullName, string username, string password, int phoneNumber, int licence, string expiryDate, int points, double rentScoreAverage,Motorbike rentedBike, vector<Request*> requests, double minimumRenterScore, Request myRequest){
            this->fullName = fullName;
            this->username = username;
            this->password = password;
            this->phoneNumber = phoneNumber;
            this->licenceNumber = licence;
            this->expiryDate = expiryDate;
            this->points = points;
            this->rentScoreAverage = rentScoreAverage;
            this->rentedBike = rentedBike;
            this->requests = requests;
            this->minimumRenterScore = minimumRenterScore;
            this->myRequest = myRequest;
        };

        void showInfo(){
            cout << "Full Name: " << fullName << endl;
            cout << "Username: " << username << endl;
            cout << "Password: " << password << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "ID Type: " << idType << endl;
            cout << "ID Number: " << idNumber << endl;
            cout << "Licence Number: " << licenceNumber << endl;
            cout << "Expiry Date: " << expiryDate << endl;
            cout << "Points: " << points << endl;
            cout << "Rent Score Average: " << rentScoreAverage << endl;
            cout << "Rented Bike: " << endl;
            rentedBike.showInfo();
        }
};