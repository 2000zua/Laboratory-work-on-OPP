#include <iostream>
#include "rabota_1/Apartment.h"
#include "rabota_1/Car.h"
#include "rabota_1/CountryHouse.h"

using namespace std;

int main()
{
    Apartment apartment(100000,80);
    Car car(30000,150);
    CountryHouse house(300000, 50);

    cout <<"Apartment property tax: $" << apartment.calculatePropertyTax() <<endl;
    cout <<"Car property tax: $" << car.calculatePropertyTax() <<endl;
    cout <<"House property tax: $" << house.calculatePropertyTax() <<endl;
    return 0;
}
