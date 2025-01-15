//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int prefSum = 0, total = 0;

       
        for (int ele: arr) {
            total += ele;
        }
    
        
        for (int pivot = 0; pivot < arr.size(); pivot++) {
              int suffSum = total - prefSum - arr[pivot];
              if (prefSum == suffSum) {
                  return pivot;
            }
              prefSum += arr[pivot];
        }
    
       
        return -1;
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends

