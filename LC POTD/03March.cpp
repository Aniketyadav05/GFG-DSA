#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to rearrange array elements based on pivot
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans; // Stores the final rearranged array
        int pivots = 0; // Counter for occurrences of pivot

        // First pass: Add elements smaller than pivot
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) ans.push_back(nums[i]);
            if (nums[i] == pivot) pivots++; // Count occurrences of pivot
        }

        // Add pivot elements in the middle
        while (pivots-- > 0) {
            ans.push_back(pivot);
        }

        // Second pass: Add elements greater than pivot
        for (int x = 0; x < nums.size(); x++) {
            if (nums[x] > pivot) ans.push_back(nums[x]);
        }

        return ans; // Return the rearranged array
    }
};

// Main function to test pivotArray function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    // Call pivotArray function
    vector<int> result = sol.pivotArray(nums, pivot);

    // Print rearranged array
    cout << "Rearranged Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
