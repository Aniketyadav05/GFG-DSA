# 14 Equilibrium Point

**The problem can be found at the following link: [Equilibrium Point](https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1)**

## Problem Statement:

Given an array `arr`, find the equilibrium point in the array. The equilibrium point is a position such that the sum of elements before it is equal to the sum of elements after it. The first element is considered at index 0.

### Example:

#### Input:
```
arr = [1, 3, 5, 2, 2]
```

#### Output:
```
2
```

#### Explanation:
The sum of elements before index 2 (`1 + 3`) is equal to the sum of elements after index 2 (`2 + 2`). Hence, index 2 is the equilibrium point.

### Approach:

1. **Calculate Total Sum:**
   - First, calculate the total sum of the array.

2. **Iterate Through the Array:**
   - Use a loop to iterate through each element, maintaining a running prefix sum.
   - For each element, calculate the suffix sum as `total sum - prefix sum - current element`.
   - Check if the prefix sum is equal to the suffix sum.
   - If they are equal, return the current index as the equilibrium point.

3. **Return -1:**
   - If no equilibrium point is found, return -1.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int prefSum = 0, total = 0;
        for (int ele: arr) {
            total += ele;
        }
        for (int pivot = 0; pivot < arr.size(); pivot++) {
            int suffSum = total - prefSum - arr[pivot];
            if (prefSum == suffSum) {
                return pivot;
            }
            prefSum += arr[pivot];
        }
        return -1;
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
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
```

### Explanation:

- **findEquilibrium Function:**
  - This function calculates the total sum of the array and then iterates through the array to find the equilibrium point.
  - It maintains a prefix sum and calculates the suffix sum dynamically to check for equilibrium.

- **Main Function:**
  - The main function reads multiple test cases, each consisting of an array.
  - It calls the `findEquilibrium` function for each test case and prints the equilibrium point index.

### Complexity Analysis:

- **Time Complexity:**
  - The time complexity is `O(n)` because each element is processed twice (once in the total sum calculation and once in the iteration).

- **Space Complexity:**
  - The space complexity is `O(1)` as we are using only a constant amount of extra space.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
