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

#include "Database.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void Database::displayData(){
    for(int i = 0; i < members.size(); i++){
        members[i]->showInfo();
    }
    for(int i = 0; i < motorbikes.size(); i++){
        motorbikes[i]->showInfo();
    }
};

//writes member data to Members.dat file
void Database::writeMemberData(Member &member){
    ofstream outFile("Database/Members.dat",ios::app);
    outFile << member.getMemberID() << "," << member.getFullName() << "," << member.getUsername() << "," << member.getPassword() << "," << member.getPhoneNumber() << "," << member.getIdType() << "," << member.getIdNumber() << "," << member.getLicenceNumber() << "," << member.getExpiryDate() << "," << member.getPoints() << "," << member.getRentScoreAverage() << "\n";
    outFile.close();
    cout << "File saved" << endl;
}

//reads the current member data
Member Database::readMemberData(string currID){
    ifstream inFile;
    inFile.open("Database/Members.dat");

    Member curr;
    string line;

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

    while(inFile.peek()!=EOF){

        string field;
        getline(inFile,field,',');
        memberID = field;
        getline(inFile,field,',');
        fullName = field;
        getline(inFile,field,',');
        username = field;
        getline(inFile,field,',');
        password = field;
        getline(inFile,field,',');
        phoneNumber = stoi(field);
        getline(inFile,field,',');
        idType = field;
        getline(inFile,field,',');
        idNumber = stoi(field);
        getline(inFile,field,',');
        licenceNumber = stoi(field);
        getline(inFile,field,',');
        expiryDate = field;
        getline(inFile,field,',');
        points = stoi(field);
        getline(inFile,field,'\n');
        rentScoreAverage = stod(field);
        if(memberID == currID){
            Member member(memberID,fullName,username,password,phoneNumber,idType,idNumber,licenceNumber,expiryDate,points,rentScoreAverage);
            curr = member;
            break;
        }
    }
    inFile.close();
    return curr;
}

// replaces data if string id matches the Member class
void Database::replaceMemberData(string currID, Member& newMember){
    ifstream inFile;
    inFile.open("Database/Members.dat");

    ofstream tempFile;
    tempFile.open("Database/temp.dat");

    string line;

    while(getline(inFile, line)){
        istringstream ss(line);
        string field;
        getline(ss,field,',');
        string memberID = field;

        // If memberID matches currID, write newMember data to the temporary file
        if(memberID == currID){
            tempFile << newMember.memberID << "," << newMember.fullName << "," << newMember.username << "," << newMember.password << "," << newMember.phoneNumber << "," << newMember.idType << "," << newMember.idNumber << "," << newMember.licenceNumber << "," << newMember.expiryDate << "," << newMember.points << "," << newMember.rentScoreAverage << "\n";
        } else {
            // Otherwise, write the original line to the temporary file
            tempFile << line << '\n';
        }
    }
    
    inFile.close();
    tempFile.close();

    // Delete the original file and rename the temporary file
    remove("Database/Members.dat");
    rename("Database/temp.dat", "Database/Members.dat");
}
void Database::readMotorbikeData(Motorbike &motorbike){

}
