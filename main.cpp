#include <iostream>
#include <vector>
#include <string>
#include "rabota/Apartment.h"
#include "rabota/Car.h"
#include "rabota/CountryHouse.h"
#include "rabota/Owner.h"

using namespace std;

void startScream(){
    cout <<"======================== START THE PROGRAMM  =========================="<<endl;
    cout <<"======== MENU ==========: "<<endl;
    cout <<"1. Add owner: "<<endl;
    cout <<"2. Remove owner: "<<endl;
    cout <<"3. Add property: "<<endl;
    cout <<"4. Remove property: "<<endl;
    cout <<"5. Exist: "<<endl;
    cout <<"Select the option: ";
}

int main()
{
    vector<Owner> owners;

    Owner owner1("Angelo Abreu Zua", 458);
    Owner owner2("Michael Jackson", 643);
    Owner owner3("Nelsom Mandela", 243);

    Apartment apartment1(190, 80.0);
    Apartment apartment2(250, 110.0);

    Car car1(320, 85.0);
    Car car2(430, 110.0);

    CountryHouse house1(900, 50.0);
    CountryHouse house2(1000, 90.0);

    owner1.addProperty(&apartment1);
    owner1.addProperty(&car1);
    owner1.addProperty(&house1);

    owner2.addProperty(&apartment2);
    owner2.addProperty(&car2);
    owner2.addProperty(&house2);

    owner3.addProperty(&apartment2);


    owners.push_back(owner1);
    owners.push_back(owner2);
    owners.push_back(owner3);


    
    return 0;
}


