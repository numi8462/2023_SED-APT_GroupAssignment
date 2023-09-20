#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Function to save member and motorbike information to files
void SaveDataToFile(const std::vector<Member>& members, const std::vector<Motorbike>& motorbikes) {
    std::ofstream memberFile("members.txt");
    std::ofstream motorbikeFile("motorbikes.txt");

    if (memberFile.is_open() && motorbikeFile.is_open()) {
        // Save member data
        for (const auto& member : members) {
            memberFile << member.GetUsername() << " " << member.GetCreditPoints() << " " << member.GetRating() << std::endl;
        }

        // Save motorbike data
        for (const auto& motorbike : motorbikes) {
            motorbikeFile << motorbike.GetModel() << " " << motorbike.GetCreditPoints() << " " << motorbike.GetRenterRating() << " " << (motorbike.IsRented() ? "1" : "0") << std::endl;
        }

        memberFile.close();
        motorbikeFile.close();
    } else {
        std::cerr << "Error: Unable to open data files for writing." << std::endl;
    }
}

// Function to load member and motorbike information from files
void LoadDataFromFile(std::vector<Member>& members, std::vector<Motorbike>& motorbikes) {
    std::ifstream memberFile("members.txt");
    std::ifstream motorbikeFile("motorbikes.txt");

    if (memberFile.is_open() && motorbikeFile.is_open()) {
        // Clear existing data
        members.clear();
        motorbikes.clear();

        // Load member data
        std::string username;
        int creditPoints, rating;
        while (memberFile >> username >> creditPoints >> rating) {
            PersonalInfo info("", "", "", "", "", ""); // Initially empty personal information
            Member member(username, "", info); // Password is not loaded from the file
            member.SetCreditPoints(creditPoints);
            member.SetRating(rating);
            members.push_back(member);
        }

        // Load motorbike data
        std::string model;
        int motorbikeCreditPoints, renterRating;
        int isRented;
        while (motorbikeFile >> model >> motorbikeCreditPoints >> renterRating >> isRented) {
            bool rented = (isRented == 1);
            Motorbike motorbike(model, motorbikeCreditPoints, renterRating, "", "", "", "");
            motorbike.SetRented(rented);
            motorbikes.push_back(motorbike);
        }

        memberFile.close();
        motorbikeFile.close();
    } else {
        std::cerr << "Error: Unable to open data files for reading." << std::endl;
    }
}