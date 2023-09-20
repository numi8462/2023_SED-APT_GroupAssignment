

#include "System.h"

System::System() {}

std::string System::trimString(std::string &str) {

    std::string finalStr;
    for (char ch: str) {
        if (ch == ' ') {
            continue;
        } else {
            finalStr += ch;
        }
    }
    return finalStr;

}

std::vector<std::string> System::splitStr(std::string &str, char del) {
    std::vector<std::string> dataLst;
    std::stringstream ss;
    ss << str;
    std::string cell;
    while (!ss.eof()) {
        std::getline(ss, cell, del);
        dataLst.push_back(cell);
    }
    return dataLst;
}

bool System::isValidNum(std::string &inputStr) {
    for (int i = 0; i < inputStr.length(); i++) {
        if (i == 0) {
            if (inputStr[i] == '-') {
                continue;
            }
        }
        if (!std::isdigit(inputStr[i])) {
            return false;
        }
    }
    return true;
}

bool System::isDouble(std::string &inputStr) {
    int dotCount = 0;
    for (int i = 0; i < inputStr.length(); i++) {
        if (i == 0) {
            if (inputStr[i] == '.') {
                dotCount++;
                continue;
            }
        }
        if (inputStr[i] == '.') {
            dotCount++;
            continue;
        }

        if (!std::isdigit(inputStr[i])) {
            std::cout << RED << "Not a number!!! Try again: " << RESET;
            return false;
        }
        if (dotCount > 1) {
            std::cout << RED << "Not a number!!! Try again: " << RESET;
            return false;
        }
    }
    return true;
}

bool System::isValidPhoneNum(std::string &phoneNum) {
    //false: phone number must have 10 numbers and start with 0
    //true: continue
    std::regex reg("^(?=0)[0-9]{10}$");
    phoneNum = trimString(phoneNum);
    if (std::regex_match(phoneNum, reg)) {
        return true;
    } else {
        std::cout << RED << "Phone number must have 10 numbers and start with 0. Try again \n" << RESET;
        return false;
    }
}

bool System::isValidPassword(std::string &password) {
    //false: Minimum 8 and maximum 10 characters, at least one uppercase letter, one lowercase letter, one number and one special character:
    //true: continue
    std::regex reg("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[@$!%*?&])[A-Za-z0-9@$!%*?&]{8,10}$");
    password = trimString(password);
    if (std::regex_match(password, reg)) {
        return true;
    } else {
        std::cout
                << RED << "Minimum 8 and maximum 10 characters, at least one uppercase letter, one lowercase letter, one number and one special character. Try again \n" << RESET;
        return false;
    }
}

bool System::isValidUserName(std::string &username) {
    std::regex reg("\\s");
    if (std::regex_match(username, reg)) {
        std::cout << RED << "The username cannot have spaces! Try again \n" << RESET;
        return false;
    } else {
        if (8 > username.length() || username.length() > 16) {
            std::cout << RED << "The username can only have 8 to 16 characters! Try again \n" << RESET;
            return false;
        } else {
            for (auto member: memberVector) {
                if (username == member->username) {
                    std::cout << RED << "Taken username! Try again: \n" << RESET;
                    return false;
                }
            }
            return true;
        }
    }
}

bool System::isValidFullname(std::string &fullname) {
    //false: Name must contain 8 to 20 characters and no digits, no special characters
    //true: continue
    std::regex reg("^[a-zA-Z]{8,20}$");
    fullname = trimString(fullname);
    if (std::regex_match(fullname, reg)) {
        return true;
    } else {
        std::cout << RED << "Name must contain 8 to 20 characters and no digits, no special characters \n" <<RESET;
        return false;
    }
}

bool System::isValidCredit(Member *mem, Bike *Bike) {
    if (mem->credit <
        (Bike->consumingPointsPerDay * (Bike->endingDate->countDate() - Bike->startingDate->countDate()))) {
        return false;
    }
    return true;
}

bool System::isValidScore(Member *mem, Bike *Bike) {
    if (mem->score < Bike->minRating) {
        return false;
    }
    return true;
}

bool System::isValidDate(std::string date) {
    std::string day = date.substr(0,2);
    std::string month = date.substr(3,2);
    std::string year = date.substr(6,4);

    for (int i = 0; i < date.length(); i++) {
        if (i == 2 || i == 5) {
            if (date[i] != '/') {
                std::cout << RED << "Date must follow the format xx/xx/xxxx. Try again \n" << RESET;
                return false;
            }
        } else if (!std::isdigit(date[i])) {
            std::cout << RED << "Your date is not valid. Try again \n" <<RESET;
            return false;
        } else if(std::stoi(month) > 13  || std::stoi(month) < 1){
            std::cout << RED << "Your date is not valid. Try again \n" << RESET;
            return false;
        } else if(std::stoi(day) > DAYS_IN_MONTHS[std::stoi(month) - 1]){
            std::cout << RED << "Your date is not valid. Try again \n" <<RESET;
            return false;
        }
    }
    return true;
}

bool System::isRightDateOrder(Date *start, Date *end) {
    if (end->countDate() - start->countDate() > 0) {
        return true;
    } else {
        return false;
    }
}


int System::menuChoice(int start, int end) {
    int finalChoice;
    std::string tempChoice;
    bool flag;

    do {
        std::cout << CYAN << "Enter your choice: " << RESET;
        std::cin >> tempChoice;
        if (!isValidNum(tempChoice)) {
            std::cout << RED << "\nChoice is only number! Try again: " << RESET;
            flag = false;
            continue;
        }
        finalChoice = std::stoi(tempChoice);
        if (finalChoice < start || finalChoice > end) {
            std::cout << RED << "Between " << start << " and " << end << " only! Try again: " << RESET;
            flag = false;
            continue;
        } else {
            flag = true;
        }
    } while (!flag);

    return finalChoice;
}

void System::guestShowBike() {
    std::cout << YELLOW << std::left
              << std::setw(10)
              << "BikeID"
              << std::left
              << std::setw(10)
              << "Location"
              << std::left
              << std::setw(30)
              << "Description"
              << std::left
              << std::setw(20)
              << "Credits Required"
              << std::left
              << std::setw(10)
              << "Scores Required \n" << RESET;
    for (auto *Bike: BikeVector) {
        std::cout << YELLOW << std::left
                  << std::setw(10)
                  << Bike->BikeID
                  << std::left
                  << std::setw(10)
                  << Bike->location
                  << std::left
                  << std::setw(30)
                  << Bike->BikeDescription
                  << std::left
                  << std::setw(20)
                  << Bike->consumingPointsPerDay
                  << std::left
                  << std::setw(10)
                  << Bike->minRating << "\n" << RESET;
    }
    guestMenu();
}

