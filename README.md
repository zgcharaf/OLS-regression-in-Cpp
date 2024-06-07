
# Ordinary Least Squares (OLS) Regression in C++

This repository contains an implementation of Ordinary Least Squares (OLS) regression in C++ along with a data loader to read CSV files and a utility to save the regression results to a CSV file.

## Overview

The project includes three main components:
1. **DataLoader**: Reads a CSV file, ignoring the header, and separates the features and target variable.
2. **OLS**: Performs OLS regression, predicts new data, and saves the results to a CSV file.
3. **Main Program**: Demonstrates the usage of DataLoader and OLS classes.

## Files

- `DataLoader.h` and `DataLoader.cpp`: Implementation of the DataLoader class.
- `OLS.h` and `OLS.cpp`: Implementation of the OLS class.
- `main.cpp`: Example usage of the DataLoader and OLS classes.
- `data.csv`: Example CSV data file (you should provide your own data file).
- `results.csv`: Output file containing the regression coefficients and predictions.

## Getting Started

### Prerequisites

- A C++ compiler that supports C++11 or later.
- CMake (optional, but recommended for building the project).

### Running the Project


1. **Using g++ directly**

    ```sh
    g++ -o ols main.cpp DataLoader.cpp OLS.cpp
    ```


Ensure that you have a `data.csv` file in the same directory as the executable. The `data.csv` file should have the following format:

```csv
feature1,feature2,...,featureN,target
value1,value2,...,valueN,target_value
...
```

### Example `data.csv`

```csv
feature1,feature2,target
1,1,6
1,2,8
2,2,9
2,3,11
```

## Using Your Own Data

To use your own data, replace the `data.csv` file with your dataset. Ensure that the target variable is in the last column and that the file has a header row.

## Project Structure

```sh
.
├── DataLoader.h
├── DataLoader.cpp
├── OLS.h
├── OLS.cpp
├── main.cpp
├── data.csv        # Example input file
├── results.csv     # Output file containing results
└── README.md       # This file
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.

## Contact

For any questions or feedback, please open an issue or contact me via GitHub.

