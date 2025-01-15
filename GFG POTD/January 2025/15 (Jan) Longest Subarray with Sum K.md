# 15 Longest Subarray with Sum K

**The problem can be found at the following link: [Longest Subarray with Sum K](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1)**

## Problem Statement:

Given an array `arr` of integers and an integer `k`, find the length of the longest subarray whose sum is equal to `k`.

### Example:

#### Input:
```
arr = [10, 5, 2, 7, 1, 9]
k = 15
```

#### Output:
```
4
```

#### Explanation:
The subarray `[5, 2, 7, 1]` sums up to `15` and is the longest such subarray.

### Approach:

1. **Prefix Sum and Hash Map:**
   - Use a hash map to store the first occurrence of each prefix sum.
   - Traverse the array while maintaining the prefix sum.
   - For each element, calculate the difference between the prefix sum and `k`.
   - If the difference exists in the hash map, it indicates a subarray with sum `k`.
   - Update the result with the length of the subarray.
   - If the prefix sum is not in the hash map, store it with its index.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
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

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine);
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore();

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}
```

### Explanation:

- **longestSubarray Function:**
  - It uses a prefix sum and a hash map to find the longest subarray with sum `k`.
  - If the prefix sum minus `k` exists in the hash map, it updates the result with the length of the subarray found.

- **Main Function:**
  - The main function reads multiple test cases, each consisting of an array and a target sum `k`.
  - It calls the `longestSubarray` function for each test case and prints the length of the longest subarray with sum `k`.

### Complexity Analysis:

- **Time Complexity:**
  - The time complexity is `O(n)` because each element is processed once.

- **Space Complexity:**
  - The space complexity is `O(n)` due to the hash map used to store the prefix sums.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
