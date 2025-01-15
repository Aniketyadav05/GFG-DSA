//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
       int n = a.size(),m=b.size();
       int last =0;
       int i=0, j=0;
       for(int d=0;d<k;d++){
            if(i<n){
                if(j<m && a[i] > b[j]){
                    last = b[j];
                    j++;
                }
                else{
                    last = a[i];
                    i++;
                }
            }
            else if (j < m) {
            last = b[j];
            j++;
        }
           
       }
       return last;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends