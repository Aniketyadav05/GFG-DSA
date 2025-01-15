# 13 Container With Most Water

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/container-with-most-water0535/1)**

## Problem Statement:

Given an array `arr` representing the heights of bars, find two bars that together with the x-axis form a container that can hold the most water. Return the maximum amount of water a container can store.

### Example:

#### Input:
```
arr = [1, 8, 6, 2, 5, 4, 8, 3, 7]
```

#### Output:
```
49
```

#### Explanation:
The vertical lines are drawn such that the height of the container is the smaller height of the two bars, and the width of the container is the distance between the two bars. The container formed between indices 1 and 8 (1-based indexing) has a height of 7 (the smaller of heights 8 and 7) and a width of 7, so it can hold 7 * 7 = 49 units of water.

### Approach:

1. **Two-Pointer Technique:**
   - Initialize two pointers, `left` at the beginning and `right` at the end of the array.
   - Calculate the area between the bars at these pointers and keep track of the maximum area found.
   - Move the pointer pointing to the shorter bar towards the other pointer to potentially find a larger area.
   - Repeat the process until the pointers meet.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int res = 0;
        while(left < right) {
            int water = min(arr[left], arr[right]) * (right - left);
            res = max(res, water);
            if(arr[left] < arr[right])
                left += 1;
            else
                right -= 1;
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
  - This function uses the two-pointer technique to calculate the maximum area that can be formed between two bars.
  - It keeps track of the maximum area found and adjusts the pointers based on the heights of the bars.

- **Main Function:**
  - The main function reads multiple test cases, each consisting of an array of bar heights.
  - It calls the `maxWater` function for each test case and prints the maximum water the container can hold.

### Complexity Analysis:

- **Time Complexity:**
  - The time complexity is `O(n)` because each bar is considered at most once as we move the pointers.

- **Space Complexity:**
  - The space complexity is `O(1)` as we are using only a constant amount of extra space.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
