class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int res = arr[0];
        int maxEnding = arr[0];
        for(int i=1;i<arr.size();i++){
            maxEnding= max(maxEnding+arr[i],arr[i]);
            res = max(res,maxEnding);
        }
        return res;
    }
};