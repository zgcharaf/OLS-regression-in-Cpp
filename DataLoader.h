#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include <vector>

class DataLoader {
public:
    DataLoader(const std::string& filename);
    std::vector<std::vector<double>> getFeatures() const;
    std::vector<double> getTarget() const;

private:
    void loadData(const std::string& filename);
    std::vector<std::vector<double>> features;
    std::vector<double> target;
};

#endif // DATALOADER_H
