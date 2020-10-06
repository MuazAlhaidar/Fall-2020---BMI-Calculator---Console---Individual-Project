#include <iomanip>
#include <iostream>
#include <limits>

#define METRIC 1
#define IMPERIAL 2

bool isPositiveNum(const float value);

void clearInputStream();
void errorMessage();
void displayBMICatagory(const float bmi);
void getWeightAndHeight(const int unitChoice, float &weight, float &height);

float getCorrectInput(float value);
float getMetricBMI(const float weight, const float height);
float getImperialBMI(const float weight, const float height);

int main() {

    float weight = 0, height = 0;
    int unitChoice = 0;

    std::cout << "Welcome to my BMI Calculator\n";
    std::cout << "Please pick your units of measurement:\n";
    std::cout << "\t1. Metric\n";
    std::cout << "\t2. Imperial\n";

    std::cin >> unitChoice;

    while (unitChoice != METRIC && unitChoice != IMPERIAL) {
        std::cout << "Please enter either 1 or 2\n";
        clearInputStream();
        std::cin >> unitChoice;
    }

    getWeightAndHeight(unitChoice, weight, height);

    float userBMI = ((unitChoice == METRIC) ? getMetricBMI(weight, height) : getImperialBMI(weight, height));

    std::cout << "Your BMI is: ";
    std::cout << std::setprecision(3);
    std::cout << userBMI << std::endl;

    displayBMICatagory(userBMI);

    return 0;
}

bool isPositiveNum(const float value) {
    if (value > 0)
        return true;

    return false;
}

void clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void errorMessage() {
    std::cout << "ERROR:NUMBER NOT IN RANGE\n";
    std::cout << "Please enter a Number Greater than 0: ";
}

void displayBMICatagory(const float bmi) {

    std::cout << "You are ";

    if (bmi < 18.5f)
        std::cout << "underweight";
    else if (bmi >= 18.5f && bmi < 25.0f)
        std::cout << "normal weight";
    else if (bmi >= 25.0f && bmi < 30.0f)
        std::cout << "overweight";
    else
        std::cout << "obese";

    std::cout << std::endl;
}

void getWeightAndHeight(const int unitChoice, float &weight, float &height) {

    std::cout << ((unitChoice == METRIC) ? "Please enter weight(kg): " : "Please enter weight(lb):");
    std::cin >> weight;
    clearInputStream();
    if (!isPositiveNum(weight))
        weight = getCorrectInput(weight);

    std::cout << ((unitChoice == METRIC) ? "Please enter height(m): " : "Please enter height(in):");
    std::cin >> height;
    clearInputStream();
    if (!isPositiveNum(height))
        height = getCorrectInput(height);
}

float getCorrectInput(float value) {

    while (!isPositiveNum(value)) {
        errorMessage();
        std::cin >> value;
        clearInputStream();
    }

    return value;
}

float getMetricBMI(const float weight, const float height) {
    return weight / (height * height);
}

float getImperialBMI(const float weight, const float height) {
    return 703 * (weight / (height * height));
}