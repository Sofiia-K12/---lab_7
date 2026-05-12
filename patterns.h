#pragma once
#include <iostream>

using namespace std;

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

class IAirportFacade {
public:
    virtual int FullTrip(int baggageWeight) = 0;
    virtual int QuickTrip() = 0;
};

class AirportFacade : public IAirportFacade {
private:
    FlightSystem* flight;
    CheckInSystem* checkin;
    BaggageSystem* baggage;
    SecuritySystem* security;

public:
    AirportFacade();

    ~AirportFacade();   

    int FullTrip(int baggageWeight) override;

    int QuickTrip() override;
};

class Client {
private:
    IAirportFacade* facade;

public:
    Client(IAirportFacade* facade);

    void Start();
};