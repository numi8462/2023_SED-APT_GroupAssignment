#ifndef CUSTOMER_B
#define CUSTOMER_B
class Date;
class Bike;

class Customer {
    Date *startFromDate;
    Date *ToDate;
    Bike *RentedBike;

public:
   Customer(Date *RentedFromDate, Date *RentedToDate, Bike *RentedBike);

    friend class Member;

    friend class Bike;

    friend class System;


};
#endif //CUSTOMER_B