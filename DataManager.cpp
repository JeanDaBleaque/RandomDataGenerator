#include "DataManager.h"
#include <iostream>
#include "json.hpp"
#include <string>
#include <fstream>
#include <time.h>
void generateData() {
    srand(time(nullptr));
    std::map<int, std::string> colorMap;
    colorMap[0] = "yellow";
    colorMap[1] = "red";
    colorMap[2] = "green";
    int dataCount = 0;
    std::cout << "How many data you want to generate: ";
    std::cin >> dataCount;
    std::ofstream dataFile("data.json");
    nlohmann::json json;
    json["data_count"] = dataCount;
    if (dataFile.is_open()) {
        for (int i=0;i<dataCount;i++) {
            json["data"][i]["x"] = (((float)rand())/RAND_MAX * (float)6);
            json["data"][i]["y"] = (((float)rand())/RAND_MAX * (float)6);
            json["data"][i]["color"] = colorMap[rand() % 3];
        }
        dataFile << json;
        dataFile.close();
    }
}

