## 16. Find K-th Element in Two Sorted Arrays

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1)**

**Problem Statement:**

Given two sorted arrays `a` and `b`, and an integer `k`, the task is to find the `k`-th smallest element from the two arrays combined.

### Example

**Input:**
```
a = [2, 3, 4, 10]
b = [1, 5, 8, 12]
k = 5
```

**Output:**
```
8
```

### Explanation:
When both arrays are merged, the combined array is `[1, 2, 3, 4, 5, 8, 10, 12]`. The 5th smallest element is `8`.

## Solution Approach

The solution uses the following simple approach:

1. **Two-pointer Technique:**
   - Use two pointers (`i` and `j`) to traverse both arrays.
   - Compare the elements at `a[i]` and `b[j]`. The smaller one is added to the result, and the respective pointer is moved forward.
   - Repeat the process `k` times to find the `k`-th smallest element.

2. **Handling Arrays of Different Sizes:**
   - If one array is exhausted (i.e., pointer moves beyond the array), continue comparing the remaining elements in the other array.

3. **Return the `k`-th Element:**
   - After `k` iterations, the variable `last` will store the `k`-th smallest element, which is returned.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        int last = 0;
        int i = 0, j = 0;
        for (int d = 0; d < k; d++) {
            if (i < n) {
                if (j < m && a[i] > b[j]) {
                    last = b[j];
                    j++;
                }
                else {
                    last = a[i];
                    i++;
                }
            }
            else if (j < m) {
                last = b[j];
                j++;
            }
        }
        return last;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
```

## Explanation:

- **kthElement Function:** 
  - It uses two pointers to iterate through both arrays and compares elements to find the `k`-th smallest element.
  - The pointer for the smaller element is moved forward until we find the `k`-th element.

- **Main Function:**
  - Reads input for multiple test cases and passes the arrays and `k` to the `kthElement` function to get the desired result.

## Complexity Analysis

- **Time Complexity:** O(k), because we only need to iterate `k` times to find the `k`-th element, and each iteration involves a constant time operation.
- **Space Complexity:** O(1), because we are only using a fixed number of extra variables regardless of the input size.

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
