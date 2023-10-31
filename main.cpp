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

    while (true)
    {
       startScream()
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            string fullName;
            int inn;
            cout << "Enter owner's full name: ";
            cin.ignore();
            getline(cin, fullName);
            cout << "Enter owner's INN: ";
            cin >> inn;
            owners.push_back(Owner(fullName, inn));
            break;
        } else if (choice == 2) {
            int inn;
            cout << "Enter INN of the owner to remove: ";
            cin >> inn;
            for (auto it = owners.begin(); it != owners.end(); ++it) {
                if (it->getINN() == inn) {
                    owners.erase(it);
                    break;
                }
            }
            break;
        } else if (choice == 3) {
            int inn;
            cout << "Enter INN of the owner to add property to: ";
            cin >> inn;
            for (Owner& owner : owners) {
                if (owner.getINN() == inn) {
                    cout << "Select property type:\n1. Apartment\n2. Car\n3. Country House\n";
                    int propertyChoice;
                    cin >> propertyChoice;

                    double worth;
                    if (propertyChoice == 1) {
                        double square;
                        cout << "Enter property worth: ";
                        cin >> worth;
                        cout << "Enter apartment square: ";
                        cin >> square;
                        owner.addProperty(new Apartment(worth, square));
                        break;
                    } else if (propertyChoice == 2) {
                        double horsepower;
                        cout << "Enter property worth: ";
                        cin >> worth;
                        cout << "Enter car horsepower: ";
                        cin >> horsepower;
                        owner.addProperty(new Car(worth, horsepower));
                        break;
                    } else if (propertyChoice == 3) {
                        double distanceFromCity;
                        cout << "Enter property worth: ";
                        cin >> worth;
                        cout << "Enter country house distance from the city: ";
                        cin >> distanceFromCity;
                        owner.addProperty(new CountryHouse(worth, distanceFromCity));
                    }
                }
            }
            break;
        } else if (choice == 4) {
            int inn;
            cout << "Enter INN of the owner to remove property from: ";
            cin >> inn;
            for (Owner& owner : owners) {
                if (owner.getINN() == inn) {
                    cout << "Select property to remove:\n";
                    for (size_t i = 0; i < owner.properties.size(); ++i) {
                        cout << i + 1 << ". Property " << i + 1 << std::endl;
                    }
                    int propertyChoice;
                    cin >> propertyChoice;
                    if (propertyChoice >= 1 && propertyChoice <= owner.properties.size()) {
                        owner.removeProperty(owner.properties[propertyChoice - 1]);
                    }
                }
            }
            break;
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
        break;
    }


    for (const Owner& owner : owners) {
        double totalPropertyTax = owner.calculateTotalPropertyTax();
        cout << "Owner: " << owner.getFullName() << " (INN: " << owner.getINN() << ")";
        cout << " Total Property Tax: $" << totalPropertyTax << std::endl;
    }

    std::string inputFileName, outputFileName;
    std::cout << "Введите имя входного JSON-файла: ";
    std::cin >> inputFileName;
    std::cout << "Введите имя выходного JSON-файла: ";
    std::cin >> outputFileName;

    // Загрузка JSON-данных из входного файла
    json inputJson;
    std::ifstream inputFile(inputFileName);
    inputFile >> inputJson;
    inputFile.close();

    // Создание и заполнение объекта Owner из входного JSON
    Owner owner("Default Name", "000000000000");
    owner.fromJson(inputJson);

    // Расчет общего налога на имущество
    double totalPropertyTax = owner.calculateTotalPropertyTax();

    // Создание JSON-объекта для хранения результатов
    json outputJson = owner.toJson();
    outputJson["total_property_tax"] = totalPropertyTax;

    // Запись результатов в выходной JSON-файл
    std::ofstream outputFile(outputFileName);
    outputFile << outputJson.dump(2);
    outputFile.close();

    std::cout << "Результаты сохранены в файл " << outputFileName << std::endl;


    
    return 0;
}


