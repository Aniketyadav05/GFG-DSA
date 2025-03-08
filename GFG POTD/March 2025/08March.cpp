#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Function to find the longest palindromic substring
    string longestPalindrome(string &s) {
        int n = s.length();
        if (n == 0) return "";

        int start = 0, maxLen = 1;

        // Traverse the input string
        for (int i = 0; i < n; i++) {
            // Check for both odd and even length palindromes
            for (int j = 0; j <= 1; j++) {
                int low = i;
                int high = i + j;

                // Expand while within bounds and palindrome property holds
                while (low >= 0 && high < n && s[low] == s[high]) {
                    int currLen = high - low + 1;
                    if (currLen > maxLen) {
                        start = low;
                        maxLen = currLen;
                    }
                    low--;
                    high++;
                }
            }
        }

        return s.substr(start, maxLen); // Extract the longest palindrome
    }
};

// Main function to test longestPalindrome function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input
    string s;
    cout << "Enter the string: ";
    cin >> s;

    // Call the function and print the result
    string result = sol.longestPalindrome(s);
    cout << "Longest palindromic substring: " << result << endl;

    return 0; // Successful execution
}
