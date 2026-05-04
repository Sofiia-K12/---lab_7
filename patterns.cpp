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



int AirportFacade::FullTrip(int baggageWeight) {

    int flightPrice = flightSystem.BookFlight();
    int checkInPrice = checkInSystem.DoCheckIn();
    int baggagePrice = baggageSystem.AddBaggage(baggageWeight);
    int securityPrice = securitySystem.SecurityCheck();

    return flightPrice + checkInPrice + baggagePrice + securityPrice;
}

int AirportFacade::QuickTrip() {
    return flightSystem.BookFlight();
}