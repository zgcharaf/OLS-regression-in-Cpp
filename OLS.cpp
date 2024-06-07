#include "OLS.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <cmath>

OLS::OLS() {}

void OLS::fit(const std::vector<std::vector<double>>& X, const std::vector<double>& y) {
    if (X.size() != y.size()) {
        throw std::invalid_argument("Number of rows in X must match size of y");
    }

    std::vector<std::vector<double>> Xt = transpose(X);
    std::vector<std::vector<double>> XtX = multiply(Xt, X);
    std::vector<std::vector<double>> XtX_inv = inverse(XtX);
    std::vector<double> Xty = multiply(Xt, y);
    coefficients = multiply(XtX_inv, Xty);
}

std::vector<double> OLS::predict(const std::vector<std::vector<double>>& X) const {
    std::vector<double> predictions(X.size());
    for (size_t i = 0; i < X.size(); ++i) {
        predictions[i] = 0.0;
        for (size_t j = 0; j < X[i].size(); ++j) {
            predictions[i] += X[i][j] * coefficients[j];
        }
    }
    return predictions;
}

std::vector<double> OLS::getCoefficients() const {
    return coefficients;
}

void OLS::saveResults(const std::vector<double>& predictions, const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    // Write coefficients
    file << "Coefficients,";
    for (size_t i = 0; i < coefficients.size(); ++i) {
        file << coefficients[i];
        if (i < coefficients.size() - 1) {
            file << ",";
        }
    }
    file << "\n";

    // Write predictions
    file << "Predictions\n";
    for (size_t i = 0; i < predictions.size(); ++i) {
        file << predictions[i] << "\n";
    }

    file.close();
}

std::vector<std::vector<double>> OLS::transpose(const std::vector<std::vector<double>>& X) const {
    size_t rows = X.size();
    size_t cols = X[0].size();
    std::vector<std::vector<double>> Xt(cols, std::vector<double>(rows));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            Xt[j][i] = X[i][j];
        }
    }
    return Xt;
}

std::vector<std::vector<double>> OLS::multiply(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) const {
    size_t rowsA = A.size();
    size_t colsA = A[0].size();
    size_t colsB = B[0].size();
    std::vector<std::vector<double>> result(rowsA, std::vector<double>(colsB, 0.0));
    for (size_t i = 0; i < rowsA; ++i) {
        for (size_t j = 0; j < colsB; ++j) {
            for (size_t k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

std::vector<std::vector<double>> OLS::inverse(const std::vector<std::vector<double>>& A) const {
    size_t n = A.size();
    std::vector<std::vector<double>> A_inv(n, std::vector<double>(n, 0.0));
    std::vector<std::vector<double>> B(A);
    for (size_t i = 0; i < n; ++i) {
        A_inv[i][i] = 1.0;
    }
    for (size_t i = 0; i < n; ++i) {
        double pivot = B[i][i];
        if (pivot == 0) {
            throw std::runtime_error("Matrix is singular and cannot be inverted.");
        }
        for (size_t j = 0; j < n; ++j) {
            B[i][j] /= pivot;
            A_inv[i][j] /= pivot;
        }
        for (size_t k = 0; k < n; ++k) {
            if (k == i) continue;
            double factor = B[k][i];
            for (size_t j = 0; j < n; ++j) {
                B[k][j] -= factor * B[i][j];
                A_inv[k][j] -= factor * A_inv[i][j];
            }
        }
    }
    return A_inv;
}

std::vector<double> OLS::multiply(const std::vector<std::vector<double>>& A, const std::vector<double>& B) const {
    size_t rowsA = A.size();
    size_t colsA = A[0].size();
    std::vector<double> result(rowsA, 0.0);
    for (size_t i = 0; i < rowsA; ++i) {
        for (size_t j = 0; j < colsA; ++j) {
            result[i] += A[i][j] * B[j];
        }
    }
    return result;
}
