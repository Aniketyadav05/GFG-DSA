#include <vector>
#include <algorithm>
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=n-2;i>=0;i--){
            if(arr[n-1]!=arr[i]){
                return arr[i];
            }

        }
        return -1;
    }
};