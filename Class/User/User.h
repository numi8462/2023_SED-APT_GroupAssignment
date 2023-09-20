#ifndef USER_B
#define USER_B



//#include "../../System/System.h"


#include <iostream>

class System;

class User {
protected:
    std::string username;
    std::string password;

public:
    User(std::string username, std::string password);

    friend class System;

};
