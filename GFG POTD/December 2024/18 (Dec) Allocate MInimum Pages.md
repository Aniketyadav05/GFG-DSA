## 18. Allocate Minimum Number of Pages

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)**

**Problem Statement:**

You are given an array `arr[]` where each element represents the number of pages in a book. You are also given an integer `k`, which is the number of students. The task is to allocate books to students such that the maximum number of pages assigned to a student is minimized. Each student must be assigned at least one book.

### Example

**Input:**
```
arr = [12, 34, 67, 90]
k = 2
```

**Output:**
```
113
```

### Explanation:
The books can be allocated as follows:
- Student 1: Books with 12 and 34 pages (sum = 46)
- Student 2: Books with 67 and 90 pages (sum = 157)

The maximum pages assigned to a student is 157.

## Solution Approach

To solve the problem, we can use **binary search**:

1. **Binary Search on the Maximum Page Limit:**
   - We will perform a binary search to minimize the maximum number of pages allocated to any student.
   - The lower bound (`lo`) will be the maximum number of pages in a book (`max(arr)`).
   - The upper bound (`hi`) will be the sum of all the pages (`sum(arr)`).

2. **Check Function:**
   - For each `mid` value during the binary search, check if it’s possible to allocate books such that the maximum number of pages assigned to any student is `mid` using a helper function `check`.
   - In the `check` function, we simulate the allocation of books to students. If we can allocate the books with the given `mid` value, return true; otherwise, return false.

3. **Binary Search Loop:**
   - If it's possible to allocate with the current `mid`, we try a smaller value by adjusting the upper bound (`hi`).
   - If it's not possible, we increase the lower bound (`lo`).

4. **Final Answer:**
   - The binary search will converge to the minimal possible value for the maximum number of pages that can be allocated.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(vector<int> &arr, int k, int pageLimit) {
        int cnt =1;
        int pageSum = 0;
        for(int i =0; i< arr.size(); i++){
            if(pageSum + arr[i] > pageLimit){
                cnt++;
                pageSum = arr[i];
            }
            else {
                pageSum += arr[i];
            }
        }
        return (cnt <= k);
    }

    int findPages(vector<int> &arr, int k) {
        if(k > arr.size()){
            return -1;
        }
        
        int lo = *max_element(arr.begin(), arr.end());
        int hi = accumulate(arr.begin(), arr.end(), 0);
        int res = -1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            
            if(check(arr, k, mid)){
                res = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return res;
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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
```

## Explanation:

- **check Function:** 
  - This function checks whether it's possible to allocate books such that no student gets more than `pageLimit` pages. If we can allocate the books within the limit, it returns `true`; otherwise, `false`.

- **findPages Function:**
  - This function uses binary search to find the minimum possible value for the maximum number of pages any student will get. The search space is between the maximum pages in any book and the total pages of all books.

- **Main Function:**
  - It reads the input, processes multiple test cases, and outputs the result of the `findPages` function.

## Complexity Analysis

- **Time Complexity:** 
  - Sorting the books takes O(N log N), where N is the number of books.
  - The binary search runs for log of the total pages, O(log(Sum of pages)).
  - Thus, the overall time complexity is O(N log N + log(Sum of pages)).

- **Space Complexity:** 
  - The space complexity is O(N) as we are storing the books in a vector.

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
