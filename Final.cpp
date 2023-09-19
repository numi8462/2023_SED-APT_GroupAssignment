#include <iostream>
#include <vector>
#include <string>

class PersonalInfo {
public:
    PersonalInfo(std::string fullName, std::string phoneNumber, std::string idType, std::string idNumber,
                 std::string licenseNumber, std::string licenseExpiryDate)
        : fullName(fullName), phoneNumber(phoneNumber), idType(idType), idNumber(idNumber),
          licenseNumber(licenseNumber), licenseExpiryDate(licenseExpiryDate), creditPoints(20), rating(10) {}

    void DisplayInfo() const {
        std::cout << "Full Name: " << fullName << std::endl;
        std::cout << "Phone Number: " << phoneNumber << std::endl;
        std::cout << "ID Type: " << idType << std::endl;
        std::cout << "ID Number: " << idNumber << std::endl;
        std::cout << "License Number: " << licenseNumber << std::endl;
        std::cout << "License Expiry Date: " << licenseExpiryDate << std::endl;
        std::cout << "Credit Points: " << creditPoints << std::endl; // Display credit points
    }

    int GetCreditPoints() const {
        return creditPoints;
    }

    int GetRating() const {
        return rating;
    }

    void SetRating(int newRating) {
        rating = newRating;
    }

    bool DeductCreditPoints(int points) {
        if (creditPoints >= points) {
            creditPoints -= points;
            return true;
        }
        return false;
    }

private:
    std::string fullName;
    std::string phoneNumber;
    std::string idType;
    std::string idNumber;
    std::string licenseNumber;
    std::string licenseExpiryDate;
    int creditPoints;
    int rating;
};

class Motorbike {
public:
    Motorbike(std::string model, int creditPoints, int renterRating, std::string style, std::string color,
              std::string engineSize, std::string gearbox)
        : model(model), creditPoints(creditPoints), renterRating(renterRating), style(style), color(color),
          engineSize(engineSize), gearbox(gearbox), isRented(false) {}

    std::string GetModel() const { return model; }

    int GetCreditPoints() const { return creditPoints; }

    int GetRenterRating() const { return renterRating; }

    bool IsRented() const { return isRented; }

    void SetRented(bool rented) { isRented = rented; }

    void DisplayInfo(bool showRating) const {
        std::cout << "Motorbike Information: " << model << std::endl;
        std::cout << "Required Credit Points: " << creditPoints << std::endl;
        if (showRating) {
            std::cout << "Minimum Renter Rating: " << renterRating << std::endl;
        }
        std::cout << "Style: " << style << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "Engine Size: " << engineSize << std::endl;
        std::cout << "Gearbox: " << gearbox << std::endl;
    }

    void SetRenterRating(int newRating) {
        renterRating = newRating;
    }

private:
    std::string model;
    int creditPoints;
    int renterRating;
    std::string style;
    std::string color;
    std::string engineSize;
    std::string gearbox;
    bool isRented;
};

class Member {
public:
    Member(std::string username, std::string password, PersonalInfo info)
        : username(username), password(password), personalInfo(info), hasRented(false) {}

    std::string GetUsername() const { return username; }

    bool Login(std::string inputUsername, std::string inputPassword) const {
        return (inputUsername == username && inputPassword == password);
    }

    void ViewPersonalInfo() const {
        std::cout << "Personal Information of " << username << ":" << std::endl;
        personalInfo.DisplayInfo();
        std::cout << "Rating: " << personalInfo.GetRating() << std::endl;
    }

    int GetCreditPoints() const { return personalInfo.GetCreditPoints(); }

    void RateMember(int newRating) {
        personalInfo.SetRating(newRating);
    }

    bool HasRentedMotorbike() const {
        return hasRented;
    }

    bool RentMotorbike(Motorbike& motorbike) {
        if (!hasRented && motorbike.GetCreditPoints() <= personalInfo.GetCreditPoints() &&
            personalInfo.GetRating() >= motorbike.GetRenterRating()) {
            if (personalInfo.DeductCreditPoints(motorbike.GetCreditPoints())) {
                hasRented = true;
                motorbike.SetRented(true);
                return true;
            }
        }
        return false;
    }

