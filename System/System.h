#ifndef SYSTEM_B    
#define SYSTEM_B    


#define ADMIN_FILE "Data/admin.dat"
#define Bike_FILE "Data/Bike.dat"
#define Bike_LIST_FILE "Data/BikeList.dat"
#define REQUEST_FILE "Data/request.dat"
#define RATING_Bike_FILE "Data/ratingBike.dat"
#define RATING_Customer_FILE "Data/ratingCustomer.dat"
#define RENTERS_FILE "Data/renters.dat"
#define MEMBERS_FILE "Data/members.dat"
#define UNRATED_OCC_FILE "Data/unratedOcc.dat"
#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <fstream>
#include <iomanip>
//#include "../Class/Member/Member.h"
#include "../Class/Admin/Admin.h"

#include "../Class/Bike/Bike.h"
#include "../Class/Date/Date.h"
#include "../Class/RentedBike/RentedBike.h"
#include "../Class/Customer/Customer.h"
#include "../Class/Review/Review.h"
#include "../Class/Request/Request.h"
#include "../define.h"
//#include "../Class/Admin/Admin.h"
class Admin;


class Bike;

class Member;

class Date;

class User;

class System {
public:
    std::vector<Member *> memberVector;


    Admin *admin;
    std::vector<Bike *> BikeVector;
    Member *currentUser = nullptr;
    Bike *currentUserBike;
    std::vector<Bike *> memberSuitableBikeList;

    System();

    std::string trimString(std::string &str);

    std::vector<std::string> splitStr(std::string &str, char del);

    bool isValidNum(std::string &inputStr);

    bool isDouble(std::string &inputStr);

    bool isValidPhoneNum(std::string &phoneNum);

    bool isValidPassword(std::string &password);

    bool isValidUserName(std::string &username);

    bool isValidFullname(std::string &fullname);

    bool isValidCredit(Member *mem, Bike *Bike);

    bool isValidScore(Member *mem, Bike *Bike);

    bool isValidDate(std::string date);

    bool isRightDateOrder(Date* start, Date *end);

    int menuChoice(int start, int end);

    void guestShowBike();

    void mainMenu();

    void guestMenu();

    void adminMenu();

    void adminLoginMenu();

    void showRequestSent();

    void adminViewMemberMenu();

    void adminViewBikeMenu();

    void loginMemMenu();
    void memberMenu();

    void BikeForRentMenu();

    void rateCustomerMenu(int leaveID);

    bool getInfoListBikeMenu();

    bool enterBikeInfo();

    void validBikeMenu(Date *start, Date *end, std::string location);

    void searchValidBikeMenu();
    bool memRequestBike(Date *startDate, Date *endDate, int BikeId);
    void viewRequestMenu();
    void actionRequestMenu(int requestID);
    void showRentedBike();

    void cancelRequestMenu(int ID);
    void showReview();

    void viewUnratedCustomerList();

    bool isValidStartBikes(Date *start, Member *mem, Bike *Bike, std::string location);

    bool isValidEndBikes(Date *end, Member *mem, Bike *Bike, std::string location);


    bool getValidStartBikes(Date *start, std::string location);
    bool getValidEndBikes(Date *end, std::string location);


    bool deleteInRentBike();

    void inputBikeToSys();

    void inputAdminToSys();

    void inputMemBikeToSys();

    void inputBikeLstToSys();

    void inputMemberToSys();

    void inputRatingCustomerToSys();

    void inputRatingBikeToSys();

    void inputRequestToSys();

    void inputRenterToSys();

    void inputUnratedToSys();

    void outputRenterToFile();

    void outputAdminToFile();

    void outputUnratedToFile();

    void outputRequestToFile();

    void outputRatingCustomerToFile();

    void outputRatingBikeToFile();

    void outputBikeToFile();

    void outputBikeLstToFile();

    void outputMemberToFile();

    void registerMember();

    bool loginMember(std::string username, std::string password);

    Date *stringToDate(std::string &date);


};


#endif //SYSTEM_B   