#include <iostream>
#include <vector>
#include <deque> // Required for deque

using namespace std;

class Solution {
public:
    // Function to find the longest subarray where max - min <= x
    vector<int> longestSubarray(vector<int>& arr, int x) {
        deque<int> minQueue, maxQueue; // Deques to maintain min and max elements

        int n = arr.size();
        int start = 0, end = 0; // Pointers for the sliding window
        int resStart = 0, resEnd = 0; // Pointers for the result subarray

        while (end < n) {
            // Maintain increasing order in minQueue
            while (!minQueue.empty() && arr[minQueue.back()] > arr[end])
                minQueue.pop_back();
            
            // Maintain decreasing order in maxQueue
            while (!maxQueue.empty() && arr[maxQueue.back()] < arr[end])
                maxQueue.pop_back();
            
            // Push current index into both queues
            minQueue.push_back(end);
            maxQueue.push_back(end);
            
            // If the max - min difference exceeds x, shrink window from the start
            while (arr[maxQueue.front()] - arr[minQueue.front()] > x) {
                if (start == minQueue.front()) minQueue.pop_front();
                if (start == maxQueue.front()) maxQueue.pop_front();
                start++;
            }
            
            // Update longest subarray range
            if (end - start > resEnd - resStart) {
                resStart = start;
                resEnd = end;
            }
            end++;
        }

        // Store the longest subarray
        vector<int> res;
        for (int i = resStart; i <= resEnd; i++)
            res.push_back(arr[i]);
        
        return res;
    }
};

// Main function to test longestSubarray function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input array
    vector<int> arr = {8, 2, 4, 7};
    int x = 4; // Maximum allowed difference

    // Call longestSubarray function
    vector<int> result = sol.longestSubarray(arr, x);

    // Print the longest valid subarray
    cout << "Longest valid subarray: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0; // Program executed successfully
}