    bool ReturnMotorbike(Motorbike& motorbike) {
        if (hasRented) {
            hasRented = false;
            motorbike.SetRented(false);
            return true;
        }
        return false;
    }

private:
    std::string username;
    std::string password;
    PersonalInfo personalInfo;
    bool hasRented;
};

// Function to display the selection menu
void DisplayMenu() {
    std::cout << "----- MENU -----" << std::endl;
    std::cout << "1. View Detailed Motorbike Information" << std::endl;
    std::cout << "2. Log in and View Personal Information" << std::endl;
    std::cout << "3. Register as a Member" << std::endl;
    std::cout << "4. Rate User (Admin)" << std::endl;
    std::cout << "5. View Motorbike List and Ratings" << std::endl;
    std::cout << "6. Rent a Motorbike (Members only, by Motorbike ID)" << std::endl;
    std::cout << "7. Return a Motorbike (Members only, by Rented Motorbike ID)" << std::endl;
     std::cout << "8. Admin Login" << std::endl;  
    std::cout << "9. Exit" << std::endl;         
    std::cout << "----------------" << std::endl;
    std::cout << "Select an option (1/2/3/4/5/6/7/8/9): ";
}

// Function to display the list of motorbikes and their ratings
void DisplayMotorbikeList(const std::vector<Motorbike>& motorbikes) {
    std::cout << "List of Motorbikes and Ratings:" << std::endl;
    for (int i = 0; i < motorbikes.size(); ++i) {
        const Motorbike& motorbike = motorbikes[i];
        std::cout << "ID: " << i << std::endl;
        motorbike.DisplayInfo(true); // Display ratings
        std::cout << "Rental Status: " << (motorbike.IsRented() ? "Rented" : "Available") << std::endl;
        std::cout << std::endl;
    }
}

// Function to display detailed information about motorbikes
void DisplayMotorbikeInfo(const std::vector<Motorbike>& motorbikes, bool isLoggedIn) {
    std::cout << "Detailed Motorbike Information:" << std::endl;
    for (int i = 0; i < motorbikes.size(); ++i) {
        const Motorbike& motorbike = motorbikes[i];
        std::cout << "ID: " << i << std::endl;
        motorbike.DisplayInfo(isLoggedIn); // Hide ratings if not logged in
        std::cout << std::endl;
    }
}

