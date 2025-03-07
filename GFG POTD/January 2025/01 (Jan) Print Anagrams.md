## 01. Print Anagrams Together
**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/print-anagrams-together/1)**


## Problem Statement

Given an array of strings, the task is to group anagrams together. Two strings are anagrams if they contain the same characters with the same frequency, but possibly in a different order.

### Example

**Input:**
```
["eat", "tea", "tan", "ate", "nat", "bat"]
```

**Output:**
```
[["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]
```

## Solution Approach

The solution involves the following steps:

1. **Frequency Hashing:** 
   - For each string, create a hash based on the frequency of each character in the string.
   - The hash is generated by appending the frequency of each character followed by a delimiter (`$`).

2. **Grouping Anagrams:** 
   - Use an unordered map to keep track of the groups of anagrams. The key is the hash of the string, and the value is the index of the group in the result vector.
   - For each string, calculate its hash, check if it already exists in the map, and either add it to the existing group or create a new group.

## Code

```cpp
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    const int MAX_CHAR = 26;

    string getHash(string &s) {
        string hash;
        vector<int> freq(MAX_CHAR, 0);

        for(char ch: s)
            freq[ch - 'a'] += 1;

        for(int i = 0; i < MAX_CHAR; i++) {
            hash.append(to_string(freq[i]));
            hash.append("$");
        }

        return hash;
    }

    vector<vector<string>> anagrams(vector<string>& arr) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            string key = getHash(arr[i]);
            if (mp.find(key) == mp.end()) {
                mp[key] = res.size();
                res.push_back({});
            }
            res[mp[key]].push_back(arr[i]);
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }
        Solution ob;
        vector<vector<string>> result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "~\n";
    }
    return 0;
}
```

## Explanation

- **getHash Function:** Computes a unique hash for each string based on the frequency of characters.
- **anagrams Function:** Groups strings with the same hash into a list, thus grouping anagrams together.
- **Main Function:** Reads input, processes each test case, and outputs the groups of anagrams.

## Complexity Analysis

- **Time Complexity:** O(N * M), where N is the number of strings and M is the average length of a string. Hash computation and comparison take linear time relative to the length of the string.
- **Space Complexity:** O(N * M) for storing the groups of anagrams and their hashes.


## Contribution and Support
For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐




