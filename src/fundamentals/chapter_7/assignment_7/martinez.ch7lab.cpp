//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 02/11/2023
// Status    : Completed
// This program will calculate the tip for the pretax total
// of an entered bill, based on the tax & tip rates inputted
//******************************************************************

#include<iostream>
#include<iomanip>
#include<cctype>

using namespace std;

class Tips {
    private:
        int taxRate;
    public:
        Tips(int);
        double computeTip(double, int);
};
Tips::Tips(int newTaxRate) {
    taxRate = newTaxRate;
}
double Tips::computeTip(double billAmount, int tipRate) {
    return (billAmount - taxRate / 100.0 * billAmount) * tipRate / 100.0;
}

int startProgram();

int main() {
    string divider;     // String to visually distinguish between tip calculations
    double userBill;    // Total bill entered by user
    int userTaxRate,    // Tax rate entered by user
        userTipRate;    // Tip rate entered by user
    char quit;          // Sentinel to end program, entered by user

    // Introduce program & set tax rate

    userTaxRate = startProgram();
    divider.assign(12, '*');

    do {

        // Take bill total & tip rate
        
        cout << endl << divider << " Tip Helper " << divider << endl
             << "\nEnter total bill amount: ";
        cin >> userBill;
        cout << "Enter desired tip %: ";
        cin >> userTipRate;

        // Use Tips instance to calculate tip & ask user to continue

        Tips tipCalculator = Tips(userTaxRate);
        
        cout << fixed << setprecision(2) << "\nThe tip should be $" << tipCalculator.computeTip(userBill, userTipRate) << endl;
        cout << "Compute another tip (y/n)? ";
        cin >> quit;

    } while (tolower(quit) != 'n');

    cout << "\nGoodbye";

    return 0;
}

// Introduces program and returns tax rate based on validated user input
int startProgram() {
    int userTaxRate;    // Tax rate entered by user

    // Take tax rate as input

    cout << "This program will compute a restaurant tip based on a total" << endl
         << "bill amount and the % the patron wishes to tip the server" << endl
         << "\nTax % for this location: ";
    cin >> userTaxRate;

    // Validate tax rate
    
    while (userTaxRate < 0) {
        cout << "Tax % cannot be negative. Please re-enter tax %: ";
        cin >> userTaxRate;
    }

    return userTaxRate;
}