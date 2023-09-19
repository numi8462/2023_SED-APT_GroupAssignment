#ifndef USER
#define USER



//#include "../../System/System.h"


#include <iostream>

class System;

class User {
protected:
    std::string lonThien;
    std::string username;
    std::string password;

public:
    User(std::string username, std::string password);

    friend class System;

};


#endif 