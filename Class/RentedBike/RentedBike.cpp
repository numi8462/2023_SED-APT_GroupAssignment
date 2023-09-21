#include "RentedBike.h"
RentedBike::RentedBike(Date *startFromDate, Date *toDate, Member *Customer) {
    this->startFromDate = startFromDate;
    this->toDate = toDate;
    this->Customer = Customer;
}