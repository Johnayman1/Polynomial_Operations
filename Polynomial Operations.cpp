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
    Polynomial() = default ;
    Polynomial(int degree) ;
    ~Polynomial();                      // Destructor

    void displayMenu(Polynomial polynomial1 , const Polynomial& polynomial2) const;                           // Display the menu
    void add(const Polynomial& other);              // Add two polynomial
    void subtract(const Polynomial& other);         // Subtract another polynomial from this polynomia
    void displayPolynomial() const;               // Display the polynomial
};

// ----------------------------------------------- CLASS IMPLEMENTATION
// --------------------- CONSTRUCTOR & DESTRUCTOR


Polynomial::Polynomial(int degree ){
    this->degree = degree;
    this->coefficients = new int[degree + 2];

    if(degree > 0) {
        cout << "Please , enter coefficients of Polynomial: ";
        for (int i = 0; i < degree + 2; i++)
            cin >> this->coefficients[i] ;

    }

}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

// --------------------- ADD TWO POLYNOMIALS
void Polynomial::add(const Polynomial &other) {
    const int n = max(this->degree, other.degree);
     Polynomial result{};

    result.degree = n ;
    result.coefficients = new int[n + 2];

    for (int i = 0 ; i < n + 2; i++) {
        if (i < this->degree + 2 && i < n + 2) result.coefficients[i] = coefficients[i] + other.coefficients[i];
        else {
            if (this->degree > other.degree) {
                result.coefficients[i] = this->coefficients[i] ;
            }else {
                result.coefficients[i] = other.coefficients[i] ;
            }
        }
    }
    cout << "Polynomial addition is : " ;
    result.displayPolynomial() ;
}

// --------------------- SUBTRACT TWO POLYNOMIALS
void Polynomial::subtract(const Polynomial &other) {

    //cout << "Polynomial Subtraction is : " ;
    //result.displayPolynomial() ;
}

// --------------------- DISPLAY THE POLYNOMIAL
void Polynomial::displayPolynomial() const {

    // Wrong watch the example in the PDF

    for (int i = 0; i < degree + 2; i++) {
        cout << coefficients[i];
        if (i < degree) {
            cout << "x^" << (degree - i) << " + ";
        }
    }
    cout << " = " <<coefficients[degree+1] << endl;
    cout << endl;
}
// --------------------- DISPLAY THE MENU
void Polynomial::displayMenu(Polynomial polynomial1 , const Polynomial& polynomial2) const {

    cout << "\n1) Calculate the sum" << endl;
    cout << "2) Calculate the difference" << endl;
    cout << "3) Display the polynomial" << endl;
    cout << "4) Exit " << endl;
    cout << "\nPlease, enter your choice: ";

    string choice;
    getline(cin, choice);

    if (choice != "1" && choice != "2" && choice != "3" && choice != "4") {
        cout << "Invalid choice, Please try again: " ;
        getline(cin, choice);
    }
    cout << endl;

    if (choice ==  "1")  polynomial1.add(polynomial2);
    else if (choice == "2") polynomial1.subtract(polynomial2);
    else if (choice == "3") {
        cout << "First polynomial is : " ;polynomial1.displayPolynomial();
        cout << endl;
        cout << "Second Polynomial is : " ;polynomial2.displayPolynomial();
    }else exit(0);
}

// ----------------------------------------------- MAIN FUNCTION

int main() {

    cout << "\n------------- WELCOME TO OUR POLYNOMIAL OPERATIONS APPLICATION -------------\n" << endl;

    int degree1 , degree2;
    cout << "Please, enter order of First Polynomial: ";
    cin >> degree1;

    while (cin.fail() || degree1 < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a non-negative integer: ";
            cin >> degree1;
        }

    const Polynomial polynomial1(degree1);
    cout << "Please, enter order of Second Polynomial: ";
    cin >> degree2;

    while (cin.fail() || degree1 < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a non-negative integer: ";
        cin >> degree1;
    }

    const Polynomial polynomial2(degree2);

    cin.ignore(); char choice;

    while (true) {

        polynomial1.displayMenu(polynomial1 , polynomial2);
        cout << "Do you want to continue? (y/n):";
        cin >> choice;

        while (tolower(choice) != 'y' && tolower(choice) != 'n') {
            cout << "Invalid choice. Please try again: " ;
            cin >> choice;
        }

        if (tolower(choice) == 'n') {
            cout << "\nTHANKS FOR USING OUR APPLICATION :" << endl;
            exit(0);
        }
    }
}
