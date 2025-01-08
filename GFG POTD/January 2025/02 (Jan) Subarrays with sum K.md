## 02. Subarrays with sum K
**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1)**

## Problem Statement

Given an array of integers `arr` and an integer `k`, the task is to find the number of subarrays whose sum is equal to `k`.

### Example

**Input:**
```
arr = [1, 1, 1], k = 2
```

**Output:**
```
2
```

### Explanation:
There are two subarrays `[1, 1]` and `[1, 1]` that sum to `2`.

## Solution Approach

The solution involves the following steps:

1. **Prefix Sum and Hash Map:**
   - Calculate the prefix sum for each element of the array.
   - Use a hash map to store the frequency of each prefix sum encountered.
   - For each prefix sum, check if there is a previous prefix sum such that the difference between them is `k`. If such a prefix sum exists, the count of such subarrays is incremented.

2. **Counting Subarrays:**
   - If the prefix sum difference is found in the hash map, it indicates that there are subarrays ending at the current index which sum to `k`.
   - Update the hash map with the current prefix sum for future reference.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int n = arr.size(); 
        map<int, int> mpp;
        int preSum = 0, cnt = 0;

        mpp[0] = 1; 
        for (int i = 0; i < n; i++) {
            preSum += arr[i];
            int remove = preSum - k;
            cnt += mpp[remove];
            mpp[preSum] += 1;
        }
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
```

## Explanation

- **countSubarrays Function:** Calculates the number of subarrays that sum to `k` using prefix sums and a hash map.
- **Main Function:** Reads input, processes each test case, and outputs the count of subarrays that sum to `k`.

## Complexity Analysis

- **Time Complexity:** O(N), where N is the size of the array. Each element is processed once, and hash map operations are on average O(1).
- **Space Complexity:** O(N) for storing the prefix sums in the hash map.

## Contribution and Support
For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