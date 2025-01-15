//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int res = 0;
        int prefSum = 0;
    
        for (int i = 0; i < arr.size(); ++i) {
            prefSum += arr[i];
    
            
            if (prefSum == k) 
                res = i + 1;
    
            
            else if (mp.find(prefSum - k) != mp.end()) 
                res = max(res, i - mp[prefSum - k]);
    
            
              if (mp.find(prefSum) == mp.end())
                mp[prefSum] = i;
        }
    
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends