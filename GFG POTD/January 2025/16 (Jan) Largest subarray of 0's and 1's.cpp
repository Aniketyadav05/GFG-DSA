//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        
    unordered_map<int, int> mp;

    int preSum = 0; 
    int res = 0; 
  
    // Traverse through the given array
    for (int i = 0; i < arr.size(); i++) {
      
        // Add current element to sum
          // if current element is zero, add -1
        preSum += (arr[i] == 0) ? -1 : 1;

        // To handle sum = 0 at last index
        if (preSum == 0) 
            res = i + 1;

        // If this sum is seen before, then update 
          // result with maximum
        if (mp.find(preSum) != mp.end())
            res = max(res, i - mp[preSum]);
        
        // Else put this sum in hash table
        else 
            mp[preSum] = i;
    }

    return res;
    }
};
//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}