#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the length of the longest palindromic subsequence (LPS)
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        // Create two vectors: one for the current state (curr)
        // and one for the previous state (prev) to save space
        vector<int> curr(n), prev(n);

        // Loop through the string in reverse (starting from the end)
        for (int i = n - 1; i >= 0; --i) {
            curr[i] = 1; // A single character is always a palindrome of length 1

            // Loop through the characters ahead of i
            for (int j = i + 1; j < n; ++j) {

                // If the characters at i and j are the same
                if (s[i] == s[j]) {
                    // Add 2 to the length of the palindrome between them
                    curr[j] = prev[j - 1] + 2;
                } else {
                    // Take the maximum between excluding either i or j
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }

            // Update previous to the current state of dp
            prev = curr;
        }

        return curr[n - 1]; // Return the longest palindromic subsequence length
    }
};

// Main function to test the longestPalindromeSubseq function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input strings
    string s1 = "bbbab";
    string s2 = "cbbd";

    // Call longestPalindromeSubseq function and print results
    cout << "Longest Palindromic Subsequence length for '" << s1 << "': " 
         << sol.longestPalindromeSubseq(s1) << endl;

    cout << "Longest Palindromic Subsequence length for '" << s2 << "': " 
         << sol.longestPalindromeSubseq(s2) << endl;

    return 0; // Successful execution
}
