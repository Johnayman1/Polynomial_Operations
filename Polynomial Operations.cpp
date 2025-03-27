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
    // Matches the zero and positive integers only (no spaces, letters, etc.)
    regex pattern("^(0|[1-9][0-9]*)$");
    return regex_match(input, pattern);
}

// ----------------------------------------------- CLASS DEFINITION

class Polynomial {
    int degree;
    int *coefficients;

public:
    Polynomial() = default;
    explicit Polynomial(int degree , bool Help);

    ~Polynomial();

    static void displayMenu(Polynomial& polynomial1, const Polynomial &polynomial2);
    void add(const Polynomial &other);
    void splitString(string& input, int& index);
    void subtract(const Polynomial &other);
    void displayPolynomial() const;
};

// ----------------------------------------------- CLASS IMPLEMENTATION
//--------------------- Global Variable
bool Status ;
// --------------------- CONSTRUCTOR & DESTRUCTOR

Polynomial::Polynomial(int degree, bool IN) {
    if(IN) {
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
    else {
        this->degree = degree;
        this->coefficients = new int[degree + 2];
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
    // Degree of the result polynomial is the maximum of the two degrees.
    const int resultDegree = max(this->degree, other.degree);
    Polynomial result{};

    result.degree = resultDegree;
    result.coefficients = new int[resultDegree + 2];

    // Use 0 for missing coefficients in the polynomials and add them.
    for (int i = 0; i < resultDegree + 2; i++) {
        int firstCoefficient = (i < this->degree + 2) ? this->coefficients[i] : 0;
        int secondCoefficient = (i < other.degree + 2) ? other.coefficients[i] : 0;
        result.coefficients[i] = firstCoefficient + secondCoefficient;
    }
   
    cout << "Sum of polynomials: ";
    result.displayPolynomial();
}

// --------------------- SUBTRACT TWO POLYNOMIALS

void Polynomial::subtract(const Polynomial &other) {
    // Degree of the result polynomial is the maximum of the two degrees.
    const int resultDegree = max(this->degree, other.degree);
    Polynomial result{};

    result.degree = resultDegree;
    result.coefficients = new int[resultDegree + 2];

    // Use 0 for missing coefficients and subtract the two polynomials.
    for (int i = 0; i < resultDegree + 2; i++) {
        int firstCoefficient = (i < this->degree + 2) ? this->coefficients[i] : 0;
        int secondCoefficient = (i < other.degree + 2) ? other.coefficients[i] : 0;
        result.coefficients[i] = secondCoefficient - firstCoefficient;
    }

    cout << "Difference of polynomials: ";
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

void Polynomial::displayMenu(Polynomial& polynomial1, const Polynomial& polynomial2) {
    while (true) {
        cout << "\nChoose the operation you want to perform: " << endl;
        cout << "1) Calculate the sum" << endl;
        cout << "2) Calculate the difference" << endl;
        cout << "3) Display the polynomial" << endl;
        cout << "0) Exit " << endl;
        cout << "\nPlease, enter your choice: ";

        string choice;
        getline(cin, choice);

        while (choice != "1" && choice != "2" && choice != "3" && choice != "0") {
            cout << "Invalid choice, Please try again: ";
            getline(cin, choice);
        }
        cout << endl;

        if (choice == "1") polynomial1.add(polynomial2);
        else if (choice == "2") polynomial1.subtract(polynomial2);
        else if (choice == "3") {
            cout << "First polynomial: ";
            polynomial1.displayPolynomial();
            cout << "Second polynomial: ";
            polynomial2.displayPolynomial();
        } 
        else return;
    }
}

// ----------------------------------------------- KIND OF I/P
void runFromTerminal(){
    string degree1, degree2;
    Status = true;
    while (true) {
        cout << "Please, enter order of First Polynomial: ";
        getline(cin, degree1);
        while (!isValidNumber(degree1)) {
            cout << "Invalid input, Please enter a positive integer: ";
            getline(cin, degree1);
        }
        Polynomial polynomial1(stoi(degree1) , Status);

        cout << "Please, enter order of Second Polynomial: ";
        getline(cin, degree2);
        while (!isValidNumber(degree2)) {
            cout << "Invalid input, Please enter a positive integer: ";
            getline(cin, degree2);
        }
        Polynomial polynomial2(stoi(degree2) , Status);

        Polynomial::displayMenu(polynomial1, polynomial2);

        cout << "Do you want to continue? (y/n): ";
        char choice; cin >> choice;

        while (tolower(choice) != 'y' && tolower(choice) != 'n') {
            cout << "Invalid choice. Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (tolower(choice) == 'n') break;
    }
}

void runFromFile() {
        string fileName;
        Status = false ;
        cout << "\nPlease, enter file name:";
        while (true) {
            getline(cin, fileName);
            // Input the file and check from existing
            if (fileName.size() < 5 || fileName.substr(fileName.size() - 4) != ".txt") {
                cout << "\nThe file name should be like this ----> (file name).txt\n";
                cout << "Please, enter a valid file name:";
                continue;
            }
            ifstream file(fileName);
            if (!file.is_open()) {
                cout << "\nFile not found! Please, enter a valid file name:";
                continue;
            }

            // Extract the coefficient and degree of polynomial
            string line;
            int poly_NO = 1;
            while (getline(file, line)) {
                if (line.empty()) continue;
                cout << "\n======== Polynomial #" << poly_NO << " ========" << endl;

                // Checker from 1st polynomial degree
                if (!isValidNumber(line)) {
                    cerr << "Error: Missing First polynomial degree in test case " << poly_NO << endl;
                    continue;
                }
                // 1st polynomial will be extracted
                Polynomial polynomial1(stoi(line) , Status);
                getline(file, line);
                int index1 = 0;
                polynomial1.splitString(line, index1);

                if (!getline(file, line)) {
                    cerr << "Error: Missing second polynomial degree in test case " << poly_NO << endl;
                    continue;
                }
                if (!isValidNumber(line)) {
                    cerr << "Error: Degree of the second polynomial is invalid in test case " << poly_NO << endl;
                    continue;
                }
                Polynomial polynomial2(stoi(line) , Status);
                if (!getline(file, line)) {
                    cerr << "Error: Missing coefficients for second polynomial in test case " << poly_NO << endl;
                    continue;
                }
                // 1st polynomial will be extracted
                int index2 = 0;
                polynomial2.splitString(line, index2);

                // Display them
                cout << "First polynomial: ";
                polynomial1.displayPolynomial();
                cout << "Second polynomial: ";
                polynomial2.displayPolynomial();
                // Implement Sum - Subtract
                polynomial1.add(polynomial2);
                polynomial1.subtract(polynomial2);

                poly_NO++;
            }
            file.close();
            cout << "\n======== Done !! ========" << endl;
            return;
        }
}
// ----------------------------------------------- MAIN FUNCTION

int main() {
    cout << "\n------------- WELCOME TO OUR POLYNOMIAL OPERATIONS APPLICATION -------------\n" << endl;
    string choice;
    while (true) {
        while (true) {
            cout << "\nWhat do you want to do?" << endl;
            cout << "1) Polynomial System." << endl;
            cout << "2) Exit." << endl;
            cout << "Please, enter your choice:";
            getline(cin, choice);

            // Check the validity of input.
            if (choice == "1" || choice == "2") break;
            cout << "Invalid choice. Please, Try again." << endl << endl;
        }

        // Exit the system.
        if (choice == "2") break;
        while (true) {
            cout << "\nWhat do you want to do ?" << endl;
            cout << "1) Run From Terminal." << endl;
            cout << "2) Run From File." << endl;
            cout << "3) Exit." << endl;
            cout << "Please, enter your choice:";
            getline(cin, choice);

            // Check the validity of input.
            if (choice == "1" || choice == "2" || choice == "3") break;
            cout << "Invalid choice. Please, Try again." << endl << endl;
        }

        // Run from the terminal.
        if (choice == "1") runFromTerminal();

        // Run from the file.
        else if (choice == "2") {
            runFromFile();
        } else continue;
    }
    cout << "\nTHANKS FOR USING OUR APPLICATION :)" << endl;
}