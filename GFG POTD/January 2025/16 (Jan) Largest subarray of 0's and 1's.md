# 16 Largest Subarray with Equal Number of 0s and 1s

**The problem can be found at the following link: [Largest Subarray with Equal Number of 0s and 1s](https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1)**

## Problem Statement:

Given an array `arr` of integers containing only 0s and 1s, find the length of the largest subarray with an equal number of 0s and 1s.

### Example:

#### Input:
```
arr = [0, 1, 0, 1, 1, 1, 0]
```

#### Output:
```
6
```

#### Explanation:
The subarray `[0, 1, 0, 1, 1, 0]` contains an equal number of 0s and 1s and is the largest such subarray.

### Approach:

1. **Prefix Sum and Hash Map:**
   - Convert 0s to -1s in the array to use the prefix sum method.
   - Use a hash map to store the first occurrence of each prefix sum.
   - Traverse the array while maintaining the prefix sum.
   - If the prefix sum is 0, the subarray from the start to the current index is balanced.
   - For each element, calculate the difference between the prefix sum and 0.
   - If the difference exists in the hash map, it indicates a balanced subarray.
   - Update the result with the length of the subarray.
   - If the prefix sum is not in the hash map, store it with its index.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        unordered_map<int, int> mp;
        int preSum = 0; 
        int res = 0; 
  
        for (int i = 0; i < arr.size(); i++) {
            preSum += (arr[i] == 0) ? -1 : 1;

            if (preSum == 0) 
                res = i + 1;

            if (mp.find(preSum) != mp.end())
                res = max(res, i - mp[preSum]);
            else 
                mp[preSum] = i;
        }

        return res;
    }
};

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        Solution obj;
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
```

### Explanation:

- **maxLen Function:**
  - It uses a prefix sum and a hash map to find the largest subarray with equal 0s and 1s.
  - The prefix sum is adjusted to treat 0s as -1s.
  - If the prefix sum is 0, the subarray from the start to the current index is balanced.
  - If the prefix sum has been seen before, it calculates the length of the subarray between the previous occurrence and the current index.

- **Main Function:**
  - The main function reads multiple test cases, each consisting of an array.
  - It calls the `maxLen` function for each test case and prints the length of the largest balanced subarray.

### Complexity Analysis:

- **Time Complexity:**
  - The time complexity is `O(n)` because each element is processed once.

- **Space Complexity:**
  - The space complexity is `O(n)` due to the hash map used to store the prefix sums.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
