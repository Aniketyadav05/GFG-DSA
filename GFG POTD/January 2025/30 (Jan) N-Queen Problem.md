# 30 N-Queen Problem

**The problem can be found at the following link: [N-Queen Problem](https://www.geeksforgeeks.org/problems/n-queen-problem0315/1)**

---

## Problem Statement

The N-Queen problem involves placing `N` queens on an `N x N` chessboard such that:
1. No two queens attack each other.
2. No two queens share the same row, column, or diagonal.

The task is to return all possible valid configurations, where each configuration is represented as a list of column positions of queens for each row.

---

## Example:

### Input:
```
N = 4
```

### Output:
```
[ [2 4 1 3] [3 1 4 2] ]
```

Explanation:
1. The first valid configuration places queens at columns `[2, 4, 1, 3]` in each row.
2. The second valid configuration places queens at `[3, 1, 4, 2]`.

---

## Approach

We use **Backtracking** to generate all valid queen placements.

### Steps:

1. **Recursive Backtracking Function (`nQueenUtil`)**:
   - Place a queen in the current column.
   - Check if it is safe using:
     - `rows` array (to ensure no two queens are in the same row).
     - `diag1` (major diagonal) and `diag2` (minor diagonal) arrays.
   - If safe, recursively try to place the next queen.
   - If a full solution is found, store it.

2. **Backtrack**:
   - Remove the last placed queen and try the next possible position.

3. **Base Case**:
   - If all `N` queens are placed, store the configuration.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nQueenUtil(int j, int n, vector<int> &board, vector<bool> &rows, 
                    vector<bool> &diag1, vector<bool> &diag2, vector<vector<int>> &res) {
        if (j > n) {
            res.push_back(board); // Store valid configuration
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (!rows[i] && !diag1[i + j] && !diag2[i - j + n]) {
                // Place queen
                rows[i] = diag1[i + j] = diag2[i - j + n] = true;
                board.push_back(i);

                // Recurse to next column
                nQueenUtil(j + 1, n, board, rows, diag1, diag2, res);

                // Remove queen (Backtrack)
                board.pop_back();
                rows[i] = diag1[i + j] = diag2[i - j + n] = false;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> board;
        vector<bool> rows(n + 1, false);
        vector<bool> diag1(2 * n + 1, false);
        vector<bool> diag2(2 * n + 1, false);

        // Start from the first column
        nQueenUtil(1, n, board, rows, diag1, diag2, res);
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.empty())
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (auto &solution : ans) {
                cout << "[";
                for (int col : solution)
                    cout << col << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity**:  
  - **O(N!)** in the worst case, as we generate all possible placements and backtrack when necessary.
  
- **Space Complexity**:  
  - **O(N)** for recursive calls and arrays storing row and diagonal checks.

---

## Input and Output Format

### Input:
1. Number of test cases `T`.
2. For each test case, an integer `N` representing the size of the board.

### Output:
- Each valid configuration is printed as a list of column positions.
- If no solution exists, print `-1`.

---

## Example Walkthrough

### Input:
```
1
4
```

### Output:
```
[2 4 1 3] [3 1 4 2]
```

---

## Contribution and Support

If you have any questions, feel free to ask.  
⭐ If this solution helped you, please give it a star! ⭐
