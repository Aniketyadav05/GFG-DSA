#include <iostream>

using namespace std;

class Solution {
public:
    // Function to check if a number can be represented as a sum of distinct powers of 3
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            int remainder = n % 3;
            if (remainder == 2) { // If remainder is 2, we can't express n as a sum of powers of 3
                return false;
            }
            n /= 3; // Reduce n by dividing by 3
        }
        return true;
    }
};

// Main function to test checkPowersOfThree function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input values
    int num1 = 12, num2 = 21;

    // Test checkPowersOfThree function
    cout << "Can " << num1 << " be represented as a sum of distinct powers of 3? " 
         << (sol.checkPowersOfThree(num1) ? "Yes" : "No") << endl;

    cout << "Can " << num2 << " be represented as a sum of distinct powers of 3? " 
         << (sol.checkPowersOfThree(num2) ? "Yes" : "No") << endl;

    return 0; // Program executed successfully
}
