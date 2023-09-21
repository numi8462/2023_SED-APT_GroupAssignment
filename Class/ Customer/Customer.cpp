#include "Customer.h"
Customer::Customer(Date *occupyFromDate, Date *occupyToDate, House *occupyHouse) {
    this->startFromDate = occupyFromDate;
    this->ToDate = occupyToDate;
    this->occupyHouse = occupyHouse;
}