void System::mainMenu() {
    int choice;
    std::cout << GREEN << "-----------------------------------------------------------\n" << RESET;
    std::cout << GREEN << "|              EEET2482/COSC2082 ASSIGNMENT               |\n"
              << "|              VACATION Bike EXCHANGE APPLICATION        |\n"
              << "|              Instructors: DR. Ling Huo-Chong    |\n"
              << "|                                                         |\n"
              << "|              Group: 25                                  |\n"
              << "|              s3976442, Do Xuan Thien                |\n"
              << "|              s                  |\n"
              << "|              s                |\n"
              << "|              s                |\n"
              << "|                                                         |\n"
              << "| Use the app as 1. Guest   2. Member   3. Admin   4.Exit |\n" << RESET;
    std::cout << GREEN  << "----------------------------------------------------------\n\n" << RESET;

    choice = menuChoice(1, 4);
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
        case 4:
            outputMemberToFile();
            outputBikeToFile();
            outputBikeLstToFile();
            outputAdminToFile();
            outputRequestToFile();
            outputRatingBikeToFile();
            outputUnratedToFile();
            outputRatingCustomerToFile();
            outputOccupierToFile();
            break;
    }
}

//guest menu
void System::guestMenu() {
    int choice;
    std::cout << GREEN <<"---------------------------------------\n" << RESET;
    std::cout << GREEN <<"|              GUEST MENU             |\n" << RESET;
    std::cout << GREEN << "|     1.View Bikes                   |\n"
              << "|     2.Register                      |\n"
              << "|     3.Back to main menu             |\n" << RESET;
    std::cout << GREEN <<"---------------------------------------\n" << RESET;

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

//admin menu - basic feature
void System::adminMenu() {
    int choice;
    std::cout << GREEN << "---------------------------------------\n"<< RESET;
    std::cout << GREEN << "|              ADMIN MENU             |\n"<< RESET;
    std::cout << GREEN <<"|     1.View Member List              |\n"
              << "|     2.View Bike List               |\n"
              << "|     3.Back to main menu             |\n"<< RESET;
    std::cout << GREEN <<"---------------------------------------\n"<< RESET;
    choice = menuChoice(1, 3);
    switch (choice) {
        case 1:
            adminViewMemberMenu();
            break;
        case 2:
            adminViewBikeMenu();
            break;
        case 3:
            mainMenu();
            break;
    }


}

void System::adminViewMemberMenu() {
    int index = 1;
    std::cout << GREEN << "All the member of the system: " << "\n"<< RESET;
    std::cout
            << CYAN <<std::left
            << std::setw(5)
            << "Index"
            << std::left
            << std::setw(10)
            << "MemberID"
            << std::left
            << std::setw(15)
            << "Full Name"
            << "\n"<< RESET;
    for (auto mem: memberVector) {
        std::cout
                << CYAN << std::left
                << std::setw(5)
                << index
                << std::left
                << std::setw(10)
                << mem->memberId
                << std::left
                << std::setw(15)
                << mem->fullName
                << "\n"<< RESET;
        index++;
    }
    std::cout << "\n";
    std::cout << GREEN << "\t---1.View Member Detail---\n" << "\t---2.Back to admin menu---\n"<< RESET;
    int choice = menuChoice(1, 2);
    switch (choice) {
        case 1:
            std::cout
                    << CYAN << std::left
                    << std::setw(10)
                    << "Index"
                    << std::left
                    << std::setw(15)
                    << "MemberID"
                    << std::left
                    << std::setw(15)
                    << "Full Name"
                    << std::left
                    << std::setw(15)
                    << "PhoneNum"
                    << std::left
                    << std::setw(15)
                    << "Username"
                    << std::left
                    << std::setw(8)
                    << "Credit"
                    << std::left
                    << std::setw(15)
                    << "Location"
                    << std::left
                    << std::setw(10)
                    << "Rating Score"
                    << "\n"<< RESET;
            for (int i = 0; i < memberVector.size(); i++) {
                std::cout
                        <<CYAN << std::left
                        << std::setw(10)
                        << i + 1
                        << std::left
                        << std::setw(15)
                        << memberVector[i]->memberId
                        << std::left
                        << std::setw(15)
                        << memberVector[i]->fullName
                        << std::left
                        << std::setw(15)
                        << memberVector[i]->phoneNum
                        << std::left
                        << std::setw(15)
                        << memberVector[i]->username
                        << std::left
                        << std::setw(8)
                        << memberVector[i]->credit
                        << std::left
                        << std::setw(15)
                        << memberVector[i]->location
                        << std::left
                        << std::setw(10)
                        << memberVector[i]->getRatingScore()
                        << "\n"<< RESET;
            }
            std::cout << "\n";
            std::cout << CYAN << memberVector.size() + 1 << ".Back to admin menu\n"<< RESET;
            menuChoice(memberVector.size() + 1, memberVector.size() + 1);
            adminMenu();

        case 2:
            adminMenu();
            break;
    }
}

void System::adminViewBikeMenu() {
    int index = 1;
    std::cout << GREEN <<"All Bike of the system: " << "\n"<< RESET;
    std::cout
            << CYAN << std::left
            << std::setw(10)
            << "Index"
            << std::left
            << std::setw(8)
            << "BikeID"
            << std::left
            << std::setw(15)
            << "OwnerID"
            << std::left
            << std::setw(15)
            << "Location"
            << std::left
            << std::setw(35)
            << "Description"
            << "\n"<< RESET;
    for (auto i: BikeVector) {
        std::cout
                << CYAN << std::left
                << std::setw(10)
                << index
                << std::left
                << std::setw(8)
                << i->BikeID
                << std::left
                << std::setw(15)
                << i->owner->memberId
                << std::left
                << std::setw(15)
                << i->location
                << std::left
                << std::setw(35)
                << i->BikeDescription
                << "\n"<< RESET;
        index++;
    }
    std::cout << "\n";
    std::cout << GREEN << "\t---1.View Bike Detail---\n" << "\t---2.Back to admin menu---\n"<< RESET;
    int choice = menuChoice(1, 2);
    switch (choice) {
        case 1:
            std::cout
                    << CYAN << std::left
                    << std::setw(10)
                    << "Index"
                    << std::left
                    << std::setw(10)
                    << "BikeID"
                    << std::left
                    << std::setw(10)
                    << "OwnerID"
                    << std::left
                    << std::setw(20)
                    << "Start Date"
                    << std::left
                    << std::setw(20)
                    << "End Date"
                    << std::left
                    << std::setw(25)
                    << "CreditPerDay"
                    << std::left
                    << std::setw(15)
                    << "minScore"
                    << std::left
                    << std::setw(20)
                    << "Location"
                    << std::left
                    << std::setw(35)
                    << "Description"
                    << "\n" << RESET;
            for (int j = 0; j < BikeVector.size(); j++) {
                std::cout
                        << CYAN << std::left
                        << std::setw(10)
                        << j + 1
                        << std::left
                        << std::setw(10)
                        << BikeVector[j]->BikeID
                        << std::left
                        << std::setw(10)
                        << BikeVector[j]->owner->memberId
                        << std::left
                        << std::setw(20)
                        << BikeVector[j]->startingDate->convertDatetoString()
                        << std::left
                        << std::setw(20)
                        << BikeVector[j]->endingDate->convertDatetoString()
                        << std::left
                        << std::setw(25)
                        << BikeVector[j]->consumingPointsPerDay
                        << std::left
                        << std::setw(15)
                        << BikeVector[j]->minRating
                        << std::left
                        << std::setw(20)
                        << BikeVector[j]->location
                        << std::left
                        << std::setw(35)
                        << BikeVector[j]->BikeDescription
                        << "\n" << RESET;
            }
            std::cout << "\n";
            std::cout << CYAN << BikeVector.size() + 1 << ".Back to admin menu\n"<< RESET;
            menuChoice(BikeVector.size() + 1, BikeVector.size() + 1);
            adminMenu();
            break;
        case 2:
            adminMenu();
            break;
    }


}

void System::loginMemMenu() {
    std::string username, password;
    std::cout << GREEN << "--------------------------------------\n"<< RESET;
    std::cout << GREEN << "|            MEMBER LOGIN            |\n"<< RESET;
    std::cout << GREEN << "|        1. Login as member          |\n"
              << "|        2. Back to main menu        |\n"<< RESET;
    std::cout << GREEN << "--------------------------------------\n"<< RESET;

    switch (menuChoice(1, 2)) {
        case 1:
            std::cin.ignore();
            std::cout << CYAN << "Enter your username: "<< RESET;
            std::getline(std::cin, username);
            std::cout << CYAN << "Enter your password: "<< RESET;
            std::getline(std::cin, password);
            if (loginMember(username, password)) {
                memberMenu();
                break;
            }
        case 2:
            mainMenu();
            break;
    }


}

void System::adminLoginMenu() {
    std::string username, password;

    std::cout << GREEN << "---------------------------------------\n"<< RESET;
    std::cout << GREEN << "|              ADMIN MENU             |\n"<< RESET;
    std::cout << GREEN << "|     1.Login As Admin                |\n"
              << "|     2.Back to main menu             |\n"<< RESET;
    std::cout << GREEN << "---------------------------------------\n"<< RESET;
    switch (menuChoice(1, 2)) {
        case 1:
            std::cin.ignore();
            std::cout << CYAN << "Enter your username: " << RESET;
            std::getline(std::cin, username);
            std::cout << CYAN << "Enter your password: "<< RESET;
            std::getline(std::cin, password);
            if (admin->username == username && admin->password == password) {
                std::cout <<GREEN << "Log in successfully!!! \n\n\n\n"<< RESET;
                adminMenu();
                break;
            } else {
                std::cout << RED <<"\n\nWrong username or password!!! \n"<< RESET;
            }
        case 2:
            mainMenu();
            break;


    }
}


void System::memberMenu() {
    int choice;
    std::cout <<GREEN << "----------------------------------------\n"<< RESET;
    std::cout <<GREEN << "|          ---MEMBER MENU---           |\n"<< RESET;
    std::cout <<GREEN << "|  1.View Account's Information        |\n"
              << "|  2.View Available Bikes             |\n"
              << "|  3.Handle Requests                   |\n"
              << "|  4.List Bike For Rental             |\n"
              << "|  5.Show rented menu                  |\n"
              << "|  6.View Unrated Customer List          |\n"
              << "|  7.Show Request Sent                 |\n"
              << "|  8.Logout                            |\n" << RESET;
    std::cout << GREEN<< "----------------------------------------\n"<< RESET;
    choice = menuChoice(1, 8);
    switch (choice) {
        case 1:
            currentUser->showAccountInfo();
            std::cout << CYAN <<"1. Back to menu...\n"<< RESET;
            menuChoice(1, 1);
            memberMenu();
            break;
        case 2:
            searchValidBikeMenu();
            break;
        case 3:
            viewRequestMenu();
            break;
        case 4:
            BikeForRentMenu();
            break;
        case 5:
            showRentedBike();
            break;
        case 6:
            viewUnratedCustomerList();
            break;
        case 7:
            showRequestSent();
            break;
        case 8:
            currentUser = nullptr;
            mainMenu();
            break;
    }


}

void System::BikeForRentMenu() {
    std::cout << GREEN <<"\t---UP Bike FOR RENT MENU ---\n"<< RESET;
    if (currentUser->BikeOwner != nullptr) {
        if (currentUser->BikeOwner->isAdded) {
            std::cout << GREEN<< "You are having a Bike for rent: \n"<< RESET;
            currentUser->BikeOwner->viewBikeInfo();
            if (currentUser->BikeOwner->listBikeRequest.empty()) {
                std::cout << CYAN << "\n\n---\t1. Omit the Bike of renting site ---\n" << "\t---2. Back to member menu ---\n"<< RESET;
                switch (menuChoice(1, 2)) {
                    case 1:
                        deleteInRentBike();
                        std::cout << GREEN << "\tCome back to UP Bike FOR RENT MENU \n" << RESET;
                        BikeForRentMenu();
                        break;
                    case 2:
                        memberMenu();
                        break;
                }
            } else {
                std::cout << GREEN << "\tCome back to member menu \n"<< RESET;
                memberMenu();
            }
        } else {
            std::cout << CYAN <<"You are having a Bike but not allowing rental yet: \n" << "1. Add the Bike for rent\n"
                      << "2. Back to member menu\n" << RESET;
            switch (menuChoice(1, 2)) {
                case 1:
                    getInfoListBikeMenu();
                    std::cout << GREEN <<"\nSuccessfully added your Bike\n\n" << RESET;
                    BikeForRentMenu();
                    break;
                case 2:
                    memberMenu();
                    break;
            }
        }
    } else {
        std::cout << RED <<"You do not have a Bike. Add one: \n" << RESET;
        enterBikeInfo();
        BikeForRentMenu();
    }
}

bool System::getInfoListBikeMenu() {
    std::string startDate, endDate, minScores, minCredits;
    std::cin.ignore();

    std::cout << GREEN <<"\tPlease enter of your rental info\n" << RESET;
    do {
        do {
            std::cout << CYAN << "Enter the first renting date "<< RESET;
            std::getline(std::cin, startDate);
        } while (!isValidDate(startDate));
        do {
            std::cout << CYAN << "Enter the end renting date "<< RESET;
            std::getline(std::cin, endDate);
        } while (!isValidDate(endDate));
    } while (!isRightDateOrder(stringToDate(startDate), stringToDate(endDate)));

    do {
        std::cout << CYAN << "Enter the required credits per day "<< RESET;
        std::getline(std::cin, minCredits);
    } while (!isDouble(minCredits));

    do {
        std::cout << CYAN << "Enter the required minimum scores of renant "<< RESET;
        std::getline(std::cin, minScores);
    } while (!isDouble(minScores));

    Date *start = stringToDate(startDate);
    Date *end = stringToDate(endDate);
    currentUser->addBike(start, end, std::stod(minCredits), std::stod(minScores), STATUS[0]);
    return true;
}

bool System::enterBikeInfo() {
    std::string BikeId, location, description;
    int choice;
    std::cout << GREEN << "\tPlease enter your Bike's information\n"<< RESET;
    std::cout << GREEN <<"\tChoose the supported app location: "<< RESET;
    std::cout << CYAN <<"\t1. HANOI \t2.SAIGON\n"<< RESET;
    choice = menuChoice(1, 2);
    switch (choice) {
        case 1:
            location = LOCATIONS[0];
            break;
        case 2:
            location = LOCATIONS[1];
            break;
      
    }
    std::cin.ignore();
    std::cout << CYAN <<"\tEnter the description for your Bike: \n" << RESET;
    std::getline(std::cin, description);
    auto *createdBike = new Bike("HOU" + std::to_string(BikeVector.size() + 1), location, description);
    BikeVector.push_back(createdBike);
    currentUser->createBike(createdBike);
    return true;
}

void System::showRentedBike() {
    //Check if current member ocupying any Bike
    if (currentUser->CustomerList.empty()) {
        std::cout << RED << "\n\t\tThere are no Bike you are renting\n\n\t\tBack To Member Menu\n" << RESET;
        memberMenu();
    }
    std::cout << GREEN << "\nThe list of Bike you rented:\n" << RESET;
    currentUser->viewCustomer();
    std::cout << "\n---" << currentUser->CustomerList.size() + 1 << ".Back to menu\n";
    int choice = menuChoice(1, currentUser->CustomerList.size() + 1);
    if (choice == currentUser->CustomerList.size() + 1) {
        memberMenu();
    }
    auto CustomerBike = currentUser->CustomerList[choice - 1]->occupyBike;
    CustomerBike->viewBikeInfo();
    std::cout << CYAN <<"\n"
              << "\t\t1.Checkout\n"
              << "\t\t2.Back to menu\n" << RESET;
    int newChoice = menuChoice(1, 2);
    switch (newChoice) {
        case 1:
            currentUser->checkout(choice - 1);
            std::cout << GREEN << "\n\t\tLeft Bike\n" << RESET;
            rateCustomerMenu(choice - 1);
            break;
        case 2:
            memberMenu();
            break;
    }

}

void System::rateCustomerMenu(int leaveID) {
    std::cout << CYAN << "\n\t\t1.Press 1 to rate the Bike: " << RESET;

    int choice = menuChoice(1, 1);
    if(choice == 1) {
        auto leaveMember = currentUser->CustomerList[leaveID];
            std::string comment;
            int score;
            std::cout << CYAN << "\n\t\tPlease leave a comment: " << RESET;
            std::cin.ignore();
            std::getline(std::cin, comment);
            std::cout << CYAN << "\n\t\tPlease leave a score: " << RESET;
            std::cin >> score;
            currentUser->reviewBike(leaveMember->occupyBike, score, comment);
            std:: cout<< CYAN << "\nPress 2 to back to the member Menu: " << RESET;
            if(menuChoice(2,2) == 2) {
                memberMenu();
            }
            
    }
}

void System::showRequestSent() {
    std::cout << GREEN <<"\nEnter the index of request that you want to cancel:\n" << RESET;
    std::cout << GREEN <<"List of the request you have sent: \n" << RESET;
    currentUser->showRequestSent();
    std::cout << CYAN << currentUser->requestList.size() + 1 << ".Back to Member Menu\n" << RESET;
    int choice = menuChoice(1, currentUser->requestList.size() + 1);
    if(choice == currentUser->requestList.size() + 1) {
        memberMenu();
    }
    else {
        cancelRequestMenu(choice);
    }

}

void System:: cancelRequestMenu(int ID) {
    std::cout << CYAN << "\nPress 1 to cancel the request\n" << RESET;
    std::cout << CYAN << "\nPress 2 to back to show request sent menu\n" << RESET;
    int choice = menuChoice(1 , 2);
    switch(choice) {
        case 1:
            for(auto i : BikeVector) {
                for(int j = 0; j < i->listBikeRequest.size(); j ++) {
                    if(i->listBikeRequest[j]->BikeID == currentUser->requestList[ID - 1]->BikeID){
                            i->listBikeRequest.erase(i->listBikeRequest.begin() + j);
                        }
                }
            }
            currentUser->cancelRequest(ID);
            std::cout << GREEN << "\nRequest canceled\nBack to menu:\n" << RESET;
            showRequestSent();
            break;
            
        case 2:
            showRequestSent();
            break;
    }
}

void System::searchValidBikeMenu() {
    std::string startDate;
    std::string endDate;
    std::string location;
    Date *end, *start;
    int choice;
    std::cout << GREEN << "\tSearch for suitable Bikes: \n" << RESET;
    std::cout << CYAN << "\t---1. Search by your start day ---\n" << "\t---2. Search by your end day ---\n" << RESET;
    switch (menuChoice(1, 2)) {
        case 1:
            std::cin.ignore();
            do {
                std::cout << CYAN << "Enter when you want to rent (dd/mm/yyyy): " <<RESET;
                std::getline(std::cin, startDate);
            } while (!isValidDate(startDate));
            std::cout << startDate << "\n";
            break;

        case 2:
            std::cin.ignore();
            do {
                std::cout << CYAN << "Enter when you want to end renting (dd/mm/yyyy): " <<RESET;
                std::getline(std::cin, endDate);
            } while (!isValidDate(endDate));
            break;
    }

    std::cout << GREEN << "\tChoose the city you want to stay: \n\n" <<RESET;
    std::cout << CYAN << "\t1. HANOI \t2.SAIGON\n" << RESET;
    choice = menuChoice(1, 2);
    switch (choice) {
        case 1:
            location = LOCATIONS[0];
            break;
        case 2:
            location = LOCATIONS[1];
            break;
     
    }

    if (endDate.length() == 0) {
        end = nullptr;
    } else {
        end = stringToDate(endDate);
    }

    if (startDate.length() == 0) {
        start = nullptr;
    } else {
        start = stringToDate(startDate);
    }

    validBikeMenu(start, end, location);

}

void System::validBikeMenu(Date *start, Date *end, std::string location) {
    memberSuitableBikeList.clear();
    Request *request;
    int choice;
    if (end == nullptr) {
        getValidStartBikes(start, location);
    } else {
        getValidEndBikes(end, location);
    }
    std::cout << CYAN << memberSuitableBikeList.size() + 1 << ". Back to member menu\n" << RESET;
    choice = menuChoice(1, memberSuitableBikeList.size() + 1);
    if (choice == memberSuitableBikeList.size() + 1) {

        memberMenu();
    } else {
        memberSuitableBikeList[choice - 1]->viewBikeInfo();
        std::cout << CYAN << "\n\n--> 1.\tRequest to rent this Bike\n\n"
                  << "--> 2.\tView Bike's reviews\n\n"
                  << "--> 3.\tBack to Bike list\n" << RESET;
        switch (menuChoice(1, 3)) {
            case 1: {
                if (end == nullptr) {
                    request = new Request(start, memberSuitableBikeList[choice - 1]->endingDate, currentUser, memberSuitableBikeList[choice-1]->BikeID,
                                          RE_STATUS[0]);
                } else {
                    request = new Request(memberSuitableBikeList[choice - 1]->startingDate, end, currentUser, memberSuitableBikeList[choice-1]->BikeID,
                                          RE_STATUS[0]);
                }
                memberSuitableBikeList[choice - 1]->addRequestToBikeRequestList(request);
                memberMenu();
                break; //function send requests
            }
            case 2:
                std::cout << CYAN << "\nReviews of the Bike you want: \n" << RESET;
                choice; 
                memberSuitableBikeList[choice -1]->viewBikeReview();
                std::cout << CYAN << "\n4. Back to the request action menu: \n" << RESET;
                if(menuChoice(4, 4) == 4) {
                    validBikeMenu(start, end, location);
                    break; //function view reviews
                }
                
                
            case 3:
                validBikeMenu(start, end, location);
                break;
        }
    }
}

void System::actionRequestMenu(int requestID) {
    std::cout << CYAN <<"\n\n1.Show Requester Review\n2.Accept Request\n3.Decline Request\n" << RESET;
    switch (menuChoice(1, 3)) {
        case 1:
            {std::cout << GREEN << "\nThe review of your requester is being shown below: \n" << RESET;
            auto requester =currentUser->BikeOwner->listBikeRequest[requestID]->requestedByMember;
            if(requester->CustomerReviewList.empty()) {
                std::cout << RED <<"\nThere are no reviews for this member\n" << RESET;
                std::cout << CYAN << "4.Back to the Request Menu: \n" << RESET;

                if(menuChoice(4, 4) == 4) {
                actionRequestMenu(requestID);
            }
            break;
            }
            else {
                requester->showReview();
            }
            
            std::cout << CYAN << "4.Back to the Request Menu: \n" <<RESET;
            if(menuChoice(4, 4) == 4) {
                actionRequestMenu(requestID);
                break;
            }
    }
        case 2:
            if(!currentUser->acceptRequest(requestID)) {
                std::cout << CYAN << "\n" << currentUser->BikeOwner->listBikeRequest.size() +1 << ".Back to request menu\n" << RESET;
                menuChoice(currentUser->BikeOwner->listBikeRequest.size() +1, currentUser->BikeOwner->listBikeRequest.size() +1);
                viewRequestMenu();
            }
            else {
                std::cout << GREEN << "\nRequest accepted\n" << RESET;
            memberMenu();
            break;
            }
        case 3:
            //Return owner to request menu once there is no valid accept yet
            if(!currentUser->declineRequest(requestID)) {
                std::cout << RED << "You can not decline a request that has been accpeted and declinded" << RESET;
                std::cout << CYAN <<  "\n" << currentUser->BikeOwner->listBikeRequest.size() +1 << ".Back to request menu\n" << RESET;
                menuChoice(currentUser->BikeOwner->listBikeRequest.size() +1, currentUser->BikeOwner->listBikeRequest.size() +1);
                viewRequestMenu();
            }
            else {
            std::cout << GREEN << "\nRequest Declined\n" << RESET;
            memberMenu();
            break;
            }
            
    }
}

void System::viewUnratedCustomerList() {
    std::cout << CYAN << "\n\t\tList of Unrated Occupiers: \n" << RESET;
    if (currentUser->BikeOwner->unratedCustomer.empty()) {
        std::cout << RED << "\nThere are no Customers in your list\n" << RESET;
        memberMenu();
    }
    currentUser->viewUnratedList();
    std::cout << GREEN << "\n" << currentUser->BikeOwner->unratedCustomer.size() + 1 << ".Back to member menu" << RESET;
    std::cout << CYAN << "\nChoose the Customer you would like to review: " << RESET;
    int choice = menuChoice(1, currentUser->BikeOwner->unratedCustomer.size() + 1);

    if (choice == currentUser->BikeOwner->unratedCustomer.size() + 1) {
        memberMenu();
    } else {
        std::string comment;
        int score;
        std::cout << CYAN << "\nPlease leave a comment to this Customer: " << RESET;
        std::cin.ignore();
        std::getline(std::cin, comment);
        std::cout << CYAN <<"\nPlease score the Customer: " << RESET;
        std::cin >> score;
        currentUser->reviewCustomer(choice - 1, score, comment);
        memberMenu();
    }

}

void System::viewRequestMenu() {
   int choice;
    std::cout << CYAN << "\n\n\tYour request today:\n\n" << RESET;
    if(currentUser->BikeOwner == nullptr ){
        std::cout << RED <<  "You do not have a Bike. So you do not have any request! \n" << RESET;
        memberMenu();
    }else{
           int numberRequest = currentUser->viewAllRequest();
    std::cout << GREEN << "\n\tChoose your option:\n\n" << RESET;
    std::cout << CYAN << "\n\n--> 1.\tPoint the Request:\n\n"
              << "--> 2.\tBack to Menu\n" << RESET;
    choice = menuChoice(1, 3);
    switch (choice) {
        case 1: {
            std::cout << GREEN << "Enter the request you want to proceed: \n" << RESET;
            int newChoice = menuChoice(1, numberRequest);
            actionRequestMenu(newChoice - 1);
            break;
        }
        case 2:
            memberMenu();
            break;
    }
    }
 
}

bool System::memRequestBike(Date *startDate, Date *endDate, int BikeId) {
    if (BikeId > memberSuitableBikeList.size()) {
        return false;
    }

}

bool System::isValidStartBikes(Date *start, Member *mem, Bike *Bike, std::string location) {

    int count = 0;
    if (!Bike->isAdded) {
        return false;
    }

    if (Bike->BikeStatus == STATUS[1]) {
        return false;
    }

    if (Bike == mem->BikeOwner) {
        return false;
    }

    if (!isValidScore(mem, Bike)) {
        return false;
    }
    if (!isValidCredit(mem, Bike)) {
        return false;
    }

    if (location != Bike->location) {
        return false;
    }

    if (Bike->startingDate->convertDatetoString() == start->convertDatetoString()) {
        return true;
    }
    return false;

}

bool System::isValidEndBikes(Date *end, Member *mem, Bike *Bike, std::string location) {
    if (!Bike->isAdded) {
        return false;
    }

    if (Bike->BikeStatus == STATUS[1]) {
        return false;
    }

    if (Bike == mem->BikeOwner) {
        return false;
    }

    if (!isValidScore(mem, Bike)) {
        return false;
    }
    if (!isValidCredit(mem, Bike)) {
        return false;
    }

    if (location != Bike->location) {
        return false;
    }


    if (Bike->endingDate == end) {
        return true;
    }

    return false;
}

bool System::getValidStartBikes(Date *start, std::string location) {
    memberSuitableBikeList.clear();
    for (auto &Bike: BikeVector) {
        if (isValidStartBikes(start, currentUser, Bike, location)) {
            memberSuitableBikeList.push_back(Bike);
        }
    }

    if (memberSuitableBikeList.empty()) {
        std::cout << RED << "\nThere is no Bikes matched your search\n" << RESET;
        return false;
    }

    std::cout << GREEN << "\nThe suitable Bike list:\n\n" << RESET;
    for (int i = 0; i < memberSuitableBikeList.size(); i++) {
        std::cout << CYAN << "--> " << i + 1 << ". " << RESET;
        std::cout << CYAN << "Bike Id: " << memberSuitableBikeList[i]->BikeID << "\tLocation: "
                  << memberSuitableBikeList[i]->location << "\tRating: "
                  << memberSuitableBikeList[i]->getRatingScore() << "\n" << RESET;
    }
    std::cout << "\n\n";

    return true;
}

bool System::getValidEndBikes(Date *end, std::string location) {
    memberSuitableBikeList.clear();
    for (auto &Bike: BikeVector) {
        if (isValidEndBikes(end, currentUser, Bike, location)) {

            memberSuitableBikeList.push_back(Bike);
        }
    }

    if (memberSuitableBikeList.empty()) {
        std::cout << RED << "\nThere is no Bikes matched your search\n" << RESET;
        return false;
    }

    std::cout << GREEN<< "\nThe suitable Bike list:\n\n" << RESET;
    for (int i = 0; i < memberSuitableBikeList.size(); i++) {
        std::cout << "--> " << i + 1 << ". ";
        std::cout << CYAN << "Bike Id: " << memberSuitableBikeList[i]->BikeID << "\tLocation: "
                  << memberSuitableBikeList[i]->location << "\tRating: "
                  << memberSuitableBikeList[i]->getRatingScore() << "\n" << RESET;
    }
    std::cout << "\n\n";

    return true;
}

bool System::deleteInRentBike() {
    if (currentUser->deleteBike()) {
        std::cout << GREEN << "\nSuccessfully omit the Bike\n" << RESET;
        return true;
    } else {
        std::cout << CYAN << "The Bike have requests hanging. Resolved all before omitting! \n" << RESET;
        return false;
    }
}

void System::inputBikeToSys() {
    BikeVector.clear();
    std::string dataLine;
    std::ifstream readFile{Bike_FILE};
    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << Bike_FILE << "\n";

    }
    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst;
        dataLst = splitStr(dataLine, ';');
        auto *Bike = new Bike(dataLst[0], dataLst[2], dataLst[3]);
        BikeVector.push_back(Bike);
    }
    readFile.close();
}

