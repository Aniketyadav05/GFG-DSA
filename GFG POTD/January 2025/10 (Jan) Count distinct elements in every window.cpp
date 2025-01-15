//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n = arr.size();  
        vector<int> res;
        unordered_map<int, int> freq;
      
       
        for(int i = 0; i < k; i++)
            freq[arr[i]] += 1;
      
        res.push_back(freq.size());
      
        for(int i = k; i < n; i++) {
            freq[arr[i]] += 1;
            freq[arr[i - k]] -= 1;
          
        
            if(freq[arr[i - k]] == 0)
                freq.erase(arr[i - k]);
          
            res.push_back(freq.size());
        }
      
    return res;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
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
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends