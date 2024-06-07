#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

DataLoader::DataLoader(const std::string& filename) {
    loadData(filename);
}

void DataLoader::loadData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    std::vector<std::vector<double>> data;

    // Skip the header
    if (std::getline(file, line)) {
        // Do nothing, just skip the header line
    }

    // Read the data
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        std::vector<double> row;

        while (std::getline(ss, value, ',')) {
            row.push_back(std::stod(value));
        }

        // Separate features and target
        target.push_back(row.back());
        row.pop_back();
        features.push_back(row);
    }

    file.close();
}

std::vector<std::vector<double>> DataLoader::getFeatures() const {
    return features;
}

std::vector<double> DataLoader::getTarget() const {
    return target;
}
