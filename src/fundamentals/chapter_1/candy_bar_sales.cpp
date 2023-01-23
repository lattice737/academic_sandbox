#include<iostream>

using namespace std;

int main() {
    double candyBarsSold,
           earningsPerBar;

    cout << "Enter the number of candy bars sold: ";
    cin >> candyBarsSold;

    cout << "Enter the amount of earnings per candy bar sold: ";
    cin >> earningsPerBar;

    cout << "\nTotal earnings are $" << candyBarsSold * earningsPerBar;

    return 0;
}