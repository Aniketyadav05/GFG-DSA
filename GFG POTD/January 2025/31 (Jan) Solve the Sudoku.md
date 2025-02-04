# 31. Solve the Sudoku

**The problem can be found at the following link: [Solve the Sudoku](https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1)**

---

## Problem Statement

The task is to solve a given `9x9` Sudoku puzzle by filling the empty cells (`0`s) with numbers from `1` to `9` while ensuring:
1. No two numbers in the same row are the same.
2. No two numbers in the same column are the same.
3. No two numbers in the same `3x3` subgrid are the same.

---

## Example:

### Input:
```
3
53 0 0 0 0 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

### Output:
```
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```

---

## Approach

We use **Backtracking** to find a valid solution for the Sudoku grid.

### Steps:

1. **Recursive Backtracking Function (`solveSudokuRec`)**:
   - Find the next empty cell.
   - Try filling it with numbers `1-9`.
   - If the number is **valid**, recurse to the next empty cell.
   - If no number works, **backtrack** by resetting the cell to `0`.

2. **Validity Check (`isSafe`)**:
   - Ensure the number is **not present** in the same row.
   - Ensure the number is **not present** in the same column.
   - Ensure the number is **not present** in the same `3x3` subgrid.

3. **Base Case**:
   - If all cells are filled, return `true`.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSafe(vector<vector<int>> &mat, int row, int col, int num) {
        for (int x = 0; x < 9; x++) 
            if (mat[row][x] == num || mat[x][col] == num) 
                return false;

        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (mat[i + startRow][j + startCol] == num)
                    return false;

        return true;
    }

    bool solveSudokuRec(vector<vector<int>> &mat, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return solveSudokuRec(mat, row + 1, 0);
        if (mat[row][col] != 0) return solveSudokuRec(mat, row, col + 1);

        for (int num = 1; num <= 9; num++) {
            if (isSafe(mat, row, col, num)) {
                mat[row][col] = num;
                if (solveSudokuRec(mat, row, col + 1)) return true;
                mat[row][col] = 0;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<int>> &mat) {
        solveSudokuRec(mat, 0, 0);
    }
};

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;
        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity**:  
  - **O(9^(n*n))** in the worst case, as we try all possible placements.
  - The backtracking approach ensures early pruning, making it much faster in practice.

- **Space Complexity**:  
  - **O(1)** (Only uses the Sudoku grid and a few variables).

---

## Input and Output Format

### Input:
1. Number of test cases `T`.
2. For each test case, a `9x9` grid of integers (0 represents an empty cell).

### Output:
- The solved `9x9` Sudoku grid.

---

## Example Walkthrough

### Input:
```
1
53 0 0 0 0 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

### Output:
```
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```

---

## Contribution and Support

If you have any questions, feel free to ask.  
⭐ If this solution helped you, please give it a star! ⭐