void System::inputAdminToSys() {
    std::string dataLine;
    std::ifstream readFile{ADMIN_FILE};
    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << ADMIN_FILE << "\n";
    }

    std::getline(readFile, dataLine);
    std::vector<std::string> dataLst = splitStr(dataLine, ';');
    std::string username = dataLst[0];
    std::string pass = dataLst[1];

    admin = new Admin(username, pass);

}

void System::inputBikeLstToSys() {
    std::string dataLine;
    std::ifstream readFile{Bike_LIST_FILE};
    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << Bike_LIST_FILE << "\n";
    }
    Member *owner;
    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst;
        dataLst = splitStr(dataLine, ';');
        Date *startDate = stringToDate(dataLst[2]);
        Date *endDate = stringToDate(dataLst[3]);
        double credits = std::stod(dataLst[4]);
        double scores = std::stod(dataLst[5]);
        std::string status = dataLst[6];
        std::string ownerId = dataLst[1];
        for (Member *mem: memberVector) {
            if (ownerId == mem->memberId) {
                owner = mem;
            }
        }
        owner->addBike(startDate, endDate, credits, scores, status);
    }
    readFile.close();
}

void System::inputMemBikeToSys() {
    std::string dataLine;
    std::ifstream readFile{Bike_FILE};
    Member *targetMem;
    Bike *memBike;

    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << Bike_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst;
        dataLst = splitStr(dataLine, ';');
        for (Bike *Bike: BikeVector) {
            if (dataLst[0] == Bike->BikeID) {
                memBike = Bike;
            }
        }
        for (Member *mem: memberVector) {
            if (dataLst[1] == mem->memberId) {
                targetMem = mem;
            }
        }
        targetMem->createBike(memBike);
    }
    readFile.close();

}

