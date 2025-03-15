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
private:
    int degree;
    int* coefficients;

public:
    Polynomial(int degree, int* coefficients);    // Constructor
    ~Polynomial();                      // Destructor

    void displayMenu();                           // Display the menu

    Polynomial add(const Polynomial& other);              // Add two polynomials
    Polynomial subtract(const Polynomial& other);         // Subtract another polynomial from this polynomial

    void displayPolynomial() const;               // Display the polynomial
};

// ----------------------------------------------- CLASS IMPLEMENTATION
// --------------------- CONSTRUCTOR & DESTRUCTOR

Polynomial::Polynomial(int degree, int* coefficients){

}

Polynomial::~Polynomial() {

}

// --------------------- DISPLAY THE MENU
void Polynomial::displayMenu() {

}

// --------------------- ADD TWO POLYNOMIALS
Polynomial Polynomial::add(const Polynomial &other) {

}

// --------------------- SUBTRACT TWO POLYNOMIALS
Polynomial Polynomial::subtract(const Polynomial &other) {

}

// --------------------- DISPLAY THE POLYNOMIAL
void Polynomial::displayPolynomial() const {

}

// ----------------------------------------------- MAIN FUNCTION

int main() {
    cout << "\n------------- WELCOME TO OUR POLYNOMIAL OPERATIONS APPLICATION -------------\n" << endl;

    return 0;
}