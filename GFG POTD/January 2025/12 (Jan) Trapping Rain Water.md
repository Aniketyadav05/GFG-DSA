# 12 Trapping Rain Water

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1)**

## Problem Statement:

Given an array `arr` representing the height of blocks, calculate the amount of water that can be trapped between the blocks after raining.

### Example:

#### Input:
```
arr = [3, 0, 0, 2, 0, 4]
```

#### Output:
```
10
```

#### Explanation:
Water trapped:
- Between blocks 0 and 3, 3 units of water are trapped.
- Between blocks 3 and 5, 1 unit of water is trapped.
- Between blocks 1 and 5, 6 units of water are trapped.

Total trapped water = 3 + 1 + 6 = 10 units.

### Approach:

1. **Two-Pointer Technique:**
   - Initialize two pointers, `left` and `right`, to the start and end of the array, respectively.
   - Maintain two variables, `lMax` and `rMax`, to track the maximum heights encountered from the left and right.
   - Use a loop to move the pointers towards each other, calculating the trapped water at each step.
   - If the right max is less than or equal to the left max, calculate the trapped water at the right pointer, update `rMax`, and move the `right` pointer to the left.
   - If the left max is less than the right max, calculate the trapped water at the left pointer, update `lMax`, and move the `left` pointer to the right.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int left = 1;
        int right = arr.size() - 2;
        int lMax = arr[left - 1];
        int rMax = arr[right + 1];
        int res = 0;
        while (left <= right) {
            if (rMax <= lMax) {
                res += max(0, rMax - arr[right]);
                rMax = max(rMax, arr[right]);
                right -= 1;
            } else { 
                res += max(0, lMax - arr[left]);
                lMax = max(lMax, arr[left]);
                left += 1;
            }
        }
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
        Solution ob;
        int res = ob.maxWater(arr);
        cout << res << endl << "~" << endl;
    }
    return 0;
}
```

### Explanation:

- **maxWater Function:**
  - This function takes the array `arr` as input.
  - It uses the two-pointer technique to calculate the amount of trapped water.
  - It keeps a running total of water trapped at each step and returns the result.

- **Main Function:**
  - The main function reads multiple test cases, each consisting of an array of block heights.
  - It calls the `maxWater` function for each test case and prints the amount of trapped water.

### Complexity Analysis:

- **Time Complexity:**
  - The time complexity is `O(n)` because each block is processed at most twice.

- **Space Complexity:**
  - The space complexity is `O(1)` as we are using only a constant amount of extra space.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
