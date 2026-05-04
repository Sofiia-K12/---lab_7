#pragma once

#include <stdexcept>



class FlightSystem {
public:
    int BookFlight();
};

class CheckInSystem {
public:
    int DoCheckIn();
};

class BaggageSystem {
public:
    int AddBaggage(int weight);
};

class SecuritySystem {
public:
    int SecurityCheck();
};


class AirportFacade {
private:
    FlightSystem flightSystem;
    CheckInSystem checkInSystem;
    BaggageSystem baggageSystem;
    SecuritySystem securitySystem;

public:
    int FullTrip(int baggageWeight);
    int QuickTrip();
};