int main() {
    std::vector<Member> members;
    std::vector<Motorbike> motorbikes;

    // Register members and add personal information
    PersonalInfo info1("John Doe", "1234567890", "ID Card", "123456789", "AB12345", "30/12/2025");
    Member member1("user1", "pass1", info1);
    members.push_back(member1);

    PersonalInfo info2("Jane Smith", "0987654321", "ID Card", "987654321", "CD67890", "25/06/2024");
    Member member2("user2", "pass2", info2);
    members.push_back(member2);

    // Add information about motorbikes
    motorbikes.push_back(Motorbike("Motorbike A", 20, 7, "Scooter", "Black", "150cc", "Automatic"));
    motorbikes.push_back(Motorbike("Motorbike B", 10, 8, "Sport", "Blue", "200cc", "Manual"));
    motorbikes.push_back(Motorbike("Motorbike C", 15, 6, "Cruiser", "Red", "250cc", "Manual"));
    motorbikes.push_back(Motorbike("Motorbike D", 18, 7, "Touring", "Silver", "180cc", "Automatic"));
    motorbikes.push_back(Motorbike("Motorbike E", 12, 9, "Sport", "Yellow", "250cc", "Manual"));
    motorbikes.push_back(Motorbike("Motorbike F", 22, 7, "Cruiser", "Black", "200cc", "Manual"));
    motorbikes.push_back(Motorbike("Motorbike G", 17, 8, "Scooter", "White", "150cc", "Automatic"));
    motorbikes.push_back(Motorbike("Motorbike H", 14, 7, "Sport", "Green", "200cc", "Manual"));
    motorbikes.push_back(Motorbike("Motorbike I", 19, 8, "Touring", "Blue", "180cc", "Automatic"));
    motorbikes.push_back(Motorbike("Motorbike J", 16, 6, "Cruiser", "Orange", "250cc", "Manual"));


    while (true) {
        DisplayMenu();
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Do you want to log in to view detailed motorbike information? (Y/N): ";
            char loginChoice;
            std::cin >> loginChoice;

            bool isLoggedIn = false;
            std::string inputUsername, inputPassword;

            if (loginChoice == 'Y' || loginChoice == 'y') {
                if (!members.empty()) {
                    std::cout << "Log in:" << std::endl;
                    std::cout << "Enter username: ";
                    std::cin >> inputUsername;
                    std::cout << "Enter password: ";
                    std::cin >> inputPassword;

                    for (const auto& member : members) {
                        if (member.Login(inputUsername, inputPassword)) {
                            isLoggedIn = true;
                            break;
                        }
                    }
                }
            }

            DisplayMotorbikeInfo(motorbikes, isLoggedIn);
        } else if (choice == 2) {
            // Function 2: Log in and view personal information (for members only)
            if (members.empty()) {
                std::cout << "No members have been registered yet. Please register first." << std::endl;
            } else {
                std::string inputUsername, inputPassword;
                std::cout << "Log in:" << std::endl;
                std::cout << "Enter username: ";
                std::cin >> inputUsername;
                std::cout << "Enter password: ";
                std::cin >> inputPassword;

                bool loggedIn = false;
                Member* loggedInMember = nullptr;
                for (auto& member : members) {
                    if (member.Login(inputUsername, inputPassword)) {
                        loggedIn = true;
                        loggedInMember = &member;
                        break;
                    }
                }

                if (loggedIn) {
                    std::cout << "Logged in successfully!" << std::endl;
                    loggedInMember->ViewPersonalInfo();
                } else {
                    std::cout << "Incorrect username or password. Login failed." << std::endl;
                }
            }
        } else if (choice == 3) {
            // Function 3: Register as a member
            std::string username, password;
            std::cout << "Register as a member:" << std::endl;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;

            bool usernameTaken = false;
            for (const auto& member : members) {
                if (member.GetUsername() == username) {
                    usernameTaken = true;
                    break;
                }
            }

            if (!usernameTaken) {
                PersonalInfo newMemberInfo("", "", "", "", "", ""); // Initially empty personal information
                Member newMember(username, password, newMemberInfo);
                members.push_back(newMember);
                std::cout << "Member registration successful!" << std::endl;
            } else {
                std::cout << "Username already exists. Registration failed." << std::endl;
            }
        } else if (choice == 4) {
            // Function 4: Rate a user (Admin)
            std::string adminUsername = "admin";
            std::string adminPassword = "adminpass";
            std::string inputUsername, inputPassword;

            std::cout << "Log in as Admin:" << std::endl;
            std::cout << "Enter username: ";
            std::cin >> inputUsername;
            std::cout << "Enter password: ";
            std::cin >> inputPassword;

            if (inputUsername == adminUsername && inputPassword == adminPassword) {
                std::cout << "Logged in successfully as Admin!" << std::endl;
                
                // Display a list of all members and allow rating
                for (auto& member : members) {
                    std::string username;
                    int newRating;
                    std::cout << "Enter a new rating for member " << member.GetUsername() << ": ";
                    std::cin >> newRating;
                    
                    // Rate the member
                    member.RateMember(newRating);
                    std::cout << "Rating successful!" << std::endl;
                }
            } else {
                std::cout << "Incorrect username or password. Login failed." << std::endl;
            }
        } else if (choice == 5) {
            // Function 5: View the list of motorbikes and their ratings
            DisplayMotorbikeList(motorbikes);
        } else if (choice == 6) {
            // Function 6: Rent a motorbike (Members only, by Motorbike ID)
            if (members.empty()) {
                std::cout << "No members have been registered yet. Please register first." << std::endl;
            } else {
                std::string inputUsername, inputPassword;
                std::cout << "Log in to rent a motorbike:" << std::endl;
                std::cout << "Enter username: ";
                std::cin >> inputUsername;
                std::cout << "Enter password: ";
                std::cin >> inputPassword;

                bool loggedIn = false;
                Member* loggedInMember = nullptr;
                for (auto& member : members) {
                    if (member.Login(inputUsername, inputPassword)) {
                        loggedIn = true;
                        loggedInMember = &member;
                        break;
                    }
                }

                if (loggedIn) {
                    DisplayMotorbikeList(motorbikes);
                    int motorbikeID;
                    std::cout << "Enter the ID of the motorbike you want to rent: ";
                    std::cin >> motorbikeID;

                    if (motorbikeID >= 0 && motorbikeID < motorbikes.size()) {
                        Motorbike& selectedMotorbike = motorbikes[motorbikeID];
                        if (selectedMotorbike.IsRented()) {
                            std::cout << "The motorbike is already rented. Rental failed." << std::endl;
                        } else {
                            if (loggedInMember->RentMotorbike(selectedMotorbike)) {
                                std::cout << "Motorbike rental successful!" << std::endl;
                            } else {
                                std::cout << "You don't have enough credit points or the renter rating is insufficient to rent this motorbike." << std::endl;
                            }
                        }
                    } else {
                        std::cout << "Invalid motorbike ID. Rental failed." << std::endl;
                    }
                } else {
                    std::cout << "Incorrect username or password. Login failed." << std::endl;
                }
            }
        } else if (choice == 7) {
            // Function 7: Return a motorbike (Members only, by Rented Motorbike ID)
            if (members.empty()) {
                std::cout << "No members have been registered yet. Please register first." << std::endl;
            } else {
                std::string inputUsername, inputPassword;
                std::cout << "Log in to return a motorbike:" << std::endl;
                std::cout << "Enter username: ";
                std::cin >> inputUsername;
                std::cout << "Enter password: ";
                std::cin >> inputPassword;

                bool loggedIn = false;
                Member* loggedInMember = nullptr;
                for (auto& member : members) {
                    if (member.Login(inputUsername, inputPassword)) {
                        loggedIn = true;
                        loggedInMember = &member;
                        break;
                    }
                }

                if (loggedIn) {
                    if (loggedInMember->HasRentedMotorbike()) {
                        for (auto& motorbike : motorbikes) {
                            if (motorbike.IsRented() && motorbike.GetModel() == loggedInMember->GetUsername()) {
                                loggedInMember->ReturnMotorbike(motorbike);
                                std::cout << "Motorbike return successful!" << std::endl;
                                break;
                            }
                        }
                    } else {
                        std::cout << "You have not rented any motorbike to return." << std::endl;
                    }
                } else {
                    std::cout << "Incorrect username or password. Login failed." << std::endl;
                }
            }
        } else if (choice == 8) {
            // Function 8: Exit
            std::string inputUsername, inputPassword;
            std::cout << "Admin Login:" << std::endl;
            std::cout << "Enter username: ";
            std::cin >> inputUsername;
            std::cout << "Enter password: ";
            std::cin >> inputPassword;

            if (inputUsername == "admin" && inputPassword == "adminpass") {
                std::cout << "Logged in successfully as Admin!" << std::endl;
                // Add code here to display information about all members and motorbikes
                // Loop through the members and motorbikes vectors and display their details
                std::cout << "Members Information:" << std::endl;
                for (const auto& member : members) {
                    member.ViewPersonalInfo();
                    std::cout << "----------------" << std::endl;
                }

                std::cout << "Motorbikes Information:" << std::endl;
                for (const auto& motorbike : motorbikes) {
                    motorbike.DisplayInfo(true); // Display ratings
                    std::cout << "----------------" << std::endl;
                }
            } else {
                std::cout << "Incorrect username or password. Login failed." << std::endl;
            }
        } else if (choice == 9) {
            // Function 9: Exit
            std::cout << "Thank you for using the application!" << std::endl;
            break;
        } else {
            std::cout << "Invalid option. Please select again." << std::endl;
        }
    }

    return 0;
}
