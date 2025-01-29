# 28 Permutations of a Given String

**The problem can be found at the following link: [Permutations of a Given String](https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1)**

---

## Problem Statement

Given a string `S`, the task is to generate all possible permutations of the string in any order. The output should contain only distinct permutations.

---

## Example:

### Input:
```
S = "ABC"
```

### Output:
```
"ABC ACB BAC BCA CAB CBA"
```

Explanation:
- All possible permutations of `"ABC"` are: `"ABC"`, `"ACB"`, `"BAC"`, `"BCA"`, `"CAB"`, `"CBA"`.

---

## Approach

We use **Backtracking** to generate all unique permutations of the string.

### Steps:

1. **Recursive Function**:
   - The function `genPermutation()` generates permutations by swapping characters at different positions and recursively exploring all possibilities.

2. **Handling Duplicates**:
   - Since the input may contain duplicate characters, we use an `unordered_set` to store only unique permutations.

3. **Implementation Details**:
   - A **boolean vector** `used` tracks whether a character has been used in the current permutation.
   - A **string** `curr` stores the current permutation being built.
   - The **unordered_set** `st` ensures only unique permutations are stored.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Helper function to generate permutations using backtracking
    void genPermutation(int i, string &s, vector<bool> &used, 
                        string &curr, unordered_set<string>& st) {
        if (i == s.size()) {
            st.insert(curr);  // Store unique permutations
            return;
        }

        for (int j = 0; j < s.size(); j++) {
            if (!used[j]) {
                used[j] = true;   // Mark as used
                curr.push_back(s[j]);  // Add character to current permutation
                
                genPermutation(i + 1, s, used, curr, st);
                
                used[j] = false;  // Backtrack
                curr.pop_back();  
            }
        }
    }

    // Function to find all unique permutations
    vector<string> findPermutation(string &s) {
        vector<bool> used(s.size(), false);
        unordered_set<string> st;
        string curr = "";

        genPermutation(0, s, used, curr, st);

        // Convert set to vector and return
        vector<string> res(st.begin(), st.end());
        return res;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";
        cout << "~" << "\n";
    }
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity**:
  - Since we generate all permutations, the worst-case complexity is **O(N!)**.
  - The sorting operation takes **O(N! log N!)**.

- **Space Complexity**:
  - The extra space used for recursion and storing permutations is **O(N!)**.

---

## Input and Output Format

### Input:
1. Number of test cases `T`.
2. For each test case, a string `S` is given.

### Output:
- A space-separated list of unique permutations of `S` in lexicographically sorted order.

---

## Example Walkthrough

### Input:
```
1
ABC
```

### Output:
```
ABC ACB BAC BCA CAB CBA
```

---

## Contribution and Support

If you have any questions, feel free to ask.  
⭐ If this solution helped you, please give it a star! ⭐
