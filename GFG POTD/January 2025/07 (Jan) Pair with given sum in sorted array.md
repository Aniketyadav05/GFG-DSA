## 07. Count Pairs with Given Sum


**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1)**

**Problem Statement:**

Given an array of integers `arr` and an integer `target`, the task is to count the number of distinct pairs of elements in the array whose sum is equal to the given `target`.

### Example

**Input:**
```
arr = [1, 2, 3, 4, 3, 5], target = 6
```

**Output:**
```
2
```

### Explanation:
The pairs `(1, 5)` and `(2, 4)` are the two distinct pairs that sum up to `6`.

## Solution Approach

The solution involves the following steps:

1. **Sorting the Array:**
   - First, sort the array to allow efficient two-pointer traversal.

2. **Two-pointer Approach:**
   - Use two pointers: one starting from the beginning (`left`) and one starting from the end (`right`) of the array.
   - Move the pointers based on the sum of the elements at the current positions:
     - If the sum is less than the target, move the `left` pointer to the right to increase the sum.
     - If the sum is greater than the target, move the `right` pointer to the left to decrease the sum.
     - If the sum equals the target, count the number of occurrences of both elements and update the result.

3. **Handling Duplicate Elements:**
   - If both `arr[left]` and `arr[right]` are the same, calculate the number of combinations of those elements.
   - Otherwise, multiply the counts of both elements to get the total number of distinct pairs.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int res = 0;
        int n = arr.size();
        int left = 0, right = n - 1;
    
        while (left < right){
            if (arr[left] + arr[right] < target)
                left++;
    
            else if (arr[left] + arr[right] > target)
                right--;
    
            else {
                int cnt1 = 0, cnt2 = 0;
                int ele1 = arr[left], ele2 = arr[right];
              
                while (left <= right and arr[left] == ele1) {
                    left++;
                    cnt1++;
                }
              
                while(left <= right and arr[right] == ele2) {
                    right--;
                    cnt2++;
                }
               
                if(ele1 == ele2) 
                    res += (cnt1 * (cnt1 - 1))/2;
                else 
                    res += (cnt1 * cnt2);
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
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }
    return 0;
}
```

## Explanation:

- **countPairs Function:** 
  - Uses the two-pointer technique to find pairs that sum up to the target.
  - Handles duplicates by counting the occurrences of matching elements.

- **Main Function:**
  - Reads input for multiple test cases, processes each test case, and outputs the number of valid pairs.

## Complexity Analysis

- **Time Complexity:** O(N log N), where N is the size of the array, due to the sorting step and linear scan with two pointers.
- **Space Complexity:** O(1), as the algorithm uses constant extra space (other than input storage).

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐


