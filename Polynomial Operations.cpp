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

 * Version: V3.0
*/
// < ========================================================================================== >

#include <bits/stdc++.h>
using namespace std;

bool isValidNumber(const string &input) {
    regex pattern("^(0|[1-9][0-9]*)$");         // Matches positive integers only (no spaces, letters, etc.)
    return regex_match(input, pattern);
}

// ----------------------------------------------- CLASS DEFINITION

class Polynomial {
    int degree;
    int *coefficients;

public:
    Polynomial() = default;
    Polynomial(int degree);
    void splitString(string& input, int& index);

    ~Polynomial();                      // Destructor

    void displayMenu(Polynomial& polynomial1, const Polynomial &polynomial2) const;                  // Display the menu.
    void add(const Polynomial &other);                                                            // Add two polynomial.
    void subtract(const Polynomial &other);                         // Subtract another polynomial from this polynomial.
    void displayPolynomial() const;                                                           // Display the polynomial.
};

// ----------------------------------------------- CLASS IMPLEMENTATION

// --------------------- CONSTRUCTOR & DESTRUCTOR

Polynomial::Polynomial(int degree) {
    this->degree = degree;
    this->coefficients = new int[degree + 2];

    if (degree > 0) {
        cout << "Please, enter coefficients of Polynomial:";
        string element;

        // Handle int and long.
        getline(cin, element);
        int index = 0;
        splitString(element, index);
    }
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

// --------------------- SPLIT STRING

void Polynomial::splitString(string& input, int& index) {
    while (true) {
        istringstream stream(input);
        string token;
        bool isValid = true;

        int tempIndex = index;

        while (stream >> token && tempIndex < this->degree + 2) {
            if (isValidNumber(token)) {
                this->coefficients[tempIndex++] = stoi(token);
            }
            else {
                isValid = false;
                break;
            }
        }

        if (isValid && tempIndex == degree + 2) break;

        // Handle invalid input
        cout << "Invalid input..." << endl;
        cout << "Please, enter positive coefficients of Polynomial: ";
        getline(cin, input);
    }
}

// --------------------- ADD TWO POLYNOMIALS

void Polynomial::add(const Polynomial &other) {
    const int n = max(this->degree, other.degree);
    Polynomial result{};

    result.degree = n;
    result.coefficients = new int[n + 2];

    // Use 0 for missing coefficients.
    for (int i = 0; i < n + 2; i++) {
        int firstCoefficient = (i < this->degree + 2) ? this->coefficients[i] : 0;
        int secondCoefficient = (i < other.degree + 2) ? other.coefficients[i] : 0;
        result.coefficients[i] = firstCoefficient + secondCoefficient;
    }
   
    cout << "Polynomial addition is : ";
    result.displayPolynomial();
}

// --------------------- SUBTRACT TWO POLYNOMIALS

void Polynomial::subtract(const Polynomial &other) {
    const int n = max(this->degree, other.degree);
    Polynomial result{};

    result.degree = n;
    result.coefficients = new int[n + 2];

    // Use 0 for missing coefficients.
    for (int i = 0; i < n + 2; i++) {
        int firstCoefficient = (i < this->degree + 2) ? this->coefficients[i] : 0;
        int secondCoefficient = (i < other.degree + 2) ? other.coefficients[i] : 0;
        result.coefficients[i] = secondCoefficient - firstCoefficient;
    }

    cout << "Polynomial Subtraction is: ";
    result.displayPolynomial();
}


// --------------------- DISPLAY THE POLYNOMIAL

void Polynomial::displayPolynomial() const {
    for (int i = degree + 1; i > 0; i--) {
        if (coefficients[i] == 0) continue;

        if (i == degree + 1) cout << coefficients[i];
        else if (coefficients[i] < 0) {
            cout << " - ";
            if (coefficients[i] != -1 || i == 1) cout << -coefficients[i];
        }
        else {
            cout << " + ";
            if (coefficients[i] != 1 || i == 1) cout << coefficients[i];
        }

        if (i > 1) {
            if (i == 2) cout << "x";
            else cout << "x^" << (i - 1);
        }
    }
    cout << " = " << coefficients[0] << endl;
    cout << endl;
}

// --------------------- DISPLAY THE MENU

void Polynomial::displayMenu( Polynomial& polynomial1, const Polynomial& polynomial2) const {
    while (true) {
        cout << "\nChoose the operation you want to perform: " << endl;
        cout << "1) Calculate the sum" << endl;
        cout << "2) Calculate the difference" << endl;
        cout << "3) Display the polynomial" << endl;
        cout << "0) Exit " << endl;
        cout << "\nPlease, enter your choice: ";

        string choice;
        getline(cin, choice);

        if (choice != "1" && choice != "2" && choice != "3" && choice != "0") {
            cout << "Invalid choice, Please try again: ";
            getline(cin, choice);
        }
        cout << endl;

        if (choice == "1") polynomial1.add(polynomial2);
        else if (choice == "2") polynomial1.subtract(polynomial2);
        else if (choice == "3") {
            cout << "First polynomial is : ";
            polynomial1.displayPolynomial();
            cout << "Second Polynomial is : ";
            polynomial2.displayPolynomial();
        } 
        else if (choice == "0") return;
    }
}

// ----------------------------------------------- MAIN FUNCTION

int main() {
    cout << "\n------------- WELCOME TO OUR POLYNOMIAL OPERATIONS APPLICATION -------------\n" << endl;

    string degree1, degree2;

    while (true) {
        cout << "Please, enter order of First Polynomial: ";
        getline(cin, degree1);
        while (!isValidNumber(degree1)) {
            cout << "Invalid input, Please enter a positive integer: ";
            getline(cin, degree1);
        }

        Polynomial polynomial1(stoi(degree1));

        cout << "Please, enter order of Second Polynomial: ";
        getline(cin, degree2);
        while (!isValidNumber(degree2)) {
            cout << "Invalid input, Please enter a positive integer: ";
            getline(cin, degree2);
        }

        Polynomial polynomial2(stoi(degree2));

        polynomial1.displayMenu(polynomial1, polynomial2);

        char choice;
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

        while (tolower(choice) != 'y' && tolower(choice) != 'n') {
            cout << "Invalid choice. Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (tolower(choice) == 'n') {
            cout << "\nTHANKS FOR USING OUR APPLICATION :)" << endl;
            return 0;
        }
    }
}