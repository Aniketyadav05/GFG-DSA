//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  int findClosest(vector<int>& arr, int lo, int hi, int complement) {
    int res = arr[lo];
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

    
        if (abs(arr[mid] - complement) < abs(res - complement))
            res = arr[mid];
      
        else if(abs(arr[mid] - complement) == abs(res - complement))
            res = max(res, arr[mid]);   
        
        if (arr[mid] == complement) 
            return arr[mid];
        else if (arr[mid] < complement)
            lo = mid + 1;
        else 
            hi = mid - 1;
    }

    return res;
}
vector<int> sumClosest(vector<int>& arr, int target) {
  
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> res;
    int minDiff = INT_MAX;

    for (int i = 0; i < n - 1; i++) {
      
        
        int complement = target - arr[i];
        int closest = findClosest(arr, i + 1, n - 1, complement);
      
        int currDiff = abs(target - arr[i] - closest);
        if(currDiff < minDiff) {
            minDiff = currDiff;
            res = {arr[i], closest};
        }
    }

    return res;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends