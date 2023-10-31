#include <iostream>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class IJsonIO {
public:
    virtual void fromJson(const json& jsonObject) = 0;
    virtual json toJson() const = 0;
    virtual ~IJsonIO() {}
};