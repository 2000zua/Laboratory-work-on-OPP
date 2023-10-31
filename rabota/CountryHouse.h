#include <iostream>

using namespace std;

class CountryHouse :public Property
{
protected:
    double distanceFromCity; // distancia da cidade
public:
    CountryHouse(double _worth, double _distance);

    double calculatePropertyTax() override{
        if (distanceFromCity < TAX_RATES::LIMIT_DISTANCE_FROM_CITY)
        {
            return Property::worth*TAX_RATES::LOW_COUNTRY_HOUSE_TAX;
        }
        else
        {
            return Property::worth*TAX_RATES::HIGHT_COUNTRY_HOUSE_TAX;
        }
    }
    void fromJson(const json& jsonObject) override {
        Property::fromJson(jsonObject);
        distanceFromCity = jsonObject["distanceFromCity"];
    }

    json toJson() const override {
        json propertyJson = Property::toJson();
        propertyJson["distanceFromCity"] = distanceFromCity;
        return propertyJson;
    }

    void setDistanceFromCity(double _distance);

    double getDistanceFromCity();
};

CountryHouse::CountryHouse(double _worth, double _distance) : Property(_worth){
    setDistanceFromCity(_distance);
};

void CountryHouse::setDistanceFromCity(double _distance){
    this->distanceFromCity = _distance;
};

double CountryHouse::getDistanceFromCity(){
    return this->distanceFromCity;
};

