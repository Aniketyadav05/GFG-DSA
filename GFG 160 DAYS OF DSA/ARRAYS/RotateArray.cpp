class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // reverse the first d elements 
        int n = arr.size();
        // Making d<n when its greater
        d%=n;
        // reversing the array from 0th index to 0+d index
        reverse(arr.begin(),arr.begin()+d);
        // reversing the array from 0+d to end 
        reverse(arr.begin()+d,arr.end());
        // Reversing the whole array
        reverse(arr.begin(),arr.end());
    }
};