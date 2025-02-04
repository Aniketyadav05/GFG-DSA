# 1. Word Search

**The problem can be found at the following link: [Word Search](https://www.geeksforgeeks.org/problems/word-search/1)**

---

## Problem Statement

Given a 2D grid of characters and a word, the task is to determine if the word exists in the grid. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

---

## Example:

### Input:
```
3
3 4
a b c e
s f c s
a d e e
abcced
```

### Output:
```
true
```

---

## Approach

We use **Depth-First Search (DFS)** to explore all possible paths in the grid that can form the given word.

### Steps:

1. **DFS Function (`dfs`)**:
   - Check if the current cell matches the current character of the word.
   - Mark the cell as visited by changing its value to a special character (`#`).
   - Recursively check all four possible directions (up, down, left, right).
   - If any path matches the word, return `true`.
   - Restore the cell's original value after the recursive call (backtracking).

2. **Main Function (`isWordExist`)**:
   - Iterate through each cell in the grid.
   - If the cell matches the first character of the word, start DFS from that cell.
   - If DFS returns `true`, the word exists in the grid.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(vector<vector<char>> &b, string &w, int i, int j, int k) {
        if(k == w.size()) return true;
        if(i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || b[i][j] != w[k]) return false;
        char t = b[i][j]; 
        b[i][j] = '#';
        bool f = dfs(b, w, i-1, j, k+1) || dfs(b, w, i+1, j, k+1) ||
                 dfs(b, w, i, j-1, k+1) || dfs(b, w, i, j+1, k+1);
        b[i][j] = t;
        return f;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        for(int i = 0; i < mat.size(); i++)
            for(int j = 0; j < mat[0].size(); j++)
                if(mat[i][j] == word[0] && dfs(mat, word, i, j, 0))
                    return true;
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity**:  
  - **O(N * M * 4^L)**, where `N` and `M` are the dimensions of the grid, and `L` is the length of the word.
  - The DFS explores up to 4 directions for each character in the word.

- **Space Complexity**:  
  - **O(L)** for the recursion stack, where `L` is the length of the word.

---

## Input and Output Format

### Input:
1. Number of test cases `T`.
2. For each test case:
   - Dimensions of the grid `n` and `m`.
   - The `n x m` grid of characters.
   - The word to search for.

### Output:
- `true` if the word exists in the grid, otherwise `false`.

---

## Example Walkthrough

### Input:
```
1
3 4
a b c e
s f c s
a d e e
abcced
```

### Output:
```
true
```

---

## Contribution and Support

If you have any questions, feel free to ask.  
⭐ If this solution helped you, please give it a star! ⭐