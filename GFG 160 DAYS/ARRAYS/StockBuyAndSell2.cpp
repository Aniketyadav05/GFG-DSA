class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int minPrice = prices[0] , result = 0;
        for(int i = 1; i<prices.size();i++){
            minPrice = min(minPrice, prices[i]);
            
            result = max(result,prices[i] - minPrice);
        }
        return result;
    }
};
