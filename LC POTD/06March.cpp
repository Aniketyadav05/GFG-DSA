#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the missing and repeated numbers in an NxN grid
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<long long> freq(n * n / 64 + 1); // Frequency array using bit manipulation
        vector<int> ans; // Stores the repeated and missing values

        // Step 1: Identify the repeated value using bitwise operations
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num = grid[i][j] - 1; // Convert number to 0-based index
                int ind = num / 64;
                int val = num % 64;

                // Check if the number has been seen before
                if ((freq[ind] & (1LL << val))) {
                    ans.push_back(num + 1); // This number is repeated
                }

                // Mark this number as seen
                freq[ind] |= (1LL << val);
            }
        }

        // Step 2: Find the missing number
        for (int i = 0; i < (int)freq.size(); i++) {
            for (int j = 0; j < 64; j++) {
                if ((freq[i] & (1LL << j)) == 0) { // If bit is not set, number is missing
                    ans.push_back(i * 64 + j + 1);
                    return ans; // Since we need only one missing number, return immediately
                }
            }
        }

        return ans;
    }
};

// Main function to test the solution
int main() {
    Solution sol; // Create an instance of Solution

    // Example input: 2D grid (NxN)
    vector<vector<int>> grid = {
        {1, 2, 2}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };

    // Call findMissingAndRepeatedValues function
    vector<int> result = sol.findMissingAndRepeatedValues(grid);

    // Print result
    cout << "Repeated number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0; // Successful execution
}
