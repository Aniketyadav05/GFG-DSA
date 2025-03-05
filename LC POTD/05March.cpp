#include <iostream>

using namespace std;

class Solution {
public:
    // Function to calculate the number of colored cells in an expanding grid pattern
    long long coloredCells(int n) {
        return 1 + 4 * n * (n - 1) / 2; // Formula to compute the number of colored cells
    }
};

// Main function to test coloredCells function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input values
    int n1 = 1, n2 = 3, n3 = 5;

    // Test coloredCells function and print results
    cout << "Number of colored cells for n = " << n1 << ": " << sol.coloredCells(n1) << endl;
    cout << "Number of colored cells for n = " << n2 << ": " << sol.coloredCells(n2) << endl;
    cout << "Number of colored cells for n = " << n3 << ": " << sol.coloredCells(n3) << endl;

    return 0; // Program executed successfully
}
