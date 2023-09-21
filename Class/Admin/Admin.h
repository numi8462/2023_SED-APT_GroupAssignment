#ifndef ADMIN_B
#define ADMIN_B

#endif //ADMIN_B
#include <iostream>
#include "../User/User.h"


class Admin : public User {
public:
    Admin(std::string username, std::string password);

    friend class System;

    friend class Bike;
};