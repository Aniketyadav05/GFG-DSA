## 17. Aggressive Cows

**The problem can be found at the following link: [question link](https://www.geeksforgeeks.org/problems/aggressive-cows/1)**

**Problem Statement:**

You are given a set of stalls and `k` cows. The goal is to place the cows in the stalls such that the minimum distance between any two cows is maximized. We need to find this maximum possible minimum distance.

### Example

**Input:**
```
stalls = [1, 2, 4, 8, 9]
k = 3
```

**Output:**
```
3
```

### Explanation:
To place 3 cows, the largest minimum distance between any two cows will be 3. The cows can be placed in stalls at positions 1, 4, and 8.

## Solution Approach

The solution uses a **binary search** approach to find the maximum possible minimum distance between cows:

1. **Sorting the Stalls:**
   - First, sort the stalls to make sure we can easily calculate distances between adjacent stalls.

2. **Binary Search for Distance:**
   - The minimum possible distance is `0`, and the maximum possible distance is the difference between the first and last stall.
   - Use binary search to check for the maximum distance where we can place at least `k` cows with that distance.

3. **Placing Cows:**
   - For each middle distance in the binary search, check if it is possible to place at least `k` cows such that the distance between any two cows is at least `mid`. This check is done in the `Isok` function.

4. **Update the Result:**
   - If it’s possible to place the cows with the current distance, try for a larger distance by moving the search space to the right. Otherwise, try smaller distances by moving the search space to the left.

5. **Final Answer:**
   - The binary search will give the maximum possible minimum distance at the end.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int Isok(int dist, vector<int>& stalls) {
        int count = 1; // Place the first cow in the first stall
        int lastPlaced = stalls[0]; // Track the position of the last placed cow

        for (int i = 1; i < stalls.size(); i++) {
            // Place the next cow if the distance condition is met
            if (stalls[i] - lastPlaced >= dist) {
                count++;
                lastPlaced = stalls[i];
            }
        }

        return count;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Sort the stalls to simplify distance calculations
        sort(stalls.begin(), stalls.end());

        // Define the search space for the minimum distance
        int l = 0; // Minimum possible distance
        int r = stalls[stalls.size() - 1] - stalls[0]; // Maximum possible distance
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // Check if we can place at least `k` cows with distance `mid`
            if (Isok(mid, stalls) >= k) {
                ans = mid;  // Update the answer
                l = mid + 1; // Try for a larger distance
            } else {
                r = mid - 1; // Try for a smaller distance
            }
        }

        return ans;
    }
};

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
```

## Explanation:

- **Isok Function:** 
  - This function checks if it is possible to place `k` cows such that the minimum distance between any two cows is at least `dist`. It places cows in the stalls starting from the first one and checks the distance condition for the rest.
  
- **aggressiveCows Function:**
  - This function uses binary search to find the maximum possible minimum distance. It repeatedly narrows down the range of possible distances using the result from the `Isok` function.

- **Main Function:**
  - It reads multiple test cases, processes each test case, and calls the `aggressiveCows` function to find the result.

## Complexity Analysis

- **Time Complexity:** 
  - Sorting the stalls takes O(N log N), where N is the number of stalls.
  - The binary search takes O(log M), where M is the difference between the largest and smallest stall positions.
  - Thus, the overall time complexity is O(N log N + log M).

- **Space Complexity:** 
  - The space complexity is O(1) since we are using a constant amount of extra space.

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
