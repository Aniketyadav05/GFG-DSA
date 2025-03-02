#include <iostream>
#include <vector>
#include <deque> // Required for deque

using namespace std;

class Solution {
public:
    // Function to find the maximum of each subarray of size k
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> res; // Stores results
        deque<int> dq;   // Deque to store indices of elements

        for (int i = 0; i < arr.size(); ++i) {
            // Remove elements that are out of the current window
            if (!dq.empty() && dq.front() <= i - k) 
                dq.pop_front();

            // Remove smaller elements from back as they won't be needed
            while (!dq.empty() && arr[dq.back()] < arr[i]) 
                dq.pop_back();

            // Add current element index to deque
            dq.push_back(i);

            // Add maximum of current window to result (starts at index k-1)
            if (i >= k - 1) 
                res.push_back(arr[dq.front()]);
        }

        return res;
    }
};

// Main function to test the maxOfSubarrays function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3; // Window size

    // Call function
    vector<int> result = sol.maxOfSubarrays(arr, k);

    // Print result
    cout << "Maximum of each subarray of size " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
