//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution {
  public:
  int Isok(int dist, vector<int>& stalls) {
        int count = 1; // Place the first cow in the first stall
        int lastPlaced = stalls[0]; // Track the position of the last placed cow

        for (int i = 1; i < stalls.size(); i++) {
            // Place the next cow if the distance condition is met
            if (stalls[i] - lastPlaced >= dist) {
                count++;
                lastPlaced = stalls[i];
            }
        }

        return count;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n = stalls.size();

        // Sort the stalls to simplify distance calculations
        sort(stalls.begin(), stalls.end());

        // Define the search space for the minimum distance
        int l = 0; // Minimum possible distance
        int r = stalls[n - 1] - stalls[0]; // Maximum possible distance
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // Check if we can place at least `k` cows with distance `mid`
            if (Isok(mid, stalls) >= k) {
                ans = mid;  // Update the answer
                l = mid + 1; // Try for a larger distance
            } else {
                r = mid - 1; // Try for a smaller distance
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends