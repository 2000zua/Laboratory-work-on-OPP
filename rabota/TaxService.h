class TaxService {
public:
    static void loadJsonData(const std::string& fileName, std::vector<Owner>& owners) {
        // Реализуйте загрузку данных из JSON-файла
    }

    static void saveJsonData(const std::string& fileName, const std::vector<Owner>& owners) {
        // Реализуйте сохранение данных в JSON-файл
    }

    static void loadXmlData(const std::string& fileName, std::vector<Owner>& owners) {
        // Реализуйте загрузку данных из XML-файла
    }

    static void saveXmlData(const std::string& fileName, const std::vector<Owner>& owners) {
        // Реализуйте сохранение данных в XML-файл
    }
    static void calculateTaxes(const std::string& inputFileName, const std::string& outputFileName) {
        // Загрузка JSON-данных из входного файла
        json inputJson;
        std::ifstream inputFile(inputFileName);
        inputFile >> inputJson;
        inputFile.close();

        // Создание объектов Owner из входного JSON
        std::vector<Owner> owners;
        for (const auto& ownerJson : inputJson) {
            Owner owner("Default Name", "000000000000");
            owner.fromJson(ownerJson);
            owners.push_back(owner);
        }

        // Расчет общего налога на имущество для каждого собственника
        json outputJson = json::array();
        for (const Owner& owner : owners) {
            double totalPropertyTax = owner.calculateTotalPropertyTax();
            json ownerJson = owner.toJson();
            ownerJson["total_property_tax"] = totalPropertyTax;
            outputJson.push_back(ownerJson);
        }

        // Запись результатов в выходной JSON-файл
        std::ofstream outputFile(outputFileName);
        outputFile << outputJson.dump(2);
        outputFile.close();

        std::cout << "Результаты сохранены в файл " << outputFileName << std::endl;
    }
};
