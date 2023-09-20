#ifndef RENTEDBIKE_B
#define RENTEDBIKE_B

class Date;

class Member;

class RentedBike {
private:
    Date *startFromDate;
    Date *toDate;
    Member *Customer;
public:
    RentedBike(Date *startFromDate, Date *toDate, Member *Customer);

    friend class System;

    friend class Bike;

    friend class Member;

};
#endif //RENTEDBIKE_B