void System::inputMemberToSys() {
    memberVector.clear();
    std::string dataLine;
    std::ifstream readFile{MEMBERS_FILE};

    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << MEMBERS_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst;
        dataLst = splitStr(dataLine, ';');
        auto *member = new Member(dataLst[3], dataLst[4], dataLst[0], dataLst[1], dataLst[2],
                                  std::stod(dataLst[6]), std::stod(dataLst[7]), dataLst[5]);
        memberVector.push_back(member);
    }
    readFile.close();
}


void System::inputRatingCustomerToSys() {
    std::string dataLine;
    std::ifstream readFile{RATING_Customer_FILE};
    Member *beCommentedMem;
    Member *commentMem;


    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << RATING_Bike_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst;
        dataLst = splitStr(dataLine, ';');
        for (auto mem: memberVector) {
            if (mem->memberId == dataLst[1]) {
                beCommentedMem = mem;
            }
        }
        for (auto mem2: memberVector) {
            if (mem2->memberId == dataLst[0]) {
                commentMem = mem2;
            }
        }


        auto memRating = new Review(std::stod(dataLst[2]), dataLst[3], commentMem);
        beCommentedMem->CustomerReviewList.push_back(memRating);
    }

    readFile.close();

}

void System::outputRatingCustomerToFile() {
    std::ofstream writeFile{RATING_Customer_FILE};

    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << RATING_Customer_FILE << "\n";
    }

    for (auto &mem: memberVector) {
        for (auto &memRating: mem->CustomerReviewList) {
            writeFile << memRating->memberReview->memberId << ";"
                      << mem->memberId << ';'
                      << memRating->ratingScore << ";"
                      << memRating->comment << "\n";
        }
    }
    writeFile.close();
}

