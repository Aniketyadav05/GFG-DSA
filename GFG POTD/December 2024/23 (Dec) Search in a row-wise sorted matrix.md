## 23. Search a Given Number in Row-Column Sorted Matrix

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/search-in-a-row-wise-sorted-matrix/1)**

### Problem Statement:

Given a matrix of size `r x c` where each row is sorted in ascending order from left to right and each column is sorted in ascending order from top to bottom, the task is to search for an element `x` in the matrix.

### Example:

#### Input:
```
matrix = [
    [10, 20, 30, 40],
    [15, 25, 35, 45],
    [27, 29, 37, 48],
    [32, 33, 39, 50]
]
x = 29
```

#### Output:
```
true
```

#### Input:
```
matrix = [
    [10, 20, 30, 40],
    [15, 25, 35, 45],
    [27, 29, 37, 48],
    [32, 33, 39, 50]
]
x = 100
```

#### Output:
```
false
```

### Approach

1. **Brute Force Search:**
   - We can loop through each row and each column to check if the element exists. This results in a time complexity of `O(r * c)` where `r` is the number of rows and `c` is the number of columns.
   
2. **Optimized Approach (Binary Search):**
   - A more optimal solution would be to start from the top-right corner. 
   - If the current element is equal to `x`, we have found the element.
   - If the current element is greater than `x`, move left (decrease the column index).
   - If the current element is less than `x`, move down (increase the row index).
   - This reduces the time complexity to `O(r + c)`.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        for(int i = 0; i < n; i++) {
            int m = mat[i].size();
            if(mat[i][m-1] >= x) {  // Check if the last element of the row is greater than or equal to x
                for(int j = 0; j < m; j++) {
                    if(mat[i][j] == x) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.searchRowMatrix(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
```

### Explanation:

- **searchRowMatrix Function:**
  - This function iterates through each row of the matrix, and if the last element of a row is greater than or equal to `x`, it then checks every element of the row for `x`. If `x` is found, it returns `true`.
  - If no matching element is found, it returns `false`.

- **Main Function:**
  - The main function reads multiple test cases, takes a matrix and the element `x` as input, and calls the `searchRowMatrix` function to check if the element exists in the matrix.
  - It prints `true` if the element is found, otherwise `false`.

### Complexity Analysis:

- **Time Complexity:**
  - The time complexity is `O(r * c)` where `r` is the number of rows and `c` is the number of columns since in the worst case, all the elements may need to be checked.

- **Space Complexity:**
  - The space complexity is `O(1)` because we are using a constant amount of extra space apart from the input matrix.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