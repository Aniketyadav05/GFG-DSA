## 10. Count Distinct Elements in Every Window

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1)**

### Problem Statement:

Given an array of integers `arr` and an integer `k`, your task is to find the number of distinct elements in every window of size `k` in the array.

### Example:

#### Input:
```
arr = [1, 2, 1, 3, 4, 2, 3]
k = 4
```

#### Output:
```
3 4 4 3
```

#### Explanation:
- The first window is `[1, 2, 1, 3]` with 3 distinct numbers: 1, 2, 3.
- The second window is `[2, 1, 3, 4]` with 4 distinct numbers: 1, 2, 3, 4.
- The third window is `[1, 3, 4, 2]` with 4 distinct numbers: 1, 2, 3, 4.
- The fourth window is `[3, 4, 2, 3]` with 3 distinct numbers: 2, 3, 4.

### Approach:

1. **Sliding Window with Hash Map:**
   - Use an `unordered_map` to track the frequency of elements in the current window of size `k`.
   - As you slide the window, add the new element and remove the element that is no longer in the window.
   - Store the size of the `unordered_map` after each iteration as it represents the count of distinct elements in the window.

### Code

```cpp
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
      
       // Add first k elements to the map
        for(int i = 0; i < k; i++)
            freq[arr[i]] += 1;
      
        res.push_back(freq.size());
      
        for(int i = k; i < n; i++) {
            freq[arr[i]] += 1;
            freq[arr[i - k]] -= 1;
          
            // Remove the element if its frequency becomes 0
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
```

### Explanation:

- **countDistinct Function:**
  - This function takes the array `arr` and the integer `k` as inputs.
  - It initializes an `unordered_map` to store the frequency of elements in the current window.
  - It first populates the map with the first `k` elements and then slides the window, updating the map by adding the next element and removing the first element of the previous window.
  - The size of the map at each step gives the count of distinct elements in the current window.

- **Main Function:**
  - Reads multiple test cases, each consisting of an array and the window size `k`.
  - Calls the `countDistinct` function for each test case and prints the result.

### Complexity Analysis:

- **Time Complexity:**
  - The initial population of the map takes `O(k)` time.
  - Each slide of the window takes `O(1)` time for insertion and deletion, resulting in `O(n - k)` for all slides.
  - Overall time complexity is `O(n)`.

- **Space Complexity:**
  - The space complexity is `O(k)` for the map.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

