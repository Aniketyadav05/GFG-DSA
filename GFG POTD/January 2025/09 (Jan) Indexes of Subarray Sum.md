## 09. Indexes of Subarray Sum

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1)**

### Problem Statement:

Given an unsorted array `arr` of non-negative integers and an integer `target`, find the starting and ending positions (1-based index) of a continuous subarray that adds up to `target`. If no such subarray exists, return `-1`.

### Example:

#### Input:
```
arr = [1, 2, 3, 7, 5]
target = 12
```

#### Output:
```
2 4
```

#### Explanation:
The subarray `[2, 3, 7]` sums to `12`, and its positions are 2 to 4.

### Approach:

1. **Sliding Window Technique:**
   - Use two pointers `i` and `j` to traverse the array and maintain the sum of the current window.
   - Start with both pointers at the beginning of the array.
   - Increment the `j` pointer and add `arr[j]` to the sum.
   - If the sum exceeds the `target`, move the `i` pointer to reduce the window size and subtract `arr[i]` from the sum.
   - If the sum equals the `target`, return the positions of the subarray.
   - Continue until `j` reaches the end of the array.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        vector<int> ans(2);
        
        int n = arr.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        
        while (j < n) {
            sum += arr[j];
            
            while (sum > target) {
                sum -= arr[i];
                i++;
            }
            
            if (sum == target) {
                ans[0] = i + 1;
                ans[1] = j + 1;
                return ans;
            }
            j++;
        }
        return {-1};
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}
```

### Explanation:

- **subarraySum Function:**
  - This function finds the subarray with the given sum using the sliding window technique.
  - If a subarray is found, it returns the starting and ending indices (1-based).
  - If no such subarray exists, it returns `-1`.

- **Main Function:**
  - It reads multiple test cases, each consisting of an array and a target value.
  - It calls the `subarraySum` function for each test case and prints the result.

### Complexity Analysis:

- **Time Complexity:**
  - The time complexity is `O(n)` because each element is visited at most twice (once by `i` and once by `j`).

- **Space Complexity:**
  - The space complexity is `O(1)` as we are using only a constant amount of extra space for variables.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
