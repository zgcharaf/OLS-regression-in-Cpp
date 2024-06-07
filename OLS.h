#ifndef OLS_H
#define OLS_H

#include <vector>
#include <string>

class OLS {
public:
    OLS();
    void fit(const std::vector<std::vector<double>>& X, const std::vector<double>& y);
    std::vector<double> predict(const std::vector<std::vector<double>>& X) const;
    std::vector<double> getCoefficients() const;
    void saveResults(const std::vector<double>& predictions, const std::string& filename) const;

private:
    std::vector<double> coefficients;
    std::vector<std::vector<double>> transpose(const std::vector<std::vector<double>>& X) const;
    std::vector<std::vector<double>> multiply(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) const;
    std::vector<double> multiply(const std::vector<std::vector<double>>& A, const std::vector<double>& B) const;
    std::vector<std::vector<double>> inverse(const std::vector<std::vector<double>>& A) const;
};

#endif // OLS_H
