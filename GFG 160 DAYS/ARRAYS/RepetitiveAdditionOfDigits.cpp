#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int singleDigit(int n) {
        // code here
        if (n == 0) 
            return 0;
    
     
      if(n % 9 == 0)
          return 9;
     
      return (n % 9);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.singleDigit(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends