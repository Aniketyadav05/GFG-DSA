#include <iostream>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    // Function to find the minimum number of recolors needed
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int minOperations = INT_MAX;

        // Sliding window approach: check all substrings of length k
        for (int i = 0; i <= n - k; i++) {
            int whiteCount = 0;

            // Count number of 'W' in current window of size k
            for (int j = i; j < i + k; j++) {
                if (blocks[j] == 'W') {
                    whiteCount++;
                }
            }

            // Update minimum operations required
            minOperations = min(minOperations, whiteCount);
        }
        return minOperations;
    }
};

// Main function to test the minimumRecolors function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input
    string blocks;
    int k;
    
    cout << "Enter the block sequence (B/W): ";
    cin >> blocks;
    
    cout << "Enter the value of k: ";
    cin >> k;

    // Call the function and print the result
    int result = sol.minimumRecolors(blocks, k);
    cout << "Minimum recolors needed: " << result << endl;

    return 0; // Successful execution
}
