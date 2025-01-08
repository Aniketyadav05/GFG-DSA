## 06. Closest Pair to Target Sum

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1)**

## Problem Statement

Given an array of integers `arr` and an integer `target`, the task is to find a pair of elements from the array such that the sum of the pair is closest to the `target`.

### Example

**Input:**
```
arr = [10, 22, 28, 29, 30, 40], target = 54
```

**Output:**
```
22 30
```

### Explanation:
The pair `(22, 30)` has the sum closest to `54`.

## Solution Approach

The solution involves the following steps:

1. **Sorting the Array:**
   - First, sort the array to simplify the process of finding the closest pair.

2. **Binary Search for Closest Pair:**
   - For each element in the array, calculate the complement needed to reach the target.
   - Use a binary search helper function to find the element closest to the complement in the sorted array.
   - Update the result if the current pair is closer to the target than the previously found pairs.

3. **Minimizing the Difference:**
   - Keep track of the minimum difference between the sum of the pair and the target.
   - Update the result whenever a closer pair is found.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findClosest(vector<int>& arr, int lo, int hi, int complement) {
        int res = arr[lo];
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (abs(arr[mid] - complement) < abs(res - complement))
                res = arr[mid];
            else if (abs(arr[mid] - complement) == abs(res - complement))
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
            if (currDiff < minDiff) {
                minDiff = currDiff;
                res = {arr[i], closest};
            }
        }
        return res;
    }
};

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
```

## Explanation

- **findClosest Function:** Uses binary search to find the element closest to the complement in the sorted array.
- **sumClosest Function:** Iterates through the array, calculates the complement for each element, and finds the closest pair using `findClosest`.
- **Main Function:** Reads input, processes each test case, and outputs the pair of elements whose sum is closest to the target.

## Complexity Analysis

- **Time Complexity:** O(N log N), where N is the size of the array, due to sorting and binary search.
- **Space Complexity:** O(1), as the algorithm uses constant extra space.

## Contribution and Support
For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
```
