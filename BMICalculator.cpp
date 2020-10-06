#include <iostream>

#define METRIC 1
#define IMPERIAL 2

int getMetricBMI(const float weight, const float height) {
    return weight / (height * height);
}

int getImperialBMI(const float weight, const float height) {
    return (703 * weight) / (height * height);
}

bool isPositiveNum(const float value) {
    if (value > 0)
        return true;

    return false;
}

void errorMessage() {
    std::cout << "ERROR:NUMBER NOT IN RANGE\n";
    std::cout << "Please enter a Number Greater than 0\n ";
    clearInputStream();
}

float getCorrectInput(float value) {

    errorMessage();
    std::cin >> value;

    while (!isPositiveNum(value)) {
        errorMessage();
        std::cin >> value;
    }

    return value;
}

void clearInputStream() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

void getWeightAndHeight(const int unitChoice, float &weight, float &height) {

    std::cout << ((unitChoice == METRIC) ? "Please enter weight(kg): " : "Please enter weight(lb):");
    std::cin >> weight;
    clearInputStream();
    if (isPositiveNum(weight))
        weight = getCorrectInput(weight);

    std::cout << ((unitChoice == METRIC) ? "Please enter height(m): " : "Please enter height(in):");
    std::cin >> height;
    clearInputStream();
    if (isPositiveNum(height))
        height = getCorrectInput(height);
}

int main() {

    float weight = 0, height = 0;
    int unitChoice = 0;

    std::cout << "Welcome to my BMI Calculator\n";
    std::cout << "Please pick your units of measurement:\n";
    std::cout << "\t1. Imperical\n";
    std::cout << "\t2. Metric\n";

    std::cin >> unitChoice;

    while (unitChoice != METRIC && unitChoice != IMPERIAL) {
        std::cout << "Please enter either 1 or 2\n";
        clearInputStream();
        std::cin >> unitChoice;
    }

    getWeightAndHeight(unitChoice, weight, height);

    std::cout << "Your BMI is: ";
    std::cout << ((unitChoice == METRIC) ? getMetricBMI(weight, height) : getMetricBMI(weight, height)) << std::endl;

    return 0;
}