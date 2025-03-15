# Polynomial Operations Using Pointers

##  📌 Description
This program dynamically allocates arrays to store polynomials and performs essential operations on them. It allows users to:
- Display a polynomial in a readable format.
- Compute the sum of two polynomials.
- Compute the difference of two polynomials (subtracting the first from the second).
- Run test cases to validate each function.

## 🚀 Features
- **Dynamic Memory Allocation:** Efficient handling of polynomials using pointers.
- **Polynomial Representation:** Displays polynomials in mathematical notation.
- **Addition & Subtraction:** Computes the sum and difference of polynomials.
- **User Input Handling:** Accepts and processes polynomial coefficients.

## 📌 Usage
### 1. Input Format
- The user is prompted to enter the order (degree) of each polynomial.
- Coefficients are provided as space-separated values.

### 2. Example Runs
#### Example 1
**Input:**
```
Order of first polynomial: 2   
Enter polynomial: 0 1 3 2   
Order of second polynomial: 4   
Enter polynomial: 8 0 4 0 0 3   
```
**Output:**
```
First polynomial: 2x^2 + 3x + 1 = 0   
Second polynomial: 3x^4 + 4x = 8   
Sum of polynomials: 3x^4 + 2x^2 + 7x + 1 = 8   
Difference of polynomials: 3x^4 - 2x^2 + x - 1 = 8   
```

#### Example 2
**Input:**
```
Order of first polynomial: 3   
Enter polynomial: 0 5 0 1 4   
Order of second polynomial: 3   
Enter polynomial: 0 2 3 0 6   
```
**Output:**
```
First polynomial: 4x^3 + x^2 + 5 = 0   
Second polynomial: 6x^3 + 3x + 2 = 0   
Sum of polynomials: 10x^3 + x^2 + 3x + 7 = 0   
Difference of polynomials: 2x^3 - x^2 + 3x - 3 = 0  
```

## ⚙️ Installation & Compilation
1. Clone the repository:
   ```sh
   git clone https://github.com/Johnayman1/Polynomial_Operations.git
   ```
2. Navigate to the project directory:
   ```sh
   cd Polynomial_Operations
   ```
3. Compile the program (for C++ users):
   ```sh
   g++ Polynomial Operations.cpp -o polynomial
   ```
4. Run the executable:
   ```sh
   ./polynomial
   ```

---

## 👨‍💻 Contributing
Contributions are welcome! Feel free to fork the repo and submit a pull request.

## ✍️ Authors
- Esraa Emary Abd El-Salam: [GitHub](https://github.com/esraa-emary) - [LinkedIn](https://www.linkedin.com/in/esraa-emary-b372b8303/)
- Mariam Badr Yehia: [GitHub](https://github.com/Mariam-Badr-MB) - [LinkedIn](https://www.linkedin.com/in/mariambadr13/)
- George Malak Magdy:  [GitHub](https://github.com/GeorgeMalakM) - [LinkedIn](https://www.linkedin.com/in/george-malak204/)
- John Ayman Demian:  [GitHub](https://github.com/Johnayman1) - [LinkedIn]()
- Mohammed Atef Abd El-Kader: [GitHub](https://github.com/Mohammed-3tef) - [LinkedIn](https://www.linkedin.com/in/mohammed-atef-b0a408299/)

## 📜 License
This project is licensed under the MIT License.

---
✨ **Developed with ❤️ in C++** ✨