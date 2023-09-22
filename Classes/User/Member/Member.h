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
#ifndef MEMBER_H
#define MEMBER_H
#include "../../Motorbike/Motorbike.cpp"
#include "../../Request/Request.cpp"
#include "../../Review/Review.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Member {
    private:
        string memberID;
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
        bool rentStatus;
    public:
        Member(){};
        Member( string memberID,string fullName, string username, string password, int phoneNumber, string idType,int idNumber,int licenceNumber, string expiryDate, int points, double rentScoreAverage, bool rentStatus){
            this->memberID = memberID;
            this->fullName = fullName;
            this->username = username;
            this->password = password;
            this->phoneNumber = phoneNumber;
            this->idType = idType;
            this->idNumber = idNumber;
            this->licenceNumber = licenceNumber;
            this->expiryDate = expiryDate;
            this->points = points;
            this->rentScoreAverage = rentScoreAverage;
            this->rentStatus = rentStatus;
        };
        virtual ~Member() {}
        // shows member information
        void showInfo();
        
        // getters
        string getMemberID();
        string getFullName();
        string getUsername();
        string getPassword();
        int getPhoneNumber();
        string getIdType();
        int getIdNumber();
        int getLicenceNumber();
        string getExpiryDate();
        int getPoints();
        double getRentScoreAverage();
        bool getRentStatus();

        //setters
        void setMemberID(string memberID);
        void setFullName(string fullName);
        void setUsername(string username);
        void setPassword(string password);
        void setPhoneNumber(int phoneNumber);
        void setIdType(string idType);
        void setIdNumber(int idNumber);
        void setLicenceNumber(int licenceNumber);
        void setExpiryDate(string expiryDate);
        void setPoints(int points);
        void setRentScoreAverage(double rentScoreAverage);
        void setRentStatus(bool rentStatus);

        friend class Database;
};

#endif