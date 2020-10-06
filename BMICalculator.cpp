#include <iostream>
using namespace std;

#define METRIC 1
#define IMPERIAL 2

int getMetricBMI(float weight, float height) {
    return 0;
}

int getImperialBMI() {
    return 0;
}

bool isPositiveNum(const float value) {
    if (value > 0)
        return true;

    return false;
}

void errorMessage() {
    cout << "ERROR:NUMBER NOT IN RANGE\n";
    cout << "Please enter a Number Greater than 0\n ";
    cin.clear();
    cin.ignore(10000, '\n');
}

float getCorrectInput(float value) {

    errorMessage();
    cin >> value;

    while (!isPositiveNum(value)) {
        errorMessage();
        cin >> value;
    }
}

void getWeightAndHeight(const int unitChoice, float &weight, float &height) {

    cout << (unitChoice == METRIC) ? "Please enter weight(kg): " : "Please enter weight(lb):";
    cin >> weight;
    if (isPositiveNum(weight))
        weight = getCorrectInput(weight);

    cout << (unitChoice == METRIC) ? "Please enter height(m): " : "Please enter height(in):";
    cin >> height;
    if (isPositiveNum(height))
        height = getCorrectInput(height);
}

int main() {

    float weight = 0, height = 0;
    int unitChoice = 0;

    cout << "Welcome to my BMI Calculator\n";
    cout << "Please pick your units of measurement:\n";
    cout << "\t1. Imperical\n";
    cout << "\t2. Metric\n";

    cin >> unitChoice;

    while (unitChoice != METRIC && unitChoice != IMPERIAL) {
        cout << "Please enter either 1 or 2\n";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> unitChoice;
    }

    return 0;
}