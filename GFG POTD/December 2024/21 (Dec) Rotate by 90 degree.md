## 21. Spiral Matrix Traversal

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1)**

### Problem Statement:

Given a matrix of size `n x m`, the task is to print all the elements of the matrix in a spiral order starting from the top-left corner.

### Example:

#### Input:
```
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
```

#### Output:
```
1 2 3 6 9 8 7 4 5
```

### Approach

1. **Spiral Traversal:**
   - The goal is to traverse the matrix in a spiral order starting from the top-left element and moving in four directions: left to right, top to bottom, right to left, and bottom to top. 
   - We will use four pointers (`top`, `bottom`, `left`, `right`) to mark the boundaries of the current layer we are traversing.

2. **Traversal Logic:**
   - Start from the top-left corner.
   - Traverse the top row from left to right.
   - Traverse the rightmost column from top to bottom.
   - Traverse the bottom row from right to left.
   - Traverse the leftmost column from bottom to top.
   - Shrink the boundaries (`top++`, `bottom--`, `left++`, `right--`) after each traversal until all elements are covered.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int> ans;
        int n = mat.size(); // no. of rows
        int m = mat[0].size(); // no. of columns

        int top = 0, left = 0, bottom = n - 1, right = m - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) 
                ans.push_back(mat[top][i]);
            top++;

            for (int i = top; i <= bottom; i++) 
                ans.push_back(mat[i][right]);
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) 
                    ans.push_back(mat[bottom][i]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) 
                    ans.push_back(mat[i][left]);
                left++;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
```

### Explanation:

- **SpirallyTraverse Function:**
  - This function takes a matrix as input and returns the elements in spiral order.
  - It uses four pointers (`top`, `bottom`, `left`, `right`) to traverse the matrix and push the elements in the `ans` vector.

- **Main Function:**
  - It reads the input matrix for multiple test cases and calls the `spirallyTraverse` function to get the spiral order of the matrix.
  - It prints the result for each test case.

### Complexity Analysis

- **Time Complexity:**
  - The time complexity is O(n * m), where n is the number of rows and m is the number of columns, since we are visiting each element of the matrix exactly once.

- **Space Complexity:**
  - The space complexity is O(n * m) because we are storing the result in a vector that holds all the elements of the matrix.

## Contribution and Support
For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
