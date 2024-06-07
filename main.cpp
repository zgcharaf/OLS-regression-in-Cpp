#include "OLS.h"
#include "DataLoader.h"
#include <iostream>

int main() {
    // Load data from CSV
    DataLoader dataLoader("data.csv");

    // Get features and target
    std::vector<std::vector<double>> X = dataLoader.getFeatures();
    std::vector<double> y = dataLoader.getTarget();

    // Fit the OLS model
    OLS ols;
    ols.fit(X, y);

    // Make predictions
    std::vector<std::vector<double>> new_data = {
        {3, 5},
        {5, 9}
    };
    std::vector<double> predictions = ols.predict(new_data);

    // Output the results
    std::cout << "Coefficients:" << std::endl;
    for (double coef : ols.getCoefficients()) {
        std::cout << coef << " ";
    }
    std::cout << std::endl;

    std::cout << "Predictions:" << std::endl;
    for (double pred : predictions) {
        std::cout << pred << " ";
    }
    std::cout << std::endl;

    // Save results to CSV
    ols.saveResults(predictions, "results.csv");

    return 0;
}
