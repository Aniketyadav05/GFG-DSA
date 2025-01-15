## 19. Find the Kth Missing Number

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/kth-missing-positive-number-in-a-sorted-array/1)**

### Problem Statement:

Given a sorted array `arr[]` containing `n` distinct integers, and an integer `k`, the task is to find the `k`th missing number from the array. The array contains some missing numbers in the sequence of natural numbers starting from 1. The goal is to find the kth missing number in this sequence.

### Example

**Input:**
```
arr = [2, 3, 4, 7, 11]
k = 5
```

**Output:**
```
9
```

**Explanation:**
The sequence of missing numbers is: [1, 5, 6, 8, 9]. The 5th missing number is `9`.

## Approach

1. **Binary Search:**
   - Since the array is sorted, we can apply **binary search** to efficiently find the kth missing number.
   - The idea is to calculate how many numbers are missing up to the current index during the binary search process.
   - For each middle point of the array (`arr[mid]`), the number of missing elements before `arr[mid]` is given by `arr[mid] - (mid + 1)`.
   
2. **Binary Search Logic:**
   - If the number of missing elements before the middle element is less than `k`, we need to look to the right of the middle element.
   - If the number of missing elements is greater than or equal to `k`, we search the left half of the array.

3. **Final Answer:**
   - After narrowing down the search, the kth missing element will be the one that's not yet encountered in the array.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return k + high + 1;
    }
};

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {
        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
```

### Explanation:

- **kthMissing Function:**
  - This function implements a binary search to find the kth missing number in the sequence.
  - It calculates how many numbers are missing before each midpoint and adjusts the search bounds based on that.
  
- **Main Function:**
  - It reads the input and calls the `kthMissing` function for each test case, printing the result for each.

## Complexity Analysis

- **Time Complexity:**
  - The binary search runs in O(log N) where N is the size of the array. Each operation is constant time, so the total time complexity is O(log N).

- **Space Complexity:**
  - The space complexity is O(N) due to the storage of the input array and some additional variables for calculations.
  
## Contribution and Support
For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
