## 08. Find Peak Element

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/peak-element/1)**

**Problem Statement:**

Given an array of integers `arr`, the task is to find the index of the peak element. A peak element is an element that is strictly greater than its neighbors. For corner elements (first and last elements), we need to check only one neighbor.

### Example

**Input:**
```
arr = [1, 3, 20, 4, 1]
```

**Output:**
```
2
```

### Explanation:
The peak element is `20` at index `2`, as it is greater than its neighbors `3` and `4`.

## Solution Approach

The solution involves the following steps:

1. **Finding the Peak Element:**
   - Traverse through the array and compare each element with its neighbors.
   - If an element is greater than both its neighbors, it is a peak element.
   - If the element is the first or last element, only one neighbor is checked.

2. **Edge Cases:**
   - Handle cases where the array has only one element or when the peak element is at the first or last position.

3. **Return the Index of the Peak:**
   - Once a peak element is found, return its index.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int max=arr[0],idx=0;
        for(int i =0;i<arr.size();i++){
            if(arr[i]>max){
                max = arr[i];
                idx=i;
            }
        }
        return idx;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int idx = ob.peakElement(a);
        int n = a.size();
        bool f = 0;
        if (idx < 0 and idx >= n)
            cout << "false" << endl;
        else {
            if (n == 1 and idx == 0)
                f = 1;
            else if (idx == 0 and a[0] > a[1])
                f = 1;
            else if (idx == n - 1 and a[n - 1] > a[n - 2])
                f = 1;
            else if (a[idx] > a[idx + 1] and a[idx] > a[idx - 1])
                f = 1;
            else
                f = 0;
            if (f)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
```

## Explanation:

- **peakElement Function:** 
  - Iterates through the array to find the element with the highest value, checking if it is a peak element.
  - Returns the index of the peak element.

- **Main Function:**
  - Reads input for multiple test cases, processes each test case, and checks whether the element at the returned index is a valid peak element.

## Complexity Analysis

- **Time Complexity:** O(N), where N is the size of the array, due to the linear scan to find the peak element.
- **Space Complexity:** O(1), as the algorithm uses constant extra space (other than input storage).

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

