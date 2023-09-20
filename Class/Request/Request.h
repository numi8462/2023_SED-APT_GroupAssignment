#ifndef REQUEST_B
#define REQUEST_B
#include <iostream>
#include "../Date/Date.h"
//#include "../Member/Member.h"

class Date;
class Member;

class Request {
    std::string BikeID;
    std::string requestStatus;
    Date* startDate;
    Date* endDate;
    Member* requestedByMember;

public:

    Request(Date *startDate, Date *endDate, Member *requestedByMember, std::string BikeId, std::string status);


    friend class System;

    friend class Member;


};

#endif