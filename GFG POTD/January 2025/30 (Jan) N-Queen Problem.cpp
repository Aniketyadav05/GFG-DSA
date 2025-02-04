//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void nQueenUtil(int j, int n, vector<int> &board, vector<bool> &rows, 
    vector<bool> &diag1, vector<bool> &diag2, vector<vector<int>> &res) {
    
    if (j > n) {
          // A solution is found
        res.push_back(board);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!rows[i] && !diag1[i + j] && !diag2[i - j + n]) {

            // Place queen
            rows[i] = diag1[i + j] = diag2[i - j + n] = true;
            board.push_back(i);

            // Recurse to the next column
            nQueenUtil(j + 1, n, board, rows, diag1, diag2, res);

            // Remove queen (backtrack)
            board.pop_back();
            rows[i] = diag1[i + j] = diag2[i - j + n] = false;
        }
    }
}
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> res;
    vector<int> board;

    // Rows occupied
    vector<bool> rows(n + 1, false);

    // Major diagonals (row + j) and Minor diagonals (row - col + n)
    vector<bool> diag1(2 * n + 1, false);
    vector<bool> diag2(2 * n + 1, false);

    // Start solving from the first column
    nQueenUtil(1, n, board, rows, diag1, diag2, res);
    return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends