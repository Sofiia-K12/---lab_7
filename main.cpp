#include "patterns.h"

int main() {

    IAirportFacade* facade =
        new AirportFacade();

    Client client(facade);

    client.Start();

    return 0;
}