void System::outputRatingBikeToFile() {
    std::ofstream writeFile{RATING_Bike_FILE};

    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << RATING_Bike_FILE << "\n";
    }

    for (auto &Bike: BikeVector) {
        for (auto &memRating: Bike->listBikeReview) {
            writeFile << memRating->memberReview->memberId << ";"
                      << Bike->BikeID << ';'
                      << memRating->ratingScore << ";"
                      << memRating->comment << "\n";
        }
    }
    writeFile.close();
}

void System::inputRatingBikeToSys() {
    std::string dataLine;
    Member *targetMem;
    Bike *memBike;
    std::ifstream readFile{RATING_Bike_FILE};
    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << RATING_Bike_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst = splitStr(dataLine, ';');
        for (auto mem: memberVector) {
            if (mem->memberId == dataLst[0]) {
                targetMem = mem;
            }
        }

        for (auto Bike: BikeVector) {
            if (Bike->BikeID == dataLst[1]) {
                memBike = Bike;
            }
        }

        double BikeScore = std::stod(dataLst[2]);
        std::string BikeComment = dataLst[3];

        auto BikeReview = new Review(BikeScore, BikeComment, targetMem);
        memBike->addReviewToBikeReviewList(BikeReview);
    }
    readFile.close();
}


void System::inputRequestToSys() {
    std::string dataLine;
    std::ifstream readFile{REQUEST_FILE};
    Member *targetMem;
    Bike *targetBike;

    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << REQUEST_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst;
        dataLst = splitStr(dataLine, ';');
        for (Bike *Bike: BikeVector) {
            if (dataLst[1] == Bike->BikeID) {
                targetBike = Bike;
            }
        }
        for (Member *mem: memberVector) {
            if (dataLst[0] == mem->memberId) {
                targetMem = mem;
            }
        }
        Date *startDate = stringToDate(dataLst[2]);
        Date *endDate = stringToDate(dataLst[3]);
        std::string status = dataLst[4];
        Request *req = new Request(startDate, endDate, targetMem, targetBike->BikeID, status);
        targetBike->addRequestToBikeRequestList(req);
        targetMem->requestList.push_back(req);
    }
    readFile.close();
}

