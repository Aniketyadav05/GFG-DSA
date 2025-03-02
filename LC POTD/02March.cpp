#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to merge two 2D arrays by summing values with the same key
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int cnt[1001]{}; // Array to store summed values for indices 0 to 1000
        
        // Process nums1 and sum values based on the first element (key)
        for (auto& x : nums1) {
            cnt[x[0]] += x[1];
        }

        // Process nums2 and sum values similarly
        for (auto& x : nums2) {
            cnt[x[0]] += x[1];
        }

        vector<vector<int>> ans; // Stores the final merged array

        // Collect non-zero elements from cnt array
        for (int i = 0; i < 1001; ++i) {
            if (cnt[i]) {
                ans.push_back({i, cnt[i]}); // Store key-value pairs in result
            }
        }
        return ans;
    }
};

// Main function to test mergeArrays function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 3}, {3, 4}, {4, 2}};

    // Call mergeArrays function
    vector<vector<int>> result = sol.mergeArrays(nums1, nums2);

    // Print merged result
    cout << "Merged Arrays:" << endl;
    for (const auto& row : result) {
        cout << "{" << row[0] << ", " << row[1] << "} ";
    }
    cout << endl;

    return 0;
}
