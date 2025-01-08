## 05. Count Pairs with Sum Less Than Target

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-less-than-target/1)**

## Problem Statement

Given an array of integers `arr` and an integer `target`, the task is to find the number of pairs in the array whose sum is less than `target`.

### Example

**Input:**
```
arr = [1, 5, 3, 4, 2], target = 6
```

**Output:**
```
4
```

### Explanation:
The pairs `(1, 5)`, `(1, 3)`, `(1, 4)`, and `(1, 2)` have sums less than `6`.

## Solution Approach

The solution involves the following steps:

1. **Sorting the Array:**
   - First, sort the array to simplify the process of finding pairs with sums less than `target`.

2. **Two Pointer Technique:**
   - Use two pointers (`left` and `right`) to traverse the array from both ends.
   - If the sum of the elements pointed to by `left` and `right` is less than `target`, count all pairs between `left` and `right` and move the `left` pointer.
   - If the sum is greater than or equal to `target`, move the `right` pointer.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int left = 0, right = arr.size() - 1;
        int cnt = 0;
        while(left < right) {
            int sum = arr[left] + arr[right];
            if (sum < target) {
                cnt += right-left;
                left++;
            }
            else {
                right--;
            }
        }
        return cnt;
    }
};

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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
```

## Explanation

- **countPairs Function:** The function sorts the array and uses the two-pointer technique to count pairs with sums less than `target`.
- **Main Function:** Reads input, processes each test case, and outputs the count of pairs with sums less than `target`.

## Complexity Analysis

- **Time Complexity:** O(N log N), where N is the size of the array, due to sorting.
- **Space Complexity:** O(1), as the algorithm uses constant extra space.

## Contribution and Support
For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
```
