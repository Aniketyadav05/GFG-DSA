# 17 Product of Array Except Self

**The problem can be found at the following link: [Product of Array Except Self](https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1)**

## Problem Statement:

Given an array `arr[]` of size `n`, construct a product array `P[]` (of the same size) such that `P[i]` is equal to the product of all the elements of `arr[]` except `arr[i]`.

### Example:

#### Input:
```
arr = [10, 3, 5, 6, 2]
```

#### Output:
```
180 600 360 300 900
```

#### Explanation:
For `arr[0]`, the product is `3 * 5 * 6 * 2 = 180`.
For `arr[1]`, the product is `10 * 5 * 6 * 2 = 600`.
And so on.

### Approach:

1. **Iterate through the array:**
   - Count the number of zeros in the array.
   - Calculate the product of all non-zero elements.
   - Store the index of the zero if there is exactly one zero.
   
2. **Construct the result array:**
   - If there are no zeros, for each element `arr[i]`, the result is `prod / arr[i]`.
   - If there is exactly one zero, set the product at the index of the zero.
   - If there are more than one zeros, the result is all zeros because the product of the array excluding any element will always include a zero.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int zeros = 0, idx = -1;
        int prod = 1;

        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 0) {
                zeros++;
                idx = i;
            } else {
                prod *= arr[i];
            }
        }

        vector<int> res(arr.size(), 0);

        if (zeros == 0) {
            for (int i = 0; i < arr.size(); i++)
                res[i] = prod / arr[i];
        }
        else if (zeros == 1)
            res[idx] = prod;

        return res;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
```

### Explanation:

- **productExceptSelf Function:**
  - It calculates the product of all non-zero elements and counts the zeros.
  - Based on the count of zeros, it constructs the result array with the appropriate products.

- **Main Function:**
  - It reads multiple test cases.
  - Converts each test case into an array.
  - Calls the `productExceptSelf` function and prints the result for each test case.

### Complexity Analysis:

- **Time Complexity:**
  - The time complexity is `O(n)` because each element is processed once.

- **Space Complexity:**
  - The space complexity is `O(n)` for the result array.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

