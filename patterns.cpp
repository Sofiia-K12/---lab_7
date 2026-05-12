#include "patterns.h"

int FlightSystem::BookFlight() {
    return 300;
}

int CheckInSystem::DoCheckIn() {
    return 50;
}

int BaggageSystem::AddBaggage(int weight) {

    if (weight > 30)
        return 40;

    return 20;
}

int SecuritySystem::SecurityCheck() {
    return 25;
}


AirportFacade::AirportFacade() {

    flight = new FlightSystem();
    checkin = new CheckInSystem();
    baggage = new BaggageSystem();
    security = new SecuritySystem();
}


int AirportFacade::FullTrip(int baggageWeight) {

    int total = 0;

    total += flight->BookFlight();

    total += checkin->DoCheckIn();

    total += baggage->AddBaggage(baggageWeight);

    total += security->SecurityCheck();

    return total;
}

AirportFacade::~AirportFacade() {
    delete flight;
    delete checkin;
    delete baggage;
    delete security;
}


int AirportFacade::QuickTrip() {

    return flight->BookFlight();
}

Client::Client(IAirportFacade* facade) {

    this->facade = facade;
}

void Client::Start() {

    cout << "Full trip: "
         << facade->FullTrip(25)
         << endl;

    cout << "Quick trip: "
         << facade->QuickTrip()
         << endl;
}