void System::inputOccupierToSys() {
    std::string dataLine;
    std::ifstream readFile{OCCUPIERS_FILE};
    Member *targetMem;
    Bike *targetBike;

    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << OCCUPIERS_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst = splitStr(dataLine, ';');
        for (auto &mem: memberVector) {
            if (mem->memberId == dataLst[0]) {
                targetMem = mem;
            }
        }
        for (auto &Bike: BikeVector) {
            if (Bike->BikeID == dataLst[1]) {
                targetBike = Bike;
            }
        }
        Date *start = stringToDate(dataLst[2]);
        Date *end = stringToDate(dataLst[3]);

        auto *occupyBike = new OccupyBike(start, end, targetMem);
        auto *occupyMem = new Customer(start, end, targetBike);

        targetMem->CustomerList.push_back(occupyMem);
        targetBike->listOccupyBike.push_back(occupyBike);
    }
}

void System::inputUnratedToSys() {
    std::string dataLine;
    std::ifstream readFile{UNRATED_OCC_FILE};
    Member *targetMem;
    Bike *targetBike;

    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << UNRATED_OCC_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst = splitStr(dataLine, ';');
        for (auto &mem: memberVector) {
            if (mem->memberId == dataLst[1]) {
                targetMem = mem;
            }
        }
        for (auto &Bike: BikeVector) {
            if (Bike->BikeID == dataLst[0]) {
                targetBike = Bike;
            }
        }
        Date *start = stringToDate(dataLst[2]);
        Date *end = stringToDate(dataLst[3]);

        auto *unratedOcc = new OccupyBike(start, end, targetMem);
        targetBike->unratedCustomer.push_back(unratedOcc);
    }
}

