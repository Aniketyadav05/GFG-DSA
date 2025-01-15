
## 03. Subarrays with XOR K

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1)**

## Problem Statement

Given an array of integers `arr` and an integer `k`, the task is to find the number of subarrays whose XOR is equal to `k`.

### Example

**Input:**
```
arr = [4, 2, 2, 6, 4], k = 6
```

**Output:**
```
4
```

### Explanation:
The subarrays with XOR equal to `6` are `[4, 2]`, `[4, 2, 2, 6]`, `[2, 2, 6, 4]`, and `[6]`.

## Solution Approach

The solution involves the following steps:

1. **Prefix XOR and Hash Map:**
   - Calculate the XOR prefix for each element of the array.
   - Use a hash map to store the frequency of each XOR prefix encountered.
   - For each XOR prefix, check if there is a previous XOR prefix such that the XOR between them is `k`. If such a prefix exists, the count of such subarrays is incremented.

2. **Counting Subarrays:**
   - If the XOR difference is found in the hash map, it indicates that there are subarrays ending at the current index which XOR to `k`.
   - Update the hash map with the current XOR prefix for future reference.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        int xr = 0;
        map<int, int> mpp; 
        mpp[xr]++;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            xr = xr ^ arr[i];
            int x = xr ^ k;
            cnt += mpp[x];
            mpp[xr]++;
        }
        return cnt;
    }
};

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc-- > 0) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num);
        }

        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
```

## Explanation

- **subarrayXor Function:** Calculates the number of subarrays that have an XOR equal to `k` using prefix XOR and a hash map.
- **Main Function:** Reads input, processes each test case, and outputs the count of subarrays that XOR to `k`.

## Complexity Analysis

- **Time Complexity:** O(N), where N is the size of the array. Each element is processed once, and hash map operations are on average O(1).
- **Space Complexity:** O(N) for storing the prefix XORs in the hash map.

## Contribution and Support
For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

