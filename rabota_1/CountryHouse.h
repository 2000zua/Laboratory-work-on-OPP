#include <iostream>

using namespace std;

class CountryHouse : Property
{
private:
    double distanceFromCity; // distancia da cidade
public:
    CountryHouse(double worth, double distance) : Property(worth), distanceFromCity(distance){}

    double calculatePropertyTax() const override{
        if (distanceFromCity < TAX_RATES::LIMIT_DISTANCE_FROM_CITY)
        {
            return Property::worth*TAX_RATES::LOW_COUNTRY_HOUSE_TAX;
        }
        else
        {
            return Property::worth*TAX_RATES::HIGHT_COUNTRY_HOUSE_TAX;
        }
        
    }
};

