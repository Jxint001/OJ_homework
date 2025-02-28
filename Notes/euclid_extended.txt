#include <iostream>
using namespace std;

// Function to compute the GCD of two numbers a and b, and the Bézout coefficients x and y
int extended_gcd(int a, int b, int &x, int &y) {
    // Initialize coefficients for the first step
    int x0 = 1, x1 = 0;  // Coefficients for a
    int y0 = 0, y1 = 1;  // Coefficients for b

    // Iteratively apply the Euclidean algorithm
    while (b != 0) {
        // Compute the quotient and remainder
        int q = a / b;
        int r = a % b;

        // Update x and y using the formula
        int temp_x = x0 - q * x1;
        int temp_y = y0 - q * y1;

        // Move to the next step
        a = b;
        b = r;

        // Update the coefficients
        x0 = x1;
        y0 = y1;
        x1 = temp_x;
        y1 = temp_y;
    }

    // After the loop ends, a is the GCD, and x0, y0 are the Bézout coefficients
    x = x0;
    y = y0;
    return a;  // Return the GCD
}

int main() {
    int a, b;
    
    // Input two integers
    cout << "Enter two integers: ";
    cin >> a >> b;
    
    int x, y;
    // Call the extended Euclidean function
    int gcd = extended_gcd(a, b, x, y);
    
    // Output the results
    cout << "The GCD of " << a << " and " << b << " is: " << gcd << endl;
    cout << "Bézout coefficients: x = " << x << ", y = " << y << endl;
    
    // To verify the result:
    cout << "Verification (a * x + b * y = gcd): " << a * x + b * y << endl;

    return 0;
}
