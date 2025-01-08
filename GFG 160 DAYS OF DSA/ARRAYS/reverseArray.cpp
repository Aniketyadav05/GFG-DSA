class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n =arr.size();
        //Taking 2 pointers to iterate through the array
        int i =0, j=n-1;
        // swappinng the elements from 0th index to nth index till i == j
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
};