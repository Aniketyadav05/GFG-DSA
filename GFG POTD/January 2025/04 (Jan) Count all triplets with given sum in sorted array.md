## 04. Count Triplets with a Given Sum

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/count-all-triplets-with-given-sum-in-sorted-array/1)**

## Problem Statement

Given an array of integers `arr` and an integer `target`, the task is to count the number of triplets `(i, j, k)` such that `arr[i] + arr[j] + arr[k]` equals the `target`.

### Example

**Input:**
```
arr = [1, 2, 3, 4, 5], target = 8
```

**Output:**
```
2
```

### Explanation:
The triplets that sum to `8` are `[1, 2, 5]` and `[1, 3, 4]`.

## Solution Approach

The solution involves the following steps:

1. **Two Pointers Technique:**
   - Iterate through the array with one pointer `i`.
   - For each element, use two pointers `left` and `right` to find triplets that sum to the `target`.
   - If the sum is less than `target`, move the `left` pointer to the right to increase the sum.
   - If the sum is greater than `target`, move the `right` pointer to the left to decrease the sum.
   - If the sum equals `target`, count the triplets and handle duplicates.

2. **Counting Triplets:**
   - If duplicates are found for `left` or `right` elements, count them accordingly and adjust the pointers.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size(), res = 0;
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    if (arr[left] == arr[right]) {
                        int count = right - left + 1;
                        res += (count * (count - 1)) / 2;
                        break;
                    } else {
                        int cnt1 = 1, cnt2 = 1;
                        while (left + 1 < right && arr[left] == arr[left + 1]) ++left, ++cnt1;
                        while (right - 1 > left && arr[right] == arr[right - 1]) --right, ++cnt2;
                        res += cnt1 * cnt2;
                        ++left;
                        --right;
                    }
                }
            }
        }
        return res;
    }
};

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}
```

## Explanation

- **countTriplets Function:** Finds the number of triplets that sum to the `target` using the two-pointer technique.
- **Main Function:** Reads input, processes each test case, and outputs the count of triplets that sum to the `target`.

## Complexity Analysis

- **Time Complexity:** O(N^2), where N is the size of the array. Each triplet is checked once.
- **Space Complexity:** O(1), as we are not using extra space except for variables.

## Contribution and Support
For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

