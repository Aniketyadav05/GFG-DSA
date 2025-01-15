## 08. Count Pairs with Sum Less Than Target

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-less-than-target/1)**

### Problem Statement:

Given an array of integers `arr` and a target integer `target`, the task is to count the number of pairs `(i, j)` where `i < j` such that `arr[i] + arr[j] < target`.

### Example:

#### Input:
```
arr = [1, 2, 3, 4, 5]
target = 7
```

#### Output:
```
6
```

#### Explanation:
The pairs are:
- (1, 2)
- (1, 3)
- (1, 4)
- (2, 3)
- (2, 4)
- (3, 4)

### Approach:

1. **Sorting and Two-Pointer Technique:**
   - First, sort the array in ascending order.
   - Initialize two pointers: `left` at the start (0) and `right` at the end (`n-1`) of the array.
   - Use a loop to check the sum of the elements pointed by `left` and `right`.
   - If the sum is less than the target, all pairs from `left` to `right-1` will satisfy the condition, and we increase `left` to find more pairs.
   - If the sum is greater than or equal to the target, we decrease `right` to reduce the sum.
   - Continue this until `left` is less than `right`.

### Code

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
                cnt += right - left;
                left++;
            } else {
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

### Explanation:

- **countPairs Function:**
  - This function takes the array `arr` and the `target` as inputs.
  - It sorts the array and uses a two-pointer approach to count the number of pairs whose sum is less than `target`.
  - It keeps a running count of pairs that satisfy the condition.

- **Main Function:**
  - The main function reads multiple test cases, each consisting of an array and a target value.
  - It calls the `countPairs` function for each test case and prints the number of valid pairs.

### Complexity Analysis:

- **Time Complexity:**
  - Sorting the array takes `O(n log n)` time.
  - The two-pointer traversal takes `O(n)` time.
  - Thus, the overall time complexity is `O(n log n)`.

- **Space Complexity:**
  - The space complexity is `O(1)` as we are using only a constant amount of extra space for the two pointers.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
