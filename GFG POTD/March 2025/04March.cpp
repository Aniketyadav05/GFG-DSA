#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the length of the longest increasing subsequence (LIS)
    int lis(vector<int>& a) {
        int n = a.size();
        vector<int> d(n, 1); // DP array initialized with 1 (minimum LIS is 1)

        // Compute LIS for each element
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i]) 
                    d[i] = max(d[i], d[j] + 1);
            }
        }

        // Find the maximum LIS value
        int ans = d[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, d[i]);
        }
        return ans;
    }
};

// Main function to test the LIS function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input array
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};s

    // Call lis function
    int result = sol.lis(arr);

    // Print result
    cout << "Length of Longest Increasing Subsequence: " << result << endl;

    return 0; // Program executed successfully
}