void System::outputOccupierToFile() {
    std::ofstream writeFile{OCCUPIERS_FILE};

    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << OCCUPIERS_FILE << "\n";
    }

    for (auto &mem: memberVector) {
        for (auto &memOccupy: mem->CustomerList) {
            writeFile << mem->memberId << ";"
                      << memOccupy->occupyBike->BikeID << ';'
                      << memOccupy->startFromDate->convertDatetoString() << ";"
                      << memOccupy->ToDate->convertDatetoString() << "\n";
        }
    }
    writeFile.close();
}

void System::outputAdminToFile() {
    std::ofstream writeFile{ADMIN_FILE};

    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << ADMIN_FILE << "\n";
    }

    writeFile << admin->username << ";"
              << admin->password << "\n";
}

void System::outputUnratedToFile() {
    std::ofstream writeFile{UNRATED_OCC_FILE};

    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << UNRATED_OCC_FILE << "\n";
    }

    for (auto &Bike: BikeVector) {
        for (auto &unratedOcc: Bike->unratedCustomer) {
            writeFile << Bike->BikeID << ";"
                      << unratedOcc->Customer->memberId << ';'
                      << unratedOcc->startFromDate->convertDatetoString() << ";"
                      << unratedOcc->toDate->convertDatetoString() << "\n";
        }
    }
    writeFile.close();
}

