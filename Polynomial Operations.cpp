/*
 * Authors:
    * Author1: Esraa Emary Abd El-Salam          ID: 20230054
    * Author2: Mohammed Atef Abd El-Kader        ID: 20231143
    * Author3: Mariam Badr Yehia                 ID: 20230391
    * Author4: John Ayman Demian                 ID: 20230109
    * Author5: George Malak Magdy                ID: 20231042

 * Description: A program that dynamically allocates arrays to store polynomials and performs operations on them.

 * Date: ? / 3 / 2025
 * Prof: Dr. Besheer

 * Version: V1.0
*/
// < ========================================================================================== >

#include <bits/stdc++.h>
using namespace std;

bool isInteger(const string& str) {
    static const regex integerPattern(R"(^-?\d+$)");
    return regex_match(str, integerPattern);
}

// ----------------------------------------------- CLASS DEFINITION

class Polynomial {
    int degree;
    int* coefficients;

public:
    Polynomial(int degree);    // Constructor
    ~Polynomial();                      // Destructor

    void displayMenu();                           // Display the menu

    Polynomial add(const Polynomial& other);              // Add two polynomials
    Polynomial subtract(const Polynomial& other);         // Subtract another polynomial from this polynomial

    void displayPolynomial() const;               // Display the polynomial
};

// ----------------------------------------------- CLASS IMPLEMENTATION
// --------------------- CONSTRUCTOR & DESTRUCTOR

Polynomial::Polynomial(int degree){
    this->degree = degree;
    coefficients = new int[degree + 2]; // Allocate memory for coefficients

    cout << "Enter coefficients of Pynomial: ";
    for (int i = 0; i <= degree + 1; i++) {
        cin >> coefficients[i];
    }
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

// --------------------- DISPLAY THE MENU
void Polynomial::displayMenu() {
    while (true) {
        cout << "Select an Operation:" << endl;
        cout << "1. Calculate the sum." << endl;
        cout << "2. Calculate the difference." << endl;
        cout << "3. Display the polynomial." << endl;
        cout << "0. Exit From Menu." << endl;
        cout << "Enter your choice (0 - 3):";
        string choice;
        getline(cin, choice);

        if (choice != "1" && choice != "2" && choice != "3" && choice != "0") {
            cout << "Invalid choice. Please try again." << endl << endl;
            continue;
        }

        if (choice == "1")
            add(*this);
        else if (choice == "2")
            subtract(*this);
        else if (choice == "3")
            displayPolynomial();
        else if (choice == "0")
            return;
    }
}

// --------------------- ADD TWO POLYNOMIALS
Polynomial Polynomial::add(const Polynomial &other) {

}

// --------------------- SUBTRACT TWO POLYNOMIALS
Polynomial Polynomial::subtract(const Polynomial &other) {

}

// --------------------- DISPLAY THE POLYNOMIAL
void Polynomial::displayPolynomial() const {
    for (int i = 0; i <= degree; i++) {
        cout << coefficients[i];
        if (i < degree) {
            cout << "x^" << (degree - i) << " + ";
        }
    }
    cout << " = " <<coefficients[degree+1] << endl;
    cout << endl;
}

// ----------------------------------------------- MAIN FUNCTION

int main() {
    cout << "\n------------- WELCOME TO OUR POLYNOMIAL OPERATIONS APPLICATION -------------\n" << endl;

    int degree1;
    while (true) {
        cout << "Enter order of First Polynomial: ";
        cin >> degree1;

        if (cin.fail() || degree1 < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a non-negative integer.\n";
        } else {
            break;
        }
    }

    Polynomial polynomial1(degree1);

    int degree2;
    while (true) {
        cout << "Enter order of Second Polynomial: ";
        cin >> degree2;

        if (cin.fail() || degree2 < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a non-negative integer.\n";
        } else {
            break;
        }
    }

    Polynomial polynomial2(degree2);
    cin.ignore();
    string choice;
    while (true) {
        polynomial1.displayMenu();
        cout << "Do you want to continue? (y/n):";
        getline(cin, choice);
        choice = (choice);
        if (choice == "Y" || choice == "y" || choice == "N" || choice == "n") break;
        cout << "Invalid choice. Please try again." << endl;
    }
    if (choice == "N" || choice == "n") {
        cout << "\nTHANKS FOR USING OUR APPLICATION :)" << endl;
        return 0;
    }

}
