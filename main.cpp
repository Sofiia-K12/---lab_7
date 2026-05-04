#include <iostream>
#include "patterns.h"

using namespace std;

int main() {

    AirportFacade facade;

    int price1 = facade.FullTrip(25);
    cout << "Full trip price: " << price1 << endl;

    int price2 = facade.QuickTrip();
    cout << "Quick trip price: " << price2 << endl;

    return 0;
}