void System::outputRequestToFile() {
    std::ofstream writeFile{REQUEST_FILE};

    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << REQUEST_FILE << "\n";
    }

    for (auto &Bike: BikeVector) {
        for (auto &memRequest: Bike->listBikeRequest) {
            writeFile << memRequest->requestedByMember->memberId << ";"
                      << Bike->BikeID << ';'
                      << memRequest->startDate->convertDatetoString() << ";"
                      << memRequest->endDate->convertDatetoString() << ";"
                      << memRequest->requestStatus << "\n";
        }
    }
    writeFile.close();
}

void System::outputBikeLstToFile() {
    std::ofstream writeFile{Bike_LIST_FILE};
    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << Bike_LIST_FILE << "\n";
        return;
    }

    for (auto mem: memberVector) {
        if (mem->BikeOwner == nullptr) {
            continue;
        }
        if (!mem->BikeOwner->isAdded) {
            continue;
        }

        writeFile << mem->BikeOwner->BikeID << ";"
                  << mem->memberId << ";"
                  << mem->BikeOwner->startingDate->convertDatetoString() << ";"
                  << mem->BikeOwner->endingDate->convertDatetoString() << ";"
                  << mem->BikeOwner->consumingPointsPerDay << ";"
                  << mem->BikeOwner->minRating << ";"
                  << mem->BikeOwner->BikeStatus << "\n";
    }
    writeFile.close();
}

void System::outputMemberToFile() {
    std::ofstream writeFile{MEMBERS_FILE};
    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << MEMBERS_FILE << "\n";
        return;
    }


    for (auto &mem: memberVector) {
        writeFile << mem->memberId << ";"
                  << mem->fullName << ";"
                  << mem->phoneNum << ";"
                  << mem->username << ";"
                  << mem->password << ";"
                  << mem->location << ";"
                  << mem->credit << ";"
                  << mem->score << "\n";
    }

    writeFile.close();
}

void System::outputBikeToFile() {
    std::ofstream writeFile{Bike_FILE};
    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << Bike_FILE << "\n";
        return;
    }
    for (Bike *Bike: BikeVector) {
        writeFile << Bike->BikeID << ";"
                  << Bike->owner->memberId << ";"
                  << Bike->location << ";"
                  << Bike->BikeDescription << ";"
                  << Bike->BikeScores << "\n";
    }
    writeFile.close();


}


bool System::loginMember(std::string username, std::string password) {
    int count = 0;
    for (Member *mem: memberVector) {
        if (mem->username == username && mem->password == password) {
            currentUser = mem;
            for (std::string loc: LOCATIONS) {
                if (loc == currentUser->location) {
                    count++;
                    break;
                }
            }
            if (count == 0) {
                std::cout << RED <<"The app do not support you in your region! \n" << RESET;
                mainMenu();
                return false;
            }
            std::cout << GREEN << "Log in successfully!!! \n\n" << RESET;
            return true;
        }
    }
    std::cout << RED << "\n\nWrong username or password!!! \n" << RESET;
    return false;
}

void System::registerMember() {
    int choice;
    int subChoice;
    std::string username, password, fullname, phoneNum, location;
    std::cout << GREEN << "\t---MEMBER REGISTRATION---\n" << RESET;
    std::cin.ignore();
    do {
        std::cout << CYAN<< "Enter your username: " << RESET;
        getline(std::cin, username);
    } while (!isValidUserName(username));

    do {
        std::cout << CYAN << "Enter your password: " << RESET;
        getline(std::cin, password);
    } while (!isValidPassword(password));

    do {
        std::cout << CYAN << "Enter your fullname: " << RESET;
        getline(std::cin, fullname);
    } while (!isValidFullname(fullname));

    do {
        std::cout << CYAN <<"Enter your phone number: " << RESET;
        getline(std::cin, phoneNum);
    } while (!isValidPhoneNum(phoneNum));


    std::cout <<CYAN << "1. Choose the locations the app support \n" << RESET;
    std::cout << CYAN << "2. Enter the location yourself \n" << RESET;
    choice = menuChoice(1, 2);
    switch (choice) {
        case 1:
            std::cout << CYAN <<"Choose the following locations: \n" << RESET;
            std::cout << GREEN <<"1.HANOI\t2.SAIGON\n" << RESET;
            subChoice = menuChoice(1, 2);
            switch (subChoice) {
                case 1:
                    location = LOCATIONS[0];
                    break;
                case 2:
                    location = LOCATIONS[1];
                    break;
            }
            break;
        case 2:
            std::cin.ignore();
            std::cout << CYAN <<"Enter your location: " << RESET;
            getline(std::cin, location);
            break;
    }
    Member *newMem = new Member(username, password, "MEM" + std::to_string(memberVector.size() + 1), fullname,
                                phoneNum,
                                INITIAL_CREDITS, INITIAL_SCORES, location);
    memberVector.push_back(newMem);
    std::cout << GREEN << "You have registered successfully!\n" << RESET;
    mainMenu();
}

Date *System::stringToDate(std::string &date) {
    std::vector<std::string> dataLst = splitStr(date, '/');
    Date *convertedDate = new Date(std::stoi(dataLst[0]), std::stoi(dataLst[1]), std::stoi(dataLst[2]));
    return convertedDate;

}