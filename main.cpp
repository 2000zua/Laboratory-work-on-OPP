#include <iostream>
#include "rabota_2/Apartment2.h"
#include "rabota_2/Car2.h"
#include "rabota_2/CountryHouse2.h"
#include "rabota_2/Owner.h"

using namespace std;

int main()
{
    Owner owner("Angelo Abreu Zua", 123654789);

    Property* apartment = new Apartment(100000, 80);
    Property*  car = new Car(30000, 150);
    Property*  house =new CountryHouse(300000, 50);

    owner.addProperty(apartment);
    owner.addProperty(car);
    owner.addProperty(house);

    owner.showAllProperties();

    return 0;
}
