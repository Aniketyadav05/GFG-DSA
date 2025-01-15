# 11 Longest Unique Substring

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1)**

## Problem Statement:

Given a string `s`, find the length of the longest substring that contains no repeated characters.

### Example:

#### Input:
```
s = "abcabcbb"
```

#### Output:
```
3
```

#### Explanation:
The longest substring without repeating characters is "abc", which has a length of 3.

### Approach:

1. **Sliding Window Technique:**
   - Use two pointers `left` and `right` to define the sliding window.
   - Use a boolean vector `vis` to keep track of characters present in the current window.
   - As you move the `right` pointer, if the character is already in the window, move the `left` pointer to remove characters until the current character is not in the window.
   - Update the result with the maximum length found.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    const int MAX_CHAR = 26;

    int longestUniqueSubstr(string &s) {
        if (s.length() == 0 || s.length() == 1)
            return s.length();

        int res = 0;
        vector<bool> vis(MAX_CHAR, false);
        int left = 0, right = 0;

        while (right < s.length()) {
            while (vis[s[right] - 'a'] == true) {
                vis[s[left] - 'a'] = false;
                left++;
            }
            vis[s[right] - 'a'] = true;
            res = max(res, (right - left + 1));
            right++;
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~\n";
    }
    return 0;
}
```

### Explanation:

- **longestUniqueSubstr Function:**
  - This function takes a string `s` as input.
  - It uses a sliding window technique to find the longest substring without repeating characters.
  - A boolean vector `vis` tracks characters in the current window.
  - The function updates the result with the maximum length of a unique substring found.

- **Main Function:**
  - The main function reads multiple test cases, each consisting of a string `s`.
  - It calls the `longestUniqueSubstr` function for each test case and prints the length of the longest unique substring.

### Complexity Analysis:

- **Time Complexity:**
  - The time complexity is `O(n)`, where `n` is the length of the string, since each character is processed at most twice.

- **Space Complexity:**
  - The space complexity is `O(1)` since the `vis` vector has a constant size of 26 (for lowercase English letters).

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
