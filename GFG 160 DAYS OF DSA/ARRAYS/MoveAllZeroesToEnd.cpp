class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
    // Getting the size of array so we can iterate through it easily
    int n = arr.size();
    // variable to track the position of teh non-zero element
    int count =0;
    for(int i =0;i<n;i++){
        //checking if the element is non-zero
        if(arr[i]!=0){
            //swapping the current element with the element at index count
            swap(arr[i],arr[count]);   
            // Increasing the count index by 1
            count++;
        }
    }
    }
};