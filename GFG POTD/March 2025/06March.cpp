#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to compute the length of the Longest Common Subsequence (LCS)
    int lcs(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();

        // DP table of size (m+1) x (n+1) initialized to 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Building the dp table in bottom-up fashion
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1; // If characters match, increase count
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Else, take max of excluding one char
            }
        }

        return dp[m][n]; // Return the LCS length
    }
};

// Main function to test the LCS function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input strings
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    // Call LCS function and print the result
    int result = sol.lcs(s1, s2);
    cout << "Length of Longest Common Subsequence: " << result << endl;

    return 0; // Successful execution
}
