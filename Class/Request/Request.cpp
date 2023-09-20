#include "Request.h"


Request::Request(Date *startDate, Date *endDate, Member *requestedByMember, std::string BikeId, std::string status) {


    //Note: need a function from system to get id of request

    this->startDate = startDate;
    this->endDate = endDate;
    this->requestedByMember = requestedByMember;
    this->requestStatus = status;
    this->BikeID = BikeId;
}