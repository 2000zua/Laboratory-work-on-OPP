#include <iostream>
#include <string>
#include <vector>
#include "Property2.h"

using namespace std;

class Owner
{

public:
    string fullName;
    int INN;
    vector<Property&> properties;
    Owner(string fullname, int inn) : fullName(fullname), INN(inn){}

    // add uma propriedade
    void addProperty(Property& property){
        properties.push_back(property);
    }

    // metodo para apagar
    bool removeProperty(Property& property){
        // usando um interador para achar a propriedade a ser removida
        for (auto i = properties.begin(); i != properties.end(); ++i)
        {
            if (*i == property)
            {
                try
                {
                    delete *i; // liberando da memoria e depois eliminar
                    properties.erase(i);
                    break;
                    return true;
                }
                catch(const std::exception& e)
                {
                    return false;
                }
                
            }
            else
            {
                return false;
            }
            
        }
        
    }

    // metodo para calcular o imposto total
    double calculateTotalPropertyTax() const {
        double totalTax =0;
        for (const Property& property : properties)
        {
            totalTax += property->calculatePropertyTax();
        }
        return totalTax;
    }

    //mostrar todas as propriedades do proprietario
    void showAllProperties() const {
        cout << "Properties of "<< this->fullName <<"[INN{"<<INN<<"}]: " <<endl;
        for (Property& property : properties)
        {
            cout << "- Worth: $" <<property->getWorth() << endl;
        }
        
    }

    ~Owner(){
        for (Property& property:properties)
        {
            delete property;
        }
        
    }

};
