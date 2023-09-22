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



//Main manu
void RentalService::menuMain(){
    cout << "\nEEET2482/COSC2082 ASSIGNMENT" << endl;
    cout << "MOTORBIKE RENTAL APPLICATION\n" << endl;
    cout << "Instructor: Dr. Ling Huo Chong" << endl;
    cout << "Group: Group No. 25" << endl;
    cout << "s3726115, Youngho Kim" << endl;
    cout << "s3790421, Kien Chau" << endl;
    cout << "s3976442, Thien Do" << endl;
    cout << "s3979772, Tri Ngo\n" << endl;
    cout << "Use the app as 1.Guest   2.Member    3.Admin\n" << endl;
    cout << "Enter your choice: ";
}
    choice = menuChoice(1, 3);
    switch (choice) {
        case 1:
            guestMenu();
            break;
        case 2:
            loginMemMenu();
            break;
        case 3:
            adminLoginMenu();
            break;
               }
//guest menu
Database::guestMenu() {
    int choice;
    cout << "---------------------------------------\n" << endl;
    cout <<"|              GUEST MENU             |\n" << endl;
    cout << "|     1.View bike                   |\n" << endl;
    cout << "|     2.Register                      |\n" << endl;
    cout << "|     3.Back to main menu             |\n" << endl;
    cout <<"---------------------------------------\n" << endl;

    choice = menuChoice(1, 3);
    switch (choice) {
        case 1:
            guestShowBike();
            break;
        case 2:
            registerMember();
            break;
        case 3:
            mainMenu();
            break;
    }

}
//login admin menu
void Database::adminLoginMenu() {
    string username, password;

    cout << "---------------------------------------\n"<< endl;
    cout << "|              ADMIN MENU             |\n"<< endl;
    cout << "|     1.Login As Admin                |\n"<<endl;
    cout<< "|     2.Back to main menu             |\n"<< endl;
    cout << "---------------------------------------\n"<< endl;
    switch (menuChoice(1, 2)) {
        case 1:
            cin.ignore();
            cout << "Enter your username: " << endl;
            getline(cin, username);
            cout << "Enter your password: "<< endl;
            getline(cin, password);
            if (admin->username == username && admin->password == password) {
                cout << "Log in successfully!!! \n\n\n\n"<< endl;
                adminMenu();
                break;
            } else {
                cout <<"\n\nWrong username or password!!! \n"<< endl;
            }
        case 2:
            menuMain();
            break;
              }


}


//admin menu
Database::adminMenu() {
    int choice;
    cout <<  "---------------------------------------\n"<< endl;
    cout <<  "|              ADMIN MENU             |\n"<< endl;
    cout << "|     1.View Member List              |\n" <<endl;
    cout<< "|     2.View Bike List               |\n" <<endl;
    cout<< "|     3.Back to main menu             |\n"<< endl;
    cout << "---------------------------------------\n"<< endl;
    choice = menuChoice(1, 3);
    switch (choice) {
        case 1:
            adminViewMemberMenu();
            break;
        case 2:
            adminViewBikeMenu();
            break;
        case 3:
            menuMain();
            break;
    }


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
//login member menu
void Database::memberLoginMenu() {
    string username, password;

    cout << "---------------------------------------\n"<< endl;
    cout << "|              MEMBER MENU             |\n"<< endl;
    cout << "|     1.Login As Member                |\n"<<endl;
    cout<< "|     2.Back to main menu             |\n"<< endl;
    cout << "---------------------------------------\n"<< endl;
    switch (menuChoice(1, 2)) {
        case 1:
            cin.ignore();
            cout << "Enter your username: " << endl;
            getline(cin, username);
            cout << "Enter your password: "<< endl;
            getline(cin, password);
            if (admin->username == username && member->password == password) {
                cout << "Log in successfully!!! \n\n\n\n"<< endl;
                menuMember();
                break;
            } else {
                cout <<"\n\nWrong username or password!!! \n"<< endl;
            }
        case 2:
            menuMain();
            break;
              }


}

//member menu
RentalService::menuMember(Member &member){
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
//motorbike list
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
//searching menu
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


